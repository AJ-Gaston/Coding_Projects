import requests
from bs4 import BeautifulSoup
import sys

def is_html(content_type):
    return content_type.startswith('text/html')

def main(seed_uri, output_file):
    unique_uris = set()
    timeout_seconds = 10  # Set a timeout of 10 seconds
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3'
    }

    try:
        # Request the seed webpage with timeout and custom headers
        response = requests.get(seed_uri, headers=headers, timeout=timeout_seconds)
        response.raise_for_status()  # Raise an error for bad responses
        soup = BeautifulSoup(response.content, 'html.parser')

        # Extract all links from the webpage
        links = {a['href'] for a in soup.find_all('a', href=True)}
        
        for link in links:
            if len(unique_uris) >= 500:
                break

            # Handle relative URLs
            full_link = requests.compat.urljoin(seed_uri, link)

            # Request the link and check its Content-Type and Content-Length with timeout
            try:
                link_response = requests.head(full_link, allow_redirects=True, headers=headers, timeout=timeout_seconds)
                link_response.raise_for_status()  # Raise an error for bad responses
                
                content_type = link_response.headers.get('Content-Type', '')
                content_length = link_response.headers.get('Content-Length', 0)

                if is_html(content_type) and int(content_length) > 1000:
                    # Add the final URI after any redirects
                    unique_uris.add(link_response.url)

            except requests.RequestException as e:
                print(f"Error accessing {full_link}: {e}")

        # Save unique URIs to a file
        with open(output_file, 'w') as f:
            for uri in unique_uris:
                f.write(uri + '\n')
        
        print(f"Collected {len(unique_uris)} unique URIs and saved to {output_file}")

    except requests.RequestException as e:
        print(f"Error accessing seed URI {seed_uri}: {e}")

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print("Usage: python webScrap.py <seed_uri> <output_file>")
    else:
        seed_uri = sys.argv[1]
        output_file = sys.argv[2]
        main(seed_uri, output_file)

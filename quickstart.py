from json import dumps

from httplib2 import Http

WEBHOOK_URL = "https://chat.googleapis.com/v1/spaces/AAAAU6itNNA/messages?key=AIzaSyDdI0hCZtE6vySjMm-WEfRq3CPzqKqqsHI&token=S7hB3cEhxA-H2Tag2P3HYfBGoX-sAGyRwc0noD687i4"


def main():
    """Google Chat incoming webhook quickstart."""
    url = WEBHOOK_URL
    app_message = {
        'text': 'Hello from a Python script!'}
    message_headers = {'Content-Type': 'application/json; charset=UTF-8'}
    http_obj = Http()
    response = http_obj.request(
        uri=url,
        method='POST',
        headers=message_headers,
        body=dumps(app_message),
    )
    print(response)


if __name__ == '__main__':
    main()

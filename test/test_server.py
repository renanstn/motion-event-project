import unittest, requests, json

class TestServer(unittest.TestCase):

    url = 'http://127.0.0.1:5000/'
    
    def test_hello(self):
        response = requests.get(self.url)
        self.assertEqual(response.status_code, 200)
        self.assertEqual(response.json(), {'hello': 'world'})

    def test_alert(self):
        response = requests.get(self.url + '/alert')
        self.assertEqual(response.status_code, 200)
        self.assertEqual(response.json(), {'info': 'alert received!'})

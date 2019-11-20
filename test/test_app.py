import unittest
from server import api

class ApiTest(unittest.TestCase):

    def setUp(self):
        self.app = api.app.test_client()

    def test_hello(self):
        response = self.app.get('/hello')
        self.assertEqual(200, response.status_code)
        self.assertEqual({'hello': 'world'}, response.json)

    def test_alert(self):
        response = self.app.get('/alert')
        self.assertEqual(200, response.status_code)
        self.assertEqual({'info': 'alert received!'}, response.json)

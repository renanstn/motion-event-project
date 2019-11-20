import unittest
from ..src.server.api import app

class testApi(unittest.TestCase):

    def setUp(self):
        self.app = app.test_client()

    def test_hello(self):
        response = self.app.get('/hello')
        self.assertEqual(200, response.status_code)

if __name__ == "__main__":
    unittest.main()

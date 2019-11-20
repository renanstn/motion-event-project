import unittest
from run import app

class testApi(unittest.TestCase):

    def setUp(self):
        self.api = app.test_client()

    def test_hello(self):
        response = self.api.get('/hello')
        self.assertEqual(200, response.status_code)

if __name__ == "__main__":
    unittest.main()

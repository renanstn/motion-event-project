import unittest
from src import *

class testApi(unittest.TestCase):

    def setUp(self):
        api = create_app()
        test_api = api.test_client()

    def test_hello(self):
        response = self.api.get('/hello')
        self.assertEqual(200, response.status_code)

if __name__ == "__main__":
    unittest.main()

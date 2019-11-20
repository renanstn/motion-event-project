from flask import Flask, jsonify
from .events import alt_tab

app = Flask(__name__)

@app.route('/hello')
def hello():
    return jsonify({'hello': 'world'})

@app.route('/alert')
def alert():
    alt_tab()
    return jsonify({'info' : 'alert received!'})

if __name__ == "__main__":
    app.run(host='0.0.0.0', debug=True)

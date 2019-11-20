from flask import Blueprint, jsonify
from .events import alt_tab

api = Blueprint('api', __name__)

@api.route('/hello')
def hello():
    return jsonify({'hello': 'world'})

@api.route('/alert')
def alert():
    alt_tab()
    return jsonify({'info' : 'alert received!'})

import pandas as pd
from flask import Flask, request, jsonify, Response
import re
from io import StringIO
import requests
from requests.auth import HTTPBasicAuth
import os
import sys


app = Flask(__name__)

@app.route('/')
def home():
    global page
    page=0
    
    with open("index.html") as f:
        html = f.read()
    return html


def main():
    global username
    global password
    try:
        username=str(sys.argv[1])
        password=str(sys.argv[2])
    except:
        print("Failed to detect username or password.\n")
        print("Correct usage: python3 main.py USERNAME PASSWORD")
        sys.exit(0)


## Make the error more specific
if __name__ == '__main__':
    
    main()
    app.run(host="0.0.0.0", debug=True) # don't change this line!
            
    
    

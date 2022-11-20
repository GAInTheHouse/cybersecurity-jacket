import pandas as pd
from flask import Flask, render_template
import re
from io import StringIO
import requests
from requests.auth import HTTPBasicAuth
import os
import sys


app = Flask(__name__)

@app.route('/')
def home():
    with open("index.html") as f:
        html = f.read()
    return render_template('index.html')


def main():
    print('Server begun')


## Make the error more specific
if __name__ == '__main__':
    
    main()
    app.run(host="0.0.0.0", debug=True) # don't change this line!
            
    
    

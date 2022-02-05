#!/usr/bin/python3

from firebase_admin import credentials, storage, initialize_app

cred = credentials.Certificate("/home/gagan/Downloads/reverse-coding-2022-e5fe705dd557.json")
initialize_app(cred, {'storageBucket': 'reverse-coding-2022.appspot.com'})
bucket = storage.bucket()
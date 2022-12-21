# Automatically download images from Google Drive
The PyDrive library was used for this script, since it simplifies many Google Drive Api tasks. The documentation can be found in https://pypi.org/project/PyDrive/. Copyright (c) 2016 PyPI. It can be installed as pip install pydrive

This script also requires a Google Cloud Project and the enabling of the Google Drive API for the project. An easy tutorial on how to setup said project can be found in https://www.youtube.com/watch?v=fAxXNovO-vg&t=0s&ab_channel=pyGuru, made by the channel PyGuru in 2021. The files named credentials.json and client_secrets.json are used to provide the credentials and ID of the Google Cloud Project. The script called settings.yaml provides the credentials to the Google Drive API.

The main script initializes the Google Drive API, and indicates the ID of the folder it wants to access. Then, there is a loop that lists all the files in the indicated Google Drive folder, downloads each one, and then deletes them from the folder. After two seconds, the cycle is repeated.

Note: Since all the images taken by the ESP32-CAM board are uploaded with the same name, they will be automatically replaced when they are downloaded to the computer.

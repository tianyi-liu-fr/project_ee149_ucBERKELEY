# Python code
Two python scripts were used for the project.
1. Download images from Google Drive

This script automatically downloads the images taken by the camera and uploaded to the Google Drive folder. After they are downloaded, the script deletes them from Google Drive, minimizing the storage use of the cloud service.

2. AWS Textract

This script automatically processes the images downloaded to the computer by the previous script with AWS textract. After the text is detected, it is written in a Google Spreadsheet.

Note: Both python scripts are run simultaneously when the device is being used.

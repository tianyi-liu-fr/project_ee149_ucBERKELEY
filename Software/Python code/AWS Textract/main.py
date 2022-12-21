# AWS to extract text from the image
import boto3
# Google Cloud Console to write text in a spreadsheet
import gspread
from oauth2client.service_account import ServiceAccountCredentials
import json
# Delay
import time

# Variable to store previous image
last_img = 0

# Initialize AWS clients
s3 = boto3.client('s3')
textractmodule = boto3.client('textract', region_name='us-west-1')

# Bucket name, path of photo, and name of photo file
bucket = 'visionplusplus'
path = 'C:/Users/Enriq/Desktop/Universidad/7mo semestre/Introduction to Embedded and Cyber Physical Systems/Project/Python code/Images from Google Drive/vision_photo.jpg'
name = 'vision_photo.jpg'

# Scopes to grant credentials for Google Spreadsheets
scopes = [
'https://www.googleapis.com/auth/spreadsheets',
'https://www.googleapis.com/auth/drive'
]

# Authenticate access to spreadsheet with JSON key, and select which sheet to write on
credentials = ServiceAccountCredentials.from_json_keyfile_name("visonplusplus-ad4a007f31f0.json", scopes) # Access the account JSON key
file = gspread.authorize(credentials)
sheet = file.open("vision_text")
sheet = sheet.sheet1

# Initialize variable to store recognized text
recogText = ''

while True:
    # Constantly check for new images
    img = open(path, "rb").read()
    # Extract text only when a new image is downloaded
    if(img == last_img):
        time.sleep(2)
    else:
        # Upload image taken to the AWS S3 bucket
        s3.upload_file(path, bucket, name)

        # Detect text in the image with AWS Textract
        response = textractmodule.detect_document_text(
            Document = {
                'S3Object': {
                    'Bucket': bucket,
                    'Name': name
                }
            }) 

        # Print and store detected text
        print ('------------- Detected text -----------------')
        for item in response["Blocks"]:
            if item["BlockType"] == "LINE":
                print(item["Text"])
                # Join all the lines in one string. Separate lines with a (.)
                recogText = recogText + item["Text"] + '. '
        print ('------------- Detected text -----------------')

        # Write detected text in first cell of spreadsheet
        sheet.update_acell('A1', recogText)

        # Update previous image
        last_img = img

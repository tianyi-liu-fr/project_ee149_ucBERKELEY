# Automatically extract text from images using AWS Textract
This python script uses the boto3 library https://boto3.amazonaws.com/v1/documentation/api/latest/index.html. Copyright (c) 2022, Amazon Web Services, Inc. This is the Amazon Web Services (AWS) SDK for Python. It provides access to AWS S3, a cloud server in which the images are uploaded, and to AWS Textract, a machine learning service for text detection. To access the AWS, an account has to be created and the credentials have to be provided. A tutorial on how to do this is found in https://www.youtube.com/watch?v=6dXZM9SAFzg&ab_channel=KGPTalkie, by the channel KGP Talkie in 2017. The file called bucket_config.py specifies the bucket configuration in S3 that allows for uploading of files using the SDK. The template for this file was provided in https://www.youtube.com/watch?v=FkMcX8N-x_8&ab_channel=KGPTalkie, also by KGP Talkie in 2017.

```
pip install boto3
pip install awscli
aws configure
```

The python libraries oauth2client https://pypi.org/project/oauth2client/ Copyright (c) 2022 Python Software Foundation, and gspread https://docs.gspread.org/en/v5.7.0/ Copyright (c) 2022 Anton Burnashev, were also used. oauth2client is a web authorization framework to give permission to write in Google Spreadsheets, and gspread is the Python API for Google Spreadsheets.

```
pip install oauth2client
pip install gspread
```

To use gspread, the Google Spreadsheets API has to be enabled in the Google Cloud project created to download images from Google Drive. A tutorial by Idowu Omisola, 2021, on how to so is found in https://www.makeuseof.com/tag/read-write-google-sheets-python/. The file called visonplusplus-ad4a007f31f0.json provides the credentials to access the project.

The main.py file intializes an S3 client and a Textract client from the AWS account, as well as the path and name of image to extract the text from. It also provides the credentials for the Google Cloud project, and the name of the Google Spreadsheet to write the recognized text in. Then, a while loop reads the image taken by the ESP32-CAM. If the image is different than the image read in the last iteration of the loop (i.e. a new image was downloaded), the image is uploaded to the Amazon Cloud Service S3, and Amazon Textract is called to detect the text from the uploaded file. Then, the recognized text is written in the Google Spreadsheet.

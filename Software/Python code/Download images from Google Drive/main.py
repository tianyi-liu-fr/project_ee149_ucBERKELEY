# Google Drive API authentication
from pydrive.auth import GoogleAuth
from pydrive.drive import GoogleDrive
# Delay
import time

# Initialize Google Drive API
gauth = GoogleAuth()
drive = GoogleDrive(gauth)

# Folder ID to download images from
folder = 'input Google Drive folder ID'

while True:
	# Create a list of the files in the folder
	file_list = drive.ListFile({'q' : f"'{folder}' in parents and trashed=false"}).GetList()
	for index, file in enumerate(file_list):
		print(index+1, 'Image downloaded : ', file['title'])
		# Download every file in the folder
		file.GetContentFile(file['title'])
		# Delete file from Google Drive to save space
		file.Delete()
		# Wait for 2 seconds for energy saving
		time.sleep(2)

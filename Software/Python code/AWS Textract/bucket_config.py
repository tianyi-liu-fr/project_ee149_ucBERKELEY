import boto3

s3 = boto3.client('s3')

cors_configuration = {'CORSRules': [{'AllowedHeaders':['Authorization'], 'AllowedMethods':['GET', 'PUT'], 'AllowedOrigins':['*'], 'ExposeHeaders':
['GET', 'PUT'], 'MaxAgeSeconds': 3000}]}

s3.put_bucket_cors(Bucket = 'visionplusplus', CORSConfiguration = cors_configuration)

result = s3.get_bucket_cors(Bucket = 'visionplusplus')
print(result)

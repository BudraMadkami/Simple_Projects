import requests
url ="https://api.open-meteo.com/v1/forecast?latitude=28.56&longitude=77.26&current_weather=true"

response = requests.get(url)

data = response.json()

print("Temperature",data["current_weather"]["temperature"])
print("WindSpeed",data["current_weather"]["windspeed"])
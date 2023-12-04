# -*- coding: utf-8 -*-
"""
Created on Mon Oct 23 21:28:20 2023

@author: dorle
"""

from geopy.geocoders import Nominatim
import csv
from time import sleep

# Fonction pour obtenir le nom du pays à partir des coordonnées
def get_country_name(lat, lon):
    geolocator = Nominatim(user_agent="country_locator")
    location = geolocator.reverse(f"{lat}, {lon}")
    print (location)
    return(location)
    # if location.raw.get('address'):
    #     country = location.raw['address'].get('country')
        
    #     if country:
    #         return country
    #     else :
    #         return 'Pays non trouvé'

# # Lisez le fichier CSV contenant les coordonnées
with open('Earthquakes_fusion.csv', encoding='utf-8', mode='r') as csvfile:
    csvreader = csv.DictReader(csvfile, delimiter='|')
    #csvreader = csv.reader(csvfile, delimiter=';')
    # Créez un fichier de sortie CSV pour écrire les résultats
    with open('resultats.csv',encoding='utf-8', mode='w', newline='') as resultfile:
        fieldnames = csvreader.fieldnames + ['Pays']
        
        csvwriter = csv.DictWriter(resultfile, delimiter='|', fieldnames=fieldnames)
        csvwriter.writeheader()

        for row in csvreader:
            try: 
                latitude = float(row['latitude'])
                print (latitude)
                longitude = float(row['longitude'])
                print(longitude)
                country_name = get_country_name(latitude, longitude)
            
            # Ajoutez le nom du pays à la ligne actuelle
                row['Pays'] = country_name
            #sleep(0.05)
            #break
            
            # Écrivez la ligne mise à jour dans le fichier de sortie
                csvwriter.writerow(row)
            except :
                pass

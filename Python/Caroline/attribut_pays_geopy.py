# -*- coding: utf-8 -*-
"""
Created on Mon Oct 23 21:28:20 2023

@author: dorle
"""

from geopy.geocoders import Nominatim
import csv
from time import sleep
from concurrent.futures import ThreadPoolExecutor

# Fonction pour obtenir le nom du pays à partir des coordonnées
def get_country_name(lat, lon):
    geolocator = Nominatim(user_agent="country_locator", timeout=60)
    location = geolocator.reverse(f"{lat}, {lon}")
    return(location)
    # if location.raw.get('address'):
    #     country = location.raw['address'].get('country')
        
    #     if country:
    #         return country
    #     else :
    #         return 'Pays non trouvé'

def process_line(l):
    try: 
        latitude = float(l['latitude'])
        longitude = float(l['longitude'])
        # country_name = get_country_name(latitude, longitude)
            
        # Ajoutez le nom du pays à la ligne actuelle
        l['Pays'] = get_country_name(latitude, longitude)
        #sleep(0.05)
        #break
            
        # Écrivez la ligne mise à jour dans le fichier de sortie
        #csv.writerow(l)
    except :
        pass
    return l

# # Lisez le fichier CSV contenant les coordonnées
with open('partie_10.csv', encoding='utf-8', mode='r') as csvfile:
    csvreader = csv.DictReader(csvfile, delimiter='|')
    
    # with ThreadPoolExecutor(max_workers = 1000) as threads:
    #    t_res = threads.map(process_line, csvreader)
    #csvreader = csv.reader(csvfile, delimiter=';')
    # Créez un fichier de sortie CSV pour écrire les résultats
    with open('resultats.csv',encoding='utf-8', mode='w', newline='') as resultfile:
        fieldnames = csvreader.fieldnames + ['Pays']
        
        csvwriter = csv.DictWriter(resultfile, delimiter='|', fieldnames=fieldnames)
        csvwriter.writeheader()

        for row in csvreader:
            print(row)
            csvwriter.writerow(process_line(row))
          


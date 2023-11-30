# -*- coding: utf-8 -*-
"""
Created on Thu Nov 30 23:14:46 2023

@author: dorle
"""

import pandas as pd
from geopy.geocoders import Nominatim
import csv

def get_country_name(lat, lon):
    geolocator = Nominatim(user_agent="country_locator")
    location = geolocator.reverse(f"{lat}, {lon}")
    #print(location)
    return location
def supprimer_derniere_virgule(chaine):
    # Diviser la chaîne en fonction des virgules
    parties = chaine.split(',')
    
    # Récupérer la dernière partie résultante
    dernier_element = parties[-1]
    print(dernier_element)
    
    return dernier_element
def supprimer_avant_derniere_virgule(chaine):
    # Diviser la chaîne en fonction des virgules
    parties = chaine.split(',')
    
    # Récupérer la dernière partie résultante
    try :
        dernier_element = parties[-2]
        print (parties[-2])
        if not dernier_element.isalpha():
            return parties[-3]
            print(parties[-3])       
        else:
            #print(dernier_element)
            return dernier_element
    except:
        return chaine

df = pd.read_csv('Earthquakes_fusion.csv',sep='|', encoding='utf-8')
df['latitude'] = pd.to_numeric(df['latitude'], errors='coerce')
df['longitude'] = pd.to_numeric(df['longitude'], errors='coerce')


df2=df.dropna(subset=['latitude','longitude'])
#diff = df.compare(df2, keep_equal=True, keep_shape = True)

#print(diff)

df2['Pays'] = df2.apply(lambda row: get_country_name(float(row['latitude']), float(row['longitude'])), axis=1)

pays = df2['Pays'] 


df2['region_seulement'] = df2['Pays'].apply(lambda x: supprimer_avant_derniere_virgule(x) if isinstance(x, str) else x)
df2['pays_seulement'] = df2['Pays'].apply(lambda x: supprimer_derniere_virgule(x) if isinstance(x, str) else x)


df2.to_csv('le_dern_des_der.csv', encoding='utf-8', sep='|', index=False)


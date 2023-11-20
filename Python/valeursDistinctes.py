# -*- coding: utf-8 -*-
"""
Created on Tue Nov  7 14:02:46 2023

@author: Utilisateur
"""

import pandas as pd

nom_fichier_csv = "EarthquakesTimeSeriesAnalysis_Final.csv"
data = pd.read_csv(nom_fichier_csv, delimiter="|")

print("fichier EarthquakesTimeSeriesAnalysis_Final")

for nom_colonne in data.columns:
    nombre_valeurs_distinctes = data[nom_colonne].nunique()
    print(f"Il y a {nombre_valeurs_distinctes} valeurs distinctes pour la colonne '{nom_colonne}'.")
    
    
nom_fichier_csv = "Worldwide-Earthquake_Final.csv"
data = pd.read_csv(nom_fichier_csv, delimiter="|")

print("fichier Worldwide-Earthquake_Final")

for nom_colonne in data.columns:
    nombre_valeurs_distinctes = data[nom_colonne].nunique()
    print(f"Il y a {nombre_valeurs_distinctes} valeurs distinctes pour la colonne '{nom_colonne}'.")


nom_fichier_csv = "USGS_Final_MagPos.csv"
data = pd.read_csv(nom_fichier_csv, delimiter="|")

print("fichier USGS_Final_MagPos")

for nom_colonne in data.columns:
    nombre_valeurs_distinctes = data[nom_colonne].nunique()
    print(f"Il y a {nombre_valeurs_distinctes} valeurs distinctes pour la colonne '{nom_colonne}'.")

#-------------------------------------------------
nom_fichier_csv = "Earthquakes_fusion_magnitude.csv"
data = pd.read_csv(nom_fichier_csv, delimiter="|")

for nom_colonne in data.columns:
    nombre_valeurs_distinctes = data[nom_colonne].nunique()
    print(f"Il y a {nombre_valeurs_distinctes} valeurs distinctes pour la colonne '{nom_colonne}'.")

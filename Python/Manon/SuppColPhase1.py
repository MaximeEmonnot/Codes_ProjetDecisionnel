# -*- coding: utf-8 -*-
"""
Created on Sun Oct  8 13:58:20 2023

@author: Utilisateur
"""

import pandas as pd

# Charger fichier CSV
nom_fichier_csv = 'EarthquakesMonthlyUSGS.csv'
df = pd.read_csv(nom_fichier_csv)

# Filtre ongarde que les lignes où il y a la valeur earthquake dans la colonne type
df = df[df['type'] == 'earthquake']

# Sauvegarde dans un nouveau CSV
nouveau_nom_fichier_csv = 'EarthquakesMonthlyUSGS_col_earthquake_4%.csv'
df.to_csv(nouveau_nom_fichier_csv, index=False)

print("Les lignes avec la valeur 'earthquakes' dans la colonne 'earthquake' ont été conservées.")


nom_fichier_csv = 'EarthquakesMonthlyUSGS_col_earthquake_4%.csv'
df = pd.read_csv(nom_fichier_csv)
colonnes_a_supprimer = ['updated','tz','url','detail','felt','cdi','mmi','alert','status',
                        'sig','net','code','ids','sources','types','title']

# Supprimer les colonnes au dessus
df.drop(colonnes_a_supprimer, axis=1, inplace=True)

# Sauvegarde dans un nouveau CSV
nouveau_nom_fichier_csv = 'EarthquakesMonthlyUSGS_tt_supp_mais verifier_type_avant_de_supp.csv'
df.to_csv(nouveau_nom_fichier_csv, index=False)

nom_fichier_csv = 'EarthquakesMonthlyUSGS_tt_supp_mais verifier_type_avant_de_supp.csv'
df = pd.read_csv(nom_fichier_csv)
colonnes_a_supprimer = ['type']

# Supprimer les colonnes
df.drop(colonnes_a_supprimer, axis=1, inplace=True)

# Sauvegarde dans un nouveau CSV
nouveau_nom_fichier_csv = 'EarthquakesMonthlyUSGS_tt_supp.csv'
df.to_csv(nouveau_nom_fichier_csv, index=False)

"""-----------------------------------------------------------------------------"""

nom_fichier_csv = 'EarthquakesMonthlyUSGS_col_earthquake_4%.csv'
df = pd.read_csv(nom_fichier_csv)
colonnes_a_supprimer = ['mag','tsunami','nst','dmin','rms','gap','magType','longitude','latitude',
                        'updated','tz','url','felt','cdi','mmi','alert','status',
                        'sig','net','code','ids','sources','types','title','type']

# Supprimer les colonnes au dessus
df.drop(colonnes_a_supprimer, axis=1, inplace=True)

# Sauvegarde dans un nouveau CSV
nouveau_nom_fichier_csv = 'EarthquakesMonthlyUSGS_GeoJSON.csv'
df.to_csv(nouveau_nom_fichier_csv, index=False)
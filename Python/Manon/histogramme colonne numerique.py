# -*- coding: utf-8 -*-
"""
Created on Sat Oct 21 22:42:02 2023

@author: Utilisateur
"""

import pandas as pd
import matplotlib.pyplot as plt

#attention la borne supérieur n'est pas inclusive...

nom_fichier_csv = "EarthquakesTimeSeriesAnalysis_Final.csv"
df = pd.read_csv(nom_fichier_csv, delimiter="|")

colonnes_choisies = ["year", "depth", "magnitude"]

for colonne in colonnes_choisies:
    plt.figure()
    plt.hist(df[colonne], bins=10, edgecolor='k')
    plt.title(f'Histogramme de la colonne {colonne}')
    plt.xlabel(colonne)
    plt.ylabel('Effectif')
    plt.show()
    
bornes=[0, 10,50, 410, 700]
plt.figure()
plt.hist(df['depth'], bins=bornes, edgecolor='k')  
plt.title('Histogramme de la colonne depth')
plt.xlabel('depth')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['depth'] >= bornes[i]) & (df['depth'] < bornes[i + 1])]['depth'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#------------------------

bornes=[2000, 2005, 2010, 2015, 2020, 2025]
plt.figure()
plt.hist(df['year'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne year')
plt.xlabel('year')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['year'] >= bornes[i]) & (df['year'] < bornes[i + 1])]['year'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#-----------------------

bornes=[4.5, 5, 5.5, 6, 7, 8]
plt.figure()
plt.hist(df['magnitude'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne magnitude')
plt.xlabel('magnitude')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['magnitude'] >= bornes[i]) & (df['magnitude'] < bornes[i + 1])]['magnitude'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#--------------------------------------------------------
import pandas as pd
import matplotlib.pyplot as plt

nom_fichier_csv = "USGS_Final_suppNeg.csv"
df = pd.read_csv(nom_fichier_csv, delimiter="|")

colonnes_choisies = ["year", "nst", "dmin", "rms", "gap", "mag"]

for colonne in colonnes_choisies:
    plt.figure()
    plt.hist(df[colonne], bins=10, edgecolor='k')
    plt.title(f'Histogramme de la colonne {colonne}')
    plt.xlabel(colonne)
    plt.ylabel('Effectif')
    plt.show()

#-----------------

bornes=[1990, 1995, 2000, 2005, 2010, 2015, 2020, 2025]
plt.figure()
plt.hist(df['year'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne year')
plt.xlabel('year')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['year'] >= bornes[i]) & (df['year'] < bornes[i + 1])]['year'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#-----------------

bornes=[0, 100, 400, 900]
plt.figure()
plt.hist(df['nst'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne nst')
plt.xlabel('nst')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['nst'] >= bornes[i]) & (df['nst'] < bornes[i + 1])]['nst'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#----------------

bornes=[0,0.5,5, 15, 30, 150]
plt.figure()
plt.hist(df['dmin'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne dmin')
plt.xlabel('dmin')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['dmin'] >= bornes[i]) & (df['dmin'] < bornes[i + 1])]['dmin'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#---------------

bornes=[0,0.5,10, 100]
plt.figure()
plt.hist(df['rms'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne rms')
plt.xlabel('rms')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['rms'] >= bornes[i]) & (df['rms'] < bornes[i + 1])]['rms'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#---------------

bornes=[0, 70, 100,150, 200, 270, 370]
plt.figure()
plt.hist(df['gap'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne gap')
plt.xlabel('gap')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['gap'] >= bornes[i]) & (df['gap'] < bornes[i + 1])]['gap'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#---------------

bornes=[0, 1, 2,3, 4, 6, 8]
plt.figure()
plt.hist(df['mag'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne mag')
plt.xlabel('mag')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['mag'] >= bornes[i]) & (df['mag'] < bornes[i + 1])]['mag'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#-----------------------------------------------------

nom_fichier_csv = "Worldwide-Earthquake_Final.csv"
df = pd.read_csv(nom_fichier_csv, delimiter="|")

colonnes_choisies = ["YEAR", "FOCAL_DEPTH", "MAGNITUDE", "INTENSITY", "DEATHS", "MISSING", "INJURIES", "DAMAGE_MILLIONS_DOLLARS", "HOUSES_DESTROYED", "HOUSES_DAMAGED"]

for colonne in colonnes_choisies:
    plt.figure()
    plt.hist(df[colonne], bins=10, edgecolor='k')
    plt.title(f'Histogramme de la colonne {colonne}')
    plt.xlabel(colonne)
    plt.ylabel('Effectif')
    plt.show()

#------------------

bornes=[-2150, 0, 1000, 1800, 2000, 2025]
plt.figure()
plt.hist(df['YEAR'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne YEAR')
plt.xlabel('YEAR')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['YEAR'] >= bornes[i]) & (df['YEAR'] < bornes[i + 1])]['YEAR'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#-----------------

bornes=[0, 10, 50, 410, 700]
plt.figure()
plt.hist(df['FOCAL_DEPTH'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne FOCAL_DEPTH')
plt.xlabel('FOCAL_DEPTH')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['FOCAL_DEPTH'] >= bornes[i]) & (df['FOCAL_DEPTH'] < bornes[i + 1])]['FOCAL_DEPTH'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#-----------------

bornes=[0, 5, 6, 7, 8, 9, 10]
plt.figure()
plt.hist(df['MAGNITUDE'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne MAGNITUDE')
plt.xlabel('MAGNITUDE')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['MAGNITUDE'] >= bornes[i]) & (df['MAGNITUDE'] < bornes[i + 1])]['MAGNITUDE'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#-----------------

bornes=[0, 5, 6, 7, 8, 9, 10, 11, 12]
plt.figure()
plt.hist(df['INTENSITY'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne INTENSITY')
plt.xlabel('INTENSITY')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['INTENSITY'] >= bornes[i]) & (df['INTENSITY'] < bornes[i + 1])]['INTENSITY'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#------------------

bornes=[0,1000,10000, 100000, 800000]
plt.figure()
plt.hist(df['DEATHS'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne DEATHS')
plt.xlabel('DEATHS')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['DEATHS'] >= bornes[i]) & (df['DEATHS'] < bornes[i + 1])]['DEATHS'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#------------------

bornes=[0,2000,40000, 45000]
plt.figure()
plt.hist(df['MISSING'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne MISSING')
plt.xlabel('MISSING')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['MISSING'] >= bornes[i]) & (df['MISSING'] < bornes[i + 1])]['MISSING'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#------------------

bornes=[0,100, 500,2000,10000, 100000,800000]
plt.figure()
plt.hist(df['INJURIES'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne INJURIES')
plt.xlabel('INJURIES')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['INJURIES'] >= bornes[i]) & (df['INJURIES'] < bornes[i + 1])]['INJURIES'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#-------------------

bornes=[0,100,1000,10000,40000,100000]
plt.figure()
plt.hist(df['DAMAGE_MILLIONS_DOLLARS'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne DAMAGE_MILLIONS_DOLLARS')
plt.xlabel('DAMAGE_MILLIONS_DOLLARS')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['DAMAGE_MILLIONS_DOLLARS'] >= bornes[i]) & (df['DAMAGE_MILLIONS_DOLLARS'] < bornes[i + 1])]['DAMAGE_MILLIONS_DOLLARS'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#--------------------

bornes=[0,500,5000, 50000,500000,5700000]
plt.figure()
plt.hist(df['HOUSES_DAMAGED'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne HOUSES_DAMAGED')
plt.xlabel('HOUSES_DAMAGED')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['HOUSES_DAMAGED'] >= bornes[i]) & (df['HOUSES_DAMAGED'] < bornes[i + 1])]['HOUSES_DAMAGED'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#------------------------------------------

import pandas as pd
import matplotlib.pyplot as plt

nom_fichier_csv = "Temperature.csv"
df = pd.read_csv(nom_fichier_csv, delimiter="|")

colonnes_choisies = ["Year", "AvgTemperature"]

for colonne in colonnes_choisies:
    plt.figure()
    plt.hist(df[colonne], bins=10, edgecolor='k')
    plt.title(f'Histogramme de la colonne {colonne}')
    plt.xlabel(colonne)
    plt.ylabel('Effectif')
    plt.show()

#-----------------

bornes=[1995, 2000, 2005, 2010, 2015, 2020, 2025]
plt.figure()
plt.hist(df['Year'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne Year')
plt.xlabel('Year')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['Year'] >= bornes[i]) & (df['Year'] < bornes[i + 1])]['Year'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#----------------

bornes=[-50, 0, 10, 20, 30, 50]
plt.figure()
plt.hist(df['AvgTemperature'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne AvgTemperature')
plt.xlabel('AvgTemperature')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['AvgTemperature'] >= bornes[i]) & (df['AvgTemperature'] < bornes[i + 1])]['AvgTemperature'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#----------------------------------

import pandas as pd
import matplotlib.pyplot as plt

nom_fichier_csv = "CO2_Emissions.csv"
df = pd.read_csv(nom_fichier_csv, delimiter="|")

colonnes_choisies = ["year", "value"]

for colonne in colonnes_choisies:
    plt.figure()
    plt.hist(df[colonne], bins=10, edgecolor='k')
    plt.title(f'Histogramme de la colonne {colonne}')
    plt.xlabel(colonne)
    plt.ylabel('Effectif')
    plt.show()

#-----------------

bornes=[1960, 1965, 1970, 1975, 1980,1985, 1990, 1995, 2000, 2005, 2010, 2015, 2020]
plt.figure()
plt.hist(df['year'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne year')
plt.xlabel('year')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['year'] >= bornes[i]) & (df['year'] < bornes[i + 1])]['year'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#--------------

bornes=[0,500000, 1000000, 2000000, 3000000, 4000000, 5000000, 10000000, 20000000, 35000000]
plt.figure()
plt.hist(df['value'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne value')
plt.xlabel('value')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['value'] >= bornes[i]) & (df['value'] < bornes[i + 1])]['value'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#------------------------------------
nom_fichier_csv = "PopulationDensity.csv"
df = pd.read_csv(nom_fichier_csv, delimiter=";")

colonnes_choisies = ["Year","PopulationDensity"]

for colonne in colonnes_choisies:
    plt.figure()
    plt.hist(df[colonne], bins=10, edgecolor='k')
    plt.title(f'Histogramme de la colonne {colonne}')
    plt.xlabel(colonne)
    plt.ylabel('Effectif')
    plt.show()
    
bornes=[1960, 1965, 1970, 1975, 1980, 1985, 1990, 1995, 2000, 2005, 2010, 2015, 2020, 2025]
plt.figure()
plt.hist(df['Year'], bins=bornes, edgecolor='k')  
plt.title('Histogramme de la colonne Year')
plt.xlabel('Year')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['Year'] >= bornes[i]) & (df['Year'] < bornes[i + 1])]['Year'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#------------------------

bornes=[0, 100, 200, 300, 500, 1000, 5000, 20000]
plt.figure()
plt.hist(df['PopulationDensity'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne PopulationDensity')
plt.xlabel('PopulationDensity')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['PopulationDensity'] >= bornes[i]) & (df['PopulationDensity'] < bornes[i + 1])]['PopulationDensity'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#------------------------------------
nom_fichier_csv = "Poverty.csv"
df = pd.read_csv(nom_fichier_csv, delimiter=";")

colonnes_choisies = ["Year","Poverty"]

for colonne in colonnes_choisies:
    plt.figure()
    plt.hist(df[colonne], bins=10, edgecolor='k')
    plt.title(f'Histogramme de la colonne {colonne}')
    plt.xlabel(colonne)
    plt.ylabel('Effectif')
    plt.show()
    
bornes=[1980, 1985, 1990, 1995, 2000, 2005, 2010, 2015, 2020, 2025]
plt.figure()
plt.hist(df['Year'], bins=bornes, edgecolor='k')  
plt.title('Histogramme de la colonne Year')
plt.xlabel('Year')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['Year'] >= bornes[i]) & (df['Year'] < bornes[i + 1])]['Year'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#------------------------

bornes=[0,2, 5, 10, 20, 35,60]
plt.figure()
plt.hist(df['Poverty'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne Poverty')
plt.xlabel('Poverty')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['Poverty'] >= bornes[i]) & (df['Poverty'] < bornes[i + 1])]['Poverty'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#------------------------------------
nom_fichier_csv = "sealevel.csv"
df = pd.read_csv(nom_fichier_csv, delimiter=";")

colonnes_choisies = ["Year","GMSL_noGIA"]

for colonne in colonnes_choisies:
    plt.figure()
    plt.hist(df[colonne], bins=10, edgecolor='k')
    plt.title(f'Histogramme de la colonne {colonne}')
    plt.xlabel(colonne)
    plt.ylabel('Effectif')
    plt.show()
    
bornes=[1990, 1995, 2000, 2005, 2010, 2015, 2020, 2025]
plt.figure()
plt.hist(df['Year'], bins=bornes, edgecolor='k')  
plt.title('Histogramme de la colonne Year')
plt.xlabel('Year')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['Year'] >= bornes[i]) & (df['Year'] < bornes[i + 1])]['Year'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#------------------------

bornes=[-45, -30,0, 25, 60]
plt.figure()
plt.hist(df['GMSL_noGIA'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne GMSL_noGIA')
plt.xlabel('GMSL_noGIA')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['GMSL_noGIA'] >= bornes[i]) & (df['GMSL_noGIA'] < bornes[i + 1])]['GMSL_noGIA'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()

#--------------------------------------------------------------

nom_fichier_csv = "Earthquakes_fusion_magnitude.csv"
df = pd.read_csv(nom_fichier_csv, delimiter="|")

colonnes_choisies = ["magnitude"]

for colonne in colonnes_choisies:
    plt.figure()
    plt.hist(df[colonne], bins=10, edgecolor='k')
    plt.title(f'Histogramme de la colonne {colonne}')
    plt.xlabel(colonne)
    plt.ylabel('Effectif')
    plt.show()
    
bornes=[0,1,2,3,4,5,6,7,8,9,10]
plt.figure()
plt.hist(df['magnitude'], bins=bornes, edgecolor='k')
plt.title('Histogramme de la colonne magnitude')
plt.xlabel('magnitude')
plt.ylabel('Effectif')
plt.xticks(bornes)

for i in range(len(bornes) - 1):
    intervalle = f'{bornes[i]} - {bornes[i + 1]}'
    valeurs_bin = df[(df['magnitude'] >= bornes[i]) & (df['magnitude'] < bornes[i + 1])]['magnitude'].unique()
    nb_valeurs_distinctes = len(valeurs_bin)
    print(f'Dans l\'intervalle {intervalle}, il y a {nb_valeurs_distinctes} valeurs distinctes.')

plt.show()
# -*- coding: utf-8 -*-
"""
Created on Sun Dec  3 14:32:19 2023

@author: Utilisateur
"""

import pandas as pd
import os

nom_fichier_csv = 'Earthquakes_fusion.csv'

df = pd.read_csv(nom_fichier_csv, delimiter="|")
nbr_lignes = df.shape[0]
print(f"Fichier '{nom_fichier_csv}' a {nbr_lignes} lignes.")


nbr_lignes_par_fichier = 232868

dossier_sortie = 'fichiers_decoupes'

if not os.path.exists(dossier_sortie):
    os.makedirs(dossier_sortie)

df = pd.read_csv(nom_fichier_csv, chunksize=nbr_lignes_par_fichier)

for i, chunk in enumerate(df):
    nom_fichier_sortie = os.path.join(dossier_sortie, f'partie_{i + 1}.csv')
    chunk.to_csv(nom_fichier_sortie, index=False)

print(f"Fichier '{nom_fichier_csv}' a été découpé en diiférents fichiers")

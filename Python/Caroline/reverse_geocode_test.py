import geopandas as gpd
import pandas as pd
import csv

world = gpd.read_file(gpd.datasets.get_path('naturalearth_lowres'))
cities = gpd.read_file(gpd.datasets.get_path('naturalearth_cities'))
df = pd.read_csv('Earthquakes_fusion.csv', encoding='utf-8', sep='|')

gdf = gpd.GeoDataFrame(df, geometry=gpd.points_from_xy(df.latitude, df.longitude))

result = gpd.sjoin(gdf, world, how='left')

result.to_csv('results.csv', encoding='utf-8', sep='|', index=False)

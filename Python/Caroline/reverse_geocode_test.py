import geopandas as gpd
import pandas as pd
import csv
import math

def international_water(data):
    try: 
        if math.isnan(data):
            data = 'International Waters'
        return data
    except:
        return data

world = gpd.read_file(gpd.datasets.get_path('naturalearth_lowres'))
cities = gpd.read_file(gpd.datasets.get_path('naturalearth_cities'))
df = pd.read_csv('Earthquakes_fusion.csv', encoding='utf-8', sep='|')

gdf = gpd.GeoDataFrame(df, geometry=gpd.points_from_xy(df.longitude, df.latitude))

result = gpd.sjoin(gdf, world, how='left')


result['continent'] = result.apply(lambda row: international_water(row['continent']), axis=1)
result['name'] = result.apply(lambda row: international_water(row['name']), axis=1)

print(result)

result.to_csv('results.csv', encoding='utf-8', sep='|', index=False)

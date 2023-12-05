import geopandas as gpd
from matplotlib import pyplot as plt
import pandas as pd 

world = gpd.read_file(gpd.datasets.get_path('naturalearth_lowres'))



df = pd.read_csv('partie_1.csv',encoding='utf-8',sep='|')
gdf = gpd.GeoDataFrame(df, geometry=gpd.points_from_xy(df.latitude, df.longitude))
    
result = gpd.sjoin(gdf, world, how='left')

print(result)

result.to_csv('results.csv',encoding='utf-8',sep='|')

#base = world.plot(color='white', edgecolor='black')
#gdf.plot(ax=base, marker='o', color='red', markersize=5)

#plt.show()
import pandas as pd
from pandas_profiling import ProfileReport
import os


df = pd.read_csv(os.getcwd() + '\\Code\\data\\property.csv')
print(df)

profile = ProfileReport(df, title="Pandas Profiling Report", vars={"num": {"low_categorical_threshold": 0}})
profile.to_file(output_file='report.html')

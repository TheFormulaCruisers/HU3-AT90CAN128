# -*- coding: utf-8 -*-
"""
Created on Thu Apr 15 11:19:32 2021

@author: moemi
"""


import can_decoder
import mdf_iter

mdf_path = "00000001.MF4"
dbc_path = "test.dbc"

db = can_decoder.load_dbc(dbc_path)
df_decoder = can_decoder.DataFrameDecoder(db)

with open(mdf_path, "rb") as handle:
    mdf_file = mdf_iter.MdfFile(handle)
    df_raw = mdf_file.get_data_frame()

df_phys = df_decoder.decode_frame(df_raw)
print(df_phys)

bus = Bus()
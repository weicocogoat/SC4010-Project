#!/usr/bin/env python
# coding: utf-8

# In[57]:


import pandas as pd
import matplotlib.pyplot as plt

from math import factorial
import numpy as np
import scipy.io
import scipy.signal
import sys


# In[100]:


df = pd.read_csv('F0000CH2.CSV')
df_timing = pd.read_csv('F0000CH1.CSV')


# In[101]:


df_timing


# In[47]:


df_clean = df[['Time', 'Voltage']]
df_clean


# In[53]:


df_clean.plot(x= 'Time', y = 'Voltage')


# In[76]:


df_filtered = scipy.signal.savgol_filter(df_clean['Voltage'], 35, 10)


# In[75]:


df_filtered


# In[77]:


plt.plot(df_filtered)


# In[84]:


df_2 = df_clean
df_2


# In[85]:


tsint = df_2.interpolate(method='cubic')


# In[87]:


tsint


# In[97]:


plt.plot(tsint['Voltage'])
#plt.plot(df_filtered)


# In[104]:


plt.figure(figsize=(30,10))
plt.plot(df_filtered)


# In[105]:


plt.figure(figsize=(30,10))
plt.plot(df_timing["Voltage"])


# In[ ]:





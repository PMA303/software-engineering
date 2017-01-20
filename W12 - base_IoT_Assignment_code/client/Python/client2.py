#Base Python client for MEng in IoT Assignment
#consumes data from IoT Gateway

import urllib2
import matplotlib.pyplot as plt
#import numpy as np

import xml.etree.ElementTree as ET

response = urllib2.urlopen('http://localhost:8080/')
resp = response.read("sensorlog.txt" , "r")

tree = ET.parse(resp)
for elem in tree.findall('time'):
		print ET.tostring(elem)












input("\n\nPress the enter key to exit.")


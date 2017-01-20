#Base Python client for MEng in IoT Assignment
#consumes data from IoT Gateway

import urllib2
import xml.etree.ElementTree as ET

response = urllib2.urlopen('http://localhost:8080/')
resp = response.read()

tree = ET.parse(resp)
root = tree.getroot()

#myArray1=[]
#myArray2=[]

#for x in xml.getiterator('time'):
 #   myArray1.append(x.text)

#for y in ml.getiterator('temperature'):
 #   myArray2.append(y.text)
	
#print(myArray1)
#print(myArray2)  




#for x in root.findall('time'):
#    myArray1.append(x.text)

#for y in root.findall('temperature'):
#    myArray2.append(y.text)

print resp
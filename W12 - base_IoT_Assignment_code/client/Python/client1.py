
import xml.etree.ElementTree as ET
import matplotlib.pyplot as plt

filename='sensorlogworks.txt'
tree = ET.parse(filename)
root = tree.getroot()

x=[]
y=[]

for a in root.findall('time'):
    x.append(a.text)

	
for b in root.findall('temperature'):
    y.append(b.text)
	
	
print(x)
print(y)


plt.plot(y, 'r--')
#plt.setp(lines, color='g', linewidth=2.0)
plt.axis([0, 9, 0, 40])
plt.xlabel('Time')
plt.ylabel('Temperature')
plt.show()
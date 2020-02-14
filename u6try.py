"""
Name: u6try.py
Intended Device: U6
Desc: first implementation try
"""

from datetime import datetime
import u6  # Import the u6 module

resolutionIndex = 1
gainIndex = 0
settlingFactor = 0
differential = False
duration = 10   # en secondes

# Open first found U6
d = u6.U6()

# Basic config (1623)
d.loadConfig('config/FT9498_fichier_calibration.cal')

#Allume la led ?
d.getFeedback(u6.LED(True))

# Read
feedbackArguments = []
#feedbackArguments.append(u6.DAC0_8(Value=125))
feedbackArguments.append(u6.PortStateRead())

for i in range(0, 10, 2):
    feedbackArguments.append(u6.AIN(i))

start = datetime.now()
delta = 0
while delta < duration:
    results = d.getFeedback(feedbackArguments)
    delta = datetime.now() - start

end = datetime.now()
delta = end - start

print("Execution time :" + delta)
print(results)

# When all done
d.close()

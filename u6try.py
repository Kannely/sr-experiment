"""
Name: u6try.py
Intended Device: U6
Desc: first implementation try
"""

from datetime import datetime, timedelta
import u6  # Import the u6 module

resolutionIndex = 1
gainIndex = 0
settlingFactor = 0
differential = False
duration = 5   # en secondes

# Open first found U6
d = u6.U6()

# Basic config (1623)
d.getCalibrationData()
print(d.calInfo)

#d.loadConfig('config/FT9498_fichier_calibration.cal')

# Read
feedbackArguments = []
feedbackArguments.append(u6.DAC0_8(Value=125))
feedbackArguments.append(u6.PortStateRead())

for i in range(0, 3):
    feedbackArguments.append(u6.AIN(i))

print("wait...")

endTime = datetime.now() + timedelta(seconds=duration)
results = []
while datetime.now() <= endTime:
    results.append(d.getFeedback(feedbackArguments))


print("Execution time :" + str(duration) + " secondes")
print(results[0])

# When all done
d.close()

"""
Name: u6try.py
Intended Device: U6
Desc: first implementation try
"""

from datetime import datetime
import u6  # Import the u6 module


# Open first found U6
d = u6.U6()


# ligne 2206 : class Timer(FeedbackCommand)
# 1623 : def loadConfig(self, configParserObj): (u6)

#Allume la led ?
d.getFeedback(u6.LED(True))

# When all done
d.close()

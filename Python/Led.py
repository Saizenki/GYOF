#import RPi.GPIO as GPIO
from AllPin import Pin

name="Led"

def __init__():
	pin_ob=Pin()
	pin=pin_ob.number(name)
	print("Success")
	print(pin)
	
	GPIO.setwarnings(False)
	GPIO.setmode(GPIO.BOARD)
	GPIO.setup(Relay1, GPIO.OUT)

def LedOn(self):
	GPIO.output(pin, GPIO.HIGH)
	print("Led is On")

def LedOff(self):
	GPIO.output(pin, GPIO.LOW)
	print("Led is Off")

__init__()
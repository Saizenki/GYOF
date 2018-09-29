#!/usr/bin/python
# Author: Saizenki
# Date: 14.08.2018
import RPi.GPIO as GPIO
from AllPin import Pin 

pin_ob=Pin()
pin=pin_ob.number("CirFan")
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(pin, GPIO.OUT)


def FanOn():
	GPIO.output(pin, GPIO.LOW)
	print("Circulation Fan On")
	
def FanOff():
	GPIO.output(pin, GPIO.HIGH)
	print("Circulation Fan Off")
	GPIO.cleanup()
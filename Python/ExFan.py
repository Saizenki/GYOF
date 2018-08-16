#!/usr/bin/python
# Author: Saizenki
# Date: 14.08.2018
import RPi.GPIO as GPIO
from AllPin import Pin 

def __init__(self):
	pin_ob=Pin()
	num=pin_ob.number("ExFan")
	GPIO.setwarnings(False)
	GPIO.setmode(GPIO.BOARD)
	GPIO.setup(num, GPIO.OUT)


def FanOn():
	GPIO.output(pin, GPIO.HIGH)
	print("Exhaust Fan On")
	
def FanOff():
	GPIO.output(pin, GPIO.LOW)
	print("Exhaust Fan Off")
#!/usr/bin/python
import sys
import usb.core
import usb.util
import time
import inputparsing

interface = 0

def initConn():
	try:
		dev = usb.core.find(idVendor=0x81f, idProduct=0xe401)
		if dev is None:
			raise ValueError('Our device is not connected')
		#if dev.is_kernel_driver_active(interface) is True:
		  # tell the kernel to detach
		  #dev.detach_kernel_driver(interface)
		  # claim the device
		usb.util.claim_interface(dev, interface)
		return dev
	except ValueError:
		print("Serious Error in Initialisation")
		return None
	
		
def endConn(dev):
	usb.util.release_interface(dev, interface)
	
def controller():
	try:
		ControlMount = initConn()
		if (ControlMount is None):
			return "004000000000"
		#A 0, B 1, X 2, Y 3, Up 4, Down 5, Left 6, Right 7, L 8, R 9, Start 10, Select 11
		cont = 0
		endpoint = ControlMount[0][(0,0)][0]
		
		try:
			data = ControlMount.read(endpoint.bEndpointAddress,endpoint.wMaxPacketSize)
			isPressed = inputparsing.parser(data)
		except usb.core.USBError as e:
			data = None
			endConn(ControlMount)
			return "000040000000"
		endConn(ControlMount)
	except ValueError:
		print("Error in Python")
		return "000000400000"
	return (isPressed)
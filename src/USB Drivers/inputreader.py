#!/usr/bin/python
import sys
import usb.core
import usb.util
import time
import inputparsing

try:
	dev = usb.core.find(idVendor=0x81f, idProduct=0xe401)
	if dev is None:
		raise ValueError('Our device is not connected')
	interface = 0
	endpoint = dev[0][(0,0)][0]
	# if the OS kernel already claimed the device, which is most likely true
	# thanks to http://stackoverflow.com/questions/8218683/pyusb-cannot-set-configuration
	if dev.is_kernel_driver_active(interface) is True:
	  # tell the kernel to detach
	  dev.detach_kernel_driver(interface)
	  # claim the device
	  usb.util.claim_interface(dev, interface)
	isPressed = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0] 
	#A 0, B 1, X 2, Y 3, Up 4, Down 5, Left 6, Right 7, L 8, R 9, Start 10, Select 11
	cont = 0
	while cont == 0:
		for i in range(0, len(isPressed)):
			isPressed[i] = 0
		try:
			data = dev.read(endpoint.bEndpointAddress,endpoint.wMaxPacketSize)
			isPressed = parser(data)
			print(isPressed)
		except usb.core.USBError as e:
			data = None
			if e.args == ('Operation timed out',):
				continue

		#time.sleep(3)
	usb.util.release_interface(dev, interface)
	
except ValueError:
	print("error, errrorrr")
	

# A, B, X, Y: Bit 5
# L, R, Start, Select: Bit 6
# Up, Down: Bit 1
# Left, Right: Bit 0

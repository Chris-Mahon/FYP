#!/usr/bin/python
#Original Design for Controller Drivers
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
		except usb.core.USBError as e:
			data = None
			if e.args == ('Operation timed out',):
				continue
		
		if data[5] == 31:
			isPressed[2] = 1
		elif data[5] == 47:
			isPressed[0] = 1
		elif data[5] == 79:
			isPressed[1] = 1
		elif data[5] == 143:
			isPressed[3] = 1
		elif data[5] == 63:
			isPressed[0] = 1
			isPressed[2] = 1
		elif data[5] == 95:
			isPressed[1] = 1
			isPressed[2] = 1
		elif data[5] == 111:
			isPressed[0] = 1
			isPressed[1] = 1
		elif data[5] == 159:
			isPressed[3] = 1
			isPressed[2] = 1
		elif data[5] == 175:
			isPressed[0] = 1
			isPressed[3] = 1
		elif data[5] == 207:
			isPressed[1] = 1
			isPressed[3] = 1
		elif data[5] == 127:
			isPressed[0] = 1
			isPressed[1] = 1
			isPressed[2] = 1
		elif data[5] == 223:
			isPressed[1] = 1
			isPressed[2] = 1
			isPressed[3] = 1
		elif data[5] == 239:
			isPressed[0] = 1
			isPressed[1] = 1
			isPressed[3] = 1
		elif data[5] == 291:
			isPressed[0] = 1
			isPressed[2] = 1
			isPressed[3] = 1
		elif data[5] == 255:
			isPressed[0] = 1
			isPressed[1] = 1
			isPressed[2] = 1
			isPressed[3] = 1
		
		if data[1] == 0:
			isPressed[4] = 1
		elif data[1] == 255:
			isPressed [5] = 1
		
		if data[0] == 0:
			isPressed[6] = 1
		elif data[0] == 255:
			isPressed[7] = 1
		
		if data[6] == 1:
			isPressed[8] = 1
		elif data[6] == 2:
			isPressed[9] = 1
		elif data[6] == 32:
			isPressed[10] = 1
		elif data[6] == 16:
			isPressed[11] = 1
		elif data[6] == 3: #LR
			isPressed[8] = 1
			isPressed[9] = 1
		elif data[6] == 17:
			isPressed[8] = 1
			isPressed[11] = 1
		elif data[6] == 18:
			isPressed[9] = 1
			isPressed[11] = 1
		elif data[6] == 33:
			isPressed[8] = 1
			isPressed[10] = 1
		elif data[6] == 34:
			isPressed[9] = 1
			isPressed[10] = 1
		elif data[6] == 48: #Start Select
			isPressed[10] = 1
			isPressed[11] = 1
		elif data[6] == 19: #L R Select
			isPressed[8] = 1
			isPressed[9] = 1
			isPressed[11] = 1
		elif data[6] == 35: #L R Start
			isPressed[8] = 1
			isPressed[9] = 1
			isPressed[10] = 1
		elif data[6] == 49: #L Start Select
			isPressed[8] = 1
			isPressed[10] = 1
			isPressed[11] = 1
		elif data[6] == 50: #R Start Select
			isPressed[9] = 1
			isPressed[10] = 1
			isPressed[11] = 1
		elif data[6] == 51: #L R Start Select
			isPressed[8] = 1
			isPressed[9] = 1
			isPressed[10] = 1
			isPressed[11] = 1
		
		print(isPressed)
		time.sleep(0.5)
	usb.util.release_interface(dev, interface)
	
except ValueError:
	print("error, errrorrr")
	

# A, B, X, Y: Bit 5
# L, R, Start, Select: Bit 6
# Up, Down: Bit 1
# Left, Right: Bit 0

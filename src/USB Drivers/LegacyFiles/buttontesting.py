#!/usr/bin/python
import sys
import time
import usb.core
import usb.util

try:
	dev = usb.core.find(idVendor=0x81f, idProduct=0xe401)
	if dev is None:
		raise ValueError('Our device is not connected')
	interface = 0
	endpoint = dev[0][(0,0)][0]
	# if the OS kernel already claimed the device, which is most likely true
	# thanks to http://stackoverflow.com/questions/8218683/pyusb-cannot-set-configuration
	#if dev.is_kernel_driver_active(interface) is True:
	  # tell the kernel to detach
	  #dev.detach_kernel_driver(interface)
	  # claim the device
	usb.util.claim_interface(dev, interface)
	
	collected = 0
	attempts = 50
	while collected < attempts :
		try:
			data = dev.read(endpoint.bEndpointAddress,endpoint.wMaxPacketSize)
			collected += 1
			print(data)
			
		except usb.core.USBError as e:
			data = None
			if e.args == ('Operation timed out',):
				continue
		# release the device
		time.sleep(2)
	usb.util.release_interface(dev, interface)
	
except ValueError:
	print("error, errrorrr")

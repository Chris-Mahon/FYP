import sys
import usb.core
dev = usb.core.find(find_all=True)
for cfg in dev:
  sys.stdout.write('Hexadecimal VendorID=' + hex(cfg.idVendor) 
	+ ' & ProductID=' + hex(cfg.idProduct) + '\n\n')
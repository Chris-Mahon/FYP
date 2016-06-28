def parser(data):

	isPressed = ["0","0","0","0","0","0","0", "0", "0", "0", "0","0"] 
	#for i in range(0, len(isPressed)):
	#		isPressed[i] = '0'
	if data[5] == 31:
		isPressed[2] = '1'
	elif data[5] == 47:
		isPressed[0] = '1'
	elif data[5] == 79:
		isPressed[1] = '1'
	elif data[5] == 143:
		isPressed[3] = '1'
	elif data[5] == 63:
		isPressed[0] = '1'
		isPressed[2] = '1'
	elif data[5] == 95:
		isPressed[1] = '1'
		isPressed[2] = '1'
	elif data[5] == 111:
		isPressed[0] = '1'
		isPressed[1] = '1'
	elif data[5] == 159:
		isPressed[3] = '1'
		isPressed[2] = '1'
	elif data[5] == 175:
		isPressed[0] = '1'
		isPressed[3] = '1'
	elif data[5] == 207:
		isPressed[1] = '1'
		isPressed[3] = '1'
	elif data[5] == 127:
		isPressed[0] = '1'
		isPressed[1] = '1'
		isPressed[2] = '1'
	elif data[5] == 223:
		isPressed[1] = '1'
		isPressed[2] = '1'
		isPressed[3] = '1'
	elif data[5] == 239:
		isPressed[0] = '1'
		isPressed[1] = '1'
		isPressed[3] = '1'
	elif data[5] == 291:
		isPressed[0] = '1'
		isPressed[2] = '1'
		isPressed[3] = '1'
	elif data[5] == 255:
		isPressed[0] = '1'
		isPressed[1] = '1'
		isPressed[2] = '1'
		isPressed[3] = '1'
	
	if data[1] == 0:
		isPressed[4] = '1'
	elif data[1] == 255:
		isPressed [5] = '1'
	
	if data[0] == 0:
		isPressed[6] = '1'
	elif data[0] == 255:
		isPressed[7] = '1'
	
	if data[6] == 1:
		isPressed[8] = '1'
	elif data[6] == 2:
		isPressed[9] = '1'
	elif data[6] == 32:
		isPressed[10] = '1'
	elif data[6] == 16:
		isPressed[11] = '1'
	elif data[6] == 3: #LR
		isPressed[8] = '1'
		isPressed[9] = '1'
	elif data[6] == 17:
		isPressed[8] = '1'
		isPressed[11] = '1'
	elif data[6] == 18:
		isPressed[9] = '1'
		isPressed[11] = '1'
	elif data[6] == 33:
		isPressed[8] = '1'
		isPressed[10] = '1'
	elif data[6] == 34:
		isPressed[9] = '1'
		isPressed[10] = '1'
	elif data[6] == 48: #Start Select
		isPressed[10] = '1'
		isPressed[11] = '1'
	elif data[6] == 19: #L R Select
		isPressed[8] = '1'
		isPressed[9] = '1'
		isPressed[11] = '1'
	elif data[6] == 35: #L R Start
		isPressed[8] = '1'
		isPressed[9] = '1'
		isPressed[10] = '1'
	elif data[6] == 49: #L Start Select
		isPressed[8] = '1'
		isPressed[10] = '1'
		isPressed[11] = '1'
	elif data[6] == 50: #R Start Select
		isPressed[9] = '1'
		isPressed[10] = '1'
		isPressed[11] = '1'
	elif data[6] == 51: #L R Start Select
		isPressed[8] = '1'
		isPressed[9] = '1'
		isPressed[10] = '1'
		isPressed[11] = '1'
	isPressed = "".join(isPressed)
	return isPressed
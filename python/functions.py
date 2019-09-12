import os
import json
import array
import string
from time import sleep as s
from multiprocessing import Pipe, Process, Array

mainL = []

def main_input(loop):

	mainStorage = list()
	x = 0
	while(x != loop):
		IE = "What is the ID of balll " + str(x + 1) + "? "
		DE = "What is the Diameter for ball " + str(x + 1) + "? "
		CE = "What is the color of ball " + str(x + 1) + "? "
		TE = "What is the texture of the ball " + str(x + 1) + "? (smooth 1 or rough 2)"
		diameter = int(input(DE))
		color = str(input(CE))
		texture = int(input(TE))
	
		if (texture != 1 or texture != 2):
			str(input("please enter a 1 for smooth and a 2 for rough: "))
		ID = int(input(IE))

		mainStorage.append(ID)
		mainStorage.append(diameter)
		mainStorage.append(color)
		mainStorage.append(texture)
		prettyTextOutput(ID, diameter, color, texture)
		prettyJSON(loop, ID, diameter, color, texture)
		x += 1

	return mainStorage

def prettyTextOutput(ID, diameter, color, texture):
	fileOut = open("prettyOut.txt", "a")
	part1 = str(ID) + str(":ID\n")
	part2 = str(diameter) + str(":diameter\n")
	part3 = str(color) + str(":color\n")
	part4 = str(texture) + str(":texture\n")
	master = part1 + part2 + part3 + part4
	fileOut.write(str(master))
	fileOut.close()

def prettyJSON(choice, ID, diameter, color, texture):
	#json uses object like vars
	x = 0
	counter = totalCounter(choice)
	obj = open('pretty.json', 'wb')
	if(texture == "1"):
		texture = "smooth"
	else:
		texture = "rough"

	while(x != counter):
		data = {}
		data['conter'] = counter
		data['ID'] = ID
		data['diameter'] = diameter
		data['color'] = color
		data['texture'] = texture
		json_data = json.dumps(data)
		json.dump(data, obj)

def totalCounter(choice):
	counterFile_R = open('counter.txt', 'r+')

	#enters it as an int
	line = counterFile_R.readline()
	add = int(line.strip('\n'))
	counterFile_R.close()
	print(add)

	counterFile_W = open('counter.txt', 'w')
	outToFile = choice + add
	counterFile_W.write(str(outToFile))
	counterFile_W.close()
	
	return outToFile

def pushTest(LS):
	fileOut = open("out.txt", "a")
	size = len(LS)
	x = 0
	while(x != size):
		if (size % 4 == 0):
			temp = str(LS[x]) + str("\n")
			fileOut.write(temp)
		temp = LS[x]
		fileOut.write(str(temp))
		#this finds out if a numbre is divisable by 4
		x += 1

	fileOut.close()
	mainL.extend(LS)
	print(mainL)

def countLines():
	lines = len(open("prettyOut.txt").readlines)
	return lines

def pullerText():
	inputFile = open("prettyOut.txt", "r+")
	IDlist = []
	Dlist = []
	Clist = []
	Tlist = []
	x = 0
	i = 0
	prePRE = inputFile.readlines()
	print(len(prePRE))
	preSize = len(prePRE)
	
	while(i < (preSize * 2)):
		pre = prePRE[i]
		removeTrail = pre.strip('\n')
		commaSplt = removeTrail.split(',')
		val = commaSplt
	
		while(x < len(val)):
			tempListVar = val[x]
			splitted = tempListVar.split(':')
			print(splitted[0])
			if(str(splitted[0]) == "ID"):
				tempVar = splitted[0]
				IDlist.append(tempVar)
				print(splitted[1])
			elif(str(splitted[0]) == "diameter"):
				tempVar = splitted[0]
				Dlist.append(tempVar)
				print(splitted[1])
			elif(str(splitted[0]) == "color"):
				tempVar = splitted[0]
				Clist.append(tempVar)
				print(splitted[1])
			elif(str(splitted[0]) == "texture"):
				tempVar = splitted[0]
				Tlist.append(tempVar)
				print(splitted[1])
			else:
				print("nothing added to any list")
			x += 1
		i += 1
	print("IDLIST: ", IDlist)
	print("DLIST: ", Dlist)
	print("CLIST: ", Clist)
	print("TLIST: ", Tlist)
	

	return val


import array
import string
from time import sleep as s
from functions import main_input, pushTest, prettyTextOutput 
#python doesnt have do while loops or switch statments

#test = menu()
menu = 0
while(menu != 5):
	choices = """
	\t\t==Menu==\n
	\t1. Diameter, color, texture, and ID of the ball.\n
	\t2.\n
	\t3. pull all data from file\n
	\t5. Exit.\n
	Choice: 
	"""
	menu = input(choices)
	
	if (menu == "1"):
		print("menu = 1\n")
		loop = int(input("how many do you want to enter?"))
		push = main_input(loop)
		pushTest(push)
	
	elif (menu == "2"):
		print("menu = 2\n")
	elif (menu == "3"):
		print("menu = 3\n")
#	elif (menu == "4"):
#		print("menu = 4\n")
	elif (menu == "5"):
		print("bye")
		exit()
	else:
		print("invlaid choice")

 









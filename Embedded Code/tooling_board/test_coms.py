"""Testing GUI for the tooling board."""
import serial
from tkinter import *
from tkinter.ttk import *

# Variables
ledduty = 0
dir1 = 1
dir2 = 1
dir3 = 1
dir4 = 1
duty1 = 0
duty2 = 0
duty3 = 0
duty4 = 0
sensors = 0

ser = serial.Serial('COM20', 115200)

def printSerial():
	"""Print serial data."""
	global dir1
	global dir2
	global dir3
	global dir4
	global duty1
	global duty2
	global duty3
	global duty4
	global ledduty
	global sensors
	send = (str(dir1)+","+str(duty1)+","+str(dir2)+","+str(duty2)+","+str(dir3)+","+str(duty3)+","+str(dir4)+","+str(duty4)+","+str(ledduty)+","+str(sensors))
	print(send)
	if(ser.isOpen() is False):
	    ser.open()
	ser.write(send.encode("utf-8"))
	ser.close()

def button1():
	"""Set LED."""
	global ledduty
	ledduty = e1.get()
	printSerial()

def button2():
	"""Set Motor."""
	if e2.get() == "1":
	    global dir1
	    global duty1
	    dir1 = e3.get()
	    duty1 = e4.get()
	if e2.get() == "2":
	    global dir2
	    global duty2
	    dir2 = e3.get()
	    duty2 = e4.get()
	if e2.get() == "3":
	    global dir3
	    global duty3
	    dir3 = e3.get()
	    duty3 = e4.get()
	if e2.get() == "4":
	    global dir4
	    global duty4
	    dir4 = e3.get()
	    duty4 = e4.get()
	printSerial()

def button3():
	"""Zero."""
	global duty1
	global duty2
	global duty3
	global duty4
	global ledduty
	duty1 = 0
	duty2 = 0
	duty3 = 0
	duty4 = 0
	ledduty = 0
	printSerial()

# Setup window
root = Tk()
root.title("Tooling Board Test")
root.iconbitmap('ee_logo_l8z_icon.ico')
root["padx"] = 5
root["pady"] = 5

# Labels
Label(root, text="LED Duty:").grid(row=0, column=0)
Label(root, text="Motor ID:").grid(row=0, column=1)
Label(root, text="Motor Direction:").grid(row=0, column=2)
Label(root, text="Motor Duty:").grid(row=0, column=3)

# Entry boxes
e1 = Entry(root)
e2 = Entry(root)
e3 = Entry(root)
e4 = Entry(root)

e1.grid(row=1, column=0, padx=5, pady=5)
e2.grid(row=1, column=1, padx=5, pady=5)
e3.grid(row=1, column=2, padx=5, pady=5)
e4.grid(row=1, column=3, padx=5, pady=5)

# Buttons
Button(root, text='Zero', command=button3).grid(row=0, column=4, sticky=W, padx=5, pady=5)
Button(root, text='Set Motor', command=button2).grid(row=1, column=4, sticky=W, padx=5, pady=5)
Button(root, text='Set LED', command=button1).grid(row=2, column=4, sticky=W, padx=5, pady=5)
Button(root, text='Quit', command=root.quit).grid(row=3, column=4, sticky=W, padx=5, pady=5)

mainloop( )
import serial
from PyQt5 import QtGui
from PyQt5.QtCore import (Qt)
from PyQt5.QtWidgets import (QApplication, QLabel, QWidget,
                             QHBoxLayout, QLineEdit, QVBoxLayout,
                             QPushButton)

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
    global ledduty
    ledduty = tb.text()
    printSerial()


def button2():
    if tb1.text() == "1":
        global dir1
        global duty1
        dir1 = tb2.text()
        duty1 = tb3.text()
    if tb1.text() == "2":
        global dir2
        global duty2
        dir2 = tb2.text()
        duty2 = tb3.text()
    if tb1.text() == "3":
        global dir3
        global duty3
        dir3 = tb2.text()
        duty3 = tb3.text()
    if tb1.text() == "4":
        global dir4
        global duty4
        dir4 = tb2.text()
        duty4 = tb3.text()
    printSerial()


def button3():
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


app = QApplication([])
app.setStyle('Fusion')

label = QLabel("led Duty:")

tb = QLineEdit('')
tb.setFixedSize(100, 25)
tb.setObjectName('led duty')
tb.returnPressed.connect(button1)

led = QVBoxLayout()
led.setAlignment(Qt.AlignTop)
led.addStretch(0)
led.setSpacing(0)
led.addWidget(label)
led.addWidget(tb)

label1 = QLabel("motor id:")

tb1 = QLineEdit('')
tb1.setFixedSize(100, 25)
tb1.setObjectName('motor id')
#tb1.returnPressed.connect(button2)

motor1 = QVBoxLayout()
motor1.setAlignment(Qt.AlignTop)
motor1.addStretch(0)
motor1.setSpacing(0)
motor1.addWidget(label1)
motor1.addWidget(tb1)

label2 = QLabel("Motor Direction:")

tb2 = QLineEdit('')
tb2.setFixedSize(100, 25)
tb2.setObjectName('motor duty')
#tb2.returnPressed.connect(button2)

motor2 = QVBoxLayout()
motor2.setAlignment(Qt.AlignTop)
motor2.addStretch(0)
motor2.setSpacing(0)
motor2.addWidget(label2)
motor2.addWidget(tb2)

label3 = QLabel("Motor Duty:")

tb3 = QLineEdit('')
tb3.setFixedSize(100, 25)
tb3.setObjectName('motor duty')
tb3.returnPressed.connect(button2)

motor3 = QVBoxLayout()
motor3.setAlignment(Qt.AlignTop)
motor3.addStretch(0)
motor3.setSpacing(0)
motor3.addWidget(label3)
motor3.addWidget(tb3)

Button1 = QPushButton('Zero')
Button1.setFixedSize(75, 25)
Button1.clicked.connect(button3)
Button1.setAutoDefault(True)

Button2 = QPushButton('Set Motor')
Button2.setFixedSize(75, 25)
Button2.clicked.connect(button2)
Button2.setAutoDefault(True)

Button3 = QPushButton('Set LED')
Button3.setFixedSize(75, 25)
Button3.clicked.connect(button1)
Button3.setAutoDefault(True)

but = QVBoxLayout()
but.setAlignment(Qt.AlignTop)
but.addStretch(0)
but.setSpacing(0)
but.addWidget(Button1)
but.addWidget(Button2)
but.addWidget(Button3)

set = QHBoxLayout()
set.addLayout(led)
set.addLayout(motor1)
set.addLayout(motor2)
set.addLayout(motor3)
set.addLayout(but)

start = QWidget()
start.setLayout(set)
start.setFixedSize(700, 100)
start.setWindowTitle('Tool Board test')
start.setWindowIcon(QtGui.QIcon('ee_logo_l8z_icon.ico'))
start.show()

app.exec_()

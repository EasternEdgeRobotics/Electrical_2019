import serial
import datetime

ser = serial.Serial('COM11', 115200)

while True:
    ser_bytes = ser.readline()
    decoded_bytes = ser_bytes[0:len(ser_bytes)-2].decode("utf-8")
    currentDT = datetime.datetime.now()
    test = str(currentDT)
    print(test + ": " + decoded_bytes)
    x = decoded_bytes.split(',')
    # x format pressure,temperaturePS,gyroX.gyroY,gyroZ,accelX,accelY,accelZ,TemperatureIMU
    currentDT = datetime.datetime.now()
    test = str(currentDT)
    print(test + ": " + x[0])

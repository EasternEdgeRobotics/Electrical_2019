import serial
import time

# change serial port
ser = serial.Serial('COM20', 115200)


while True:
    time.sleep(200)
    send = ("t")
    ser.write(send.encode("utf-8"))
    ser_bytes = ser.readline()
    decoded_bytes = ser_bytes[0:len(ser_bytes)-2].decode("utf-8")
    x = decoded_bytes.split(',')

    Current_a = float(x[0])
    Vin_a = float(x[1])
    Vout_a = float(x[2])
    Iout_a = float(x[3])
    Temp_a = float(x[4])
    Mode_a = float(x[5])

    Current_b = float(x[6])
    Vin_b = float(x[7])
    Vout_b = float(x[8])
    Iout_b = float(x[9])
    Temp_b = float(x[10])
    Mode_b = float(x[11])

    Current_c = float(x[12])
    Vin_c = float(x[13])
    Vout_c = float(x[14])
    Iout_c = float(x[15])
    Temp_c = float(x[16])
    Mode_c = float(x[17])

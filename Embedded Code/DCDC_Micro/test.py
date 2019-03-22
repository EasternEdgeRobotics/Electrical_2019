import serial
import time

ser = serial.Serial('COM20', 115200)


while True:
    time.sleep(200)
    send = ("t")
    ser.write(send.encode("utf-8"))
    ser_bytes = ser.readline()
    decoded_bytes = ser_bytes[0:len(ser_bytes)-2].decode("utf-8")
    x = decoded_bytes.split(',')

    Current_a = int(x[0])
    Vin_a = int(x[1])
    Vout_a = int(x[2])
    Iout_a = int(x[3])
    Temp_a = int(x[4])
    Mode_a = int(x[5])

    Current_b = int(x[6])
    Vin_b = int(x[7])
    Vout_b = int(x[8])
    Iout_b = int(x[9])
    Temp_b = int(x[10])
    Mode_b = int(x[11])

    Current_c = int(x[12])
    Vin_c = int(x[13])
    Vout_c = int(x[14])
    Iout_c = int(x[15])
    Temp_c = int(x[16])
    Mode_c = int(x[17])

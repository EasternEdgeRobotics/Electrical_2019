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

    fore_star_horz = int(x[0])
    fore_port_horz = int(x[1])
    fore_star_vert = int(x[2])
    aft_star_horz = int(x[3])
    fore_port_vert = int(x[4])
    aft_port_vert = int(x[5])
    aft_star_vert = int(x[6])
    aft_port_horz = int(x[7])
    PI_Switch_Tooling = int(x[8])

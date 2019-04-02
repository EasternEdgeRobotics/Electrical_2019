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

    fore_star_horz = float(x[0])
    fore_port_horz = float(x[1])
    fore_star_vert = float(x[2])
    aft_star_horz = float(x[3])
    fore_port_vert = float(x[4])
    aft_port_vert = float(x[5])
    aft_star_vert = float(x[6])
    aft_port_horz = float(x[7])
    PI_Switch_Tooling = float(x[8])

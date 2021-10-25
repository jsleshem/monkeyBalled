import pyvjoy
import serial

controller = pyvjoy.VJoyDevice(1)

serial_connection = serial.Serial('COM8', 9600)

print("connected to: " + serial_connection.portstr)

controller.set_button(1, 0)

while True:
    inputData = str(serial_connection.readline())

    Xstart = inputData.find("x") + len("x")
    Xend = inputData.find("|")
    try:
        XcleanInputData = int(inputData[Xstart:Xend])
    except:
        print("Bad value - " + inputData)

    Ystart = inputData.find("y") + len("y")
    Yend = inputData.find("~")
    try:
        YcleanInputData = int(inputData[Ystart:Yend])
    except:
        print("Bad value - " + inputData)

    controller.set_axis(pyvjoy.HID_USAGE_X, XcleanInputData)
    controller.set_axis(pyvjoy.HID_USAGE_Y, YcleanInputData)
ser.close()

print("end")

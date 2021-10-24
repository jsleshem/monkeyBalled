import pyvjoy
import time

from pip._vendor.distlib.compat import raw_input

controller = pyvjoy.VJoyDevice(1)

# while True:
#     for i in range(327):
#         if (i == 325):
#             i == 0
#         controller.set_axis(pyvjoy.HID_USAGE_X, i*100)
#         time.sleep(0.1)
#         print(i)

while True:
    i = raw_input("key: ")
    if (i == "a"):
        for i in range(3):
            print(3 - i)
            time.sleep(1)
        controller.set_button(1, 1)
        print("A on")
        time.sleep(2)
        controller.set_button(1, 0)
        print("A off")


print("end")
import pyvjoy
import time

from pip._vendor.distlib.compat import raw_input

controller = pyvjoy.VJoyDevice(1)

while True:
    i = raw_input("key: ")
    if (i == "z"):
        controller.set_button(1, 1)
        time.sleep(0.25)
        controller.set_button(1, 0)
    if (i == "x"):
        controller.set_button(2, 1)
        time.sleep(0.25)
        controller.set_button(2, 0)
    if (i == "c"):
        controller.set_button(3, 1)
        time.sleep(0.25)
        controller.set_button(3, 0)

print("end")
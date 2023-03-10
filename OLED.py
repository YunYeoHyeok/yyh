import sys
import os
import RPi.GPIO as GPIO
import time

picdir = os.path.join(
    os.path.dirname(os.path.dirname(os.path.realpath(__file__))), "pic"
)
libdir = os.path.join(
    os.path.dirname(os.path.dirname(os.path.realpath(__file__))), "lib"
)
if os.path.exists(libdir):
    sys.path.append(libdir)

from time import sleep
from waveshare_OLED import OLED_0in96
from PIL import Image, ImageDraw, ImageFont

disp = OLED_0in96.OLED_0in96()
disp.Init()
disp.clear()

# Create blank image for drawing.
image1 = Image.new("1", (disp.width, disp.height), 255)
draw = ImageDraw.Draw(image1)

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(18, GPIO.OUT)

p = GPIO.PWM(18, 1)
Frq = [440]
p.start(50)


def LED369():
    for i in range(1, 101):
        num_str = str(i)
        flag_369 = 0
        flag_OLED = 0

        if (
            num_str.find("3") != -1
            or num_str.find("6") != -1
            or num_str.find("9") != -1
        ):
            print("x(%s)" % num_str)
            flag_369 = 1
            flag_OLED = 1
        else:
            print(num_str)
            flag_369 = 0
            flag_OLED = 0

        if flag_369 == 1:
            try:
                for fr in Frq:
                    p.ChangeFrequency(fr)
                    time.sleep(0.5)
                    p.ChangeFrequency(1)
            except KeyboardInterrupt:
                pass
        else:
            p.ChangeFrequency(1)
        if flag_OLED == 1:
            try:
                draw.line([(0, 0), (127, 68)])
                draw.line([(127, 0), (0, 68)])
                disp.ShowImage(disp.getbuffer(image1))
            except KeyboardInterrupt:
                pass
        else:
            disp.clear()

    time.sleep(0.1)


LED369()

while 1:
    time.sleep(0.1)

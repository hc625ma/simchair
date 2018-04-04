# simchair
This is a modified UnoJoy software (https://github.com/AlanChatham) for the simchair project. It supports 6 axes (3x10 bit axes, 3x8 bit), fast filtering, stick calibration. This is intended to be used with Arduino UNO boards, note that you will need an atmega 16u2 on USB for it to work (original, or exact clones of original arduino will do, but CH340 ones wont).

How to use UnoJoy software:

    Upload the "simchair.ino" sketch to your Arduino with an Arduino IDE.
    Install Atmel FLIP.
    Turn your Arduino into DFU mode.
    Your board should come up as an atmega16u2.
    Run "Turn into a joystick.bat"
    Replug your board and it will show up as a joystick.


Simchair is a set of 3d printable, open source helicopter (for now) controls, designed to fit an IKEA GUNDE folding chair, suitable for use with PC simulators like X-Plane or DCS, or for RC model flying.

The current version in development is 3, and the following parts are available for donwload from thingiverse / currently are in development:

  - simchair mkIII 6 axis controller box and PC joystick software (https://www.thingiverse.com/thing:2775102)
  - simple single throttle collective lever (https://www.thingiverse.com/thing:2630031)
  - bell 412 style dual-throttle collective lever (https://www.thingiverse.com/thing:2747131)
  - IKEA GUNDE chair frame brackets for controls mounting (https://www.thingiverse.com/thing:2795691)
  - cyclic gimbal with B8 stick replica (https://www.thingiverse.com/thing:2795753)
  - pedals (https://www.thingiverse.com/thing:2802115)
  - cessna 182 style engine and prop controls (https://www.thingiverse.com/thing:2812556)
  - wireless cyclic grip (scheduled for development)
  - wireless collective switch panel (scheduled for development)
  - wireless button controller (scheduled for development)
  - simple yoke (scheduled for development)
  - analog controller i2c upgrade (scheduled for development)

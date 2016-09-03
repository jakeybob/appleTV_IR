# appleTV_IR
Arduino micro project to provide stereo volume knob functionality via infra-red remote.

IR Remote library used : https://github.com/z3t0/Arduino-IRremote

Datasheets for hardware found in /datasheets


This project passes a stereo input signal through a stereo digipot, controlled via IR remote, with the IR signal being demodulated 
by the sensor and interpreted by the Arduino Pro Micro via the IR lib.

Volume up, down and mute commands are implemented (with the mute command being a double-click on the volume-down button).
The up/down/mute commands are issued to the DS1802 stereo digipot chip via the IO pins and some 2N3904 NPN transistors.

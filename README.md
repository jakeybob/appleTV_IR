# appleTV_IR
Arduino micro project to provide stereo volume knob functionality via infra-red remote.

It's called AppleTV_IR because I created it to solve a problem I had with my AppleTV setup, but it is of course applicable to any audio situation.

USing the micro board, and placing everything onto an arduino-uno prototyping board (or similar) it is possible to fit everything into e.g. an Altoids tin – see /pic.jpg

IR Remote library used : https://github.com/z3t0/Arduino-IRremote

Datasheets for hardware found in /datasheets


This project passes a stereo input signal through a stereo digipot, controlled via IR remote, with the IR signal being demodulated 
by the sensor and interpreted by the Arduino Pro Micro via the IR lib.

Volume up, down and mute commands are implemented (with the mute command being a double-click on the volume-down button).
The up/down/mute commands are issued to the DS1802 stereo digipot chip via the IO pins and some 2N3904 NPN transistors.

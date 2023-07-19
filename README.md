# PaindreIOT

Paindre is an IoT device designed to assist healthcare professionals in conducting inspections on paralyzed patients. This device works by applying controlled pressure to the patient's skin, recording the data, and analyzing it using a system. The analyzed results are then displayed on a website page to serve as a guide for the patient's health progress. I building this project based on arduino.ide and flutter for website

## Source Material
1. ESP32
2. Arduino IDE
3. Mini LED
4. Servo Motor
5. IR Remote Reciver
6. Remote
7. Capasitive Touch Sensor

<details><summary>Installing Arduino IDE on windows</summary>
<a href="https://downloads.arduino.cc/arduino-ide/arduino-ide_latest_Windows_64bit.exe?_gl=1*16c6sao*_ga*MjA0MzMwNDUxMS4xNjg5NzQ1MTg1*_ga_NEXN8H46L5*MTY4OTc0NTE4NC4xLjAuMTY4OTc0NTE4NC4wLjAuMA..">1. Download Latest Build</a>
<br>2. Follow the instructions in the installation guide.
<br>3. When completing the setup, leave Run Arduino IDE ticked to launch the application, or launch it later from the Start Menu.
</details>

After installing arduino IDE then download this <a href="https://github.com/diidhul/paindreiot/tree/main/libraries">library folder</a> and also <a href="https://github.com/diidhul/paindreiot/tree/main/paindrefix">main folder</a>
<br>Put the folder under arduino IDE document root, ex : C:\Users\diidhul\Documents\Arduino
<br>Then we move into wiring all parts, you can find the images on <a href="">here</a>

### Assembly
I using tinkercad.com for designing the casing, u can find the desing on <a href="https://github.com/diidhul/paindreiot/blob/main/images/wiring.png">here</a>, if u dont understand the image, please download the <a href="https://github.com/diidhul/paindreiot/blob/main/images/sketch%20paindre.fzz">fzz file</a> and open it on <a href="https://fritzing.org/download/">fritzing</a>
<br> for the mechannics you need to print this <a href="https://www.thingiverse.com/thing:3170748">linear actuator</a> and assembly it on Servo
<br>After all... the prototype will look like this <img>

### Paindre.APK
APK is under maintenace i will update it ASAP

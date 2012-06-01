#Sequence Bot
Sequence bot allows a user to remotely control the iRobot from a webpage in any common browser (mobile, or desktop).
A user is able to control the iRobot connected to the same network by navigating to http://192.168.1.7/controls.html.
controls.html is comprised of 4 way directional pad that controls rotation, forward and reverse movement.

##Hardware
Sequence bot is comprised of an iRobot Create, an Arduino Uno chip, and a WiShield Arduino Wifi Shield.
The arduino communicates with the iRobot using a software serial connection.

##Software
The Uno + WiShield act as a webserver, serving the controls to the iRobot as an html/JS page. Pressing the Dpad control buttons on the page send GET requests to the Uno instructing it to rotate left, right or move forward and back.
Commands to the bot via the Uno chip don't have to originate from controls.html. The following GET requests will control the bot directly
* /robot/turnright
* /robot/turnleft
* /robot/forward
* /robot/backward
* /robot/stop

##Build/Install
simply type 'rake' on the command line with the uno plugged into the usb on your machine. This will compile the resources, build the binary, and upload it to the Uno.
The rake command has the following tasks:
* clean 
* build 
* upload 
* build_resources 

Build resources will take any resources (images, htmls pages etc) in the 'resource' folder and make them available over the network via http GET calls. For instance an images located at ./resources/img/arrow.jpg will be available at 'http://192.168.1.7/img/arrow.jpg'.

##Dependencies
[ino](https://github.com/amperka/ino) is a command line wrapper around the avr-gcc toolchain
[Arduino-iRobot-Create-api](https://github.com/michaelcdillon/Arduino-iRobot-Create-API) is a c wrapper around serial calls to control the iRobot




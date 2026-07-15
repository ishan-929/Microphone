---
title: "Microphone"
author: "Ishan K."
description: "Microphone that can record anything!"
created_at: "2026-07-09"
---

# July 9th: Starting the Project!!

Today was just the day that I came up with this project and did a
little reserahc as to how I can come about to create a microphone,
since Ive never worked with any kind of microphone module before
that is able to capture audio data. From researching, I found the
INMP441, an MEMS Microphone that works because of it containing
a small disk-like diaphragm that vibrates when change in air pressure
is recorded. With those vibrations, the module is able to convert it
into raw Audio data that can then eb sent over to the brains of the 
operation (in my case, ESP32), and do whatever youd like. This picks
up the data, but dosent do anything else. The way Id have to convert that
data into an actual audio file to use is by either using an already pre-exisitng
app/website that is able to convert it, or some kind of python program
to convert the data. Also, when the INMP441 is collecting Data, that information has
to go somewhere. After seraching it up, the ESP32 only has enough memory in it to be able to 
store 20-50 seconds of audio, which just does NOT cut it for me. Not only do I just want 
to use this for an insta page, I thought itd be really cool to have something where I can 
use to record experiences and much more. That is why i decided to use a Micro SD Card as 
well as an SD Card reader, since doing this will be able to give me SO MUCH MORE Audio 
time (for refrence, 8GB is enough for about 37 Hours!!!!!)

**Total time spent: 1hr**

# July 10th: 1st Quick Rough Draft + learning of the INMP441 and SD Card Reader!!

Today after settling on the components id use to create this microphone project, 
I decided to delve into them as I had never used either of these components before.
Ill start off with the INMP441, heres a pin breakdown of it:

VDD: This pin is the pin where you power the module using 3.3v connection
GND: Your typically Ground, nt crazy
L/R: This pin essentially is more useful if you were using 2 of these modules,
      maybe to get stereo audio and another being mono, but its essentially like which chennel
      do you want to send audio too. It dosent matter in my case because Im only using one, so 
      I can just pick any. Im using the right, so I also apply a 3.3v connection there
WS: This one isa little similar to the L/R, as its function to be able to change signals between
    left and right, and again, im using right so id hook it up to the microcontroller with a GPIO 
    and give it a signal
SCK: This pin essentially syncs the data the Audio data the INMP441 recieves and optimizes the 
    data so that the ESP32 is able to get it in an efficient way. It helps the microcontroler out 
    by letting it know when the SD pin is about to send its next sample of audio data. 
    Can also be in reverse order
SD: This pin is essentialy the pin that carries the audio to the ESP32 bit by bit.

Here is the SD Card Reader: 

GND: ur typical ground
VCC: ur typical 5v connection
MISO: A pin that sends data from the sd card to the ESP32
MOSI: a pin that takes in data from the ESP32
SCK: just like sck on the INMP441, this pinout is the clock for comunication for either side as to when data will arrive
CS: This pin kinda creates a doorway betwen itself an the microcontroller. The Microcontroller whenever it makes this
     pin low, it essentially is liek knocking on the SD card Readers door, letting it know its about to send over data.
     High if its not.

Thats About it for the Pinout on both!

Today also involved in making a quick rough draft for a code. These were completetly seperate,
so One code was just with the INMP441 and the other code was just with the SD Card Reader.
After taking the time to get an idea of how both are coded (SD card was so easy bro INMP was killing me),
I decided to write a quick test code for both. The SD card was stright forward and just included steps like 
initalizng the SD card, creating the file, how to write in it plus closing irt (not doing so dosent save!), etc.
And boy oh boy... the INMP441... that one was not fun. Oh and just to mention, not only is it my first time working
with these two modules, its also my first time using I2S and SPI communication so i had to learn what that was too,
which was a pain for I2S because the setup between it and the microcontroller and INMP441 itself was like more
than half the code, not even telling it to get data. The setup isnt neccesarily something that you gotta be
a critical thinker for to type out since the format is always just teh same, I just had to learn what can change
and why youd want to change it, suhc as the left or right lanes I mentioned earlier, how many bits data transffered, 
pin configuration, whats the master and whats sending / recieving data, etc. 

After setup, the code that ua ctually have to write for the two are fairly simple. For example,
fro the SD Card Reader, you just use commands such as file.print(), file.close(), literally creating a file, etc. (this dude made it so easy ot understand --> https://www.youtube.com/watch?v=1jUXlPP_xnI)
With the INMP441, you have to call commands such as i2s_read(.....) which essentially reads data, then justa bit of math to
optimize the numbers its becoming up into mroe smaller numbers when then I can see in mt Serial Monitor.

Majority of today was understanding my code (that damn imnp441 setup.....), and writing a simple code for both
modules to test them. I couldnt wait to test them anyway. 

The inmp441 code by the way isnt efficient by any means and is something I have to change later.
INMP441 also was not tested, only SD card reader was.

**Total time spent: 4-5hr**

# July 11th: Editing first Rough draft of the INMP441 Test + understanding it more!!

Today was pretty goal focused, and was all about getting the INMP441 code to really work. So many problems was run
into to the point I genuienly got a headache at one point, like not one moment of success with a 2 hour sitting.
SD card wouldnt even initialize because when I soldered the pins on the module, I got some solder on the golden ring
around it that was connected to both vdd and gnd, so that didnt end up well because I had to RESOLDER and check for shorts...
0's would also only print on my monitor a multitude of times depsite me talking in the mic like I was taolking to a deaf person
literally. Problem ended up being i wrote the left/rigth path thing wrong as well as my configuration on my circuit since I hooked 
L/R to 3.3 though im using right. (rigth takes GND). Not even that, but the audio data being printed onto the serial monitor were
data being skipped because of some bytes and sample math i did horribly wrong, so instead of getting data  hat shouldve been worth up to 20 seconds
id get lie 2...

Problems like these accumilated and what annoyed me more was that it was a tiny microphone.. bu it was okay since the end goal is something
I needed. Today just consisted of solving all these problems, which also led me to understanding this module more.

**Total time spent: 3hr**

# July 13th: Writing the final code!!

This part was mostly carrying over my knowledge + code from the starter two codes + incorrperating more, such as 2 LED's and a button.
The reason I decided to do this was because when I would test my INMP441 code, aot of the times, the code wouldnt compile at all.
I figured that maybe if i somehow set some kind of setting to let the code know when I wanted to start recording, instead of taking in inoput right away
once plugged it, itd be more stable. So what I did was incorperate one green LED and one RED Led. The green LED would indicate that the microphone is
waiting for you to hit that record button, and the red LEd on would mean it is currently recording. This would be something id need to add anyway, becauae what kind of microphone do\
u have if u cant even control it. I think this was pretty neat, and I wanted to made a CAD Model for the microphone as well, so thatll be under construction soon.
a few problems always got ran into, but that was because of button logic in which id have t make it so that everytime the button was pressed, the microphone would continue taking in data till
button pressed again.

**Total time spent: 2hr**

# July 14th: Learning simple CAD!

CAD is fairly new to me. I started a video lesson course some time ago, but never ended up continuing it.
CAD is such an essential and fun skill to have int he world of engineering, and I wanted to learn
especially so that I can take my projects out of a plain breadboard and make them look unique.
I didnt do anything related to the project since first I gotta hone my skils in CAD so thats 
just what Im gonna do. Im going to start usng lapse today to start my CAD journey while alos tracking my
hours learning.







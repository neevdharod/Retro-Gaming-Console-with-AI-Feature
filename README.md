# Retro-Gaming-Console-with-AI-Feature
Retro Gaming Console that is normal, But has a button for where If you press it, you can use your voice and explain a game idea, and it will create your game and will let you play. It will also have the basic games like Flappy Bird, Tetris, etc.

https://oshwlab.com/neev.dharod/project_aikugdql

# CAD
CAD link: https://cad.onshape.com/documents/80234ca0c6dbc53564995cd3/w/1bd3a773922b38dffe61e045/e/d0db60f0b216c6b611b1f2d4?renderMode=0&uiState=6a668a218ce625604a8985ed


Cad includes an assemblty which includes all electronic components and the actual case for it.
<img src="https://cdn.hackclub.com/019ecc9d-02e1-786a-b197-12f1cfd2ec7b/Screenshot%202026-06-15%2011.46.30%20AM.png" alt="image"/>
<img width="434" height="566" alt="image" src="https://github.com/user-attachments/assets/611b310a-7bb2-44ee-808c-b4f6e7809b4b" />


# PCB
<img src="https://cdn.hackclub.com/019ec441-da61-76bc-aa80-ccba045c6c78/Screenshot%202026-06-13%208.46.34%20PM.png" alt="image"/>
<img src="https://cdn.hackclub.com/019ebf21-7002-746d-ab61-79bef848bcba/Screenshot%202026-06-12%203.47.16%20PM.png" alt="image"/>
<img src="https://cdn.hackclub.com/019ec45a-b940-72c8-82ba-8f35575b54b3/Screenshot%202026-06-13%209.17.40%20PM.png" alt="image"/>

# Electronic Schematic
Note: Electronic Schematic does not have much since Wokwi did not have enough items to simulate everything
<img src="https://cdn.hackclub.com/019ebdc6-6430-7403-9a46-864d517d2876/Screenshot%202026-06-12%2012.44.29%20AM.png" alt="image"/>
Video Simulation: https://drive.google.com/file/d/1bcLsbRWAjZI9G2lNmVKaYL5mQRzRJAQ2/view?usp=sharing

# Key Features
- Raspberry Pi Zero 2 W
- 3.5 Inch HDMI display
- push buttons and a joystick
- microphone
- speaker
- LiPo Battery
- Cool AI button feature

# Why/How

I created this project to increase my knowledge on PCBs in general, and this is kind of my final summer project after a couple other projects I made through Macondo. Kind of like my final 'test' lol. This uses all the components I used, including screen, SEED studio, buttons, charging w battery, etc. I also thought in general it would be pretty cool to make.

Here are the steps to making this.
1. Buying the items!
2. Use the components on a breadboard, and use a simple program for testing to see if the components work.
3. Solder the components onto the PCB and do the same test there.
4. Create a final program that does everything and upload it on.
5. Use digital caliper to make sure my measurements in CAD are correct and then print the CAD out.
6. Final assembly and finished product.

This is obviously a simplified version of the full How but yeah that gives you an idea. 

# Potential Challenges
PCBs in general are always a challenge, as you never know what could happen, and my soldering skills are not exactly great, so that could be a potential challenge. To mitigate this challenge, I plan to practice soldering before going at it on the actual PCB, and I also have 5 PCBs since they come in order of 5, so I have basically 5 attempts kind of. 

# BOM

|#  |Item                     |AliExpress link / search                            |Specs / details                                                |Total  |
|---|-------------------------|----------------------------------------------------|---------------------------------------------------------------|-------|
|1  |Raspberry Pi Zero 2 W    |https://www.aliexpress.us/item/1005008701910308.html|Main computer, Wi-Fi, Bluetooth, mini HDMI, 40-pin GPIO        |$24.99 |
|2  |3.5" HDMI IPS Display    |https://aliexpress.ru/item/1005009296423819.html    |3.5 inch HDMI display, IPS, driver-free Raspberry Pi compatible|$6.30  |
|3  |Dual 18650 Battery Shield|https://www.aliexpress.com/item/4000704300145.html  |1-way battery shield, Type-C charging, 5V/3A output            |$6.49  |
|4  |MAX98357A I2S Amplifier  |https://www.aliexpress.us/item/3256809209823945.html|I2S digital audio amplifier module for speaker output          |$6.85  |
|5  |INMP441 I2S Microphone   |https://www.aliexpress.us/item/1005007096865003.html|I2S MEMS microphone module for voice input                     |$3.57  |
|6  |8Ω 1W Speaker            |https://www.aliexpress.us/item/1005006104005278.html|Small 8 ohm, 1 watt speaker for audio output                   |$1.80  |
|7  |6×6 Tactile Switches     |https://www.aliexpress.us/item/1005009186148132.html|4-pin 6×6mm tactile switches, used for 12 buttons              |$3.33  |
|8  |Button Caps              |6x6 tactile switch button caps                      |Plastic caps for A/B/X/Y, Start, Select, AI, Menu              |$3.25  |
|9  |D-pad Cross Button       |Search: Gameboy dpad replacement button             |Cross-shaped D-pad cap for four tactile switches               |$2.50  |
|10 |2×20 Female Header       |https://www.aliexpress.us/item/3256805804439042.html|2.54mm 40-pin female header for Raspberry Pi connection        |$3.40  |
|11 |2×20 Male Header         |https://www.aliexpress.us/item/3256805804439042.html|2.54mm 40-pin male header for Raspberry Pi GPIO                |$3.30  |
|12 |SS12D00G3 Slide Switch   | SS12D00G3 slide switch                             |Small 3-pin slide switch for power control                     |$2.40  |
|13 |LED                      | 3mm LED assorted                                   |Power indicator LED                                            |$0.99  |
|14 |330Ω Resistor            | 330 ohm resistor 0805                              |Current-limiting resistor for LED                              |$0.99  |
|15 |JST Connector Kit        |https://www.aliexpress.us/item/4001235017139.html   |JST connectors for battery, speaker, and power wiring          |$1.98  |
|16 |Mini HDMI Cable / Adapter|Raspberry Pi Zero mini HDMI to HDMI cable           |Connects Pi Zero 2 W to HDMI display                           |$3.99  |
|17 |MicroSD Card             |32GB microSD card                                   |Storage for Raspberry Pi OS and game software                  |$6.99  |
|18 |M2 Screw / Standoff Kit  |M2 screw standoff kit                               |Mounting PCB and case hardware                                 |$6.70  |
|19 |Custom PCB               |JLCPCB / PCBWay                                     |90mm × 145mm custom carrier PCB                                |$19.74 |
|   |                         |                                                    |Total                                                          |$109.56|


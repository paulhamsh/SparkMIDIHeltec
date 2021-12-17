# SparkMIDIHeltec
MIDI converter to control Spark amp  
Based on a Heltec ESP32 WIFI board, a commodity USB Host adapter and some components for the serial DIN MIDI.   

Allows multiple MIDI sources to control a Spark 40 amplifier - bluetooth controller, UBS MIDI controller or serial DIN MIDI.   

Can be programmed to:   
-  change hardware preset   
-  turn effect on or off   
-  send a whole custom preset   
-  change a parameter value (0.0 - 9.9)   
-  set tap tempo   
-  store preset to hardware   
-  change effect model

The current software setup changes hardware preset, toggles effects on and off and changes amp parameters.   

It is set up to reconise and map the Akai LPD8 Wireless, the MIDICommanded USB pedal and the FCB1010 serial midi controller - but any MIDI device should be mappable with a little coding.   

The UI shows activity and connection status.   

<p align="center">
  <img src="https://github.com/paulhamsh/SparkMIDIHeltec/blob/main/image1.jpg" width="350" title="Board">
</p>

The circuit diagram is below   


<p align="center">
  <img src="https://github.com/paulhamsh/SparkMIDIHeltec/blob/main/USB Host Heltec.jpg" width="900" title="Circuit">
</p>

The MIDI in circuit is from https://www.pjrc.com/teensy/td_libs_MIDI.html    


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

An example of the code to react the the MIDI signals is shown below   

```
    if (mi1 == 0xc0) {       // FCB1010 switches
      switch (mi2) {
        case 0:              change_hardware_preset(0);               break; // pad 1
        case 1:              change_hardware_preset(1);               break; // pad 2
        case 2:              change_hardware_preset(2);               break; // pad 3
        case 3:              change_hardware_preset(3);               break; // pad 4
        case 5:              change_comp_toggle();                    break; // pad 5
        case 6:              change_drive_toggle();                   break; // pad 6
        case 7:              change_delay_toggle();                   break; // pad 7
        case 8:              change_reverb_toggle();                  break; // pad 8
      }
    }
   
   
    if (mi1 == 0xb0) {       // LPD8 knobs OR FCB 1010 expression
      switch (mi2) {
        case 0:              change_amp_param(AMP_GAIN, mi3/127.0);   break; // k1       
        case 1:              change_amp_param(AMP_BASS, mi3/127.0);   break; // k2       
        case 2:              change_amp_param(AMP_MID, mi3/127.0);    break; // k3
        case 3:              change_amp_param(AMP_TREBLE, mi3/127.0); break; // k4
        case 4:              change_amp_param(AMP_MASTER, mi3/127.0); break; // k5
        case 5:                                                       break; // k6
        case 6:                                                       break; // k7
        case 7:              change_amp_param(AMP_GAIN, mi3/127.0);   break; // k8 OR FCB EXP 1
        case 27:             change_amp_param(AMP_MASTER, mi3/127.0); break; // FCB EXP2
```

Where ```mi1``` is the midi command and ```mi2``` and ```mi3``` are the two midi message data bytes.   
Hopefully it is clear that the messages to the Spark are pretty simple.   

If you want any assistance please raise an issue in the repo and I will support as best I can.   


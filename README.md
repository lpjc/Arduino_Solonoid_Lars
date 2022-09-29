# Arduino_Solenoid_Lars
 One program for sending messages through tap'ing on surfaces.
 Three other custom programs for solonoid usage with Arduino

## ascii_enc_and_decode 
Two programs in one. 
Type a message in the serial port, and the solonoid will tap the message.
If hooked up to mic, the program detects the sound, and dechipher the taps to the priginal message in the serial port. 

To use this, place the solonoid and microphone on the same metal surface. 
The limits are depending on solenoid power, but it's tested to +100m

### Singel_button_morsecode_writer
Tap a button to make the solonoid tap
Tap lenght and pauses determine morse code: Dot, Dash or New Word

### EncoderASCIISolenoid
Tap a button to make the solonoid tap
Delay between the taps is translated into alphabetical characters in the log

### CicadaWithrythmbutton
Hold down one button, to recoard the taps of a solonoid made with another button. 
Release the buttons to make the solenoid play the recorded rythm continously

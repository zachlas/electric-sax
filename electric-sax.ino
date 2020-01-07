#include <Adafruit_NeoPixel.h>


#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioPlaySdWav           playSdWav1;     //xy=272.75000762939453,561.5000095367432
AudioInputI2S            line_in;            //xy=283.33331298828125,517.3333129882812
AudioMixer4              mixer1;         //xy=490.33331298828125,533.3333129882812
AudioAmplifier           amp_fft;           //xy=633.3333129882812,670.3333129882812
AudioAmplifier           amp_headphones; //xy=665.0000228881836,526.2500171661377
AudioAnalyzeFFT256       fft256_object;       //xy=833.600025177002,638.0000095367432
AudioAnalyzePeak         peak1;          //xy=814.6000061035156,741
AudioOutputI2S           headphone_out;           //xy=890.3332405090332,525.833309173584
AudioConnection          patchCord1(line_in, 0, mixer1, 0);
AudioConnection          patchCord2(line_in, 1, mixer1, 1);
AudioConnection          patchCord3(mixer1, amp_fft);
AudioConnection          patchCord4(mixer1, amp_headphones);
AudioConnection          patchCord5(amp_fft, fft256_object);
AudioConnection          patchCord6(amp_fft, peak1);
AudioConnection          patchCord7(amp_headphones, 0, headphone_out, 0);
AudioConnection          patchCord8(amp_headphones, 0, headphone_out, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=371.5833168029785,702.3333215713501
// GUItool: end automatically generated code





#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  11
#define SDCARD_SCK_PIN   13   // 12 also works, but 13 is the SCK and 12 is MISO... https://www.pjrc.com/store/teensy3_audio.html

#define LED_HEIGHT 8
#define LED_COLS   16


// ----------------------------------------------------------------------------------------
// -------------    LED Setup
// ----------------------------------
const int num_leds = 128;     // 16 wide by 8 high
const int led_control_pin = 1;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(num_leds, led_control_pin, NEO_GRB + NEO_KHZ800);
// ----------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------



void setup() {
  // Serial Communication setup
  Serial.begin(9600);

  // Audio Setup
  AudioMemory(12);   // previously 8
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);
    // Setup Micorphone
  sgtl5000_1.inputSelect(AUDIO_INPUT_LINEIN);
  sgtl5000_1.micGain(50);         // Makes peak at 0.5 out of 1
  mixer1.gain(0, 0.5);
  mixer1.gain(1, 0.5);

  // Setup FFT
  amp_fft.gain(2.00); // amp to FFT, gain doubles the mic to give more dynamics


  // SDCARD Setup
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
  delay(1000);

  // LED Setup
  pixels.begin();
}

void loop() {
  //playAudioSDCard();

  //colorTestGreen(4);
  //colorTestRed(2);

  runFFT_256(0.12,0);    // fft_vol_threshold, color_scheme
    
}

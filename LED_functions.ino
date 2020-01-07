







/*
// keep track of previous value of leds_to_light to only increment or de-incremenet by 1 LED blob
int previous_leds_to_light_array[LED_HEIGHT]={0};

void fillLEDBar_old(int col, float fft_value, int color_scheme, float fft_vol_threshold) {

  // For each column:
  //    1) Analyze percentage of it's loudness (fft_value) to the maximum loudness (fft_vol_threshold)
  //    2) Match that percentage to # of leds in the column to light up (if loudness = 3 and max is 10, then threshold is 30% and 2 of 8 LEDS should be displayed)
  //    3) Determine if current leds_to_light is lower, the same, or higher than the current value
  //    4) With # of LEDS to display, go through case statement to determine which specific ones to show depending on column

  // 1)
  float loudness_ratio = fft_value / fft_vol_threshold;   // range: 0 - inf
  if (loudness_ratio >= 1) { loudness_ratio = 1;}         // range: 0 - 1
  
  // 2)
  int leds_to_light = loudness_ratio * LED_HEIGHT;         // auto-rounds down. range: 0 - 8

  // 3)
  int up_same_down_led_change = leds_to_light - previous_leds_to_light_array[col];    //  negative number if need to lower an led, 0 if keep same, positive if add led to column

  // 4)

  if (up_same_down_led_change > 0)  {    // Add LED
    addLED(col < 8, col);
  }
  else if (up_same_down_led_change < 0 ) {   // Remove LED
    removeLED(col < 8, col);
  }
  else if (up_same_down_led_change == 0) {   // Keep LED
    //keepLED(col < 8, col);
  }

  previous_leds_to_light_array[col] = leds_to_light;    // update previous array 

}

void addLED(bool first_or_second_matrix, int col) {
  switch(first_or_second_matrix) {
    case true:    
      if (previous_leds_to_light_array[col] == 0)   { pixels.setPixelColor(0+col, pixels.Color(0,10,0));  }
      else                                          { pixels.setPixelColor(0+col, pixels.Color(0,0,0));    }
      if (previous_leds_to_light_array[col] == 1)  { pixels.setPixelColor(15-col, pixels.Color(0,10,0)); }
      else                                          { pixels.setPixelColor(15-col, pixels.Color(0,0,0)); }
      if (previous_leds_to_light_array[col] == 2)  { pixels.setPixelColor(16+col, pixels.Color(0,10,0)); }
      else                                          { pixels.setPixelColor(16+col, pixels.Color(0,0,0)); }
      if (previous_leds_to_light_array[col] == 3)  { pixels.setPixelColor(31-col, pixels.Color(0,10,0)); }
      else                                          { pixels.setPixelColor(31-col, pixels.Color(0,0,0)); }
      if (previous_leds_to_light_array[col] == 4)  { pixels.setPixelColor(32+col, pixels.Color(0,10,0)); }
      else                                          { pixels.setPixelColor(32+col, pixels.Color(0,0,0)); }
      if (previous_leds_to_light_array[col] == 5)  { pixels.setPixelColor(47-col, pixels.Color(0,10,0)); }
      else                                          { pixels.setPixelColor(47-col, pixels.Color(0,0,0)); }
      if (previous_leds_to_light_array[col] == 6)  { pixels.setPixelColor(48+col, pixels.Color(0,10,0)); }
      else                                          { pixels.setPixelColor(48+col, pixels.Color(0,0,0)); }
      if (previous_leds_to_light_array[col] == 7)  { pixels.setPixelColor(63-col, pixels.Color(0,10,0)); }
      else                                          { pixels.setPixelColor(63-col, pixels.Color(0,0,0)); }
      if (previous_leds_to_light_array[col] == 8)  { // do nothing
      }

      break;
      
    case false:
      if (previous_leds_to_light_array[col] == 0)  { pixels.setPixelColor(64+col, pixels.Color(0,10,0)); }
      else                                         { pixels.setPixelColor(64+col, pixels.Color(0,0,0)); }
      if (previous_leds_to_light_array[col] == 1)  { pixels.setPixelColor(79-col, pixels.Color(0,10,0)); }
      else                                          { pixels.setPixelColor(79-col, pixels.Color(0,0,0)); }
      if (previous_leds_to_light_array[col] == 2)  { pixels.setPixelColor(80+col, pixels.Color(0,10,0)); }
      else                                          { pixels.setPixelColor(80+col, pixels.Color(0,0,0)); }
      if (previous_leds_to_light_array[col] == 3)  { pixels.setPixelColor(95-col, pixels.Color(0,10,0)); }
      else                                          { pixels.setPixelColor(95-col, pixels.Color(0,0,0)); }
      if (previous_leds_to_light_array[col] == 4)  { pixels.setPixelColor(96+col, pixels.Color(0,10,0)); }
      else                                          { pixels.setPixelColor(96+col, pixels.Color(0,0,0)); }
      if (previous_leds_to_light_array[col] == 5)  { pixels.setPixelColor(111-col, pixels.Color(0,10,0)); }
      else                                          { pixels.setPixelColor(111-col, pixels.Color(0,0,0)); }
      if (previous_leds_to_light_array[col] == 6)  { pixels.setPixelColor(112+col, pixels.Color(0,10,0)); }
      else                                          { pixels.setPixelColor(112+col, pixels.Color(0,0,0)); }
      if (previous_leds_to_light_array[col] == 7)  { pixels.setPixelColor(127-col, pixels.Color(0,10,0)); }
      else                                          { pixels.setPixelColor(127-col, pixels.Color(0,0,0)); }
      if (previous_leds_to_light_array[col] == 8)  { // do nothing
        
      }

      break;   
  }

  
}


void removeLED(bool first_or_second_matrix, int col) {

}
*/


#define RED     0x220000  //0xE44040
#define GREEN   0x002200  //0x40E440
#define BLUE    0x000022  //0x406CE4  

#define LEDOFF  0x000000

void fillLEDBar(int col, float fft_value, int color_scheme, float fft_vol_threshold) {

  // For each column:
  //    1) Analyze percentage of it's loudness (fft_value) to the maximum loudness (fft_vol_threshold)
  //    2) Match that percentage to # of leds in the column to light up (if loudness = 3 and max is 10, then threshold is 30% and 2 of 8 LEDS should be displayed)
  //    3) With # of LEDS to display, go through case statement to determine which specific ones to show depending on column

  // 1)
  float loudness_ratio = fft_value / fft_vol_threshold;   // range: 0 - inf
  if (loudness_ratio >= 1) { loudness_ratio = 1;}         // range: 0 - 1
  
  // 2)
  int leds_to_light = loudness_ratio * LED_HEIGHT;         // auto-rounds down. range: 0 - 8

  // 3)
  switch(col < 8) {
    case true:
      if (leds_to_light >= 1)  { pixels.setPixelColor(0+col,  GREEN);  }
      else                     { pixels.setPixelColor(0+col,  LEDOFF);    }
      if (leds_to_light >= 2)  { pixels.setPixelColor(15-col, GREEN); }
      else                     { pixels.setPixelColor(15-col, LEDOFF); }
      if (leds_to_light >= 3)  { pixels.setPixelColor(16+col, GREEN); }
      else                     { pixels.setPixelColor(16+col, LEDOFF); }
      if (leds_to_light >= 4)  { pixels.setPixelColor(31-col, BLUE); }
      else                     { pixels.setPixelColor(31-col, LEDOFF); }
      if (leds_to_light >= 5)  { pixels.setPixelColor(32+col, BLUE); }
      else                     { pixels.setPixelColor(32+col, LEDOFF); }
      if (leds_to_light >= 6)  { pixels.setPixelColor(47-col, BLUE); }
      else                     { pixels.setPixelColor(47-col, LEDOFF); }
      if (leds_to_light >= 7)  { pixels.setPixelColor(48+col, RED); }
      else                     { pixels.setPixelColor(48+col, LEDOFF); }
      if (leds_to_light == 8)  { pixels.setPixelColor(63-col, RED); }
      else                     { pixels.setPixelColor(63-col, LEDOFF); }
      
      break;
      
    case false:
      if (leds_to_light >= 1)  { pixels.setPixelColor(64+col,  GREEN); }
      else                     { pixels.setPixelColor(64+col,  LEDOFF); }
      if (leds_to_light >= 2)  { pixels.setPixelColor(79-col,  GREEN); }
      else                     { pixels.setPixelColor(79-col,  LEDOFF); }
      if (leds_to_light >= 3)  { pixels.setPixelColor(80+col,  GREEN); }
      else                     { pixels.setPixelColor(80+col,  LEDOFF); }
      if (leds_to_light >= 4)  { pixels.setPixelColor(95-col,  BLUE); }
      else                     { pixels.setPixelColor(95-col,  LEDOFF); }
      if (leds_to_light >= 5)  { pixels.setPixelColor(96+col,  BLUE); }
      else                     { pixels.setPixelColor(96+col,  LEDOFF); }
      if (leds_to_light >= 6)  { pixels.setPixelColor(111-col, BLUE); }
      else                     { pixels.setPixelColor(111-col, LEDOFF); }
      if (leds_to_light >= 7)  { pixels.setPixelColor(112+col, RED); }
      else                     { pixels.setPixelColor(112+col, LEDOFF); }
      if (leds_to_light == 8)  { pixels.setPixelColor(127-col, RED); }
      else                     { pixels.setPixelColor(127-col, LEDOFF); }

      break;   
  }
  
  // enact changes
  pixels.show(); // This sends the updated pixel color to the hardware.  
}








void ledDelay() {
  delayMicroseconds(100000/(LED_HEIGHT*LED_COLS));
}



  
void colorTestGreen(int num_leds_to_flash) {
  for(int i=0;i<num_leds_to_flash;i++){
    pixels.setPixelColor(i, pixels.Color(0,10,0)); // Moderately bright green color.     // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
}

void colorTestRed(int num_leds_to_flash) {
  for(int i=0;i<num_leds_to_flash;i++){
    pixels.setPixelColor(i, pixels.Color(10,0,0)); // Moderately bright red color.     // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
}







































void updateLEDSaxMatrix_adjustable(int freq_highest, int led_rows, int led_height, int dispersion_rate, int fft_vol_threshold) {
/*
 *   int freq_highest     = 5000;     // in Hz. Determines the cutoff of where the LEDmatrix stops paying attention to FFT data
 *   const int led_rows   = 16;       // number of row in LEDmatrix. Number of buckets FFT data will be put into before display
 *   const int led_height = 8;        // number of columns in LEDmatrix. height of LEDMatrix
 *   int dispersion_rate  = 0;        // dictates how raw FFT buckets are distributed to led_rows....evenly, more buckets at highs, etc
 *   int fft_vol_threshold= 1;        // what value the fft bucket numbers must be to 'maxing out' the led_height
 */

  const int FFT_HIGHEST_FREQ=22000;                                 // 22kHz
  const int NUM_FFT_BUCKETS=128;                                    // 512 if using 1024 FFT
  const int FFT_INTERVAL = (FFT_HIGHEST_FREQ / NUM_FFT_BUCKETS);    // 172 or 43


  int fft_full_freq_array[NUM_FFT_BUCKETS];            // {172,322,513,684......,21546,21717}
  for (int i=0; i<NUM_FFT_BUCKETS; i++) {   fft_full_freq_array[i] = FFT_INTERVAL * i;   }
  
  int led_row_buckets[led_rows];      // array of led_rows length to hold summed fft bucket data in


  /////////////////////////// Code
  
  // Throw away FFT buckets we don't care about, above frequency highest
  int fft_part_length = freq_highest / FFT_INTERVAL;
  int fft_part_freq_array[fft_part_length];   
  for (int i=0; i<=fft_part_length; i++) {   fft_part_freq_array[i] = fft_full_freq_array[i];  }
  
}

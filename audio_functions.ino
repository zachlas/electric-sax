
  // FFT TYPE                 1024 FFT          256 FFT
  //
  // Buckets                  512               128
  // Bucket size              43 Hz             172 Hz             22 kHz / (samples/2)
  // Speed                    86 times/sec      344 times/sec
  // CPU Usage (Teensy 3.1)   52% peak          ??         
  
/*
  Type      Pitch (A=440) Concert pitch range (altisimo D)      Frequency Range (altisimo)
  Soprano   Bb            Ab3-E6  (-C7)                         207-1318   (-2093)
  Alto      Eb            Db3-A5  (-F6)                         138-880    (-1397)
  Tenor     Bb            Ab2-E5  (-C6)                         103-622    (-1047)
  Baritone  Eb            C2 -A4  (-F5)                         65 -440    (-698)  
*/
/*
                Frequency Ranges      https://www.teachmeaudio.com/mixing/techniques/audio-spectrum/

    Sub-Bass         Bass                Low Mid              Mid             Upper Mid        Presence (Treble)      Brilliance
  20Hz - 60Hz     60Hz - 250Hz        250Hz - 500Hz       500Hz - 2kHz        2kHz - 4kHz        4kHz - 6kHz         6kHz - 20 kHz
  power, felt    fatness, rhythm      bass presence     instruments, tinny   rhythm attack      sounds clarity         harmonics

 */


float prev_ema = 0;
float exponentialMovingAverage(float alpha, float new_val) {
  float  new_ema  = (alpha * new_val) + ( (1-alpha) * prev_ema );  // set new ema
  float  prev_ema = new_ema;                                       // set the previous ema for next time
  return new_ema;
}


float ema_fft_col_val=0;
void runFFT_256(float fft_vol_threshold, int color_scheme) {
 
  float led_col_buckets[16];      // array of led_rows length to hold summed fft bucket data in

  if (fft256_object.available()) {    
    for(int i=0;i<16;i++){
      led_col_buckets[i] = fft256_object.read(i);
    }

    // update status of all LEDs in led matrix 
    for(int current_col=0;current_col<LED_COLS;current_col++){                              // iterate over all led_rows
      ema_fft_col_val = exponentialMovingAverage(0.75, led_col_buckets[current_col]);        // calculate average
      if (current_col==1) { 
        Serial.println("----");
        Serial.println(led_col_buckets[current_col]); 
        Serial.println(ema_fft_col_val); 
        Serial.println("--------");
      }
      fillLEDBar(current_col, ema_fft_col_val, color_scheme, fft_vol_threshold);            // fill bar with weights
    }
    //ledDelay(); // add delay to smooth     
  }
}











/*
  int matrix = col%7;   // 0 if first matrix, 1 if second matrix, etc
  
  if (leds_to_light >= 1)  { pixels.setPixelColor((0+(64*matrix))+col,  GREEN);  }
  else                     { pixels.setPixelColor((0+(64*matrix))+col,  LEDOFF); }
  if (leds_to_light >= 2)  { pixels.setPixelColor((15+(64*matrix))-col, GREEN);  }
  else                     { pixels.setPixelColor((15+(64*matrix))-col, LEDOFF);  }
  if (leds_to_light >= 3)  { pixels.setPixelColor((16+(64*matrix))+col, GREEN);   }
  else                     { pixels.setPixelColor((16+(64*matrix))+col, LEDOFF);  }
  if (leds_to_light >= 4)  { pixels.setPixelColor((31+(64*matrix))-col, BLUE);    }
  else                     { pixels.setPixelColor((31+(64*matrix))-col, LEDOFF);  }
  if (leds_to_light >= 5)  { pixels.setPixelColor((32+(64*matrix))+col, BLUE);    }
  else                     { pixels.setPixelColor((32+(64*matrix))+col, LEDOFF);  }
  if (leds_to_light >= 6)  { pixels.setPixelColor((47+(64*matrix))-col, BLUE);    }
  else                     { pixels.setPixelColor((47+(64*matrix))-col, LEDOFF);  }
  if (leds_to_light >= 7)  { pixels.setPixelColor((48+(64*matrix))+col, RED);     } 
  else                     { pixels.setPixelColor((48+(64*matrix))+col, LEDOFF);  }
  if (leds_to_light == 8)  { pixels.setPixelColor((63+(64*matrix))-col, RED);     }
  else                     { pixels.setPixelColor((63+(64*matrix))-col, LEDOFF);  }

  
 */








void runFFT_256_old(float fft_vol_threshold, int color_scheme) {
 
  float led_col_buckets[16];      // array of led_rows length to hold summed fft bucket data in

  if (fft256_object.available()) {    
    for(int i=0;i<16;i++){
      led_col_buckets[i] = fft256_object.read(i);
    }

    // update status of all LEDs in led matrix 
    for(int current_col=0;current_col<LED_COLS;current_col++){    // iterate over all led_rows
      fillLEDBar(current_col,led_col_buckets[current_col],color_scheme,fft_vol_threshold);
    }
    //ledDelay(); // add delay to smooth     
  }
}


/*
  int loopcount = 0;
  int starttime = millis();
  int endtime = starttime;
  while ((endtime - starttime) <=1000) {  // 1 second loop
    //peakPrint();  
    loopcount = loopcount+1;
    endtime = millis();
  }
*/


void playAudioSDCard(void) {
    if (playSdWav1.isPlaying() == false) {
      Serial.println("Start playing SDCard audio.");
      playSdWav1.play("SDTEST2.WAV");
      delay(100); // wait for library to parse WAV info
  }
}

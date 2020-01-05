

void runFFT(void) {
  // FFT TYPE                 1024 FFT          256 FFT
  //
  // Bucket size              43 Hz             172 Hz             22 kHz / (samples/2)
  // Speed                    86 times/sec      344 times/sec
  // CPU Usage (Teensy 3.1)   52% peak          
  
  if (fft1024_object.available()) {    // 128 buckets     22kHz / 128 = 172 Hz           22kHz / 512 = 43 Hz buckets    returns 
    Serial.print("FFT: ");
    for (int i=0; i<30; i++) {  // 0-25  -->  DC to 1.25 kHz
      float n = fft1024_object.read(i);
      printNumber(n);
    }
    Serial.println();
  }
}

void printNumber(float n) {
  if (n >= 0.004) {
    Serial.print(n, 3);
    Serial.print(" ");
  } else {
    Serial.print("   -  "); // don't print "0.00"
  }
}

  
void peakPrint(void) {
  if (peak1.available()) {
      float leftNumber = peak1.read();
      int leftPeak = leftNumber * 30.0;
      int count;
      for (count=0; count < 30-leftPeak; count++) {
        Serial.print(" ");
      }
      while (count++ < 30) {
        Serial.print("<");
      }
      Serial.print("||");
      Serial.print(leftNumber);
      Serial.println();    
  }
}


void playAudioSDCard(void) {
    if (playSdWav1.isPlaying() == false) {
      Serial.println("Start playing SDCard audio.");
      playSdWav1.play("SDTEST2.WAV");
      delay(100); // wait for library to parse WAV info
  }
}

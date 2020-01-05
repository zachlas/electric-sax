  
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

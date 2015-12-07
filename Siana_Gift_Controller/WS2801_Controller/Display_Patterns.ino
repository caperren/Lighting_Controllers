#define FRAMES_PER_SECOND  120

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();
//SimplePatternList gPatterns = { rainbow, rainbowWithGlitter, confetti, sinelon, juggle, bpm };

void all_black(){
  for(int i = 0 ; i < NUM_LEDS ; i++){
    leds[i] = CRGB::Black;
  }
}

void all_green(){
  for(int i = 0 ; i < NUM_LEDS ; i++){
    leds[i] = CRGB::Green;
  }
}



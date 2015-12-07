#include <FastLED.h>
#include <Encoder.h>

////////// General Variables & Instantiations //////////
const unsigned int button_debounce = 300;

////////// LED Variables & Instantiations //////////
const int NUM_LEDS = 50;
CRGB leds[NUM_LEDS];
unsigned int led_brightness = 255 / 2;
volatile bool leds_on = true;

////////// Encoder Variables & Instantiations //////////
Encoder myEnc(0, 1);

////////// Button Variables & Instantiations //////////
const int ENCODER_BUTTON_PIN = 2;
const int ON_OFF_BUTTON_PIN = 3;

volatile bool encoder_button_pressed = false;
volatile bool on_off_button_pressed = false;

////////// Serial Variables & Instantiations //////////
const int serial_timeout = 5000; //Timeout in ms for attempting serial debugging
bool use_serial = false;

void setup() {
  attempt_serial_init();
  init_buttons();
  init_lights();


}

void loop() {
  check_on_off();
  //Check / Process Inputs
  //Check / Show Chosen Display
  if (leds_on) {
    check_brightness();
    check_mode_change();
    
    all_green();
    FastLED.show();
  } else {
    all_black();
    FastLED.show();
  }

}





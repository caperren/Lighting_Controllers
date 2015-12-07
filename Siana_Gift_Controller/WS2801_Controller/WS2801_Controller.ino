#include <FastLED.h>
#include <Encoder.h>

////////// LED Variables & Instantiations //////////
const int NUM_LEDS = 50;
CRGB leds[NUM_LEDS];
int led_brightness = 255 / 2;
volatile bool leds_on = true;

////////// Encoder Variables & Instantiations //////////
Encoder myEnc(0, 1);
long encoder_position_previous = 0;

////////// Button Variables & Instantiations //////////
const int ENCODER_BUTTON_PIN = 2;
const int ON_OFF_BUTTON_PIN = 3;

volatile bool encoder_button_pressed = false;
volatile bool on_off_button_pressed = false;
volatile bool on_off_timer_pressed = false;


////////// Serial Variables & Instantiations //////////
const int serial_timeout = 5000; //Timeout in ms for attempting serial debugging
bool use_serial = false;


////////// General Variables & Instantiations //////////
const unsigned int button_debounce = 400;

uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0; // rotating "base color" used by many of the patterns

unsigned int FRAMES_PER_SECOND = 120;
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

////////// Timer Variables & Instantiations //////////
const unsigned int timer_threshold = 1500; //
bool run_timer = false;
unsigned long timer_end_time;

////////// Prototypes for display patterns //////////
void rainbow();
void rainbowWithGlitter();
void confetti();
void sinelon();
void bpm();
void juggle();
void northern_lights();
void christmas();

// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { northern_lights, rainbow, rainbowWithGlitter, confetti, sinelon, juggle, bpm, christmas };

void setup() {
  attempt_serial_init();
  init_buttons();
  init_lights();
}

void loop() {
  check_on_off();
  check_timer_elapsed();
  if (leds_on){
    check_timer();
    check_mode_change();
    check_brightness_change();
    gPatterns[gCurrentPatternNumber]();
    FastLED.show();
    FastLED.delay(1000/FRAMES_PER_SECOND);
    
  } else {
    freeze_encoder();
    all_black();
    FastLED.show();
  }

}





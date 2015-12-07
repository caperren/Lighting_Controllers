void on_encoder_button_pressed() {
  if (!encoder_button_pressed) {
    if (use_serial) {
      Serial.println("Encoder Button Pressed");
    }
    encoder_button_pressed = true;
  }
}

void on_on_off_button_pressed() {
  if (!on_off_button_pressed) {
    if (use_serial) {
      Serial.println("ON/OFF Button Pressed");
    }
    on_off_button_pressed = true;
  }
}

void check_on_off() {
  if (on_off_button_pressed) {
    leds_on = !leds_on;
    delay(button_debounce);
    on_off_button_pressed = false;
  }
}

void check_brightness(){
  
}


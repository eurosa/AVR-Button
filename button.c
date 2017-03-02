#define F_CPU 1000000L

#include <avr/io.h>
#include <util/delay.h>

int main(void){

  DDRB |= 1 << PINB0;  // Data Direction Register output PINB0
  DDRB |= 1 << PINB2;  // Data Direction Register output PINB2
  PORTB ^= 1 << PINB0; // toggling only PINB0 on port B
  DDRB &= ~(1 << PINB1); // Data Direction Register input PINB1
  PORTB |= 1 << PINB1; // Set PINB1 to a high reading

  int pressed = 0;
  int pressed_confidence_level = 0;
  int released_confidence_level = 0;

  while (1) {

    // Checks if button has been pressed
    if (bit_is_clear(PINB, 1)){
      pressed_confidence_level ++;

      // Register as button presssed if condition met
      if (pressed_confidence_level > 200) {
        // Toggle which led is lit
        if (pressed == 0) {
          PORTB ^= 1 << PINB0;
          PORTB ^= 1 << PINB2;
          pressed = 1;
        }
        pressed_confidence_level = 0;
      }
    } else{
      released_confidence_level ++;
      // Register as button released if condition met
      if (released_confidence_level > 200) {
          pressed = 0;
          released_confidence_level = 0;
      }

    }
  }

  return 0;
}

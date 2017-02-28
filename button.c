#define F_CPU 1000000L

#include <avr/io.h>
#include <util/delay.h>

int main(void){

  DDRB |= 1 << PINB0;  // Data Direction Register output PINB0
  DDRB &= ~(1 << PINB1); // Data Direction Register input PINB1
  PORTB |= 1 << PINB1; // Set PINB1 to a high reading

  while (1) {
    /* code */
    PORTB ^= 1 << PINB0; // XOR (^) to toggle only pin 0 on port B

    if (bit_is_clear(PINB, 1)){
      _delay_ms(1000);
    } else{
      _delay_ms(10000); // Delay between toggling on and off at 100 ms
    }
  }

  return 0;
}

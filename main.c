/*
 * Laboving5_ADC.c
 *
 * Created: 12-Feb-19 8:39:53 AM
 * Author : erlen
 */ 

#define F_CPU 16e6
#define BAUDRATE 9600 // desired baud rate
#define UBRR_VALUE (((F_CPU / (BAUDRATE * 16UL))) -1)// UBRR value
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

void uart_init(void)
{
	UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);
	UBRR0 = UBRR_VALUE;
	UCSR0B = (1<<RXEN0) | (1<<TXEN0);
}

int uart_putchar(char c, FILE *STREAM)
{
	loop_until_bit_is_set(UCSR0A, UDRE0);
	UDR0 = c;
	return 0;
}

void INT_init(void);

int main(void)
{
	//Oppgave 1
	{  
// 	DDRB = 0xff; //Setter LEDs som utganger
//     DDRD = 0b00111111; // setter LEDs som utganger
// 		
//     ADCSRB  = 0; //Ønsker å bruke ANI1 som negativ inngang
//     ACSR = 0b01000000; // Analog comparator bandgap select
//     ADCSRA  = 0b11000000;
//     while (1) 
//     {
// 		if(ACSR & (1<<ACO)){ //leser ut resultat av ADC
// 			PORTB = (1<<3); //Setter PORTB3 høy hvis ADC skriver ut 1
// 		}
// 		else
//		PORTB = 0; //ellers skal alle LEDs være av
//}
	}
	//Oppgave 2
 	{
// 		//Setter PINMODE
// 		DDRB = 0xff;
// 		DDRD = 0xff;
// 			
// 		char data;
// 		
// 			//Setter opp ADC
// 		ADCSRA = (1<<ADEN) | (1<<ADPS2) |(1<<ADPS1) | (1<<ADPS0);
// 		ADMUX = (1<<REFS0) | (1<<ADLAR);
// 		
// 		while(1)
// 		{
// 			ADCSRA |= (1<<ADSC);
// 			
// 			loop_until_bit_is_clear(ADCSRA, ADSC);{		
// 		//	if(bit_is_clear(ADCSRA, ADSC)){
// 				
// 				data = ADCH;
// 				
// 				PORTB = (data>>4);
// 				PORTD = (data<<4);
// 				
// 			}
// 				
// 		}
// 			
// 			
	}
	//Oppgave 3
	{
		//Setter PINMODE
		DDRB = 0xff;
		DDRD = 0xff;

			
		//Setter opp ADC
		ADCSRA = (1<<ADEN) | (1<<ADIE) | (1<<ADPS2) |(1<<ADPS1) | (1<<ADPS0);
		ADMUX = (1<<REFS0) | (1<<ADLAR);
			
// 		uart_init();
// 		FILE uart_output = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
// 		stdout = &uart_output;
		
		INT_init();
		sei();
			
		while(1)
		{
			ADCSRA |= (1<<ADSC);
					
			
// 			loop_until_bit_is_clear(ADCSRA, ADSC);
// 			{	
// 					
// 				data = (ADC>>6); 
// 					
// 				PORTB = (data>>6);
// 				PORTD = (data<<2);
// 				
// 				printf("The value is: %u\r\n", data);
// 				
// 					
// 			}
		
		}	
	}

	//GARBAGE
	{
// 	DDRB = 0xff;
// 	DDRD = 0b11111100;
// 	//Setter opp ADC
// 	ADCSRA = (1<<ADEN) | (1<<ADPS2) |(1<<ADPS1) | (1<<ADPS0);
// 	ADMUX = (1<<REFS0) | (1<<ADLAR);
// 	
// 	char data;
// 	
// 	uart_init();
// 	FILE uart_output = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
// 	FILE uart_input = FDEV_SETUP_STREAM(NULL, uart_getchar, _FDEV_SETUP_READ);
// 	stdout = &uart_output;
// 	stdin = &uart_input;
// 	
// 	puts("Hello world!\r\n");
// 	
// 	char input;
// 	
// 	while(1)
// 	{
// 		ADCSRA |= (1<<ADSC);
// 		
// 		loop_until_bit_is_clear(ADCSRA, ADSC);
// 		data = ADCH;
// 		PORTB = (data>>4);
// 		PORTD = (data<<4);
// 		
// 		input=getchar();
// 		printf("%c",input);
// 
// 	}
// 	
// }
	}
}

void INT_init(void)
{
	PORTD = (1<<PORTD2);
	EICRA = (1<<ISC01);
	EIMSK = (1<<INT0);
	
}

ISR(_VECTOR(21))
{
	uint16_t data;
	data = (ADC>>6);
	PORTB = (data>>6);
	PORTD = (data<<2);
}
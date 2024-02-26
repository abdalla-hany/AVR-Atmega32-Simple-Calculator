/*
 * main.c
 *
 *  Created on: Feb 10, 2024
 *      Author: abdalla
 */

#include "lcd.h"
#include "keypad.h"
#include <util/delay.h>

int main (void)
{
    /* Initialize the LCD module */
	LCD_init();

	uint16 num1 = 0, num2 = 0; /* Initialize variables for operands */
	uint8 opert = 0, clear = 0; /* Initialize variables for operator and clearing the screen */

	while (1)
	{
		uint8 key = KEYPAD_getPressedKey(); /* Get the pressed key from the keypad */

		if (clear)
		{
			clear = 0; /* Reset clear flag */
			opert = 0; /* Reset operator */
			num1 = 0; /* Reset first operand */
			num2 = 0; /* Reset second operand */
			LCD_clearScreen(); /* Clear the LCD screen */
		}

		if (key >= '*' && key <= '/') /* Check if the key corresponds to an operator */
		switch (key)
		{
			case '*':
				LCD_displayCharacter('*'); /* Display '*' on the LCD */
				opert = '*'; /* Set operator to multiplication */
				break;
			case '+':
				LCD_displayCharacter('+'); /* Display '+' on the LCD */
				opert = '+'; /* Set operator to addition */
				break;
			case '-':
				LCD_displayCharacter('-'); /* Display '-' on the LCD */
				opert = '-'; /* Set operator to subtraction */
				break;
			case '/':
				LCD_displayCharacter('/'); /* Display '/' on the LCD */
				opert = '/'; /* Set operator to division */
				break;
		}

		else if (key >= 0 && key <= 9) /* Check if the key corresponds to a digit */
		{
			if (opert == 0)
			{
				num1 = (num1*10) + key; /* Build first operand */
			}
			else
			{
				num2 = (num2*10) + key; /* Build second operand */
			}
			LCD_intgerToString(key); /* Display the digit on the LCD */
		}
		else if (key == '=') /* Check if the key corresponds to the equals sign */
		{
			LCD_displayCharacter('='); /* Display '=' on the LCD */
			switch (opert) /* Perform operation based on the operator */
			{
				case '*':
					LCD_intgerToString(num1 * num2); /* Display the result of multiplication */
					clear = 1; /* Set clear flag to clear the screen */
					break;
				case '+':
					LCD_intgerToString(num1 + num2); /* Display the result of addition */
					clear = 1; /* Set clear flag to clear the screen */
					break;
				case '-':
					LCD_intgerToString(num1 - num2); /* Display the result of subtraction */
					clear = 1; /* Set clear flag to clear the screen */
					break;
				case '/':
					LCD_intgerToString(num1 / num2); /* Display the result of division */
					clear = 1; /* Set clear flag to clear the screen */
					break;
			}

		}
		else if (key == 13) /* Check if the key corresponds to the clear key */
		{
			LCD_clearScreen(); /* Clear the LCD screen */
			clear = 1; /* Set clear flag to clear the screen */
		}

		_delay_ms(500); /* Delay for stability */
	}
}

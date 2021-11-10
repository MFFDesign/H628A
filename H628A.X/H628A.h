/* 
 * File:   H628A.h
 * Author: ToncheLAP
 *
 * Created on November 9, 2021, 6:06 PM
 */

#ifndef H628A_H
#define	H628A_H

// CONFIG
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define HIGH 1
#define LOW 0
#define OUTPUT 0
#define INPUT 1
#define _XTAL_FREQ 8000000
#define BR2Kbps4 207
#define BR9Kbps6 51
#define BR19Kbps2 25
#define BR38Kbps4 12
#define BR57Kbps6 8

void ConfiguracionInicial(void);
void setup(void);
void loop(void);
void pinMode(char pin, char dir);
void digitalWrite(char pin,char value);
char digitalRead(char pin);
unsigned int analogRead(char pin);
void analogWrite(unsigned int value);
void SerialBegin(char BaudRate);
void SerialWrite(char data);
char SerialWriteText(char *dataText);
void SerialPrint(char *dataText);
void SerialPrintLn(char *dataText);
char SerialAvailable(void);
char SerialRead(void);
void SerialReadText(char *Output, unsigned int lenght);
void delay(unsigned int millis);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* H628A_H */


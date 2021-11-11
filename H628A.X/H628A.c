#include "H628A.h"

int main(void)
{
    ConfiguracionInicial();
    setup();
    for(;;)
    {
        loop();
    }
    return 0;
}
void ConfiguracionInicial(void)
{
    CCP1CON = 0x0C; //PWM Mode
    //1. Set the PWM Period by writing the PR2 Register
    PR2 = 0x64;
    //2. Set the PWM Duty Cycle by Writing the CCPR1L and CCP1CON <5:4>
    CCPR1L = 0x00;
    //3. Make CCP1 pin as output by clearing TRISB bit 3.
    //4. Set the TMR2 prescale Value and Enable timer 2
    // by wrintign T2CON
    T2CON = 0x07;
}
void pinMode(char pin, char dir)
{
    switch(pin)
    {
        case 0:
            TRISAbits.TRISA0 = dir;
            break;
        case 1:
            TRISAbits.TRISA1 = dir;
            break;
        case 2:
            TRISAbits.TRISA2 = dir;
            break;
        case 3:
            TRISAbits.TRISA3 = dir;
            break;
        case 4:
            TRISAbits.TRISA6 = dir;
            break;
        case 5:
            TRISAbits.TRISA7 = dir;
            break;
        case 6:
            TRISBbits.TRISB0 = dir;
            break;
        case 7:
            TRISBbits.TRISB1 = dir;
            break;
        case 8:
            TRISBbits.TRISB2 = dir;
            break;
        case 9:
            TRISBbits.TRISB3 = dir;
            break;
        case 10:
            TRISBbits.TRISB4 = dir;
            break;
        case 11:
            TRISBbits.TRISB5 = dir;
            break;
        case 12:
            TRISBbits.TRISB6 = dir;
            break;
        case 13:
            TRISBbits.TRISB7 = dir;
            break;
            
    }
}
void digitalWrite(char pin,char value)
{
    switch(pin)
    {
        case 0:
            PORTAbits.RA0 = value;
            break;
        case 1:
            PORTAbits.RA1 = value;
            break;
        case 2:
            PORTAbits.RA2 = value;
            break;
        case 3:
            PORTAbits.RA3 = value;
            break;
        case 4:
            PORTAbits.RA6 = value;
            break;
        case 5:
            PORTAbits.RA7 = value;
            break;
        case 6:
            PORTBbits.RB0 = value;
            break;
        case 7:
            PORTBbits.RB1 = value;
            break;
        case 8:
            PORTBbits.RB2 = value;
            break;
        case 9:
            PORTBbits.RB3 = value;
            break;
        case 10:
            PORTBbits.RB4 = value;
            break;
        case 11:
            PORTBbits.RB5 = value;
            break;
        case 12:
            PORTBbits.RB6 = value;
            break;
        case 13:
            PORTBbits.RB7 = value;
            break;
            
    }
}
char digitalRead(char pin)
{
    switch(pin)
    {
        case 0:
            return PORTAbits.RA0;
            break;
        case 1:
            return PORTAbits.RA1;
            break;
        case 2:
            return PORTAbits.RA2;
            break;
        case 3:
            return PORTAbits.RA3;
            break;
        case 4:
            return PORTAbits.RA6;
            break;
        case 5:
            return PORTAbits.RA7;
            break;
        case 6:
            return PORTBbits.RB0;
            break;
        case 7:
            return PORTBbits.RB1;
            break;
        case 8:
            return PORTBbits.RB2;
            break;
        case 9:
            return PORTBbits.RB3;
            break;
        case 10:
            return PORTBbits.RB4;
            break;
        case 11:
            return PORTBbits.RB5;
            break;
        case 12:
            return PORTBbits.RB6;
            break;
        case 13:
            return PORTBbits.RB7;
            break;
            
    }
}

void analogWrite(char value)
{
    CCPR1L = value;
}

void SerialBegin(char BaudRate)
{
	BRGH = 1;
    SYNC = 0;
    TRISB2 = 1;                                   //As Prescribed in Datasheet
    TRISB1 = 1;
    SPEN = 1;                                     //Enables Serial Port                                   //As Prescribed in Datasheet
    CREN = 1;                                     //Enables Continuous Reception
    TXEN = 1;
    TXREG = 0x00;
    RCREG = 0x00;
    switch(BaudRate)
    {
        case BR2Kbps4:
            SPBRG = BR2Kbps4;
            break;
        case BR9Kbps6:
            SPBRG = BR9Kbps6;
            break;
        case BR19Kbps2:
            SPBRG = BR19Kbps2;
            break;
        case BR38Kbps4:
            SPBRG = BR38Kbps4;
            break;
        case BR57Kbps6:
            SPBRG = BR57Kbps6;
            break;
        default:
            SPBRG = BR9Kbps6;
            break;
    }
}
void SerialWrite(char data)
{
    while(!TXIF);
    TXREG = data;
}

char SerialWriteText(char *dataText)
{
    unsigned int i;
    for(i=0;dataText[i]!='\0';i++)
    {
       SerialWrite(dataText[i]); 
    }
}
void SerialPrint(char *dataText)
{
    for(unsigned int i=0;dataText[i]!='\0';i++)
    {
        SerialWrite(dataText[i]);
    }
}
void SerialPrintLn(char *dataText)
{
    unsigned int i;
        for(i=0;dataText[i]!='\0';i++)
        {
            SerialWrite(dataText[i]);
        }
        SerialWrite(0x0A);
}
char SerialAvailable(void)
{
    return RCIF || (TXIF && TRMT);
}

char SerialRead(void)
{
    while(!RCIF);
    return RCREG;
}

void SerialReadText(char *Output, unsigned int lenght)
{
    unsigned int i;
    for(i=0;i<lenght;i++)
    {
        Output[i] = SerialRead();
    }
}

void delay(unsigned int millis)
{
    for(char i=0;i!=200;i++)
    {
        asm("NOP");
        asm("NOP");
        asm("NOP");
        asm("NOP");
        asm("NOP");
        asm("NOP");
        asm("NOP");
        asm("NOP");
        
    }
}

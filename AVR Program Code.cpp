#include <util/delay.h>
#define F_CPU 1000000UL //Clock frequency

class LCD
{
	public:
	reg *busPort;
	reg *modePort;
	char en, RS, RW
	
	LCD(reg*, reg*, char, char, char);
	
};

void delay_ms(uint16_t ms)
{
	uint16_t i = 0;
	
	for(;i < ms; i++)
	_delay_ms(1);
	
	return;
}
void delay_us(uint16_t us)
{
	uint16_t i = 0;
	
	for(;i < us; i++)
	_delay_us(1);
	
	return;
}

LCD(reg *busPort, reg *mode, char rs, char RW, char enable)
{
	
	reg *busDDR = busPort - 1;
	reg *modeDDR = mode - 1;
	
	*(busDDR) = 0xFF;
	*(modeDDR) = (1 << enable) | (1 << rs) | (1 << RW);
	*mode = 0 << enable;
	
	delay_ms(15);
	return;
}

void clearDisplay()
{
	*(busPort) = 0x01;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_ms(2);
	return;
}
void retHome()
{
	*(busPort) = 0x02;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_ms(2);
	return;
}
void decCursor()
{
	*(busPort) = 0x04;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_us(100);
	return;
}
void incCursor()
{
	*(busPort) = 0x06;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_us(100);
	return;
}
void dispRight()
{
	*(busPort) = 0x05;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_us(100);
	return;
}
void dispLeft()
{
	*(busPort) = 0x07;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_us(100);
	return;
}
void dispcurOff()
{
	*(busPort) = 0x08;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_us(100);
	return;
}
void dispOff()
{
	*(busPort) = 0x0A;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_us(100);
	return;
}
void curOff()
{
	*(busPort) = 0x0C;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_us(100);
	return;
}
void curBlink()
{
	*(busPort) = 0x0E;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_us(100);
	return;
}
void curLeft()
{
	*(busPort) = 0x10;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_us(100);
	return;
}
void curRight()
{
	*(busPort) = 0x14;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_us(100);
	return;
}
void entireDispLeft()
{
	*(busPort) = 0x18;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_us(100);
	return;
}
void entireDispRight()
{
	*(busPort) = 0x1C;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_us(100);
	return;
}
void toFirstLine()
{
	*(busPort) = 0x80;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_us(100);
	return;
}
void toSecLine()
{
	*(busPort) = 0xC0;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_us(100);
	return;
}
void fourBitMode()
{
	*(busPort) = 0x28;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_us(100);
	return;
}
void eightBitMode()
{
	*(busPort) = 0x38;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_us(100);
	return;
}
void initLCD8()
{
	eightBitMode();
	curBlink();
	clearDisplay();
	
	return;
}
void initLCD4()
{
	fourBitMode();
	curBlink();
	clearDisplay();
	
	return;
}

void writeData(char data)
{
	//char i = 0;
	
	//while(*(data + i) != '\0')
	//{
	*(busPort) = static_cast<reg>(data);
	*(mode) = (1 << enable) | (1 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (1 << rs) | (0 << RW);
	delay_us(100);
	
	//i++;
	//}
	
	return;
}
void writeString(const char* data)
{
	char i = 0;
	
	while(*(data + i) != '\0')
	{
		*(busPort) = static_cast<reg>(*data);
		*(mode) = (1 << enable) | (1 << rs) | (0 << RW);
		delay_us(0.5);
		*(mode) = (0 << enable) | (1 << rs) | (0 << RW);
		delay_us(100);
		
		i++;
	}
	
	return;
}
void writeCommand(const unsigned char cmd)
{
	*(busPort) = cmd;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_us(100);
	return;
}
void gotoxy(const unsigned char x, const unsigned char y)
{
	unsigned char firstColAddr[] = {0x80,0xC0}; //2x16LCD
	
	writeCommand(firstColAddr[y-1] + x -1); //This is effectively line number + x-offset
	
	return;
}

void delay_ms(uint16_t ms)
{
	uint16_t i = 0;
	
	for(;i < ms; i++)
	_delay_ms(1);
	
	return;
}

void delay_us(uint16_t us)
{
	uint16_t i = 0;
	
	for(;i < us; i++)
	_delay_us(1);
	
	return;
}

void clearDisplay()
{
	*(busPort) = 0x01;
	*(mode) = (1 << enable) | (0 << rs) | (0 << RW);
	delay_us(0.5);
	*(mode) = (0 << enable) | (0 << rs) | (0 << RW);
	
	delay_ms(2);
	return;
}


int main()
{
	LCD myLcd(&PORTA, &PORTD, 0,1,2);
	myLcd.initLcd8();
	char outputStr[] = "Muiz Alvi (263791), Haziq Arbab (247385)";
	unsigned char strLength = 30;

	while(1)
	{
		unsigned char i = 0;
		unsigned char start = 1;
		while(i <= 15)
		{
			myLcd.gotoxy(16, 1);	
			myLcd.writeData(outputStr[i]);
			delay_ms(200);
			myLcd.clearDisplay();
			myLcd.gotoxy(16-(i+1), 1);
			for(unsigned char g = 0; g <= i; g++)
			{
				myLcd.writeData(outputStr[g]);
			}
			i++;
				
		}
		myLcd.gotoxy(1, 1);
		for(unsigned char g = start; g <= i; g++)
		{
			myLcd.writeData(outputStr[g]);
		}
		start += 1;
		while(outputStr[i] != '\0')
		{
			myLcd.gotoxy(16, 1);
			myLcd.writeData(outputStr[i]);
			delay_ms(200);
			myLcd.clearDisplay();
			myLcd.gotoxy(1, 1);			
			for(unsigned char g = start; g <= i; g++)
			{
				myLcd.writeData(outputStr[g]);
			}
			start++;
			i++;
		}
		start--;
		i--;
		while(outputStr[start] != '\0')
		{
			delay_ms(200);
			myLcd.clearDisplay();
			myLcd.gotoxy(1, 1);
			for(unsigned char g = start; g <= i; g++)
			{
				myLcd.writeData(outputStr[g]);
			}
			start++;
		}
		
	}
}

#ifndef _MP3setup_H_
#define _MP3setup_H_

void playNextSong()// pin number 11 of mp3 player
{
	write(portd,6,h);
	write(portd,4,l);
	_delay_ms(50);
	write(portd,4,h);
}

void playPreviousSong()//pin number 9 of mp3 player
{
	
	write(portd,5,l);
	_delay_ms(50);
	write(portd,5,h);
}

void volumeInc()// pin number 11 of mp3 player
{
	write(portd,4,l);
	_delay_ms(1500);
	write(portd,4,h);
}
void volumeDec()// pin number 9 of mp3 player
{
	write(portd,5,l);
	_delay_ms(1500);
	write(portd,5,h);
}
void mp3_init()
{
	write(portd,6,h);
}
 
void StopSong()// power supply pin number 1 of mp3 player to pin number portd 6 of microcontroller
{	
	write(portd,6,l);
	
	
}
#endif 
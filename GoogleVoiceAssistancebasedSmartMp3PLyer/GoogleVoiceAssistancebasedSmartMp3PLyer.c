/////////////////////////////////////////////////////////////////////////////////////////////////////
///  Project Name : GoogleVoiceAssistancebasedSmartMp3PLyer
//
//  Target Board : atmega32
//
//  Date Created : 10-May-18 11:53:37 AM
//
//  Libraries Included : -->wifiadvanced 
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include<avr/io.h>
#include<util/delay.h>
#include "setup.h"
#include "MP3setup.h"
#include "serial.h"
#include "clobous.h"
#include "lcd.h"



int main()
{
	mp3_init();
	complete_setup();
	wifi_connect("asus","asus1234");
    lcd_string("wifi cntd");
    _delay_ms(1000);
	 int a=1;
	 
	while (1)
	{
		a=1;
		data_retrieve("vr",data);
		lcd_clear();
		lcd_string(data);
		lcd_clear();
		
		if(compare(data,"play_song"))
		{
			
			mp3_init();
			playNextSong();
			data_update("vr", a);
			
		}
		if(compare(data,"next_song"))
		{
			
			playNextSong();
			data_update("vr", a);
		}
		
		else  if(compare(data,"prev_song"))
		{
			
			playPreviousSong();
			data_update("vr", a);
			
		}
		else if(compare(data,"Inc_volume"))
		{
			volumeInc();
			data_update("vr", a);
		
		}
		else if(compare(data,"stop_song"))
		{
			StopSong();
			data_update("vr", a);
		
		}
		else if(compare(data,"Dec_volume"))
		{
			volumeDec();
			data_update("vr", a);
		
		}
		else
		{
			lcd_string("TRY Controlling things");
		}
		

		

	}

}
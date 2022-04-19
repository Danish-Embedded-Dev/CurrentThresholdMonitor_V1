#include "main.h"


void setup() {
   
#ifdef  WATCHDOG_ENABLE   
                              iwdg_init(IWDG_PRE_256,3500); //watch-dog 5000*0.0064 = 32000 ms
#endif//WATCH_ENABLE
#ifdef  DEBUGOUT
                              SetupSerialOut(); 
#endif//DEBUGOUT   
#ifdef I2C_ENABLE 
                              Setup_I2C(); 
#endif//I2C_ENABLE 
#ifdef  ExEEPROM_ENABLE
                              Init_EEPROM_Var(); //get EEPROM store parameter
#endif//ExEEPROM_ENABLE 
#ifdef  MODULE_CURRENT_EVENT
                              Config_IO();
#endif//MODULE_CURRENT_EVENT  
#ifdef  DHCP_ENABLE
                              ConnectWithDHCP();
#endif//DHCP_ENABLE    
#ifdef  CONFIG_PAGE_ENABLE
                              Local_server.begin(); 
#endif//CONFIG_PAGE_ENABLE
#ifdef  MQTT_ENABLE
                              Setup_Mqtt_Server();
#endif//MQTT_ENABLE  
#ifdef  NTP_ENABLE
                              Setup_Ntp_Server(); 
#endif//NTP_ENABLE
#ifdef  MODULE_CURRENT_EVENT 
                              set_Dynamic_ptr();   
                              emon1.current(0, 7.9,1.0890,-0.07012);             // Current: input pin, calibration.  
                              Enable_Timer_Interrupt(TIMER_INTERVAL);
#endif//MODULE_CURRENT_EVENT    

                              DEBUG_PRINTLN("Device Started"); 
}

void loop() { 

#ifdef  WATCHDOG_ENABLE    
   iwdg_feed(); //Feeding watch dog
#endif//WATCH_ENABLE   


#ifdef CONFIG_PAGE_ENABLE
    //if tcp-client is there launch a webpage
    EthernetClient client = Local_server.available();
    if (client) {
      Local_config_mode();
      Timer2.resume();
    }
    if(!login_page){ //turn of config page access after timeout 
      if((millis()- web_Prev_tm)>(config_timeout*1000)){
        login_page = true;
        DEBUG_PRINTLN("config_timeout");
      }
    }
#endif//CONFIG_PAGE_ENABLE 

#ifdef  MQTT_ENABLE  
  //---------Network-Status-Polling-----
   Link_up = bitRead(W5100.getPHYCFGR(), 0); //link up for ethernet 
   mqtt_connected = mqttclient.connected();

   //if button is pressed don't connect to mqtt 
   if(!digitalRead(config_switch)){mqtt_connected= true;}
   
  //--link and mqtt reconnection status -------------
   if (!mqtt_connected){   
      Reconnect(1); 
   } 
   
   mqttclient.loop(); //mqttclient connected  
#endif//MQTT_ENABLE

 
#ifdef MODULE_CURRENT_EVENT
   
   
  //At reconnection 
   if(Link_up && mqtt_connected){
      //-------if-detection---------
      if(packet_update){   
        mqtt_publish(EEPROM_DATA,ONLINE,alert_status); 
        packet_update = false; //packet sended     
      }

      //if data is in eeprom 
      if(running_val.dynamic_data_Ptr>0){//check data changed or not 
        EEPROM_READ(); //read EEPROM and send to mqtt 
        delay(10);
      }
   }
#endif//MODULE_CURRENT_EVENT

}

# Current_Sensor
## communication protocol 
* I2C_2 for eeprom and RTC communication 
* Serial_1 for TTL to RS-485 interface module  
* SPI_2 for ETHERNET 

## list of Hardware Used
| NAME  | README |
| ----- | ------ |
|stm32f103c8(bluepill) | https://circuitdigest.com/microcontroller-projects/getting-started-with-stm32-blue-pill-development-board-stm32f103c8-using-arduino-ide |
|TTL to RS-485| https://protosupplies.com/product/max485-ttl-to-rs-485-interface-module/#:~:text=RS%2D485%20provides%20for%20robust,can%20be%20supported%20comes%20down.  |
|ACS-712(0-5A)| https://www.seeedstudio.com/blog/2020/02/15/acs712-current-sensor-features-how-it-works-arduino-guide/  |
|W5500 module | https://www.majju.pk/product/w5500-ethernet-network-module-w5500-shield/ |
|DS3231 RTC-module | https://datasheets.maximintegrated.com/en/ds/DS3231.pdf|
|MP1584EN DC buck step down power module |https://www.utmel.com/components/mp1584en-step-down-converter-datasheet-pinout-and-circuit?id=241|

## Programing Feature
*  unique mac id generation
*  dynamic mqtt topics generation 
*  for every current change updated packet which contain last read current and epoch value 
*  in timer routine after every 100 ms RMS current is read and when ever current difference is maximum then threshold alert generate
*  configuration http webpage to configure device via browser 
*  when physical link down network led blink for 500ms interval and when mqtt-broker disconnect led blink for 1000ms interval
*  eeprom is used when broker down all packet will store to eeprom and send to network when device goes live again 
*  RTC is using to get real time epoch value 


## Programing New Feature
* Direct configuration webpage access on port 7104
* Once access to config_page it will automatically back to login page after timeout of 10 min
* dynamic mac address generator from stm32(uniqueID) hex format issue resolved
* device search for DHCP if not get it will asign itself a static ip of 192.168.4.1 and attempt dhcp in every 5 seconds 
* introduce network lost count instead of network loss or restart massage 

## Programing deleted Feature
* Ethernet blink after 3 seconds 
* hard disconnect from broker when physical link down 


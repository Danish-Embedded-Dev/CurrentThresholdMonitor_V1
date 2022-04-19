#ifdef DEBUGOUT
void SetupSerialOut(){
  #ifdef  USE_SERIAL    
    Serial.begin(baudrate); 
  #endif//USE_SERIAL    
  #ifdef  USE_SERIAL1  
    Serial1.begin(baudrate); 
  #endif//USE_SERIAL1   
  #ifdef  USE_SERIAL2 
    Serial2.begin(baudrate); 
  #endif//USE_SERIAL2 
  #ifdef  USE_SERIAL3  
    Serial3.begin(baudrate); 
  #endif//USE_SERIAL3  
  
  #ifdef  USE_MODSERIAL1 
    Serial1.begin(115200); 
  #endif//USE_MODSERIAL1 
  
}
#endif//DEBUGOUT


#ifdef  I2C_ENABLE
void Setup_I2C(){
  Wire.begin();   //start I2C wire protocol for EEPROM and RTC
}
#endif//I2C_ENABLE

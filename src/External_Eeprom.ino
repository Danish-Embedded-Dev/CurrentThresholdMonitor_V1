  //---------------Setting EEPROM ----------------------
#ifdef ExEEPROM_ENABLE
/*
   Init_EEPROM_Var will re-initialize the variable from EEPROM save data
*/
void Init_EEPROM_Var() {

  String Temp_mqtt_server = EE.eeprom_read_String(_ADDR_MQTT_Server);
  if (Temp_mqtt_server != "-1" ) {
    running_val.mqtt_server = Temp_mqtt_server;
  } else {
    EE.eeprom_write_String(_ADDR_MQTT_Server, default_val.mqtt_server );
    running_val.mqtt_server = default_val.mqtt_server;
  }

  int Temp_port = EE.eeprom_read_Int(_ADDR_Port);
  if (Temp_port != -1 ) {
    running_val.mqtt_port = Temp_port;
  } else {
    EE.eeprom_write_Int(_ADDR_Port, default_val.mqtt_port);
    running_val.mqtt_port = default_val.mqtt_port;
  }

  String Temp_NTP_server = EE.eeprom_read_String(_ADDR_NTP_Server);
  if (Temp_NTP_server != "-1" ) {
    running_val.NTPserver = Temp_NTP_server;
  } else {
    EE.eeprom_write_String(_ADDR_NTP_Server, default_val.NTPserver);
    running_val.NTPserver = default_val.NTPserver ;
  }

  String Temp_CompanyNm = EE.eeprom_read_String(_ADDR_CompanyNm);
  if (Temp_CompanyNm != "-1" ) {
    running_val.CompanyNm = Temp_CompanyNm;
  } else {
    EE.eeprom_write_String(_ADDR_CompanyNm, default_val.CompanyNm);
    running_val.CompanyNm = default_val.CompanyNm ;
  }

  String Temp_DepartNm = EE.eeprom_read_String(_ADDR_DepartNm);
  if (Temp_DepartNm != "-1" ) {
    running_val.DepartNm = Temp_DepartNm;
  } else {
    EE.eeprom_write_String(_ADDR_DepartNm, default_val.DepartNm);
    running_val.DepartNm = default_val.DepartNm ;
  }

  String Temp_DeviceNo = EE.eeprom_read_String(_ADDR_DeviceNo);
  if (Temp_DeviceNo != "-1" ) {
    running_val.DeviceNo = Temp_DeviceNo;
  } else {
    EE.eeprom_write_String(_ADDR_DeviceNo, default_val.DeviceNo);
    running_val.DeviceNo = default_val.DeviceNo ;
  }

  int Temp_Alert = EE.eeprom_read_Int(_ADDR_Alert_tm);
  if (Temp_Alert != -1 ) {
    running_val.Alert_tm = Temp_Alert;
  } else {
    EE.eeprom_write_Int(_ADDR_Alert_tm, default_val.Alert_tm);
    running_val.Alert_tm = default_val.Alert_tm;
  }

  int Temp_Delta_Curr = EE.eeprom_read_Int(_ADDR_Delta_Curr);
  if (Temp_Delta_Curr != -1 ) {
    running_val.Delta_Curr = Temp_Delta_Curr;
  } else {
    EE.eeprom_write_Int(_ADDR_Delta_Curr, default_val.Delta_Curr);
    running_val.Delta_Curr = default_val.Delta_Curr;
  }

  int Temp_Delta_tm = EE.eeprom_read_Int(_ADDR_Delta_tm);
  if (Temp_Delta_tm != -1 ) {
    running_val.Delta_tm = Temp_Delta_tm;
  } else {
    EE.eeprom_write_Int(_ADDR_Delta_tm, default_val.Delta_tm);
    running_val.Delta_tm = default_val.Delta_tm;
  }

  int Temp_CT_Ratio = EE.eeprom_read_Int(_ADDR_CT_Ratio);
  if (Temp_CT_Ratio != -1 ) {
    running_val.CT_Ratio = Temp_CT_Ratio;
  } else {
    EE.eeprom_write_Int(_ADDR_CT_Ratio, default_val.CT_Ratio);
    running_val.CT_Ratio = default_val.CT_Ratio;
  }

  DEBUG_PRINTLN("------------EEPROM_Var--------------");
  DEBUG_PRINT("NTP_server  :");  DEBUG_PRINTLN(Temp_NTP_server);
  DEBUG_PRINT("Mqtt_server :");  DEBUG_PRINTLN(Temp_mqtt_server);
  DEBUG_PRINT("Mqtt_port   :");  DEBUG_PRINTLN(Temp_port); 
  DEBUG_PRINT("CompanyNm   :");  DEBUG_PRINTLN(Temp_CompanyNm);
  DEBUG_PRINT("DepartNm    :");  DEBUG_PRINTLN(Temp_DepartNm);
  DEBUG_PRINT("DeviceNo    :");  DEBUG_PRINTLN(Temp_DeviceNo);
  DEBUG_PRINT("Alert_tm    :");  DEBUG_PRINTLN(Temp_Alert);
  DEBUG_PRINT("Delta_Curr  :");  DEBUG_PRINTLN(Temp_Delta_Curr);
  DEBUG_PRINT("Delta_tm    :");  DEBUG_PRINTLN(Temp_Delta_tm);
  DEBUG_PRINT("CT_Ratio    :");  DEBUG_PRINTLN(Temp_CT_Ratio);
  DEBUG_PRINTLN("------------Running_Var--------------");
  DEBUG_PRINT("NTP_server  :");  DEBUG_PRINTLN(running_val.NTPserver);
  DEBUG_PRINT("Mqtt_server :");  DEBUG_PRINTLN(running_val.mqtt_server);
  DEBUG_PRINT("Mqtt_port   :");  DEBUG_PRINTLN(running_val.mqtt_port);
  DEBUG_PRINT("dynamic_ptr :");  DEBUG_PRINTLN(running_val.dynamic_data_Ptr); 
  DEBUG_PRINT("CompanyNm   :");  DEBUG_PRINTLN(running_val.CompanyNm);
  DEBUG_PRINT("Alert_tm    :");  DEBUG_PRINTLN(running_val.Alert_tm);
  DEBUG_PRINT("Delta_Curr  :");  DEBUG_PRINTLN(running_val.Delta_Curr);
  DEBUG_PRINT("Delta_tm    :");  DEBUG_PRINTLN(running_val.Delta_tm);
  DEBUG_PRINT("CT_Ratio    :");  DEBUG_PRINTLN(running_val.CT_Ratio);
  DEBUG_PRINTLN("------------Default_Var--------------");
  DEBUG_PRINT("NTP_server  :");  DEBUG_PRINTLN(default_val.NTPserver);
  DEBUG_PRINT("Mqtt_server :");  DEBUG_PRINTLN(default_val.mqtt_server);
  DEBUG_PRINT("Mqtt_port   :");  DEBUG_PRINTLN(default_val.mqtt_port);
  DEBUG_PRINT("dynamic_ptr :");  DEBUG_PRINTLN(default_val.dynamic_data_Ptr); 
  DEBUG_PRINT("CompanyNm   :");  DEBUG_PRINTLN(default_val.CompanyNm);
  DEBUG_PRINT("DepartNm    :");  DEBUG_PRINTLN(default_val.DepartNm);
  DEBUG_PRINT("DeviceID    :");  DEBUG_PRINTLN(default_val.DeviceID);
  DEBUG_PRINT("DeviceNo    :");  DEBUG_PRINTLN(default_val.DeviceNo);
  DEBUG_PRINT("Alert_tm    :");  DEBUG_PRINTLN(default_val.Alert_tm);
  DEBUG_PRINT("Delta_Curr  :");  DEBUG_PRINTLN(default_val.Delta_Curr);
  DEBUG_PRINT("Delta_tm    :");  DEBUG_PRINTLN(default_val.Delta_tm);
  DEBUG_PRINT("CT_Ratio    :");  DEBUG_PRINTLN(default_val.CT_Ratio);
}

void set_Dynamic_ptr() {
  
  int dynamic_addr_ptr;
  byte data_header ;
  
  //check dynamic ptr
  for (int i = 0; i < TOTAL_PAGES; i++) {
    dynamic_addr_ptr = PAGE_BASE_ADDR + (i*PAGE_SIZE);
     
    data_header = EE.eeprom_read_Byte(dynamic_addr_ptr);

    if (data_header == sizeof(EEPROM_DATA)) {
      Serial.println(data_header);
      Serial.print("page      : "); Serial.println(i+1); 
      Serial.print("page Addr : "); Serial.println(dynamic_addr_ptr); 
      running_val.dynamic_data_Ptr = i+1;
    } else {
      break;
    }
  }
}

void EEPROM_WRITE() {
  int dynamic_addr_ptr = PAGE_BASE_ADDR + (running_val.dynamic_data_Ptr * PAGE_SIZE) ;

  if (dynamic_addr_ptr < EEPROM_Lenght) { //when eeprom range full donot add data
    EE.eeprom_write_Obj_P( dynamic_addr_ptr , &EEPROM_DATA, sizeof(EEPROM_DATA));
    running_val.dynamic_data_Ptr++; 
    } 
}

void EEPROM_READ() {
  int dynamic_addr_ptr = PAGE_BASE_ADDR +((running_val.dynamic_data_Ptr - 1) * PAGE_SIZE)   ;

  bool checksum = EE.Eeprom_read_Obj_P(dynamic_addr_ptr, &EEPROM_DATA); //READ DATA FROM EEPROM

  if (checksum == true) { //send data if checksum is true
    
    #ifdef  MQTT_ENABLE
    mqtt_publish(EEPROM_DATA ,OFFLINE,HIGH);
    #endif//MQTT_ENABLE
    
    DEBUG_PRINT(running_val.dynamic_data_Ptr); DEBUG_PRINTLN(": packet sended success");
  }

  EE.eeprom_write_Byte( dynamic_addr_ptr , 254); //packet disturb with 254  for last ptr
  running_val.dynamic_data_Ptr--;
}



#endif//ExEEPROM_ENABLE

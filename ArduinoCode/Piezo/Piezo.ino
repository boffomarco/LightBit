// http://www.ohnitsch.net/2015/03/18/measuring-heart-rate-with-a-piezoelectric-vibration-sensor/

// initial values to obtain the heart rate directly from piezo
int threshold = 60;
int oldvalue = 0;
int newvalue = 0;
unsigned long oldmillis = 0;
unsigned long newmillis = 0;
int cnt = 0;
int timings[16];

// Initial setting for communication frequency
void setup() {
  Serial.begin(57600); 
}

// Loop to iterate the readings
void loop() {
  oldvalue = newvalue;
  newvalue = 0;
  for(int i=0; i<64; i++){ // Average over 16 measurements
    newvalue += analogRead(A2);
  }
  newvalue = newvalue/64;
  // find triggering edge
  if(oldvalue<threshold && newvalue>=threshold){ 
    oldmillis = newmillis;
    newmillis = millis();
    // fill in the current time difference in ringbuffer
    timings[cnt%16]= (int)(newmillis-oldmillis); 
    int totalmillis = 0;
    // calculate average of the last 16 time differences
    for(int i=0;i<16;i++){
      totalmillis += timings[i];
    }
    // calculate heart rate
    int heartrate = 60000/(totalmillis/16);
    Serial.println(heartrate,DEC); // To be sent via bluetooth
    cnt++;
  }
  delay(5); // Wait (and sleep) before next epoch
}
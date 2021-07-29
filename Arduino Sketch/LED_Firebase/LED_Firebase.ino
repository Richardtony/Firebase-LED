#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "https://fir-led-48594-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "AtI8K7J7Df2U1pk4BEvhmY3uDJ3zENIgC1MqLpjC"

FirebaseData led_status;

#define led_pin 4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin("tony" , "NNFHTP7TE3");
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.print("Connected");
  Serial.println(WiFi.localIP());
  pinMode(led_pin , OUTPUT);
  Firebase.begin(FIREBASE_HOST , FIREBASE_AUTH);  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Firebase.getString(led_status , "/FirebaseLED/LED_STATUS")){
    if (led_status.stringData() == "on" ){
      digitalWrite(led_pin , HIGH);
    }
    else if (led_status.stringData() == "off"){
      digitalWrite(led_pin , LOW);
    }
  }

  else{
    Serial.println("Firebase didn't detect any data");
    Serial.println(led_status.errorReason());
  }
}

#include <Adafruit_CircuitPlayground.h>

int sum_1 = 0;
int sum_2 = 0;
int sum_3 = 0;
int ctr = 0;

///////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  //delay(20000);
}

///////////////////////////////////////////////////////////////////////////////
void loop() {
  if(ctr!= 100001){
  sum_1 = analogRead(A3);
  sum_2 = analogRead(A6);
  sum_3 = 0.9*sum_3 + 0.1*analogRead(A7);
  ctr++;
  }

  Serial.print("A3: ");
  Serial.println(sum_1);
  Serial.print("A6: ");
  Serial.println(sum_2);
  Serial.print("A7: ");
  Serial.println(sum_3);
  delay(500);
}
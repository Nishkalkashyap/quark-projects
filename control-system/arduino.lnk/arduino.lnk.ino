String inputString = "";
int ledPin = 9;

int red = 0;
int green = 0;
int blue = 0;
int num = 0;
int pwm1 = 0;
int pwm2 = 0;




void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  pinMode(ledPin, OUTPUT);
  inputString.reserve(200);
}

void loop() {

  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {

      red = getValue(inputString, '-', 0);
      green = getValue(inputString, '-', 1);
      blue = getValue(inputString, '-', 2);
      num = getValue(inputString, '-', 3);
      pwm1 = getValue(inputString, '-', 4);
      pwm2 = getValue(inputString, '-', 5);



      inputString = "";
    } else {
      inputString += inChar;
    }
  }

}

int getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  String returnVal =  found > index ? data.substring(strIndex[0], strIndex[1]) : "";
  returnVal.toInt();
}

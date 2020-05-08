#include <SPI.h>

const int mosi = 13;
const int miso = 12;
const int sck = 14;
const int cs = 15;

volatile long Lval;
volatile float Fval;

void setup() {
  Serial.begin(9600);
  

}

void loop() {
  Serial.println(ATT("0x01"));
  delay(2000);
}

long SPIRead(unsigned char Cmd) {
  int n;
  long data;

  data = 0;
  digitalWrite(cs, LOW);

  for (n = 7; n >= 0; n--)
  {
    digitalWrite(sck, HIGH);
    digitalWrite(mosi, (Cmd & (1 << n)) >> n);
    digitalWrite(sck, LOW);
  }
  delayMicroseconds(5);
  for (n = 23; n >= 0; n--)
  {
    digitalWrite(sck, HIGH);
    data = data | (digitalRead(miso) << n);
    digitalWrite(sck, LOW);
  }
  digitalWrite(cs, HIGH);
  return data;
}

void SPIWrite(unsigned char Cmd, long val) {
  int n;

  digitalWrite(cs, HIGH);
  digitalWrite(sck, LOW);
  digitalWrite(cs, LOW);

  for (int n = 7; n >= 0; n--)
  {
    digitalWrite(sck, HIGH);
    digitalWrite(mosi, (Cmd & (1 << n)) >> n);
    digitalWrite(sck, LOW);
  }
  for (int n = 23; n >= 0; n--)
  {
    digitalWrite(sck, HIGH);
    asm("nop");
    asm("nop");
    asm("nop");
    digitalWrite(mosi, (val & (1 << n)) >> n);
    digitalWrite(sck, LOW);
  }
  digitalWrite(cs, HIGH);
}

long ReadSampleRegister(unsigned char cmd) {
  long datatemp;

  datatemp = 0;
  SPIWrite(0xC6, 0x00000);
  delayMicroseconds(50);

  datatemp = SPIRead(cmd);

  return datatemp;
}

String ATT(String command) {
  pinMode(mosi, OUTPUT);
  pinMode(miso, INPUT);
  pinMode(sck, OUTPUT);
  pinMode(cs, OUTPUT);

  digitalWrite(cs, HIGH);
  digitalWrite(sck, LOW);
  digitalWrite(mosi, LOW);
  if (command == "0x01") {
    Lval = ReadSampleRegister(0x01);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 15)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x02") {
    Lval = ReadSampleRegister(0x02);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 15)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x03") {
    Lval = ReadSampleRegister(0x03);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 15)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x04") {
    Lval = ReadSampleRegister(0x04);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 17)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x05") {
    Lval = ReadSampleRegister(0x05);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 15)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x06") {
    Lval = ReadSampleRegister(0x06);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 15)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x07") {
    Lval = ReadSampleRegister(0x07);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 15)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x08") {
    Lval = ReadSampleRegister(0x08);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 17)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x09") {
    Lval = ReadSampleRegister(0x09);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 15)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x0A") {
    Lval = ReadSampleRegister(0x0A);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 15)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x0B") {
    Lval = ReadSampleRegister(0x0B);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 15)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x0C") {
    Lval = ReadSampleRegister(0x0C);
    if (Lval > pow(2, 23)) {
      Lval = Lval - pow(2, 24);
    }
    Fval = (Lval * pow(2, 17)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x0D") {
    Lval = ReadSampleRegister(0x0D);
    Fval = (Lval * pow(2, 10)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x0E") {
    Lval = ReadSampleRegister(0x0E);
    Fval = (Lval * pow(2, 10)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x0F") {
    Lval = ReadSampleRegister(0x0F);
    Fval = (Lval * pow(2, 10)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x10") {
    Lval = ReadSampleRegister(0x10);
    Fval = (Lval * pow(2, 10)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x11") {
    Lval = ReadSampleRegister(0x11);
    Fval = (Lval * pow(2, 10)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x12") {
    Lval = ReadSampleRegister(0x12);
    Fval = (Lval * pow(2, 10)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x13") {
    Lval = ReadSampleRegister(0x13);
    Fval = (Lval * pow(2, 10)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x29") {
    Lval = ReadSampleRegister(0x29);
    Fval = (Lval * pow(2, 10)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x2B") {
    Lval = ReadSampleRegister(0x2B);
    Fval = (Lval * pow(2, 10)) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x14") {
    Lval = ReadSampleRegister(0x14);
    if (Lval > pow(2, 23)) {
      Lval -= pow(2, 24);
    }
    Fval = (Lval) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x15") {
    Lval = ReadSampleRegister(0x15);
    if (Lval > pow(2, 23)) {
      Lval -= pow(2, 24);
    }
    Fval = (Lval) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x16") {
    Lval = ReadSampleRegister(0x16);
    if (Lval > pow(2, 23)) {
      Lval -= pow(2, 24);
    }
    Fval = (Lval) / pow(2, 23);
    return String(Fval);
  }
  else if (command == "0x17") {
    Lval = ReadSampleRegister(0x17);
    if (Lval > pow(2, 23)) {
      Lval -= pow(2, 24);
    }
    Fval = (Lval) / pow(2, 23);
    return String(Fval);
  }
  else {
    return "Error";
  }
}

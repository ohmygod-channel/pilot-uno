// Pilot OS for Arduino UNO
// Version 0.1 (CODENAMED RETROWARE)

char buff[100], i;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(15000);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(i=0;i<100;i++) buff[i]=0;
  Serial.print("PILOT>");
  readstr();
  if (buff[0]!=0){
    if((buff[0]=='s') && (buff[1]=='e') && (buff[2]=='t')) setpin();
    else if((buff[0]=='c') && (buff[1]=='l') && (buff[2]=='r')) clrpin();
    else if((buff[0]=='i') && (buff[1]=='n')) inpin();
    else if((buff[0]=='o') && (buff[1]=='u') && (buff[2]=='t')) outpin();
    else if((buff[0]=='d') && (buff[1]=='e') && (buff[2]=='l') && (buff[3]=='a') && (buff[4]=='y')) delay_cmd();
    else if((buff[0]=='s') && (buff[1]=='o') && (buff[2]=='u') && (buff[3]=='n') && (buff[4]=='d')) sound();
    else if((buff[0]=='m') && (buff[1]=='i') && (buff[2]=='d') && (buff[3]=='i')) midi();
    else {
      Serial.print("Unknown command: ");
      Serial.print(buff);
      Serial.print("\r\n");
    }
  }
  else Serial.print("\r\n");
}

void readstr() {
  char bchr, eos=0, i=0;
  while(eos==0) {
    if(Serial.available() > 0) {
      bchr = Serial.read();
      if(bchr=='\r') eos=1;
      else buff[i] = bchr;
      i++;
    }
  }
}

void setpin() {
  int pin;
  Serial.print("Which pin do you want to set? (type in 255 or wait for 15 seconds to exit)");
  pin = Serial.parseInt();
  if(pin!=255) {
    if(pin > 19) Serial.println("Invalid pin!\r\n");
    else {
      if(pin<14) {
        pinMode(pin, 1);
        digitalWrite(pin, HIGH);
        Serial.println("Done!\r\n");
      }
      else {
        switch(pin) {
          case 14: pinMode(A0, 1); digitalWrite(A0, HIGH); break;
          case 15: pinMode(A1, 1); digitalWrite(A1, HIGH); break;
          case 16: pinMode(A2, 1); digitalWrite(A2, HIGH); break;
          case 17: pinMode(A3, 1); digitalWrite(A3, HIGH); break;
          case 18: pinMode(A4, 1); digitalWrite(A4, HIGH); break;
          case 19: pinMode(A5, 1); digitalWrite(A5, HIGH); break;
        }
        Serial.println("Done!\r\n");
      }
    }
  }
  else Serial.println("Program exited!\r\n");
}

void clrpin() {
  int pin;
  Serial.print("Which pin do you want to clear? (type in 255 or wait for 15 seconds to exit) ");
  pin = Serial.parseInt();
  if(pin!=255) {
    if(pin > 19) Serial.println("Invalid pin!\r\n");
    else {
      if(pin<14) {
        pinMode(pin, 1);
        digitalWrite(pin, LOW);
        Serial.println("Done!\r\n");
      }
      else {
        switch(pin) {
          case 14: pinMode(A0, 1); digitalWrite(A0, LOW); break;
          case 15: pinMode(A1, 1); digitalWrite(A1, LOW); break;
          case 16: pinMode(A2, 1); digitalWrite(A2, LOW); break;
          case 17: pinMode(A3, 1); digitalWrite(A3, LOW); break;
          case 18: pinMode(A4, 1); digitalWrite(A4, LOW); break;
          case 19: pinMode(A5, 1); digitalWrite(A5, LOW); break;
        }
        Serial.println("Done!\r\n");
      }
    }
  }
  else Serial.println("Program exited!\r\n");
}

void inpin() {
  int pin;
  Serial.print("Which pin do you want to set as input? (type in 255 or wait for 15 seconds to exit) ");
  pin = Serial.parseInt();
  if(pin!=255) {
    if(pin > 19) Serial.println("Invalid pin!\r\n");
    else {
      if(pin<14) {
        pinMode(pin, 0);
        Serial.println("Done!\r\n");
      }
      else {
        switch(pin) {
          case 14: pinMode(A0, 0); break;
          case 15: pinMode(A1, 0); break;
          case 16: pinMode(A2, 0); break;
          case 17: pinMode(A3, 0); break;
          case 18: pinMode(A4, 0); break;
          case 19: pinMode(A5, 0); break;
        }
        Serial.println("Done!\r\n");
      }
    }
  }
  else Serial.println("Program exited!\r\n");
}

void outpin() {
  int pin;
  Serial.print("Which pin do you want to set as output? (type in 255 or wait for 15 seconds to exit) ");
  pin = Serial.parseInt();
  if(pin!=255) {
    if(pin > 19) Serial.println("Invalid pin!\r\n");
    else {
      if(pin<14) {
        pinMode(pin, 1);
        Serial.println("Done!\r\n");
      }
      else {
        switch(pin) {
          case 14: pinMode(A0, 1); break;
          case 15: pinMode(A1, 1); break;
          case 16: pinMode(A2, 1); break;
          case 17: pinMode(A3, 1); break;
          case 18: pinMode(A4, 1); break;
          case 19: pinMode(A5, 1); break;
        }
        Serial.println("Done!\r\n");
      }
    }
  }
  else Serial.println("Program exited!\r\n");
}

void delay_cmd() {
  int t;
  Serial.print("How long do you want to delay? (type in 0 or wait for 15 seconds to exit) ");
  t = Serial.parseInt();
  if(t==0) Serial.println("Program exited!\r\n");
  else {
    delay(t);
    Serial.println("Done!\r\n");
  }
}

void sound() {
  int f, t;
  Serial.print("Type in the frequency: ");
  f = Serial.parseInt();
  Serial.print("Type in the duration: ");
  t = Serial.parseInt();
  Serial.println("Enjoy!");
  tone(8, f, t);
  delay(t);
  noTone(8);
  Serial.println("Done!\r\n");
}

void midi() {
  unsigned char cmd, pitch, velocity;
  Serial.println(" *** MIDI COMMANDER *** ");
  Serial.print("Command? ");
  cmd = Serial.parseInt();
  Serial.print("Pitch/note? ");
  pitch = Serial.parseInt();
  Serial.print("Velocity? ");
  velocity = Serial.parseInt();
  Serial.println("Please hook up the system to a MIDI synth.");
  Serial.println("Press the button on the system when you're ready.");
  Serial.println("Please do not disconnect the system out of the MIDI synth until the LED is off.");
  Serial.println("When the LED is off, connect the system to the terminal and press the button again.");
  pinMode(2, 0);
  pinMode(13, 1);
  digitalWrite(2, 1);
  while(digitalRead(2));
  while(!digitalRead(2));
  digitalWrite(13, 1);
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
  digitalWrite(13, 0);
  while(digitalRead(2));
  while(!digitalRead(2));  
  Serial.println("\r\nDone!\r\n");
}


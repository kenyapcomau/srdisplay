/*
   Test shift register display
*/

#define DATA    2
#define CLOCK   3
#define LOAD    4

#undef	COUNTER
#define	LOWON

void setup() {
  // put your setup code here, to run once:
  pinMode(DATA, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LOAD, OUTPUT);
  digitalWrite(DATA, LOW);
  digitalWrite(CLOCK, LOW);
  digitalWrite(LOAD, LOW);
}

void writebyte(unsigned int i) {
  for (byte mask = 0x80; mask != 0; mask >>= 1) {
#ifdef	LOWON
    digitalWrite(DATA, i & mask ? LOW : HIGH);
#else
    digitalWrite(DATA, i & mask ? HIGH : LOW);
#endif	// LOWON
    delayMicroseconds(10);
    digitalWrite(CLOCK, HIGH);
    delayMicroseconds(10);
    digitalWrite(CLOCK, LOW);
    delayMicroseconds(10);
  }
}

void load() {
  digitalWrite(LOAD, HIGH);
  delayMicroseconds(10);
  digitalWrite(LOAD, LOW);
  delayMicroseconds(10);
}

void write2bytes(unsigned int i, unsigned int j) {
  writebyte(i);		// MSB
  writebyte(j);		// LSB
  load();
}

void loop() {
  // put your main code here, to run repeatedly:
#ifdef	COUNTER
  for (unsigned int i = 0; i < 256; i++) {
    write2bytes(i, i);
    delay(250);
  }
#else
  for (unsigned char hour = 0; hour < 24; hour++) {
    for (unsigned char minute = 0; minute < 60; minute++) {
       write2bytes(minute, hour);
       delay(250);
    }
  }
#endif	// COUNTER
}

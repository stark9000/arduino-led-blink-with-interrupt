int LED = 5;

void setup() {
  pinMode(LED, OUTPUT);
  noInterrupts();
  //init timer1 
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 31250; //compare match register 16Mhz/256/2Hz
  TCCR1B |= (1 << WGM12);//ctc mode
  TCCR1B |= (1 << CS12);//256 prescaler
  TIMSK1 |= (1 << OCIE1A);//enable timer compare interrupt
  interrupts();
}

ISR(TIMER1_COMPA_vect) {
  digitalWrite(LED, digitalRead(LED) ^ 1);
}

void loop() {

}

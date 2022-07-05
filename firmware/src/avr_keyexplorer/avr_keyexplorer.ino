/*
 * This is and AVR firmware source code for "Unikeyboard explorer" (keyboard matrix scanning software).
 * Scans any keyboard of up to 26 pins and generates the debug output on UART for col/row of key pressed.
 * 
 * Based on AVR keyboard firmware for ps2_cpld_kbd project
 * @author Andy Karpov <andy.karpov@gmail.com>
 * Ukraine, 2019
 * 
 * Ported to ATMega32 and redesigned for custom keyboard matrix by Valeriy Matveyev
 * valerium@rambler.ru
 * Russia, 2021
 * 
 */

#define PINS_MAX 27

#define PIN1 PIN_PD2
#define PIN2 PIN_PD3
#define PIN3 PIN_PD4
#define PIN4 PIN_PD5
#define PIN5 PIN_PD6
#define PIN6 PIN_PD7
#define PIN7 PIN_PC0
#define PIN8 PIN_PC1
#define PIN9 PIN_PC2
#define PIN10 PIN_PC3
#define PIN11 PIN_PC4
#define PIN12 PIN_PC5
#define PIN13 PIN_PC6
#define PIN14 PIN_PC7
#define PIN15 PIN_PA7
#define PIN16 PIN_PA6
#define PIN17 PIN_PA5
#define PIN18 PIN_PA4
#define PIN19 PIN_PA3
#define PIN20 PIN_PA2
#define PIN21 PIN_PA1
#define PIN22 PIN_PA0
#define PIN23 PIN_PB0
#define PIN24 PIN_PB1
#define PIN25 PIN_PB2
#define PIN26 PIN_PB3
#define PIN27 PIN_PB4

const uint8_t pins[PINS_MAX] = 
{
  PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7, PIN8, PIN9, PIN10, 
  PIN11, PIN12, PIN13, PIN14, PIN15, PIN16, PIN17, PIN18, PIN19, PIN20,
  PIN21, PIN22, PIN23, PIN24, PIN25, PIN26, PIN27
};


// initial setup
void setup()
{
  for (uint8_t i=0; i<PINS_MAX; i++) pinMode (pins[i], INPUT_PULLUP);

  Serial.begin(115200);
  Serial.flush();
  Serial.println(F("Unikeyboard matrix explorer v1.0"));
}

// main loop
void loop()
{
  uint8_t colcount, rowcount;

  for (colcount=0; colcount<PINS_MAX; colcount++)
   {
     for (rowcount=0; rowcount<PINS_MAX; rowcount++) pinMode (pins[rowcount], INPUT_PULLUP);
     
     pinMode (pins[colcount], OUTPUT);
     digitalWrite (pins[colcount], LOW);
     
     for (rowcount=0; rowcount<PINS_MAX; rowcount++)
              if ( (rowcount != colcount) and !digitalRead(pins[rowcount]) )
                  {
                  Serial.println ("Pressed key ("+String((colcount<rowcount?colcount:rowcount)+1)+", "+String((colcount<rowcount?rowcount:colcount)+1)+")");
                  delay (300);
                  }
   }
}

#include <Adafruit_NeoPixel.h>    // importa libreria, debe indtalarla previamente

/*Debe instalar la libreria "Adafruit_NeoPixel.h" para que funcione el programa
Conexiones:
ARDUINO   TIRA LED
  5V        +5V ROJO
  GND       GND BLANCO
  3         Din Verde
*/

int Columns=16;
int Rows=16;
int nleds=256;  // Numero de LEDs a Probar
int retardo = 50; // más alto mas lenta la secuencia
int brillo = 20; // Brillo del LED
String Command=""; 

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

Adafruit_NeoPixel tira = Adafruit_NeoPixel(nleds, 3, NEO_GRB + NEO_KHZ800);  // Pin 3 del Arduino es salida de datos

void setup() {
    nleds = (Columns) * (Rows);
    tira.begin();       // inicializacion de la tira
    tira.show();
    Serial.begin(9600);
    while (!Serial) 
    {
    }
    Clear_Panel();
    Serial.println("Ready!!");
    //Pixel_Check();
    inputString.reserve(200);
    tira.setBrightness(brillo);
    Set_Pixel(7, 7, 255, 255, 255); //Red
}

void loop()
{
    ////////////////////////////////////////////////////

     // print the string when a newline arrives:
    if (stringComplete)
    {
        Serial.println(inputString);
        // clear the string:
        /////////////////////////////////////////////////////////////////////////
        /// COMMAND: SP C[Column] R[Row] r[Red] r[Green] r[Blue]
        /// RGB Values Between 0 - 255
        /// Example: SP C3 R2 r255 g255 b255
        SerialParse(inputString);

        /////////////////////////////////////////////////////////////////////////
        inputString = "";
        stringComplete = false;
    }
    //Sparkles();
    //Set_Pixel(0, 0, 255, 0, 0); //Red
    //Set_Pixel(7, 0, 255, 0, 0); //Red
    //Set_Pixel(0, 7, 255, 0, 0); //Red
    //Set_Pixel(7, 7, 255, 0, 0); //Red

    //Set_Pixel(8, 0, 0, 255, 0); //Green
    //Set_Pixel(15, 0, 0, 255, 0); //Green
    //Set_Pixel(8, 7, 0, 255, 0); //Green
    //Set_Pixel(15, 7, 0, 255, 0); //Green

    //Set_Pixel(0, 8, 0, 0, 255); //Blue
    //Set_Pixel(7, 8, 0, 0, 255); //Blue
    //Set_Pixel(0, 15, 0, 0, 255); //Blue
    //Set_Pixel(7, 15, 0, 0, 255); //Blue

    //Set_Pixel(15, 8, 255, 255, 0); //Yellow
    //Set_Pixel(8, 15, 255, 255, 0); //Yellow
    //Set_Pixel(15, 15, 255, 255, 0); //Yellow
    //Set_Pixel(8, 8, 255, 255, 0); //Yellow
    //delay(100);
    ////////////////////////////////////////////////////////
}
/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent()
{
    //int counter = 0;
    char inChar;
    while (Serial.available())
    {
        inputString = Serial.readString();
    }
       /* Serial.print("Finish Serial Event:");
        Serial.println(inputString);*/
        stringComplete = true;
}

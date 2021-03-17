void SerialParse(String Command)
{
    char _c;
    //String Work_String = "";
    String Param = "";
    //String Value = "";
    int Col = 0;
    int Row = 0;
    uint8_t RGB_R = 0;
    uint8_t RGB_G = 0;
    uint8_t RGB_B = 0;
    Serial.print("Command: ");
    Serial.println(Command);

    for (int i = 0; i < Command.length(); i++)
    {
        _c = Command[i];
        if (_c == ' ' || _c == '\n' || _c == '\0')
        {
            //Serial.println(Param);
            /////Selector////////
            switch (Param[0])
            {
                case 'C':
                {
                    Param.replace('C', ' ');
                    Param.trim();
                    Col = Param.toInt();
                    //Serial.println(Col);
                    break;
                }
                case 'R':
                {
                    Param.replace('R', ' ');
                    Param.trim();
                    Row = Param.toInt();
                    //Serial.println(Row);
                    break;
                }
                case 'r':
                {
                    Param.replace('r', ' ');
                    Param.trim();
                    RGB_R = Param.toInt();
                    //Serial.println(RGB_R);
                    break;
                }
                case 'g':
                {
                    Param.replace('g', ' ');
                    Param.trim();
                    RGB_G = Param.toInt();
                    //Serial.println(RGB_G);
                    break;
                }
                case 'b':
                {
                    Param.replace('b', ' ');
                    Param.trim();
                    RGB_B = Param.toInt();
                    //Serial.println(RGB_B);
                    break;
                }
                default:
                {
                    break;
                }
            }
            /////////////////////
            Param = "";
        }
        else
        {
            Param += _c;
        }
    }
    //Serial.println(Param);
    Param = "";
    Set_Pixel(Col, Row, RGB_R, RGB_G, RGB_B);
}

void Sparkles()
{
    int R_Pixel_C = random(0, Columns);
    int R_Pixel_R = random(0, Rows);
    byte R_RGB_R = random(0, 255);
    byte R_RGB_G = random(0, 255);
    byte R_RGB_B = random(0, 255);
    Set_Pixel(R_Pixel_C, R_Pixel_R, R_RGB_R, R_RGB_G, R_RGB_B);
}  
void Set_Pixel(int Column, int Row, byte R, byte G, byte B)
{
    int Pixel_No = (Column);
    for (int i = 0; i < Row; i++)
    {
        Pixel_No += Columns;
    }
    tira.setPixelColor(Pixel_No, R, G, B);
    tira.show();
    delay(10);
}
void Clear_Panel()
{
    for (int i = 0; i < nleds; i++) 
    {
        tira.setPixelColor(i, 0, 0, 0); // Apagado
        //tira.show();
        //delay(retardo);
        //tira.setPixelColor(i,0,0,0); 
    }
    tira.show();
    delay(10);
    Serial.println("Panel Cleared!");
}    
  void Pixel_Check()
  {
      Serial.print("Qty of Pixels: ");
      Serial.println(nleds);
      for (int i = 0; i < nleds; i++) {
          tira.setPixelColor(i, 255, 255, 255); //Encendido
          tira.show();
          delay(retardo);
          tira.setPixelColor(i, 0, 0, 0); // Apagado
          tira.show();
      }
      delay(500);
  }

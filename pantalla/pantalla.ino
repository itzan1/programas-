#include <UTFT.h> 
#include <URTouch.h>
int a=1;
//indicamos pines para hardware

UTFT    myGLCD(ILI9341_16,38,39,40,41);
URTouch  myTouch( 6, 5, 4, 3, 2);

//==== Definimos fuentes que utilizaremos
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

void setup() {
  // Inicializamos pantalla y touch
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);
int a=1;
}
void principal(){
  
// myGLCD.setBackColor(0,0,0); // Sets the background color of the area where the text will be printed to black
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.setFont(BigFont); // Sets font to big
  myGLCD.print("Modo Normal 0V-999V", CENTER, 0); // Prints the string on the screen

  //BOTON SET VOLTAJE

myGLCD.setColor(16, 167, 103); // Sets green color
  myGLCD.fillRoundRect (180, 40, 285, 70); // Draws filled rounded rectangle
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.drawRoundRect (180, 40, 285, 70); // Draws rounded rectangle without a fill, so the overall appearance of the button looks like it has a frame
  myGLCD.setFont(SmallFont); // Sets the font to big
  myGLCD.setBackColor(16, 167, 103); // Sets the background color of the area where the text will be printed to green, same as the button
  myGLCD.print("SET VOLTAJE", 190, 50); // Prints the string

  //MODO DE FUNCIONAMIENTO

myGLCD.setColor(16, 167, 103); // Sets green color
  myGLCD.fillRoundRect (180, 80, 285, 120); // Draws filled rounded rectangle
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.drawRoundRect (180, 80, 285, 120); // Draws rounded rectangle without a fill, so the overall appearance of the button looks like it has a frame
  myGLCD.setFont(SmallFont); // Sets the font to big
  myGLCD.setBackColor(16, 167, 103); // Sets the background color of the area where the text will be printed to green, same as the button
  myGLCD.print("CONFIGURAR", 190, 95); // Prints the string


  
  
//IMPRIMIR LECTURA DE VOLTAJE
  myGLCD.setBackColor(0, 0, 0); 
  myGLCD.setFont(SevenSegNumFont); 
  myGLCD.setColor(255, 0, 0);
  myGLCD.print("800", 20, 30); 
  myGLCD.setFont(BigFont); 
  myGLCD.setColor(255, 255, 255);
  myGLCD.print("V", 130, 60); 

 //IMPRIMIR VOLTAJE SET
 myGLCD.setBackColor(0, 0, 0); 
  myGLCD.setFont(SmallFont); 
  myGLCD.setColor(255, 255, 255);
  myGLCD.print("800", 30, 85); 
  myGLCD.setFont(SmallFont); 
  myGLCD.setColor(255, 255, 255);
  myGLCD.print("V SET", 70, 85); 
  //IMPRIMIR CORRIENTE
  
  myGLCD.setFont(BigFont); 
  myGLCD.setColor(255, 0, 0);
  myGLCD.print("5.8", 70, 100); // Prints the string on the screen
  
  myGLCD.setFont(BigFont); 
  myGLCD.setColor(255, 255, 255);
  myGLCD.print("mA", 130, 100); // Prints the string on the screen

    //IMPRIMIR potencia
  
  myGLCD.setFont(BigFont); 
  myGLCD.setColor(255, 0, 0);
  myGLCD.print("180", 70, 130); // Prints the string on the screen
  
  myGLCD.setFont(BigFont); 
  myGLCD.setColor(255, 255, 255);
  myGLCD.print("W", 130, 130); // Prints the string on the screen

  //ALIMENTACION

  myGLCD.setFont(SmallFont); 
  myGLCD.setColor(255, 255, 255);
  myGLCD.print("INPUT: ", 10, 225);
  
  myGLCD.setFont(SmallFont); 
  myGLCD.setColor(255, 0, 0);
  myGLCD.print("12V", 60, 225);

  //SEND DATA

  myGLCD.setFont(SmallFont); 
  myGLCD.setColor(255, 255, 255);
  myGLCD.print("ENVIANDO DATOS ", 205, 225);

  
  
  }

void loop() {
  // put your main code here, to run repeatedly:
  if(a==1){
    
    principal();
    a=0;
  }
  }

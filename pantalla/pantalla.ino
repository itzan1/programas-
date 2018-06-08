/////////////////////////////////////
//programa para control de alto voltaje
//mediante la implementacion de LCD TOUCH TFT de 3.2´´
//
//
//
/////////////////////////////////////
#include <UTFT.h>
#include <URTouch.h>



//indicamos pines para hardware
UTFT    myGLCD(ILI9341_16,38,39,40,41);
URTouch  myTouch( 6, 5, 4, 3, 2);


//Definimos fuentes que utilizaremos
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

//variables que estaremos utilizando
int x,y;


void botones(){
  myGLCD.setFont(BigFont); 
  for (x=0; x<3; x++)
  {
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (200, 10+(x*55), 310, 60+(x*55));
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (200, 10+(x*55), 310, 60+(x*55));
    
  }

for (x=0; x<2; x++)
  {
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (10+(x*155), 175, 155+(x*155), 225);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (10+(x*155), 175, 155+(x*155), 225);
    
  }



  
  myGLCD.setBackColor(0, 0, 255);
  myGLCD.print("ON 2", 220 , 30);
  myGLCD.print("ON 3", 220 , 85);
  myGLCD.print("ON 1", 220 , 140);
  //myGLCD.print("UART ON", 185 , 195);
  myGLCD.print("V SET", 40 , 190);
  myGLCD.print("CONFIG", 190 , 190);
  
  
  
  }


void marco(int x1, int y1, int x2, int y2){
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
  while (myTouch.dataAvailable())
  myTouch.read();
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
  
}



void setup(){
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_HI);
  botones();
  }




void touch(){
  
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();

      if((x>=200) && (x<=310))
      {
        if((y>=10) && (y<=60)){ //boton ON 2
          marco(200,10,310,60);

        }
        
        if((y>=65) && (y<=115)){ //boton ON 3
          marco(200,65,310,115);

        }

        if((y>=120) && (y<=170)){ //boton ON 1
          marco(200,120,310,170);

        }

       
      }

      if((y>=175) && (y<=225))
      {
        if((x>=10) && (x<=155)){ //boton V SET
        
          marco(10,175,155,225);

        }
      }
        if((x>=165) && (x<=310)){ //boton V SET
        
          marco(165,175,310,225);

        }
}

        
    

  void loop(){
if(myTouch.dataAvailable()){

  touch();
  }
  }


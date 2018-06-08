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
int x,y,pantalla=1,k,vout=0,a=0;


void botones1(){ //pantalla 1
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

 
  
void marco1(int x1, int y1, int x2, int y2){ //marcos pantalla 1
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
  while (myTouch.dataAvailable())
  myTouch.read();
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
  
}

void touch1(){
  
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();

      if((x>=200) && (x<=310))
      {
        if((y>=10) && (y<=60)){ //boton ON 2
          marco1(200,10,310,60);
        }
        
        if((y>=65) && (y<=115)){ //boton ON 3
          marco1(200,65,310,115);

        }

        if((y>=120) && (y<=170)){ //boton ON 1
          marco1(200,120,310,170);
   
        }

       
      }

      if((y>=175) && (y<=225))
      {
        if((x>=10) && (x<=155)){ //boton V SET
          marco1(10,175,155,225);
          pantalla =2;
        }
      
        if((x>=165) && (x<=310)){ //boton config
          marco1(165,175,310,225);
          
        }
}
}

////////////////////////////// fin de pantalla 1



////////////////////////////// pantalla 2

void botones2(){ //pantalla 2
  
  for (x=0; x<4; x++) //botones +
  {
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (10+(x*60), 10, 60+(x*60), 60);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (10+(x*60), 10, 60+(x*60), 60);
    myGLCD.print("+", 27+(x*60), 27);
  }


  for (x=0; x<4; x++) //botones -
  {
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (10+(x*60), 170, 60+(x*60), 220);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (10+(x*60), 170, 60+(x*60), 220);
    myGLCD.print("-", 27+(x*60), 190);
  }

  for (x=0; x<4; x++) //blanco 
  {
    myGLCD.setColor(255, 255, 255);
    myGLCD.fillRoundRect (10+(x*60), 70, 60+(x*60), 160);
    myGLCD.setColor(255, 0, 0);
    myGLCD.drawRoundRect (10+(x*60), 70, 60+(x*60), 160);
    //myGLCD.print("-", 27+(x*60), 170);
  }

  myGLCD.setColor(0, 0, 255); /// boton set
   myGLCD.fillRoundRect(250,70,310,160);
   myGLCD.setColor(255, 255, 255);
   myGLCD.drawRoundRect(250,70,310,160);
   myGLCD.print("set" , 255,105);
  }
  
   void touch2(){
    myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();

      if((y>=10) && (y<=60)){ /////////////botones +
        if((x>=10) && (x<=60)){ //boton + kilos
          marco1(10,10,60,60);
//          myGLCD.setFont(SevenSegNumFont); 
//          vout=vout+1000;
//          a=a+1;
//          myGLCD.print(string.toInt(a),20,70);
          
        }

        if((x>=70) && (x<=120)){ //boton + kilos
          marco1(70,10,120,60);
        }

        if((x>=130) && (x<=180)){ //boton + kilos
          marco1(130,10,180,60);
        }

        if((x>=190) && (x<=240)){ //boton + kilos
          marco1(190,10,240,60);
        }
        }


        if((y>=170) && (y<=220)){ ////////////botones -
          
        if((x>=10) && (x<=60)){ //boton + kilos
          marco1(10,170,60,220);
        }

        if((x>=70) && (x<=120)){ //boton + kilos
          marco1(70,170,120,220);
        }

        if((x>=130) && (x<=180)){ //boton + kilos
          marco1(130,170,180,220);
        }

        if((x>=190) && (x<=240)){ //boton + kilos
          marco1(190,170,240,220);
        }
        }

        if((x>=250) && (x<=310)){ // boton SET

          if((y>=70) && (y<=160)){
            marco1(250,70,310,160);
            pantalla =1;
            
            }
          

        }
       
    
    }


///////////////////////fin pantalla set voltaje

void setup(){
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_HI);

  }

void loop(){

//pantalla 1
if(pantalla == 1){
    myGLCD.fillScr(VGA_BLACK);
    botones1();
while(true){
if(myTouch.dataAvailable()){

  touch1();
  }

  if(pantalla == 2 )break;
  }
}

if(pantalla == 2){
  myGLCD.fillScr(VGA_BLACK);
  botones2();
  while(true)
    {
      if(myTouch.dataAvailable()){

  touch2();
  }

  if(pantalla == 1){break;}
    }
  }


  }


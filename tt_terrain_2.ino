#define madv 2
#define madr 3

#define magv 4
#define magr 5

#define mrdv 6
#define mrdr 7

#define mrgv 8
#define mrgr 9
#include <Servo.h>

Servo sna ;
Servo snr ; 
Servo sbd ;
Servo sbg ; 
int v=200;
int v2=230;
char i; 


void setup() {
  Serial.begin(9600);
  pinMode(sna,OUTPUT);
   sna.attach(10);
   snr.attach(11) ; 
   sbd.attach(12) ;
   sbg.attach(13) ; 
  pinMode(madv, OUTPUT);




  pinMode(madr, OUTPUT);

  pinMode(magv, OUTPUT);
  pinMode(magr, OUTPUT);

  pinMode(mrdv, OUTPUT);
  pinMode(mrdr, OUTPUT);

  pinMode(mrgv, OUTPUT);
  pinMode(mrgr, OUTPUT);

}
void avancer()
{

  analogWrite(madv, v);
  analogWrite(madr, 0);
  analogWrite(magv, v2);
  analogWrite(magr, 0);
  analogWrite(mrdv, v);
  analogWrite(mrdr, 0);
  analogWrite(mrgv, v2);

  analogWrite(mrgr, 0);
}


void reculer()
{
  analogWrite(madv, 0);
  analogWrite(madr, v);
  analogWrite(magv, 0);
  analogWrite(magr, v2);
  analogWrite(mrdv, 0);
  analogWrite(mrdr, v);
  analogWrite(mrgv, 0);
  analogWrite(mrgr, v2);
}
void mini_gauche ()
{ analogWrite(madv, v);
  analogWrite(madr, 0);
  analogWrite(magv, 0);
  analogWrite(magr, 0);
  analogWrite(mrdv, v);
  analogWrite(mrdr, 0);
  analogWrite(mrgv, 0);
  analogWrite(mrgr, 0);

}
void mini_droite ()
{ analogWrite(madv, 0);
  analogWrite(madr, 0);
  analogWrite(magv, v2);
  analogWrite(magr, 0);
  analogWrite(mrdv, 0);
  analogWrite(mrdr, 0);
  analogWrite(mrgv, v2);
  analogWrite(mrgr, 0);

}

void droite()
  { analogWrite(madv,0);
  analogWrite(madr,v);
  analogWrite(magv,v2);
  analogWrite(magr,0);
  analogWrite(mrdv,0);
  analogWrite(mrdr,v);
  analogWrite(mrgv,v2);
  analogWrite(mrgr,0);

  }

void gauche ()
  {
  analogWrite(madv,v);
  analogWrite(madr,0);
  analogWrite(magv,0);
  analogWrite(magr,v2);
  analogWrite(mrdr,0);
  analogWrite(mrdv,v);
  analogWrite(mrgv,0);
  analogWrite(mrgr,v2);
  }
  void mini_droite_back()
  {analogWrite(madv,0);
  analogWrite(madr,0);
  analogWrite(magv,0);
  analogWrite(magr,v2);
  analogWrite(mrdr,0);
  analogWrite(mrdv,0);
  analogWrite(mrgv,0);
  analogWrite(mrgr,v2);
  
  }

  void mini_gauche_back ()
  {
  analogWrite(madv,0);
  analogWrite(madr,v);
  analogWrite(magv,0);
  analogWrite(magr,0);
  analogWrite(mrdr,v);
  analogWrite(mrdv,0);
  analogWrite(mrgv,0);
  analogWrite(mrgr,0);
  }
void stopp()
{
  analogWrite(madv, 0);
  analogWrite(madr, 0);
  analogWrite(magv, 0);
  analogWrite(magr, 0);
  analogWrite(mrdv, 0);
  analogWrite(mrdr, 0);
  analogWrite(mrgv, 0);
  analogWrite(mrgr, 0);

}
void presser() 
{ 
  sbd.write(90) ;
  sbg.write(170) ; 
  
}
 void retirer()
 { 
  sbd.write(70) ;
  sbg.write(180) ; 
  
}
void loop()
  {
  if(Serial.available()>0) // send data only when u receive data
   {i= Serial.read();
     switch(i)
      {
        case 'F':
          avancer();
          break;

        case 'B':
         reculer();
         break;

        case 'L':
         gauche();
         break; 

        case 'R':
         droite();
         break;

        case 'G':
        mini_gauche();
        break;

        case 'I':
        mini_droite();
        break;
        case 'J':
        mini_droite_back();
        break;

        case 'H':
        mini_gauche_back();
        break;
        
        case 'u': 
         sna.write(0) ;
        break ;   
         case 'W' :
         sna.write(70) ;
        break ;
 
         case 'U' : 
         sna.write(180) ;
         break ;


         
         case 'V' :
         presser() ;
         break ;
         
         case 'v' :
         retirer() ;
         break ;
          
         case 'S':
         stopp();
         break;
  
  }
   }

  }

#define b 0
#define w 1
int s[8]={0};
bool boo=true;
void setup() {
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);

}
void loop() {
  if(boo){
    eyes();
  //-------------------------------------------------------------------------STRIGHT---------------------------------------------------------------------------
  if(s[0]==w && s[1]==w && s[2]==w && s[3]==b && s[4]==b && s[5]==w && s[6]==w &&s[7]==w)
  straight();
  //--------------------------------------------------------------- LEFT------TURNS---------------------------------------------------------------------------------
  else if(s[0]==w && s[1]==w && s[2]==w && s[3]==b && s[4]==w && s[5]==w && s[6]==w &&s[7]==w)
  left1();
  else if(s[0]==w && s[1]==w && s[2]==b && (s[3]==b || s[3]==w) && s[4]==w && s[5]==w && s[6]==w && s[7]==w)
  left2();
  else if(s[0]==w && s[1]==b && (s[2]==w || s[2]==b) && s[3]==w && s[4]==w && s[5]==w && s[6]==w && s[7]==w)
  left3();
  else if(s[0]==b && (s[1]==w || s[1]==b) && s[2]==w && s[3]==w && s[4]==w && s[5]==w && s[6]==w && s[7]==w)
  right_90();
  else if(s[0]==b && s[1]==b && s[2]==b && s[3]==b && s[4]==b && s[5]==w && s[6]==w &&s[7]==w)
  left_90();
  //------------------------------------------------------------------RIGHT-----TURNS----------------------------------------------------------------------------
  if(s[0]==w && s[1]==w && s[2]==w && s[3]==w && s[4]==b && s[5]==w && s[6]==w &&s[7]==w)
  right1();
  else if(s[0]==w && s[1]==w && s[2]==w && s[3]==w && (s[4]==b || s[4]==w) && s[5]==b && s[6]==w && s[7]==w)
  right2();
  else if(s[0]==w && s[1]==b && s[2]==w && s[3]==w && s[4]==w && (s[5]==w || s[5]==b) && s[6]==b && s[7]==w)
  right3();
  else if(s[0]==w && s[1]==w && s[2]==w && s[3]==w && s[4]==w && s[5]==w && s[6]==w && s[7]==b)
  right_90;
  else if(s[0]==w && s[1]==w && s[2]==w && s[3]==b && s[4]==b && s[5]==b && s[6]==b &&s[7]==b)
  right_90();
  //-------------------------------------------------------------------------BRAKE------------------------------------------------------------------------------
  else if(s[0]==b && s[1]==b && s[2]==b && s[3]==b && s[4]==b && s[5]==b && s[6]==b &&s[7]==b){
    analogWrite(3,100);
    analogWrite(5,0);
    analogWrite(9,100);
    analogWrite(10,0);
    delay(500);
    brake();
  }
  //--------------------------------------------------------------------------ERROR--------------------------------------------------------------------------------
  else if(s[0]==w && s[1]==w && s[2]==w && s[3]==w && s[4]==w && s[5]==w && s[6]==w &&s[7]==w)
  back();
  //else
  //brake();
  }
  
}
void eyes()
{
  s[0]=digitalRead(A5);
  s[1]=digitalRead(A4);
  s[2]=digitalRead(A3);
  s[3]=digitalRead(A2);
  s[4]=digitalRead(A1);
  s[5]=digitalRead(A0);
  s[6]=digitalRead(2);
  s[7]=digitalRead(4);
}
void straight()
{
  analogWrite(3,180);
  analogWrite(5,0);
  analogWrite(9,180);
  analogWrite(10,0);
}
void brake()
{
  analogWrite(3,0);
  analogWrite(5,0);
  analogWrite(9,0);
  analogWrite(10,0);
  boo=false;
}
void back(){
  analogWrite(3,0);
  analogWrite(5,50);
  analogWrite(9,0);
  analogWrite(10,50);
}

void left1()
{ 
  analogWrite(3,110);
  analogWrite(5,0);
  analogWrite(9,140);
  analogWrite(10,0);
}
void left2()
{
  analogWrite(3,0);
  analogWrite(5,80);
  analogWrite(9,160);
  analogWrite(10,0);
}
void left3()
{
  analogWrite(3,0);
  analogWrite(5,50);
  analogWrite(9,180);
  analogWrite(10,0);
}
void left4()
{
  analogWrite(3,0);
  analogWrite(5,0);
  analogWrite(9,140);
  analogWrite(10,0);
}
void left_90()
{
  analogWrite(3,0);
  analogWrite(5,200);
  analogWrite(9,200);
  analogWrite(10,0);
}
void right1()
{
  analogWrite(3,140);
  analogWrite(5,0);
  analogWrite(9,0);
  analogWrite(10,100);
}
void right2()
{
  analogWrite(3,160);
  analogWrite(5,0);
  analogWrite(9,0);
  analogWrite(10,80);
}
void right3()
{
  analogWrite(3,140);
  analogWrite(5,0);
  analogWrite(9,0);
  analogWrite(10,40);
} 
void right4()
{
  analogWrite(3,140);
  analogWrite(5,0);
  analogWrite(9,0);
  analogWrite(10,0);
}
void right_90()
{
  analogWrite(3,200);
  analogWrite(5,0);
  analogWrite(9,0);
  analogWrite(10,200);
}

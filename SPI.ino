void setup() {
  // put your setup code here, to run once:
pinMode (7, INPUT);
pinMode (8, OUTPUT);
pinMode (9, OUTPUT);
pinMode (10 , OUTPUT);

unsigned int value = 0x0C01;

SPI (value);

value = 0x0B07;

SPI (value);

value = 0x09FF;

SPI (value);
}

void loop() {
  // put your main code here, to run repeatedly:

unsigned int value;
int but = 0;
int schet = 0;
int chek_but =0;
while (1){

but = digitalRead(7); // button wtih only 1 click 

if (but == 1)
{
    if (chek_but == 0)
    {
      schet = schet+1;
      }
  
  } 

chek_but = digitalRead(7);

cifra(schet);

}

}

void SPI(unsigned int value)  // programm SPI 
{
digitalWrite (10, 0); // cheap select
//digitalWrite (9, 0);

for (int i =0; i<16; i++)
    {
    digitalWrite (9, 0);// CLK 
    if ((value & 0x8000)== 0) digitalWrite (8, 0);  //Data OUT
       else  digitalWrite (8, 1);  
    delay (0.5); 
    digitalWrite (9, 1); 
    digitalWrite (9, 0);
    value = value << 1;
    
    }
digitalWrite (10, 1);    

}


void cifra (long a){ //void for sendin SPI voamtd to display from any int data 
  
int C[8];
long del = 10000000;
for (int i =0; i<8; i++)
{
  C[7-i]= a/del;
  a=a-C[7-i]*del;
  del = del/10;
    
  } 
int adr = 0x0100;
int value;

for (int i = 0; i<8; i++){

if (C[7-i]==0) C[7-i]=0xF;
else i =8; 

}

for (int i =0; i<8; i++){
  
  value = adr + C[i];

 SPI (value);
    
  adr = adr + 0x0100; 
  
  }
 
  }

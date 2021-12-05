void setup() {
  // put your setup code here, to run once:
pinMode (7, INPUT);
pinMode (8, OUTPUT);
pinMode (9, OUTPUT);
pinMode (10 , OUTPUT);
pinMode(A0, INPUT);
pinMode(A1, INPUT);


unsigned int value;

value = 0x0C01;

SPI (value);

value = 0x0B07;

SPI (value);

value = 0x0900;

SPI (value);

value= 0x0100;


 for (int i = 0; i<8; i++)
    { 
      SPI (value);
      value=value + 0x0100;  
    }


}

void loop() {
  // put your main code here, to run repeatedly:

unsigned int value;
int but = 1;
int schet = 0;
int chek_but =0;
int x;
int y;
int strelka[8][8];   // this is "arrow" in Russian :D
int Sn[8][8];
int Sl[8][8];
int Su[8][8];
int Sn1[8][8]={0, 0, 0, 1, 1, 0, 0, 0,
               0, 0, 1, 1, 1, 1, 0, 0,
               0, 1, 1, 1, 1, 1, 1, 0,
               1, 1, 0, 1, 1, 0, 1, 1,
               1, 0, 0, 1, 1, 0, 0, 1,
               0, 0, 0, 1, 1, 0, 0, 0,
               0, 0, 0, 1, 1, 0, 0, 0,
               0, 0, 0, 1, 1, 0, 0, 0};

int Sl1[8][8]={0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 1, 1, 1, 1, 0, 0,
               0, 0, 1, 1, 1, 1, 0, 0,
               0, 0, 1, 1, 1, 1, 0, 0,
               0, 0, 1, 1, 1, 1, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0};

int Su1[8][8]={1, 1, 1, 1, 1, 1, 1, 1,
               1, 1, 1, 1, 1, 1, 1, 1,
               0, 0, 0, 0, 1, 1, 1, 1,
               0, 0, 0, 1, 1, 1, 1, 1,
               0, 0, 1, 1, 1, 0, 1, 1,
               0, 1, 1, 1, 0, 0, 1, 1,
               1, 1, 1, 0, 0, 0, 1, 1,
               1, 1, 0, 0, 0, 0, 1, 1};              


int Sn2[8][8]={0, 0, 0, 1, 1, 0, 0, 0,  //easter egg
               0, 0, 1, 0, 0, 1, 0, 0,
               0, 0, 1, 0, 0, 1, 0, 0,
               0, 0, 1, 0, 0, 1, 0, 0,
               0, 1, 1, 0, 0, 1, 1, 0,
               1, 0, 0, 0, 0, 0, 0, 1,
               1, 0, 0, 1, 1, 0, 0, 1,
               0, 1, 1, 0, 0, 1, 1, 0};

int Sl2[8][8]={0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0,
               0, 1, 1, 1, 1, 1, 1, 0,
               0, 1, 1, 1, 1, 1, 1, 0,
               0, 1, 1, 1, 1, 1, 1, 0,
               0, 1, 1, 0, 0, 1, 1, 0,
               0, 0, 0, 0, 0, 0, 0, 0,
               0, 0, 0, 0, 0, 0, 0, 0};

int Su2[8][8]={0, 0, 0, 0, 0, 1, 1, 0,
               0, 0, 0, 0, 1, 0, 1, 1,
               0, 1, 0, 1, 0, 0, 0, 1,
               1, 0, 1, 0, 0, 0, 1, 0,
               1, 0, 0, 0, 0, 1, 0, 0,
               0, 1, 1, 0, 1, 0, 0, 0,
               0, 0, 1, 0, 0, 1, 0, 0,
               0, 0, 0, 1, 1, 0, 0, 0};  
            
x = analogRead(A1) / 342;
y = analogRead(A0) / 342;

if (digitalRead(7)==0)
  {

for (int i =0; i<8; i++){
    for (int j=0; j<8; j++){
//      easter_egg(Sn1[i][j], Sl1[i][j], Su1[i][j]);   // this I try to make fuinction of easter egg
        Sn[i][j]=Sn2[i][j];
        Sl[i][j]=Sl2[i][j];
        Su[i][j]=Su2[i][j];

      }      
    }
  }
  
if (digitalRead(7)==1) {
  for (int i =0; i<8; i++){
    for (int j=0; j<8; j++){
      
        Sn[i][j]=Sn1[i][j];
        Sl[i][j]=Sl1[i][j];
        Su[i][j]=Su1[i][j];
      }
    }
  }


for (int j=0; j<8; j++){
  for (int i=0; i<8; i++){
    if((x==0)&&(y==0))
    strelka[i][j]=Su[i][7-j];

    if((x==1)&&(y==0))
    strelka[i][j]=Sn[i][j];    

    if((x==2)&&(y==0))
    strelka[i][j]=Su[i][j];

    if((x==0)&&(y==1))
    strelka[i][j]=Sn[j][i];

    if((x==1)&&(y==1))
    strelka[i][j]=Sl[i][j];  

    if((x==2)&&(y==1))
    strelka[i][j]=Sn[7-j][i];      

    if((x==0)&&(y==2))
    strelka[i][j]=Su[7-i][7-j];

    if((x==1)&&(y==2))
    strelka[i][j]=Sn[7-i][j]; 

    if((x==2)&&(y==2))
    strelka[i][j]=Su[7-i][j];       
    
   }
  }



STRELKA(strelka);


}

void STRELKA(int Sn[8][8])
{
int value = 0x01;  
for (int j=0; j<8; j++){

  for (int i=0; i<8; i++){
    value= value << 1;
    value = value + Sn[j][i];
    }
    SPI (value);
    value = value >> 8;
    value = value + 0x01;
  } 
  
}




void SPI(unsigned int value)  // programm SPI 
{
digitalWrite (10, 0); // cheap select

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



int easter_egg(int *Sn[8][8], int *Sl[8][8], int *Su[8][8]){
int Sn1[8][8]={0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0};

int Sl1[8][8]={0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0};

int Su1[8][8]={0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0};

  for (int i =0; i<8; i++){
    for (int j=0; j<8; j++){
      Sn[i][j]=Sn1[i][j];
      }
    }    

  for (int i =0; i<8; i++){
    for (int j=0; j<8; j++){
      Sl[i][j]=Sl1[i][j];
      }
    }  

  for (int i =0; i<8; i++){
    for (int j=0; j<8; j++){
      Su[i][j]=Su1[i][j];
      }
    }                
//  return Sn;
//  return Sl;
//  return Su;
  }


int RX=11;
unsigned char receive(void);
void pause(unsigned int k);

unsigned char my_data;

unsigned char receive(void)
{
unsigned char x=0;
for(int i=0;i<8;i++)
{
if(digitalRead(RX)&0x01) x|=(1<<i); 
pause(1000);
}
return x;
}
void pause(unsigned int k)
{
while(k--) _delay_us(1);
}
//*****************
void get_data(unsigned char j)
{
  
  while(receive()!=j);
  for(int i=0; i<1;i++)// le for à un tour pour les continue qui ne dfonctionnent que dans une boucle ; sans for il y a erreur .
  {

while(receive()!=j)continue;//J pour le start , on peut mettre autre chose .
while(receive()!=j+1) continue;

while(receive()!=j+2)continue;
my_data=receive();


while(receive()!=j+3) continue ;//Z pour le stop , possible de mettre autre chose .
/*if (isAlphaNumeric(my_data))//teste si le data ne contient que des caractères alphanumériques= chiffres ou lettres alphabet .
Serial.println((char)my_data);
uint16_t a =(uint16_t)(my_data);
Serial.println(a*2);
*/
  }
  
  }

//*********************

void setup(void)
{
  Serial.begin(9600);
pinMode(RX,INPUT);
my_data=0;

}


void loop()
{
uint32_t mon_nombre  ,a,b,c;
get_data('1');
a=(uint32_t)my_data;
Serial.print(my_data);Serial.print("  :  ");
_delay_ms(10);//ms(10)bloque clefs de voitures mais pas ms(100)
get_data('5');
b=(uint32_t)my_data;
Serial.print(my_data);Serial.print("  :  ");
_delay_ms(10);
get_data('9');
c=(uint32_t)my_data;
Serial.println(my_data);
mon_nombre  = (a<<16)+(b<<8)+c;
Serial.println(mon_nombre);
Serial.println(mon_nombre*2);
_delay_ms(10);
}


 int TX=12 ;


void init(void);
void transmit(unsigned char x);
void envoi_0(void);
void envoi_1(void);
void pause(unsigned int k);
void send_char(char x,uint8_t i);

unsigned char my_data,y;
uint8_t haut,milieu,bas;


void transmit(unsigned char x)
{
for(int i=0;i<8;i++)
{
if(x&(1<<i)) envoi_1(); else envoi_0();
}

}
//**************
void send_char(unsigned char x,unsigned char i)
{
transmit(i);
transmit(i+1);
transmit(i+2);
transmit(x);//my_data);
transmit(i+3);

}
//****************
void envoi_1(void)
{
digitalWrite(TX,HIGH);

pause(1000);
}

void envoi_0(void)
{
digitalWrite(TX,LOW);
pause(1000);
}

void pause(unsigned int k)
{
while(k--) _delay_us(1);
}

void decompose(uint32_t x)
{
bas=x&0xff;
milieu=(x>>8)&0xff;
haut=(x>>16)&0xff ;
}

void setup()
{
pinMode(TX,OUTPUT);
my_data=0;
y=0;
}



void loop()// send 3 unsigned chars = numbers from 0 to 255;
{
decompose(123654);

send_char(haut,'1');

send_char(milieu,'5');

send_char(bas,'9');
_delay_ms(50);
}

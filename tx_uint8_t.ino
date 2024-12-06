
 int TX=12 ;


void init(void);
void transmit(unsigned char x);
void envoi_0(void);
void envoi_1(void);
void pause(unsigned int k);
void send_char(char x,uint8_t i);

unsigned char my_data,y;


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


void setup()
{
pinMode(TX,OUTPUT);
my_data=0;
y=0;
}

void loop()// send 3 unsigned chars = numbers from 0 to 255;
{
my_data=123;//can be a value of resistance mapped in [0;255];
send_char(my_data,'1');
my_data=182;//=PIND;
send_char(my_data,'5');
my_data=87;//=PIND;
send_char(my_data,'9');
_delay_ms(50);
}

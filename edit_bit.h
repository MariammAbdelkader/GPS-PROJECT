#define set(reg,value) reg|= value;
#define clr(reg,value) reg&=~ value;
#define set_bit(reg,bit) reg|= (1<<bit)
#define clr_bit(reg,bit) reg &=~ (1<<bit)
#define get_bit(reg,bit) ((reg>>bit)&1)

#define set_1bit (reg,bit) reg|=(1<<bit);
#define clr_1bit (reg,bit) reg&=(~(1<<bit));
#define tgl_1bit (reg,bit) reg^=(1<<bit);
#define read_1bit (reg,bit) (reg&(1<<bit))>>bit;


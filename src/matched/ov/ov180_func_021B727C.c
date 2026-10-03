/*
 * function: func_021B727C
 * address: 0x021B727C
 * packet: pkt_ov180_021B727C
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020056EC 0x020056EC thumb
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern unsigned func_020056EC(unsigned);
void func_021B727C(char *p){u32 i;char *q;*(u8 *)(p+37215)=0;for(i=0;i<8;i++){q=p+i*2;*(u16 *)(q+37220)=func_020056EC(8)-4;*(u16 *)(q+37236)=func_020056EC(8)-4;}}

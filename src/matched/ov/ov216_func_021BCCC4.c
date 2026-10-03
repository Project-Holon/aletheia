/*
 * function: func_021BCCC4
 * address: 0x021BCCC4
 * packet: pkt_ov216_021BCCC4
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035D20 0x02035D20 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02035D20(u32*,u32*);
int func_021BCCC4(u8*p){u32 x,y;if(func_02035D20(&x,&y)){if((u32)(x-(*(short*)(p+0x25c)-12))<=24 && (u32)(y-(*(short*)(p+0x25e)-16))<=32)return 1;}return 0;}

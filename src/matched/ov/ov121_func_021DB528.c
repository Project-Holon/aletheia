/*
 * function: func_021DB528
 * address: 0x021DB528
 * packet: pkt_ov121_021DB528
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DB938 0x021DB938 thumb ov121
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021DB938(char *,int,u16);
extern void func_020409B4(u32);
void func_021DB528(char *p,int a) { int i; for(i=0;i<4;i++) func_021DB938(p,a,i); func_020409B4(3); }

/*
 * function: func_021D83C4
 * address: 0x021D83C4
 * packet: pkt_ov093_021D83C4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef enum { ZERO=0 } Bits;
void func_021D83C4(u32 *p) { Bits t=ZERO; t &=~15; t|=3; t &=~0x380; t|=0x400; *p=t; }

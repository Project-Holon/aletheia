/*
 * function: func_021BCDDC
 * address: 0x021BCDDC
 * packet: pkt_ov216_021BCDDC
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BDDA2 0x021BDDA2 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 d_021BDDA2[];
const u8*func_021BCDDC(u32 n){u32 i;for(i=0;i<6;i++){if(n==d_021BDDA2[i*3])return d_021BDDA2+i*3;}return d_021BDDA2;}

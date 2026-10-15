/*
 * function: NAMEIN_GRAPHIC_GridIndex
 * address: 0x021F3358
 * packet: pkt_ov194_021F3358
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u32 NAMEIN_GRAPHIC_GridIndex(u32 a,u32 b,u32 c) {if(a==3) a=b+(a+2*c);return a;}

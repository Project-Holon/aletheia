/*
 * function: BTL_ACTION_SetItem
 * address: 0x021D8358
 * packet: pkt_ov093_021D8358
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
void BTL_ACTION_SetItem(u32 *p,u32 id,u32 sub,u32 val) { Bits t=ZERO; t &=~15; t|=2; t &=~0x7fff80; t|=(u16)id<<7; t &=~0x70; t|=(sub&7)<<4; t &=~0x7f800000; t|=(val&255)<<23; *p=t; }

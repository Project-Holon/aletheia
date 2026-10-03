/*
 * function: func_021D5310
 * address: 0x021D5310
 * packet: pkt_ov122_021D5310
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void func_021D5310(u8 *p) { int i; for(i=0;i<16;i++) if(*(u16 *)(p+i*12+108)) --*(u16 *)(p+i*12+108); }

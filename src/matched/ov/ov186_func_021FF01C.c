/*
 * function: BR_SIDEBAR_UpdateSlot
 * address: 0x021FF01C
 * packet: pkt_ov186_021FF01C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
void BR_SIDEBAR_UpdateSlot(u8 *p){void (*f)(u8 *);f=*(void (**)(u8 *))(p+24);if(f)f(p);}

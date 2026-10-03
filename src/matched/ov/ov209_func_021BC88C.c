/*
 * function: func_021BC88C
 * address: 0x021BC88C
 * packet: pkt_ov209_021BC88C
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201AF80 0x0201AF80 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 *func_0201AF80(u32 heap, u16 *countOut);
void func_021BC88C(char *p) { *(void **)(p+0xc38)=func_0201AF80(107,0); }

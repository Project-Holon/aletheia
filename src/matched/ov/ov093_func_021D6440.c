/*
 * function: func_021D6440
 * address: 0x021D6440
 * packet: pkt_ov093_021D6440
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void func_021D6440(u8 *p,u32 n) { u8 *q; u8 i; u8 bit; q=p+0x153; i=n>>3; bit=1<<(n&7); q[i]&=(u8)~bit; }

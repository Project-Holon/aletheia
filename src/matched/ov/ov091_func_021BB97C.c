/*
 * function: func_021BB97C
 * address: 0x021BB97C
 * packet: pkt_ov091_021BB97C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201EC64 0x0201EC64 thumb
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
void func_021BB97C(u16 *p,u32 s) { *(u32 *)(s+44)=(u32)func_0201EC64(*p); }

/*
 * function: func_021D5734
 * address: 0x021D5734
 * packet: pkt_ov093_021D5734
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D51DC 0x021D51DC thumb ov093
 */
typedef unsigned char u8;
extern void func_021D51DC(void *, int, int, int);
typedef unsigned int u32;
void func_021D5734(u8 *p, u32 i, int a, int b, int c)
{ func_021D51DC((void *)((u32)p + 0x104 + i * 14), a, b, c); }

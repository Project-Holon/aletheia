/*
 * function: func_021D7B60
 * address: 0x021D7B60
 * packet: pkt_ov093_021D7B60
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021D59B4 0x021D59B4 thumb ov093
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern int func_021D59B4(u8 *p, int k);
u32 func_021D7B60(void *p,u32 b) { return (u32)func_021D59B4(p,14)/b; }

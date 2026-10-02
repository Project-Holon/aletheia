/*
 * function: func_02174F34
 * address: 0x02174F34
 * packet: pkt_ov012_02174F34
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller consumes 020399A8's live r0 despite its filed void return.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 */
typedef unsigned int u32;
extern u32 func_020399A8(void);
extern void func_0203D3A8(u32, u32, u32, u32);
void func_02174F34(void) { func_0203D3A8(func_020399A8(), 0x150d, 0, 0); }

/*
 * function: func_021739CC
 * address: 0x021739CC
 * packet: pkt_ov012_021739CC
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 * Caller reads live r0 after 020399A8 and return from send wrapper.
 */
typedef unsigned int u32;
extern u32 func_020399A8(void);
extern int func_0203D3A8(u32 a, u32 b, u32 c, u32 d);
int func_021739CC(void)
{
    return func_0203D3A8(func_020399A8(), 0x1400, 0, 0);
}

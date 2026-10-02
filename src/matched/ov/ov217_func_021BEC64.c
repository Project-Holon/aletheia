/*
 * function: func_021BEC64
 * address:  0x021BEC64
 * packet:   pkt_ov217_021BEC64
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BF76C 0x021BF76C thumb ov217
 *   func_021BF77C 0x021BF77C thumb ov217
 *   func_021C11A4 0x021C11A4 thumb ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern u32 func_021BF76C(void *p);
extern u32 func_021BF77C(void *p);
extern void func_021C11A4(u32 a, u32 b);
void func_021BEC64(void *p)
{
    func_021C11A4(func_021BF76C(p), 0xFFFFE000);
    func_021C11A4(func_021BF77C(p), 0);
}

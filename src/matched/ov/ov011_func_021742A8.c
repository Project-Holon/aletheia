/*
 * function: func_021742A8
 * address:  0x021742A8
 * packet:   pkt_ov011_021742A8
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D4D0  0x0203D4D0  arm
 */

int func_021736D8(void);
int func_020399A8(void);
typedef unsigned int   u32;
u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int func_021742A8(int a)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D4D0(func_020399A8(), a, 0x21a, 0, 0, 0, 0, 0);
}

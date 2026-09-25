/*
 * function: func_021D9410
 * address:  0x021D9410
 * packet:   pkt_ov119_021D9410
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *
 * Byte-identical twin of func_021D93D4 (same 12-byte predicate stub).
 */

typedef unsigned int u32;

extern u32 func_020399A8(void);

void func_021D9410(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    if (func_020399A8() == e)
        return;
}

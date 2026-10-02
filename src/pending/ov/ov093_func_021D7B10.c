/*
 * function: func_021D7B10
 * address:  0x021D7B10
 * packet:   pkt_ov093_021D7B10
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-02 (wave B2 lane 01): DIFF, register allocation only. The image multiplies in place (muls r1,r0,r1), loads the 0xfff mask into r0, copies the product to r2 for the AND and shifts from r1; mwcc copies an operand into r2 first (adds r2,r0,#0; muls r2,r1,r2) and ANDs in place. Tried: operand order, b *= a, mask-first and shift-first orders, / and % by 4096, inline helpers, int and u32 parameters, an unused third parameter.
 */
typedef unsigned int u32;
u32 func_021D7B10(u32 a, u32 b)
{
    u32 v = a * b;
    u32 r = v >> 12;
    if ((v & 0xfff) > 0x800) r++;
    return r;
}

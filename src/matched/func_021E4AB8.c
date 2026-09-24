/*
 * function: func_021E4AB8
 * address:  0x021E4AB8
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Normalise the third argument to 0 or 1 and tail call the setter.
 *
 * symbols:
 *   (none)
 */

extern void func_0204B688(int a, int b);

void func_021E4AB8(int a0, int a1, int a2)
{
    func_0204B688(a1, a2 != 0);
}


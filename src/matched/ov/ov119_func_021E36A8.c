/*
 * function: func_021E36A8
 * address:  0x021E36A8
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Force the third argument to one when the sixth is set and the third is clear.
 *
 * symbols:
 *   func_021E35A0  0x021E35A0  thumb
 */

extern void func_021E35A0(void *a, int b, int c, void *d, int e);

void func_021E36A8(void *a, int b, int c, void *d, int e, int f)
{
    if (f != 0 && c == 0) {
        c = 1;
        e = 0;
    }
    func_021E35A0(a, b, c, d, e);
}


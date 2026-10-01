/*
 * function: func_021F51A4
 * address: 0x021F51A4
 * packet: pkt_ov194_021F51A4
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Padding: two zero bytes at 0x021F51E2, then a function prologue.
 * symbols:
 *   func_02082D44 0x02082D44 arm
 */
extern void func_02082D44(const void *, void *, unsigned);
void func_021F51A4(const char *src, char *dst, unsigned *a, unsigned *b, unsigned n, unsigned step)
{
    int i;
    for (i = 0; i < 8; i++) {
        func_02082D44(src + *a, dst + *b, n);
        *a += step;
        *b += n;
    }
}

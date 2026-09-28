/*
 * function: func_021DD25C
 * address:  0x021DD25C
 * packet:   pkt_021DD25C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02094798  0x02094798  arm
 *
 * Re-arm the object: clear both the +4 and +0x18 ranges, store the +0x14
 * count and set the live flag at +0.
 */

extern void func_02094798(void *, int);

void func_021DD25C(char *p, int b, int c, int d)
{
    func_02094798(p + 4, b);
    func_02094798(p + 0x18, d);
    *(int *)(p + 0x14) = c;
    *(int *)p = 1;
}


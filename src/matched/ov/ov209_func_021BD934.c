/*
 * function: func_021BD934
 * address:  0x021BD934
 * packet:   pkt_021BD934
 * region:   ov209
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B404 0x0204B404 arm
 */

extern void func_0204B404(void *, void *, unsigned short);

void func_021BD934(char *p, int idx, unsigned short a, unsigned short b, unsigned short c)
{
    unsigned short buf[2];
    buf[0] = a;
    buf[1] = b;
    func_0204B404(*(void **)(p + idx * 4 + 0xa74), buf, c);
}

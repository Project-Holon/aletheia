/*
 * function: func_021BD86C
 * address:  0x021BD86C
 * packet:   pkt_021BD86C
 * region:   ov209
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B878 0x0204B878 arm
 */

extern void func_0204B8C4(void *, int);
extern void func_0204B878(void *, int);

void func_021BD86C(char *p, int idx, int v)
{
    func_0204B8C4(*(void **)(p + 0xa74 + idx * 4), 0);
    func_0204B878(*(void **)(p + 0xa74 + idx * 4), (unsigned short)v);
}

/*
 * function: func_021BED98
 * address:  0x021BED98
 * packet:   pkt_021BED98
 * region:   ov210
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

void func_021BED98(char *p, int idx, int v)
{
    func_0204B8C4(*(void **)(p + 0x28 + idx * 4), 0);
    func_0204B878(*(void **)(p + 0x28 + idx * 4), (unsigned short)v);
}

/*
 * function: func_021BEDB8
 * address:  0x021BEDB8
 * packet:   pkt_ov210_021BEDB8
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BED98 0x021BED98 thumb ov210
 *   func_0204B92C 0x0204B92C arm
 * Addresses are Black-image addresses.
 */

extern void func_021BED98(char *p, int idx, int v);
struct Obj;
extern void func_0204B92C(struct Obj *p, unsigned int v);

void func_021BEDB8(int p, int i, int v)
{
    func_021BED98((char *)p, i, v);
    func_0204B92C((struct Obj *)((int *)(p + i * 4))[0xa], 1);
}

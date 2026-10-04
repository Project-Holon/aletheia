/*
 * function: func_021BED68
 * address:  0x021BED68
 * packet:   pkt_ov210_021BED68
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B944 0x0204B944 arm
 *   func_0204B8D4 0x0204B8D4 arm
 *   func_0204A600 0x0204A600 arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
struct Obj;
extern u32 func_0204B944(struct Obj *p);
extern void func_0204B8D4(struct Obj *p, u32 arg);
extern void func_0204A600(void);

void func_021BED68(int p)
{
    unsigned i;

    for (i = 0; i < 0x39; i++) {
        int *q = (int *)(p + i * 4);

        if (q[0xa] != 0 && func_0204B944((struct Obj *)q[0xa]) != 1)
            func_0204B8D4((struct Obj *)q[0xa], 0x1000);
    }
    func_0204A600();
}

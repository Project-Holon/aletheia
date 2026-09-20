/*
 * function: func_02061BD0
 * address:  0x02061BD0
 * packet:   pkt_02061BD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02061878  0x02061878  arm
 *   func_02061840  0x02061840  arm
 */

typedef unsigned short u16;

struct Obj02061BD0 {
    char pad0[8];
    u16 f8;
    char padA[2];
    u16 fC;
};

extern int func_02061878(struct Obj02061BD0 *);
extern u16 func_02061840(struct Obj02061BD0 *, u16);

int func_02061BD0(struct Obj02061BD0 *p)
{
    if (func_02061878(p) != 0) {
        return 0;
    }
    p->f8 = func_02061840(p, p->f8);
    p->fC -= 1;
    return 1;
}

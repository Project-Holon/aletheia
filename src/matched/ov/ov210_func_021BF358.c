/*
 * function: func_021BF358
 * address:  0x021BF358
 * packet:   pkt_ov210_021BF358
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 * Addresses are Black-image addresses.
 */

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void func_021BF358(int p, int i)
{
    int o = i * 4;
    int *q = (int *)(p + 0x28);

    if (*(int *)((int)q + o) != 0) {
        CLACT_DeleteActor((struct Obj *)(*(int *)((int)q + o)));
        *(int *)((int)q + o) = 0;
    }
}

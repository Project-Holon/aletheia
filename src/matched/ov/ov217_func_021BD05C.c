/*
 * function: func_021BD05C
 * address:  0x021BD05C
 * packet:   pkt_021BD05C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *
 * Addresses are Black-image addresses.
 */

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void func_021BD05C(int *p)
{
    int i;
    for (i = 0; i < 3; i++)
        CLACT_DeleteActor((struct Obj *)p[i + 0x48]);
}

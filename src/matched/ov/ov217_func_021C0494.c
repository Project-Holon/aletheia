/*
 * function: func_021C0494
 * address:  0x021C0494
 * packet:   pkt_021C0494
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

void func_021C0494(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        CLACT_DeleteActor((struct Obj *)p[i + 0xE5]);
}

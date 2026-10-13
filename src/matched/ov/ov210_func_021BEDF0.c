/*
 * function: func_021BEDF0
 * address:  0x021BEDF0
 * packet:   pkt_ov210_021BEDF0
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 * Addresses are Black-image addresses.
 */

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

void func_021BEDF0(int p, int i, int v)
{
    int h = ((int *)(p + i * 4))[0xa];

    if (h != 0)
        CLACT_SetActorDrawEnable((struct Obj *)h, v);
}

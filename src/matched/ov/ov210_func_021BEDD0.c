/*
 * function: ZKNSEARCH_MAIN_GetActorAnimSeq
 * address:  0x021BEDD0
 * packet:   pkt_ov210_021BEDD0
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
struct Obj;
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);

int ZKNSEARCH_MAIN_GetActorAnimSeq(int p, int i)
{
    return CLACT_GetActorAnimSeq((struct Obj *)(((int *)(p + i * 4))[0xa]));
}

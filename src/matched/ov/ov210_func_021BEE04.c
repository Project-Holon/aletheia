/*
 * function: ZKNSEARCH_MAIN_GetActorVisible
 * address:  0x021BEE04
 * packet:   pkt_ov210_021BEE04
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);

int ZKNSEARCH_MAIN_GetActorVisible(int p, int i)
{
    return CLACT_GetActorDrawEnable((struct Obj *)(((int *)(p + i * 4))[0xa]));
}

/*
 * function: ZKND_TBAR_IsButtonAnimating
 * address:  0x021BD7E4
 * packet:   pkt_021BD7E4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_IsActorAnimActive  0x0204B98C  arm  arm9
 *   (none)
 *
 * Returns 1 when the ARM9 call at 0x0204B98C on the word at [p] comes back zero.
 */

typedef unsigned int   u32;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);

int ZKND_TBAR_IsButtonAnimating(int *p)
{
    return CLACT_IsActorAnimActive((struct Actor *)(*p)) == 0;
}

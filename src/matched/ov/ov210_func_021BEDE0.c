/*
 * function: ZKNSEARCH_MAIN_IsActorAnimActive
 * address:  0x021BEDE0
 * packet:   pkt_ov210_021BEDE0
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Indexed 32-bit field fetch (base + i*4 + 0x28) forwarded as a tail call to
 * 0x0204B98C.  Blocker target of ZKNSEARCH_MAIN_UpdateMessageDialog.
 *
 * symbols:
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);

int ZKNSEARCH_MAIN_IsActorAnimActive(int a0, int a1)
{
    int *p = (int *)(a0 + a1 * 4);

    return CLACT_IsActorAnimActive((struct Actor *)p[0xa]);
}

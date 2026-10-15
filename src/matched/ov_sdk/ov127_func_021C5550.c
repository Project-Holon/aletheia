/*
 * function: WF2DMAP_ACTOR_FIND_HasMatch
 * address:  0x021C5550
 * packet:   pkt_021C5550
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C4BA4  0x021C4BA4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
extern u8 *func_021C4BA4(u8 *p, void *list, int n);

int WF2DMAP_ACTOR_FIND_HasMatch(void *a0, void *a1, int a2)
{
    return func_021C4BA4(a0, a1, a2) != 0;
}

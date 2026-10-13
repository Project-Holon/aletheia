/*
 * function: VS_MULTI_LIST_MoveSlotActors
 * address:  0x021F7308
 * packet:   pkt_ov097_021F7308
 * region:   ov097
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VS_MULTI_LIST_MoveActorX  0x021F72DC  thumb  ov097
 */

extern void VS_MULTI_LIST_MoveActorX(unsigned p, unsigned i, int dx);

void VS_MULTI_LIST_MoveSlotActors(int a, unsigned b, int c)
{
    unsigned i;

    for (i = b; i < b + 3; i++) {
        VS_MULTI_LIST_MoveActorX(a, i, c);
        VS_MULTI_LIST_MoveActorX(a, i + 6, c);
        VS_MULTI_LIST_MoveActorX(a, i + 12, c);
        VS_MULTI_LIST_MoveActorX(a, i + 18, c);
    }
}

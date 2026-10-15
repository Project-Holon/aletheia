/*
 * function: BOX2_SEQ_MoveActor
 * address:  0x021ED14C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_AddActorSurfacePos  0x021EC08C  thumb  ov170
 *
 * One range call with the sub-range selector.
 */



extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
void BOX2_SEQ_MoveActor(int a, int b, int c)
{
    BOX2_SEQ_AddActorSurfacePos((char *)a, 10, b, c, 0);
}

/*
 * function: BOX2_SEQ_MoveActorToSlotB
 * address:  0x021ED198
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_SEQ_GetSlotPos  0x021EC548  thumb  ov170
 *   BOX2_SEQ_MoveActor  0x021ED14C  thumb  ov170
 *
 * Read the 2-short record for the sub-range then push it back with
 *   the first element biased by 4.
 */


extern void BOX2_SEQ_GetSlotPos(unsigned i, short *x, short *y, int mode);
extern void BOX2_SEQ_MoveActor(int a, int b, int c);
void BOX2_SEQ_MoveActorToSlotB(char *p, int a, int c)
{
    short t[2];
    BOX2_SEQ_GetSlotPos(a, t + 1, t, c);
    BOX2_SEQ_MoveActor((int)p, t[1], (short)(t[0] + 4));
}

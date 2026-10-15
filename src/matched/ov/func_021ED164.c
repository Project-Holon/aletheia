/*
 * function: BOX2_SEQ_MoveActorToSlot
 * address:  0x021ED164
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_GetSlotPos  0x021EC548  thumb  ov170
 *   BOX2_SEQ_MoveActor  0x021ED14C  thumb  ov170
 *
 * Twin of BOX2_SEQ_MoveActorToSlotB with both shorts biased by 8.
 */


extern void BOX2_SEQ_GetSlotPos(unsigned i, short *x, short *y, int mode);
extern void BOX2_SEQ_MoveActor(int a, int b, int c);
void BOX2_SEQ_MoveActorToSlot(char *p, int a, int c)
{
    short t[2];
    BOX2_SEQ_GetSlotPos(a, t + 1, t, c);
    BOX2_SEQ_MoveActor((int)p, (short)(t[1] + 8), (short)(t[0] + 8));
}

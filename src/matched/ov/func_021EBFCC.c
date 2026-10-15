/*
 * function: BOX2_SEQ_SetActorAutoAnim
 * address:  0x021EBFCC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetActorAnimSeq  0x021EBFA8  thumb  ov170
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm  arm9
 *
 * Release-and-flag slot i of the 0x9E74 array.
 */


extern void BOX2_SEQ_SetActorAnimSeq(char *p, int i, int v);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *, unsigned int);
void BOX2_SEQ_SetActorAutoAnim(char *p, int i, int v)
{
    BOX2_SEQ_SetActorAnimSeq(p, i, v);
    CLACT_SetActorAutoAnim((struct Obj *)*(int *)(p + i * 4 + 0x9E74), 1);
}

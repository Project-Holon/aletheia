/*
 * function: BOX2_SEQ_HideActor
 * address:  0x021ECA24
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_ResetActorTransform  0x021ECA38  thumb  ov170
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *
 * Zero*p through the pool, then run the sibling teardown.
 */


struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void BOX2_SEQ_ResetActorTransform(int *);
void BOX2_SEQ_HideActor(int *p)
{
    CLACT_SetActorDrawEnable((struct Obj *)*p, 0);
    BOX2_SEQ_ResetActorTransform(p);
}

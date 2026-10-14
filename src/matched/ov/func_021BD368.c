/*
 * function: ZKND_TBAR_SetButtonAnimSeq
 * address:  0x021BD368
 * packet:   pkt_021BD368
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKND_TBAR_FindButtonActor 0x021BD404  thumb  ov208
 *   ZKND_TBAR_SetActorAnimSeq 0x021BD814  thumb  ov208
 */

extern int ZKND_TBAR_FindButtonActor(int, int);
extern void ZKND_TBAR_SetActorAnimSeq(char *p, int v);

void ZKND_TBAR_SetButtonAnimSeq(int a, int b, int c)
{
    ZKND_TBAR_SetActorAnimSeq((char *)ZKND_TBAR_FindButtonActor(a, b), c);
}


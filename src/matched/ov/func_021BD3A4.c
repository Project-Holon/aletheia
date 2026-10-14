/*
 * function: ZKND_TBAR_SetButtonAnimSeqOnce
 * address:  0x021BD3A4
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
 *   ZKND_TBAR_SetAnimByState 0x021BD848  thumb  ov208
 */

extern int ZKND_TBAR_FindButtonActor(int, int);
extern void ZKND_TBAR_SetAnimByState(char *p, int which);

void ZKND_TBAR_SetButtonAnimSeqOnce(int a, int b, int c)
{
    ZKND_TBAR_SetAnimByState((char *)ZKND_TBAR_FindButtonActor(a, b), c);
}


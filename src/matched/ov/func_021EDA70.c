/*
 * function: BOX2_UI_FindSlotPos
 * address:  0x021EDA70
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_GetActorSurfacePos  0x021EC0B0  thumb  ov170
 *
 * Scan six 0x2d-spaced panel rows for the (a1+1)*0x22 key and clear
 *   both shorts when nothing matched.  The key must be written as an
 *   ASSIGNMENT TO THE PARAMETER,
 *       a1 = (a1 + 1) * 0x22;
 *   then tested as `if (a1 == a3[0])`.  A separate `int k = ...` local
 *   loses the image's two-instruction parameter home (r6 = a1, r1 =
 *   r6+1, r6 = r1, muls r6) and swaps a2/a3 between r6 and r7.
 */

extern void BOX2_SEQ_GetActorSurfacePos(char *p, int i, short *a, short *b, unsigned short space);
extern void BOX2_SEQ_GetActorSurfacePos(char *p, int i, short *a, short *b, unsigned short space);
void BOX2_UI_FindSlotPos(int a0, int a1, short *a2, short *a3)
{
    unsigned i;
    a1 = (a1 + 1) * 0x22;
    for (i = 0; i < 6; i++) {
        BOX2_SEQ_GetActorSurfacePos((char *)a0, i + 0x2d, a2, a3, 0);
        if (a1 == a3[0])
            return;
    }
    *a2 = 0;
    *a3 = 0;
}


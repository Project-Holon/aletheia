/*
 * function: EVENT_RECOVERY_FinishBalls
 * address:  0x021C0A48
 * packet:   pkt_ov021_021C0A48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets mode 3 on each of the p[0x15] handles.
 *
 * symbols:
 *   FIELD_BUILDMODEL_PlayNodeSlot  0x0218C88C  thumb  ov021
 */

typedef unsigned char u8;

extern void FIELD_BUILDMODEL_PlayNodeSlot(unsigned char *p, int v, int c);

void EVENT_RECOVERY_FinishBalls(u8 *p)
{
    int i;

    for (i = 0; i < p[0x15]; i++)
        FIELD_BUILDMODEL_PlayNodeSlot((unsigned char *)(((int *)(p + 0x1C))[i]), 0, 3);
}

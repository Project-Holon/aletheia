/*
 * function: EVENT_RECOVERY_AreBallsIdle
 * address:  0x021C0A70
 * packet:   pkt_ov021_021C0A70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Returns 1 when every one of the p[0x15] handles reports done.
 *
 * symbols:
 *   FIELD_BUILDMODEL_IsNodeSlotIdle  0x0218C8FC  thumb  ov021
 */

typedef unsigned char u8;

extern int FIELD_BUILDMODEL_IsNodeSlotIdle(unsigned char *p, int i);

int EVENT_RECOVERY_AreBallsIdle(u8 *p)
{
    int i;

    for (i = 0; i < p[0x15]; i++) {
        if (FIELD_BUILDMODEL_IsNodeSlotIdle((unsigned char *)(((int *)(p + 0x1C))[i]), 0) != 1)
            return 0;
    }
    return 1;
}

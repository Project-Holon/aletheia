/*
 * function: FIELD_BUILDMODEL_TryOpenNodeSlot
 * address:  0x0218C8B0
 * packet:   pkt_ov021_0218C8B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_BUILDMODEL_IsNodeSlotIdle  0x0218C8FC  thumb  ov021
 *   FIELD_BUILDMODEL_PlayNodeSlot  0x0218C88C  thumb  ov021
 */

extern int FIELD_BUILDMODEL_IsNodeSlotIdle(unsigned char *p, int i);
extern void FIELD_BUILDMODEL_PlayNodeSlot(unsigned char *p, int v, int c);

int FIELD_BUILDMODEL_TryOpenNodeSlot(void *p, int v)
{
    if (p == 0)
        return 1;
    if (FIELD_BUILDMODEL_IsNodeSlotIdle(p, v) == 1) {
        FIELD_BUILDMODEL_PlayNodeSlot(p, v, 3);
        return 1;
    }
    return 0;
}

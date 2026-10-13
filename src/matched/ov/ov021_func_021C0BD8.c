/*
 * function: EVENT_RECOVERY_DeleteMachineNode
 * address:  0x021C0BD8
 * packet:   pkt_ov021_021C0BD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Releases the optional handle at +0x38.
 *
 * symbols:
 *   FIELD_BUILDMODEL_DeleteNode  0x0218C860  thumb  ov021
 */

extern void FIELD_BUILDMODEL_DeleteNode(int);

void EVENT_RECOVERY_DeleteMachineNode(int *p)
{
    if (p[13] != 0)
        FIELD_BUILDMODEL_DeleteNode(p[14]);
}

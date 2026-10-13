/*
 * function: FIELD_BUILDMODEL_IsNodeSlotIdle
 * address:  0x0218C8FC
 * packet:   pkt_ov021_0218C8FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_BUILDMODEL_IsSlotIdle  0x0218C43C  thumb  ov021
 */

typedef unsigned int   u32;
int FIELD_BUILDMODEL_IsSlotIdle(u32 *st, int i);

int FIELD_BUILDMODEL_IsNodeSlotIdle(unsigned char *p, int i)
{
    if (p == 0)
        return 0;
    return FIELD_BUILDMODEL_IsSlotIdle((u32 *)(p + 0xC), i);
}

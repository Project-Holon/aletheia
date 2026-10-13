/*
 * function: FIELD_BUILDMODEL_CheckNodeKindFlag
 * address:  0x0218C9A4
 * packet:   pkt_ov021_0218C9A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry  0x0218C990  thumb  ov021
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_IsSeSlotBusy  0x02006224  thumb
 */

int FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry(unsigned char *p, int v);
typedef unsigned int   u32;
int GFL_USE_GetSeSlot(u32 a0);
int GFL_USE_IsSeSlotBusy(u32 a0);

int FIELD_BUILDMODEL_CheckNodeKindFlag(void *p)
{
    unsigned short v;
    if (FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry(p, (int)(&v)) == 0)
        return 0;
    return GFL_USE_IsSeSlotBusy(GFL_USE_GetSeSlot(v));
}

/*
 * function: FIELD_BUILDMODEL_TryOpenNodeCurrentSlot
 * address:  0x0218C8D8
 * packet:   pkt_ov021_0218C8D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_BUILDMODEL_IsNodeCurrentSlotIdle  0x0218C910  thumb  ov021
 *   FIELD_BUILDMODEL_PlayNodeCurrentSlot  0x0218C89C  thumb  ov021
 */

int FIELD_BUILDMODEL_IsNodeCurrentSlotIdle(unsigned char *p);
void FIELD_BUILDMODEL_PlayNodeCurrentSlot(unsigned char *p, int v);

int FIELD_BUILDMODEL_TryOpenNodeCurrentSlot(void *p)
{
    if (p == 0)
        return 1;
    if (FIELD_BUILDMODEL_IsNodeCurrentSlotIdle(p) == 1) {
        FIELD_BUILDMODEL_PlayNodeCurrentSlot(p, 3);
        return 1;
    }
    return 0;
}

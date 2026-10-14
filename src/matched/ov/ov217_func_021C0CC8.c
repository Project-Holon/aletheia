/*
 * function: RESEARCH_COMMON_FreeSlotBuffers
 * address:  0x021C0CC8
 * packet:   pkt_ov217_021C0CC8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
struct PalAnmSlot;
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);

void RESEARCH_COMMON_FreeSlotBuffers(int *p)
{
    int obj;
    obj = p[10];
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)obj, 0);
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)obj, 2);
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)obj, 1);
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)obj, 3);
}

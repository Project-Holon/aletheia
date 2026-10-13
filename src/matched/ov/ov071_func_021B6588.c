/*
 * function: MONOLITH_TOOL_FreePalAnm
 * address: 0x021B6588
 * packet: pkt_ov071_021B6588
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 */
typedef unsigned int u32;
struct PalAnmSlot;
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *, u32);
extern u32 PALANM_Delete(void *a0);
void MONOLITH_TOOL_FreePalAnm(struct PalAnmSlot **p)
{
    PALANM_FreeSlotBuffers(*p, 2);
    PALANM_FreeSlotBuffers(*p, 3);
    PALANM_FreeSlotBuffers(*p, 0);
    PALANM_FreeSlotBuffers(*p, 1);
    PALANM_Delete(*p);
}

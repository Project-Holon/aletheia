/*
 * function: ITEMMENU_FreePalAnmSlots
 * address: 0x021B8E84
 * packet: pkt_ov070_021B8E84
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 02021540 forwards r0 to the allocator's free; name the pointer here
 * despite its legacy ARM9 thunk definition omitting that argument.
 * symbols:
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 */
#include "../include/Obj09878.h"
typedef unsigned int u32;
struct PalAnmSlot;
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
void ITEMMENU_FreePalAnmSlots(char *p)
{
    PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj09878 *)p)->f854, 0);
    PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj09878 *)p)->f854, 2);
    PALANM_Delete(*(struct PalAnmSlot * *)&((struct Obj09878 *)p)->f854);
}

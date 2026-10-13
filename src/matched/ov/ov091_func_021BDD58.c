/*
 * function: PLIST_DEMO_ApplyShayminSkyForm
 * address: 0x021BDD58
 * packet: pkt_ov091_021BDD58
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent tail: two bytes of alignment padding at 0x021BDD76.
 * symbols:
 *   POKE_TOOL_ChangeForm 0x02017988 thumb
 *   ZUKAN_SAVE_RegisterCaught 0x0200CDE0 thumb
 */
#include "../include/Obj20931.h"
typedef unsigned int u32;
struct Blk37;
extern u32 POKE_TOOL_ChangeForm(void *, u32);
extern void ZUKAN_SAVE_RegisterCaught(struct Blk37 *, void *);
void PLIST_DEMO_ApplyShayminSkyForm(u32 p, void *m)
{
    POKE_TOOL_ChangeForm(m, 1);
    ZUKAN_SAVE_RegisterCaught(*(struct Blk37 **)(((struct Obj20931 *)p)->f280 + 0x18), m);
}

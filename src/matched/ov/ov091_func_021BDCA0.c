/*
 * function: PLIST_DEMO_ApplyGiratinaAlteredForm
 * address: 0x021BDCA0
 * packet: pkt_ov091_021BDCA0
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent tail: two bytes of alignment padding at 0x021BDCBE.
 * symbols:
 *   POKE_TOOL_ChangeForm 0x02017988 thumb
 *   ZUKAN_SAVE_RegisterCaught 0x0200CDE0 thumb
 */
#include "../include/Obj20928.h"
typedef unsigned int u32;
struct Blk37;
extern u32 POKE_TOOL_ChangeForm(void *, u32);
extern void ZUKAN_SAVE_RegisterCaught(struct Blk37 *, void *);
void PLIST_DEMO_ApplyGiratinaAlteredForm(u32 p, void *m)
{
    POKE_TOOL_ChangeForm(m, 0);
    ZUKAN_SAVE_RegisterCaught(*(struct Blk37 **)(((struct Obj20928 *)p)->f280 + 0x18), m);
}

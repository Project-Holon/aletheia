/*
 * function: BEACON_VIEW_UpdateFadeWait
 * address: 0x021F26F0
 * packet: pkt_ov032_021F26F0
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: BEACON_VIEW_RefreshActorAnims forwards r0 to BEACON_VIEW_UpdateActorAnims, which reads p.
 * symbols:
 *   BEACON_VIEW_SetArrowAnim 0x021F05E8 thumb ov032
 *   BEACON_VIEW_RefreshActorAnims 0x021F067C thumb ov032
 */
#include "../include/Obj00007.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void BEACON_VIEW_SetArrowAnim(u8 *, int, u32);
extern void BEACON_VIEW_RefreshActorAnims(char *p);
int BEACON_VIEW_UpdateFadeWait(u8 *p)
{
    if (((struct Obj00007 *)p)->fA8 != 0)
        return 2;
    BEACON_VIEW_SetArrowAnim(p, 4, 0);
    BEACON_VIEW_RefreshActorAnims((char *)p);
    return 0;
}

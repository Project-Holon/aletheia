/*
 * function: EVENT_ENTRANCE_IN_ShouldFadeBgm
 * address:  0x021BD8C0
 * packet:   pkt_ov021_021BD8C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_ENTRANCE_IN_IsDungeonTransition  0x021BD904  thumb  ov021
 *   EVENT_ENTRANCE_IN_GetPlayerForm  0x021BD93C  thumb  ov021
 *   FIELD_SOUND_SYSTEM_HasZoneBgmOverride  0x02029E08  thumb
 *   FIELD_SOUND_SYSTEM_GetFinalBgm  0x02029DFC  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12889.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int EVENT_ENTRANCE_IN_IsDungeonTransition(u32 *);
extern int EVENT_ENTRANCE_IN_GetPlayerForm(u32 *);
extern int FIELD_SOUND_SYSTEM_HasZoneBgmOverride(int a0, int a1);
extern void *FIELD_SOUND_SYSTEM_GetFinalBgm(const void *p);

u32 EVENT_ENTRANCE_IN_ShouldFadeBgm(u32 *ctx)
{
    u8 *p = (u8 *)ctx[2];
    u32 q = ((struct Obj12889 *)p)->f8;

    if (!EVENT_ENTRANCE_IN_IsDungeonTransition(ctx))
        return 0;
    if (FIELD_SOUND_SYSTEM_HasZoneBgmOverride(q, ((struct Obj12889 *)p)->f20))
        return 0;
    if (EVENT_ENTRANCE_IN_GetPlayerForm(ctx) == 1 && (u32)FIELD_SOUND_SYSTEM_GetFinalBgm((const void *)q) == 0x3F4)
        return 0;
    return 1;
}

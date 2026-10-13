/*
 * function: FIELD_SOUND_SYSTEM_UpdateFadingInLoaded
 * address:  0x02029288
 * packet:   pkt_02029250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_IsBgmFading  0x02005E50  thumb
 *   FIELD_SOUND_SYSTEM_SetState  0x02029344  thumb
 *   FIELD_SOUND_SYSTEM_FinishRequest  0x02029364  thumb
 *   FIELD_SOUND_SYSTEM_FadeOutCurrentBgm  0x0202938C  thumb
 */
#include "../include/Obj05724.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern int GFL_USE_IsBgmFading(void);
extern void FIELD_SOUND_SYSTEM_SetState(void *obj, u32 value);
extern void FIELD_SOUND_SYSTEM_FadeOutCurrentBgm(u8 *p);
extern void FIELD_SOUND_SYSTEM_FinishRequest(u8 *p);

void FIELD_SOUND_SYSTEM_UpdateFadingInLoaded(u8 *p)
{
    if (GFL_USE_IsBgmFading() != 0) {
        return;
    }
    if (((struct Obj05724 *)p)->fC != 0 && ((struct Obj05724 *)p)->fC != ((struct Obj05724 *)p)->f8) {
        FIELD_SOUND_SYSTEM_FadeOutCurrentBgm(p);
        FIELD_SOUND_SYSTEM_SetState(p, 8);
        return;
    }
    FIELD_SOUND_SYSTEM_SetState(p, 1);
    FIELD_SOUND_SYSTEM_FinishRequest(p);
}

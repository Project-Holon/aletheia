/*
 * function: WEATHER_TASK_PlaySeWithVoice
 * address:  0x021A2604
 * packet:   pkt_ov021_021A2604
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_IsLoaderBusy  0x02005C64  thumb
 *   FIELD_SOUND_SYSTEM_ClaimSlotWithOwner  0x02028ACC  thumb
 *   GFL_USE_PlaySeWithVolume  0x020061F0  thumb
 */
#include "../include/Obj12714.h"

typedef unsigned char u8;
typedef unsigned int  u32;

int GFL_USE_IsLoaderBusy(void);
struct SoundSys2;
void FIELD_SOUND_SYSTEM_ClaimSlotWithOwner(struct SoundSys2 *s, u32 id, u32 who);
void GFL_USE_PlaySeWithVolume(u32 a, u32 b);

void WEATHER_TASK_PlaySeWithVoice(u8 *p, int a, int b)
{
    if (GFL_USE_IsLoaderBusy() == 0) {
        if (((struct Obj12714 *)p)->f48 != 0)
            FIELD_SOUND_SYSTEM_ClaimSlotWithOwner((struct SoundSys2 *)(((struct Obj12714 *)p)->fC), a, b);
        else
            GFL_USE_PlaySeWithVolume(a, b);
    }
}

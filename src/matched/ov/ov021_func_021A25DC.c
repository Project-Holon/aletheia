/*
 * function: WEATHER_TASK_PlaySeDirect
 * address:  0x021A25DC
 * packet:   pkt_ov021_021A25DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_USE_IsLoaderBusy  0x02005C64  thumb
 *   FIELD_SOUND_SYSTEM_ClaimSlot  0x02028A7C  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */
#include "../include/Obj00954.h"

typedef unsigned char u8;
typedef unsigned int  u32;

int GFL_USE_IsLoaderBusy(void);
struct SoundSys2;
void FIELD_SOUND_SYSTEM_ClaimSlot(struct SoundSys2 *s, u32 id);
void GFL_USE_PlaySeDefaultVolume(u32 a);

void WEATHER_TASK_PlaySeDirect(u8 *p, int a)
{
    if (GFL_USE_IsLoaderBusy() == 0) {
        if (((struct Obj00954 *)p)->f48 != 0)
            FIELD_SOUND_SYSTEM_ClaimSlot((struct SoundSys2 *)(((struct Obj00954 *)p)->fC), a);
        else
            GFL_USE_PlaySeDefaultVolume(a);
    }
}

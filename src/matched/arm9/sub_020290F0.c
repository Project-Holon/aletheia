/*
 * function: FIELD_SOUND_SYSTEM_HandleModeState2
 * address:  0x020290F0
 * packet:   pkt_02028FD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_SetState  0x02029344  thumb
 *   FIELD_SOUND_SYSTEM_FinishRequest  0x02029364  thumb
 *   FIELD_SOUND_SYSTEM_FadeInCurrentBgm  0x02029374  thumb
 *   FIELD_SOUND_SYSTEM_PlayRequestedBgmNow  0x0202945C  thumb
 */
#include "../include/Obj16754.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void FIELD_SOUND_SYSTEM_FadeInCurrentBgm(u8 *p);
extern void FIELD_SOUND_SYSTEM_SetState(void *p, u32 v);
extern void FIELD_SOUND_SYSTEM_PlayRequestedBgmNow(u8 *p);
extern void FIELD_SOUND_SYSTEM_FinishRequest(u8 *p);

void FIELD_SOUND_SYSTEM_HandleModeState2(u8 *p)
{
    switch (((struct Obj16754 *)p)->f1C) {
    case 0:
        break;
    case 1:
        FIELD_SOUND_SYSTEM_FadeInCurrentBgm(p);
        FIELD_SOUND_SYSTEM_SetState(p, 4);
        break;
    case 7:
        FIELD_SOUND_SYSTEM_PlayRequestedBgmNow(p);
        FIELD_SOUND_SYSTEM_SetState(p, 1);
        FIELD_SOUND_SYSTEM_FinishRequest(p);
        break;
    }
}

/*
 * function: FIELD_SOUND_SYSTEM_UpdateLoading
 * address:  0x02029250
 * packet:   pkt_02029250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb
 *   FIELD_SOUND_SYSTEM_SetState  0x02029344  thumb
 *   FIELD_SOUND_SYSTEM_FadeInCurrentBgm  0x02029374  thumb
 *   FIELD_SOUND_SYSTEM_StepBgmLoading  0x02029434  thumb
 */
#include "../include/Obj00164.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  FIELD_SOUND_SYSTEM_StepBgmLoading(u8 *p);
extern void FIELD_SOUND_SYSTEM_SetState(void *obj, u32 value);
extern void FIELD_SOUND_SYSTEM_FadeInCurrentBgm(u8 *p);
extern void GFL_USE_CancelChangeAndStopBgm(void);

void FIELD_SOUND_SYSTEM_UpdateLoading(u8 *p)
{
    if (FIELD_SOUND_SYSTEM_StepBgmLoading(p) == 0) {
        return;
    }
    if (((struct Obj00164 *)p)->fC != 0 && ((struct Obj00164 *)p)->fC != ((struct Obj00164 *)p)->f8) {
        GFL_USE_CancelChangeAndStopBgm();
        FIELD_SOUND_SYSTEM_SetState(p, 8);
        return;
    }
    FIELD_SOUND_SYSTEM_FadeInCurrentBgm(p);
    FIELD_SOUND_SYSTEM_SetState(p, 0xa);
}

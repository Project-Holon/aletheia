/*
 * function: FIELD_SOUND_SYSTEM_PlayRequestedBgmNow
 * address:  0x0202945C
 * packet:   pkt_02029354
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FIELD_SOUND_SYSTEM_PlayRequestedBgmNow.c \\
 *       --func FIELD_SOUND_SYSTEM_PlayRequestedBgmNow --addr 0x0202945C --thumb --cc 1.1p1
 *
 * symbols:
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 */
#include "../include/Obj04742.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void GFL_USE_CancelChangeAndPlayBgm(u32 a, u32 b);

void FIELD_SOUND_SYSTEM_PlayRequestedBgmNow(u8 *p)
{
    if (((struct Obj04742 *)p)->fC != 0) {
        GFL_USE_CancelChangeAndPlayBgm(((struct Obj04742 *)p)->fC, 0xffff);
        ((struct Obj04742 *)p)->f8 = ((struct Obj04742 *)p)->fC;
        ((struct Obj04742 *)p)->fC = 0;
        ((struct Obj04742 *)p)->f10 = 0;
    }
}

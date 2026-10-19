/*
 * function: FIELD_SOUND_SYSTEM_FadeInCurrentBgm
 * address:  0x02029374
 * packet:   pkt_02029354
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FIELD_SOUND_SYSTEM_FadeInCurrentBgm.c \\
 *       --func FIELD_SOUND_SYSTEM_FadeInCurrentBgm --addr 0x02029374 --thumb --cc 1.1p1
 *
 * symbols:
 *   GFL_USE_SetBgmPaused  0x02005DE4  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 */
#include "../include/Obj00164.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void GFL_USE_FadeInBgmFull(u32 v);
extern void GFL_USE_SetBgmPaused(void *p);

void FIELD_SOUND_SYSTEM_FadeInCurrentBgm(u8 *p)
{
    if (((struct Obj00164 *)p)->f8 == 0) {
        return;
    }
    GFL_USE_FadeInBgmFull(((struct Obj00164 *)p)->f18);
    GFL_USE_SetBgmPaused(0);
}

/*
 * function: FIELD_SOUND_SYSTEM_FadeOutCurrentBgm
 * address:  0x0202938C
 * packet:   pkt_02029354
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FIELD_SOUND_SYSTEM_FadeOutCurrentBgm.c \\
 *       --func FIELD_SOUND_SYSTEM_FadeOutCurrentBgm --addr 0x0202938C --thumb --cc 1.1p1
 *
 * symbols:
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 */
#include "../include/Obj05724.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void GFL_USE_FadeOutBgm(u32 v);

void FIELD_SOUND_SYSTEM_FadeOutCurrentBgm(u8 *p)
{
    if (((struct Obj05724 *)p)->f8 != 0) {
        GFL_USE_FadeOutBgm(((struct Obj05724 *)p)->f1A);
    }
}

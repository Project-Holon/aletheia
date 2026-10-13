/*
 * function: ISS_ROAD_SYS_FadeOut
 * address:  0x0202B2A4
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Lowers the object's +4 value by 8, saturating at 0, and refreshes it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ROAD_SYS_FadeOut.c \
 *       --func ISS_ROAD_SYS_FadeOut --addr 0x0202B2A4 --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_ROAD_SYS_ApplyVolume  0x0202B2BC  thumb
 */
#include "../include/Obj03001.h"

typedef unsigned char u8;
typedef signed int    s32;
typedef unsigned int  u32;

extern void ISS_ROAD_SYS_ApplyVolume(u8 *p);

void ISS_ROAD_SYS_FadeOut(u8 *p)
{
    s32 v = (s32)((struct Obj03001 *)p)->f4;

    if (v > 0) {
        v -= 8;
        if (v < 0) {
            v = 0;
        }
        ((struct Obj03001 *)p)->f4 = (u32)v;
        ISS_ROAD_SYS_ApplyVolume(p);
    }
}

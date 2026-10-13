/*
 * function: ISS_ROAD_SYS_UpdateVolume
 * address:  0x0202B230
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * When the object is active, polls it and either advances or retreats.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ROAD_SYS_UpdateVolume.c \
 *       --func ISS_ROAD_SYS_UpdateVolume --addr 0x0202B230 --thumb --cc 1.1p1

 * Closed by the `matched` class: 0x0202B254 was filed as an EXACT entry this wave (pkt_0202B230).
 *
 * symbols:
 *   ISS_ROAD_SYS_HasPlayerMoved  0x0202B254  thumb
 *   ISS_ROAD_SYS_FadeIn  0x0202B28C  thumb
 *   ISS_ROAD_SYS_FadeOut  0x0202B2A4  thumb
 */
#include "../include/Obj03001.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  ISS_ROAD_SYS_HasPlayerMoved(u8 *p);
extern void ISS_ROAD_SYS_FadeIn(u8 *p);
extern void ISS_ROAD_SYS_FadeOut(u8 *p);

void ISS_ROAD_SYS_UpdateVolume(u8 *p)
{
    if (((struct Obj03001 *)p)->f0 == 0) {
        return;
    }
    if (ISS_ROAD_SYS_HasPlayerMoved(p) != 0) {
        ISS_ROAD_SYS_FadeIn(p);
    } else {
        ISS_ROAD_SYS_FadeOut(p);
    }
}

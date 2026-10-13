/*
 * function: ISS_ROAD_SYS_Activate
 * address:  0x0202B20C
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * When the object is idle, marks it started, clears its +4 value and
 * refreshes it through ISS_ROAD_SYS_ApplyVolume.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ROAD_SYS_Activate.c \
 *       --func ISS_ROAD_SYS_Activate --addr 0x0202B20C --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_ROAD_SYS_ApplyVolume  0x0202B2BC  thumb
 */
#include "../include/Obj08802.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void ISS_ROAD_SYS_ApplyVolume(u8 *p);

void ISS_ROAD_SYS_Activate(u8 *p)
{
    if (((struct Obj08802 *)p)->f0 == 0) {
        ((struct Obj08802 *)p)->f0 = 1;
        ((struct Obj08802 *)p)->f4 = 0;
        ISS_ROAD_SYS_ApplyVolume(p);
    }
}

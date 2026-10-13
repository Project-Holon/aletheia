/*
 * function: ISS_ROAD_SYS_ApplyVolume
 * address:  0x0202B2BC
 * packet:   pkt_0202B1F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-calls GFL_USE_SetBgmTrackVolume(0x300, value).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ROAD_SYS_ApplyVolume.c \
 *       --func ISS_ROAD_SYS_ApplyVolume --addr 0x0202B2BC --thumb --cc 1.1p1
 *
 * symbols:
 *   GFL_USE_SetBgmTrackVolume  0x02005F24  thumb
 */
#include "../include/Obj15831.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void GFL_USE_SetBgmTrackVolume(u32 a, u32 b);

void ISS_ROAD_SYS_ApplyVolume(u8 *p)
{
    GFL_USE_SetBgmTrackVolume(0x300, ((struct Obj15831 *)p)->f4);
}

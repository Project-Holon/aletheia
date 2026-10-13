/*
 * function: ZONEDATA_SetExitRailLocation
 * address:  0x02014134
 * packet:   pkt_02014134
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ZONEDATA_SetExitRailLocation.c \
 *       --func ZONEDATA_SetExitRailLocation --addr 0x02014134 --cc 1.1p1 --thumb
 *
 * symbols:
 *   ZONEDATA_ExitDirToDir  0x02014274  thumb
 *   ZONEDATA_DirToRailKey  0x0201441C  thumb
 */
#include "../include/Obj00193.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;
typedef signed int s32;

extern u32  ZONEDATA_ExitDirToDir(u32 a);
extern u8 ZONEDATA_DirToRailKey(int i);

void ZONEDATA_SetExitRailLocation(u8 *p, u16 b, int c, u16 d, u16 e, u16 f, u16 g, s16 h)
{
    ((struct Obj00193 *)p)->f0 = 0;
    ((struct Obj00193 *)p)->f4 = b;
    ((struct Obj00193 *)p)->f6 = c;
    ((struct Obj00193 *)p)->f8 = d;
    ((struct Obj00193 *)p)->fA = e;
    ((struct Obj00193 *)p)->fC = 1;
    *(u8 *)(p + 0x12) = 1;
    *(u16 *)&((struct Obj00193 *)p)->f10 = f;
    *(u16 *)(p + 0x16) = g;
    *(u16 *)&((struct Obj00193 *)p)->f14 = h;
    *(u8 *)(p + 0x13) = ZONEDATA_DirToRailKey(ZONEDATA_ExitDirToDir(d));
}

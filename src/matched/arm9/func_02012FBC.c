/*
 * function: GAME_DATA_CheckPlayTime
 * address:  0x02012FBC
 * packet:   pkt_02012FBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_DATA_CheckPlayTime.c \
 *       --func GAME_DATA_CheckPlayTime --addr 0x02012FBC --cc 1.1p1 --thumb
 */
#include "../include/Obj15640.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern u32 func_020085D4(u32 v, u32 x);

u32 GAME_DATA_CheckPlayTime(u8 *p, u32 x)
{
    return func_020085D4(((struct Obj15640 *)p)->f6AC, x);
}

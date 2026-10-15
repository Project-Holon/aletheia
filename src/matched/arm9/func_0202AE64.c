/*
 * function: ISS_CITY_SYS_GetVolume
 * address:  0x0202AE64
 * packet:   pkt_0202AE68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker FILE_UTIL_GetBankCount.c is now a manifest entry (matched class)
 *
 * Plain field read: the word at 0xc.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ISS_CITY_SYS_GetVolume.c \
 *       --func ISS_CITY_SYS_GetVolume --addr 0x0202AE64 --thumb --cc 1.1p1
 */
#include "../include/Obj11306.h"

typedef unsigned char u8;
typedef unsigned int  u32;

u32 ISS_CITY_SYS_GetVolume(u8 *p)
{
    return ((struct Obj11306 *)p)->fC;
}

/*
 * function: NNSi_G2dFixupCharacterDataEx
 * address:  0x02062A88
 * packet:   pkt_0206296C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * *
 * One-field offset-to-pointer fixup for the second 'RAHC' consumer, same fixup: the u32 at +0x14 is a
 * self-relative offset that becomes an absolute pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G2dFixupCharacterDataEx.c  *       --func NNSi_G2dFixupCharacterDataEx --addr 0x02062A88 --cc 1.1p1
 */
#include "../include/Obj11517.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


void NNSi_G2dFixupCharacterDataEx(u8 *block)
{
    ((struct Obj11517 *)block)->f14 = ((struct Obj11517 *)block)->f14 + (u32)block;
}

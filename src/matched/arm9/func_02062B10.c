/*
 * function: func_02062B10
 * address:  0x02062B10
 * packet:   pkt_0206296C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * *
 * One-field offset-to-pointer fixup for the palette-compress-proxy bank ('PMCP' body): the u32 at +0x4 is a
 * self-relative offset that becomes an absolute pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062B10.c  *       --func func_02062B10 --addr 0x02062B10 --cc 1.1p1
 */
#include "../include/Obj11520.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


void func_02062B10(u8 *block)
{
    ((struct Obj11520 *)block)->f4 = ((struct Obj11520 *)block)->f4 + (u32)block;
}

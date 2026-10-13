/*
 * function: func_02062A3C
 * address:  0x02062A3C
 * packet:   pkt_0206296C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * *
 * One-field offset-to-pointer fixup for the character-data bank ('RAHC' / NCGR body): the u32 at +0x14 is a
 * self-relative offset that becomes an absolute pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062A3C.c  *       --func func_02062A3C --addr 0x02062A3C --cc 1.1p1
 */
#include "../include/Obj11515.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


void func_02062A3C(u8 *block)
{
    ((struct Obj11515 *)block)->f14 = ((struct Obj11515 *)block)->f14 + (u32)block;
}

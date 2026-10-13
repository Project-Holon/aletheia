/*
 * function: func_02062B20
 * address:  0x02062B20
 * packet:   pkt_0206296C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * *
 * One-field offset-to-pointer fixup for the palette bank ('TTLP' / NCLR body): the u32 at +0xc is a
 * self-relative offset that becomes an absolute pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062B20.c  *       --func func_02062B20 --addr 0x02062B20 --cc 1.1p1
 */
#include "../include/Obj11521.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


void func_02062B20(u8 *block)
{
    ((struct Obj11521 *)block)->fC = ((struct Obj11521 *)block)->fC + (u32)block;
}

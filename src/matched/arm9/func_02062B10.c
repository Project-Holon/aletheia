/*
 * function: NNSi_G2dFixupPaletteCompressInfo
 * address:  0x02062B10
 * packet:   pkt_0206296C
 * region:   arm9
 * compiler: ../2.0/sp2
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
 *   python tools/match.py one --src src/matched/NNSi_G2dFixupPaletteCompressInfo.c  *       --func NNSi_G2dFixupPaletteCompressInfo --addr 0x02062B10 --cc 1.1p1
 */
#include "../include/Obj11520.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


void NNSi_G2dFixupPaletteCompressInfo(u8 *block)
{
    ((struct Obj11520 *)block)->f4 = ((struct Obj11520 *)block)->f4 + (u32)block;
}

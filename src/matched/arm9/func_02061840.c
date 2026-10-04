/*
 * function: func_02061840
 * address:  0x02061840
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _u32_div_f   0x0209C2B0  arm
 *
 * Returns (value + 1) modulo the +4 word, truncated to a halfword.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02061840.c \
 *       --func func_02061840 --addr 0x02061840 --arm --cc 1.1p1
 */
#include "../include/Obj16393.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_02061840(u8 *p, u32 v)
{
    return (u16)((v + 1) % ((struct Obj16393 *)p)->f4);
}
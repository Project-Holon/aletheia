/*
 * function: sub_0200F800
 * address:  0x0200F800
 * packet:   pkt_0200F168
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D534 0x0207D534  arm
 *
 * Two writes of a fixed global struct's fields straight to hardware I/O
 * registers at 0x0400006C and 0x0400106C (main-engine and sub-engine
 * capture control, per the DS memory map); the global at 0x0214617C is
 * read at +0x14 and +0x18 for the values written to each. The addresses
 * are literal pool words, not symbol references, so nothing needed
 * relocation resolution here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F800.c \
 *       --func sub_0200F800 --addr 0x0200F800 --cc 1.1p1
 */
#include "../include/Obj11713.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef unsigned short u16;
extern void func_0207D534(volatile u16 *reg, int brightness);

void sub_0200F800(void)
{
    u32 *g = (u32 *)0x0214617C;
    func_0207D534((volatile u16 *)0x0400006C, ((struct Obj11713 *)g)->f14);
    func_0207D534((volatile u16 *)0x0400106C, ((struct Obj11713 *)g)->f18);
}

/*
 * unit:     no
 * function: func_02036E80
 * address:  0x02036E80
 * packet:   pkt_02036CA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Program two four-field control blocks: the base one at 0x07000000 always,
 * the second at 0x07000400 only when the byte at +0xe of the record is set.
 * Each block writes the constant 0x40000200, a zero halfword, the same
 * constant, then another zero halfword, which the compiler emits as a
 * word/halfword/word/halfword run off one base register.  The record is then
 * released through the overruled SDK address 0x020307B0 (matched), attesting
 * the PC24 site.  This function was the last blocker for
 * src/matched/func_020370C8.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036E80.c \
 *       --func func_02036E80 --addr 0x02036E80 --arm --cc 1.1p1
 */
#include "../include/Obj06937.h"

typedef unsigned int  u32;
typedef unsigned short u16;

extern u32 func_020307B0(void *p);

void func_02036E80(unsigned char *p)
{
    *(volatile u32 *)0x07000000 = 0x40000200;
    *(volatile u16 *)0x07000004 = 0;
    *(volatile u32 *)0x07000008 = 0x40000200;
    *(volatile u16 *)0x0700000c = 0;
    if (p[0xe] != 0) {
        volatile u32 *q = (volatile u32 *)(0x07000000 + 0x400);
        q[0] = 0x40000200;
        *(volatile u16 *)&((struct Obj06937 *)q)->f4 = 0;
        q[2] = 0x40000200;
        *(volatile u16 *)&((struct Obj06937 *)q)->fC = 0;
    }
    func_020307B0(p);
}

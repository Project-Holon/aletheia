/*
 * function: func_02028164
 * address:  0x02028164
 * packet:   pkt_02027FEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02028164.c \\
 *       --func func_02028164 --addr 0x02028164 --thumb --cc 1.1p1
 */
#include "../include/Obj15779.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
extern void func_020307B0(void *p);

void func_02028164(u8 *p)
{
    func_020452E8((struct Descriptor *)(((struct Obj15779 *)p)->f0));
    func_020307B0(p);
}

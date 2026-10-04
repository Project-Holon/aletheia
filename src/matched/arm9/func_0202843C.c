/*
 * function: func_0202843C
 * address:  0x0202843C
 * packet:   pkt_02027FEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202843C.c \\
 *       --func func_0202843C --addr 0x0202843C --thumb --cc 1.1p1
 */
#include "../include/Obj11291.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Descriptor;
extern void func_020456F8(struct Descriptor *d);
extern void func_02041B6C(u32 v);

void func_0202843C(u8 *p)
{
    func_020456F8((struct Descriptor *)(((struct Obj11291 *)p)->f0));
    func_02041B6C((u8)*(u16 *)(((struct Obj11291 *)p)->f18));
}

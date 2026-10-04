/*
 * function: func_0202B894
 * address:  0x0202B894
 * packet:   pkt_0202B744
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker  is now a manifest entry (matched class)
 *
 * Allocates and clears a 0x26c-byte node, seeds its three scalar members and
 * runs its three initialisers.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202B894.c \
 *       --func func_0202B894 --addr 0x0202B894 --thumb --cc 1.1p1
 */
#include "../include/Obj01019.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_0202BA24(u8 *p);
extern void func_0202B944(void *obj);
extern void  func_0202B958(u8 *p);

u8 *func_0202B894(u32 id)
{
    u8 *p = (u8 *)func_02030734(id, 0x26c, 0, (const void *)0x020A7738, 0xa3);

    ((struct Obj01019 *)p)->f0 = (u16)id;
    ((struct Obj01019 *)p)->f4 = 0;
    p[8] = 0x7f;
    p[9] = 0x7f;
    p[0xa] = 4;
    ((struct Obj01019 *)p)->fC = 0;
    ((struct Obj01019 *)p)->f10 = 0;
    ((struct Obj01019 *)p)->f14 = 0;
    ((struct Obj01019 *)p)->f18 = 0;
    ((struct Obj01019 *)p)->f1C = 0;
    ((struct Obj01019 *)p)->f20 = 0;

    func_0202BA24(p);
    func_0202B944(p);
    func_0202B958(p);
    return p;
}

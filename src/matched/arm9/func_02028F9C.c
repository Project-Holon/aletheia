/*
 * function: func_02028F9C
 * address:  0x02028F9C
 * packet:   pkt_02028F30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker func_02028F48.c is now a manifest entry (matched class)
 *
 * Node kind 6 setter: guarded by func_02028FD0, then the kind tag and
 * this kind's payload members are written.
 *
 * symbols:
 *   func_02028FD0  0x02028FD0  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02028F9C.c \
 *       --func func_02028F9C --addr 0x02028F9C --thumb --cc 1.1p1
 */
#include "../include/Obj00354.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct SoundParam;
extern u32 func_02028FD0(struct SoundParam *obj, u32 kind);

void func_02028F9C(u8 *p, u32 a, u32 b)
{
    if (func_02028FD0((struct SoundParam *)p, 6) != 0) {
        ((struct Obj00354 *)p)->f1C = (u32)6;
        ((struct Obj00354 *)p)->fC = (u32)a;
        ((struct Obj00354 *)p)->f1A = (u16)b;
    }
}

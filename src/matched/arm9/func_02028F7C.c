/*
 * function: func_02028F7C
 * address:  0x02028F7C
 * packet:   pkt_02028F30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker func_02028F48.c is now a manifest entry (matched class)
 *
 * Node kind 5 setter: guarded by func_02028FD0, then the kind tag and
 * this kind's payload members are written.
 *
 * symbols:
 *   func_02028FD0  0x02028FD0  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02028F7C.c \
 *       --func func_02028F7C --addr 0x02028F7C --thumb --cc 1.1p1
 */
#include "../include/Obj00354.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct SoundParam;
extern u32 func_02028FD0(struct SoundParam *obj, u32 kind);

void func_02028F7C(u8 *p, u32 a, u32 b, u32 c)
{
    if (func_02028FD0((struct SoundParam *)p, 5) != 0) {
        ((struct Obj00354 *)p)->f1C = (u32)5;
        ((struct Obj00354 *)p)->fC = (u32)a;
        ((struct Obj00354 *)p)->f18 = (u16)c;
        ((struct Obj00354 *)p)->f1A = (u16)b;
    }
}

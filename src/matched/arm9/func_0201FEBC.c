/*
 * function: func_0201FEBC
 * address:  0x0201FEBC
 * packet:   pkt_0201FC5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201FEBC.c \
 *       --func func_0201FEBC --addr 0x0201FEBC --cc 1.1p1 --thumb
 */
#include "../include/Obj02590.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

struct Obj;
extern u32 func_0201FA04(struct Obj *o);
struct PrintSys;
extern u32 func_0201C4E4(struct PrintSys *ps);
struct Descriptor;
extern void func_02045334(struct Descriptor *a);
extern void func_0201FEF4(u8 *o);

u32 func_0201FEBC(u8 *p)
{
    u32 r = func_0201FA04((struct Obj *)p);
    u32 t = func_0201C4E4((struct PrintSys *)(((struct Obj02590 *)p)->f18));

    if (((struct Obj02590 *)p)->f20 == 0 && t != 0) {
        func_02045334((struct Descriptor *)((struct Obj02590 *)p)->f4);
        ((struct Obj02590 *)p)->f20 = 1;
    }
    if (r != 0xffffffff) {
        func_0201FEF4(p);
    }
    return r;
}


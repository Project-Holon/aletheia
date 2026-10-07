/*
 * file:     field_ground_anime_p07.c
 * unit:     yes
 * function: func_021A7AB0, func_021A7B08
 * address:  0x021A7AB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A811C  0x021A811C  thumb
 */
#include "../../matched/include/Obj12760.h"

struct V3;
typedef unsigned int u32;

typedef struct Out {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0C;
    u32 f10;
    u32 f14;
    u32 f18;
} Out;

typedef unsigned char  u8;

typedef unsigned short u16;

extern int func_021A811C(u32 a, u32 b);
void func_021A7AB0(u32 *src, Out *o);
void func_021A7B08(int a, struct V3 *b);


void func_021A7AB0(u32 *src, Out *o)
{
    u32 n;
    u32 p;
    u32 m;

    n = *src;
    p = (u32)(src + 1);
    o->f10 = n;
    o->f00 = p;
    p += n * 2;
    m = (n * 2) & 3;
    if (m != 0) p += 4 - m;
    o->f04 = p;
    p += o->f10;
    m = o->f10 & 3;
    if (m != 0) p += 4 - m;
    o->f08 = p;
    p += o->f10;
    m = o->f10 & 3;
    if (m != 0) p += 4 - m;
    n = ((struct Obj12760 *)p)->f0;
    p += 4;
    o->f0C = p;
    o->f14 = n;
    p += n;
    m = n & 3;
    if (m != 0) p += 4 - m;
    o->f18 = ((struct Obj12760 *)p)->f0;
}


/*
 * Tail-call thunk: forwards to func_021A811C with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A7B08(int a, struct V3 *b)
{
    func_021A811C(a, (u32)b);
}

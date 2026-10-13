/*
 * function: FIELD_GROUND_ANIME_KeyTableUnpack
 * address:  0x021A7AB0
 * packet:   pkt_ov021_021A7AB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */
#include "../include/Obj12760.h"

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

void FIELD_GROUND_ANIME_KeyTableUnpack(u32 *src, Out *o)
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

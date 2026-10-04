/*
 * function: func_021CC918
 * address:  0x021CC918
 * packet:   pkt_ov093_021CC918
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj21130.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    u32 a : 10;
    u32 b : 9;
    u32 c : 9;
    u32 d : 1;
    u32 e : 1;
    u32 f : 1;
    u32 g : 1;
} Bf;

u32 func_021CC918(Bf *p, u32 v)
{
    u32 old = ((struct Obj21130 *)p)->f0;
    p->a = v;
    p->c = p->b;
    p->e = 0;
    p->d = 0;
    p->f = 0;
    return old;
}

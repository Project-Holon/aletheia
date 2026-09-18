/*
 * function: func_0202B7BC
 * address:  0x0202B7BC
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202AB5C  0x0202AB5C  thumb
 */

typedef unsigned int u32;

struct Obj;

extern u32 func_0202AB5C(u32 v);

u32 func_0202B7BC(struct Obj *o)
{
    return func_0202AB5C(*(u32 *)((char *)o + 0x10));
}

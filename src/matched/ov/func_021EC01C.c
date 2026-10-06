/*
 * function: func_021EC01C
 * address:  0x021EC01C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3F4  0x0204B3F4  arm  arm9
 *
 * Forward the i-th word of the pooled table.
 */

typedef unsigned int   u32;
struct Obj;
extern u32 func_0204B3F4(struct Obj *p);

u32 func_021EC01C(char *p, int i)
{
    return func_0204B3F4((struct Obj *)(*(int *)(p + i * 4 + 0x9E74)));
}


/*
 * function: func_0217D388
 * address:  0x0217D388
 * packet:   pkt_0217D388
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200B078  0x0200B078  thumb
 */

typedef signed int     s32;
typedef unsigned int   u32;
struct Reg2;
extern s32 func_0200B078(struct Reg2 *p, u32 id);

void func_0217D388(int *p, int *q)
{
    *(int *)((char *)p + 0x40) = func_0200B078((struct Reg2 *)(*(int *)((char *)q + 0x38)), 2);
}

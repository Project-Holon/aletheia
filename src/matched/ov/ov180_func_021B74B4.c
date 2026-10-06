/*
 * function: func_021B74B4
 * address:  0x021B74B4
 * packet:   pkt_021B74B4
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B98C  0x0204B98C  arm
 */

typedef unsigned int   u32;
struct Actor;
extern u32 func_0204B98C(struct Actor *a);

int func_021B74B4(int *p, int i)
{
    return func_0204B98C((struct Actor *)(*(int *)((char *)p + i * 4 + 0x9048)));
}

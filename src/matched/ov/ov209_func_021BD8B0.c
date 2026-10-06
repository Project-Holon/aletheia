/*
 * function: func_021BD8B0
 * address:  0x021BD8B0
 * packet:   pkt_021BD8B0
 * region:   ov209
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B898 0x0204B898 arm
 */

typedef unsigned short u16;
struct Obj;
extern u16 func_0204B898(struct Obj *p);

int func_021BD8B0(char *a, int b)
{
    return func_0204B898((struct Obj *)(*(int *)(a + b * 4 + 0xa74)));
}
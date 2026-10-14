/*
 * function: ZUKAN_LIST_GetActorAnimSeq
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
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 */

typedef unsigned short u16;
struct Obj;
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);

int ZUKAN_LIST_GetActorAnimSeq(char *a, int b)
{
    return CLACT_GetActorAnimSeq((struct Obj *)(*(int *)(a + b * 4 + 0xa74)));
}
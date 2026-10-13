/*
 * function: func_021DE0AC
 * address:  0x021DE0AC
 * packet:   pkt_021DE0AC
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 */

typedef unsigned int   u32;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);

int func_021DE0AC(int *p, int i)
{
    return CLACT_IsActorAnimActive((struct Actor *)(*(int *)((char *)p + i * 4 + 0xB74)));
}

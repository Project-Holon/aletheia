/*
 * function: BOX2_SEQ_IsActorAnimActive
 * address:  0x021EBFEC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_IsActorAnimActive  0x0204B98C  arm  arm9
 *
 * Forward the i-th word of the pooled table.
 */

typedef unsigned int   u32;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);

u32 BOX2_SEQ_IsActorAnimActive(char *p, int i)
{
    return CLACT_IsActorAnimActive((struct Actor *)(*(int *)(p + i * 4 + 0x9E74)));
}


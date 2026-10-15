/*
 * function: BOX2_SEQ_GetActorDrawEnable
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
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm  arm9
 *
 * Forward the i-th word of the pooled table.
 */

typedef unsigned int   u32;
struct Obj;
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);

u32 BOX2_SEQ_GetActorDrawEnable(char *p, int i)
{
    return CLACT_GetActorDrawEnable((struct Obj *)(*(int *)(p + i * 4 + 0x9E74)));
}


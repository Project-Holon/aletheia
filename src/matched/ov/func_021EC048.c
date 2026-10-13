/*
 * function: func_021EC048
 * address:  0x021EC048
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorDrawPriority  0x0204B800  arm  arm9
 *
 * Tail call with the table word at the pooled offset.
 */



typedef unsigned int   u32;
struct Node;
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
void func_021EC048(char *p, int i, int c)
{
    CLACT_SetActorDrawPriority((struct Node *)(*(int *)(p + i * 4 + 0x9E74)), (unsigned char)c);
}

/*
 * function: BOX2_SEQ_SetActorBgPriority
 * address:  0x021EC030
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorBgPriority  0x0204B84C  arm  arm9
 *
 * Tail call with the table word at the pooled offset.
 */



extern void CLACT_SetActorBgPriority(int, int);
void BOX2_SEQ_SetActorBgPriority(char *p, int i, int c)
{
    CLACT_SetActorBgPriority(*(int *)(p + i * 4 + 0x9E74), (unsigned char)c);
}

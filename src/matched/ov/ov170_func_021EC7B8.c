/*
 * function: BOX2_SEQ_SetSlotDrawPriorityB
 * address:  0x021EC7B8
 * packet:   pkt_ov170_021EC7B8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetActorBgPriority 0x021EC030 thumb
 *   BOX2_SEQ_SetActorDrawPriority 0x021EC048 thumb
 */

extern void BOX2_SEQ_SetActorBgPriority(char *p, int i, int c);
extern void BOX2_SEQ_SetActorDrawPriority(char *p, int i, int c);

void BOX2_SEQ_SetSlotDrawPriorityB(char *p, int i, unsigned j, int flag)
{
    unsigned char c = *(unsigned char *)(p + i + 0x3DD2);
    if (flag == 0) {
        BOX2_SEQ_SetActorBgPriority(p, c, 0);
        BOX2_SEQ_SetActorDrawPriority(p, c, 0x14);
        return;
    }
    if (j < 0x1E)
        BOX2_SEQ_SetActorBgPriority(p, c, 3);
    else
        BOX2_SEQ_SetActorBgPriority(p, c, 1);
    BOX2_SEQ_SetActorDrawPriority(p, c, 0x75 - j * 2);
}

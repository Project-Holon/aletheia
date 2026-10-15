/*
 * function: BOX2_SEQ_SetSlotDrawPriority
 * address:  0x021EC768
 * packet:   pkt_ov170_021EC768
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

void BOX2_SEQ_SetSlotDrawPriority(char *p, unsigned i, int flag)
{
    unsigned char c = *(unsigned char *)(p + i + 0x3DD2);
    if (flag == 0) {
        BOX2_SEQ_SetActorBgPriority(p, c, 0);
        BOX2_SEQ_SetActorDrawPriority(p, c, 0x14);
        return;
    }
    if (i < 0x1E || i == 0x24)
        BOX2_SEQ_SetActorBgPriority(p, c, 3);
    else
        BOX2_SEQ_SetActorBgPriority(p, c, 1);
    BOX2_SEQ_SetActorDrawPriority(p, c, 0x75 - i * 2);
}

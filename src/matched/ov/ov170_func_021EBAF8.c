/*
 * function: BOX2_SEQ_PrintWordset
 * address:  0x021EBAF8
 * packet:   pkt_ov170_021EBAF8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WORDSET_SetSlotFromMsg36 0x0201EF40 thumb
 *   BOX2_SEQ_PrintMessageMsg 0x021EBA84 thumb
 *
 * Puts item v into word slot 0 and prints message 0x15 into window i.
 */

typedef unsigned int u32;

struct WordSet;
extern void WORDSET_SetSlotFromMsg36(struct WordSet *p, u32 i, u32 v);
extern void BOX2_SEQ_PrintMessageMsg(unsigned char *p, int msg, int i);

#define WORK(p) (*(char **)((p) + 0x2C))

void BOX2_SEQ_PrintWordset(unsigned char *p, u32 v, int i)
{
    WORDSET_SetSlotFromMsg36(*(void **)(WORK(p) + 0x84), 0, v);
    BOX2_SEQ_PrintMessageMsg(p, 0x15, i);
}

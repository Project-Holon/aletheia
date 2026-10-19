/*
 * function: BOX2_SEQ_PrintWordsetB
 * address:  0x021EBB34
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_SEQ_PrintMessageMsg  0x021EBA84  thumb  ov170
 *   WORDSET_SetSlotFromMsg36  0x0201EF40  thumb  arm9
 *
 * Stage 0x84 of the p+0x2c object with (0, arg1), then index 0xe
 *   with the third argument.
 */
#include "../include/Obj18518.h"


typedef unsigned int   u32;
struct WordSet;
extern void WORDSET_SetSlotFromMsg36(struct WordSet *p, u32 i, u32 v);
extern void BOX2_SEQ_PrintMessageMsg(unsigned char *p, int msg, int i);
void BOX2_SEQ_PrintWordsetB(char *p, int a, int b)
{
    WORDSET_SetSlotFromMsg36((struct WordSet *)(*(int *)(((struct Obj18518 *)p)->f2C + 0x84)), 0, a);
    BOX2_SEQ_PrintMessageMsg((unsigned char *)p, 0xe, b);
}

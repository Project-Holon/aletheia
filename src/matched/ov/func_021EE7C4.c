/*
 * function: BOX2_UI_PickSlot
 * address:  0x021EE7C4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_SelectSlot  0x021EE754  thumb  ov170
 *   BOX2_UI_MoveCursorBetweenIcons  0x021EEF74  thumb  ov170
 *   BOX2_MAIN_SetSeqParam  0x021DC9B4  thumb  ov170
 *
 * Stage the pair, forward it, re-key the queue with the
 *   0x021E066D selector and record the first argument at 0xA168.
 */
#include "../include/Obj00000.h"


extern void BOX2_UI_SelectSlot(unsigned char *p, unsigned r);
extern void BOX2_UI_MoveCursorBetweenIcons(char *q, int a, int b);
extern void BOX2_MAIN_SetSeqParam(char *p, int v);
void BOX2_UI_PickSlot(char *p, int a, int b)
{
    BOX2_UI_SelectSlot((unsigned char *)p, a);
    BOX2_UI_MoveCursorBetweenIcons((char *)(*(int *)&((struct Obj00000 *)p)->f2C), a, b);
    BOX2_MAIN_SetSeqParam((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 0x021E066D);
    *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0xA168) = a;
}

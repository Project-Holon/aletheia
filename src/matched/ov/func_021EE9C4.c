/*
 * function: BOX2_UI_PickSlotB
 * address:  0x021EE9C4
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
 * Twin of BOX2_UI_PickSlot with the same selector and target word.
 */
#include "../include/Obj00000.h"


extern void BOX2_UI_SelectSlot(unsigned char *p, unsigned r);
extern void BOX2_UI_MoveCursorBetweenIcons(char *q, int a, int b);
extern void BOX2_MAIN_SetSeqParam(char *p, int v);
void BOX2_UI_PickSlotB(char *p, int a, int b)
{
    BOX2_UI_SelectSlot((unsigned char *)p, a);
    BOX2_UI_MoveCursorBetweenIcons((char *)(*(int *)&((struct Obj00000 *)p)->f2C), a, b);
    BOX2_MAIN_SetSeqParam((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 0x021E066D);
    *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0xA168) = a;
}

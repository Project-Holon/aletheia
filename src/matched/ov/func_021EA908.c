/*
 * function: BOX2_SEQ_ToggleHandSlot
 * address:  0x021EA908
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_SetHandSlots  0x021DF110  thumb  ov170
 *
 * candidate BOX2_SEQ_ToggleHandSlot: xor bit
 */
#include "../include/Obj00000.h"


extern void BOX2_MAIN_SetHandSlots(char *p, int b);
void BOX2_SEQ_ToggleHandSlot(int p, int bit)
{
    *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0xA174) ^= 1 << bit;
    BOX2_MAIN_SetHandSlots((char *)p, *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0xA174));
}


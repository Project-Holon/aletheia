/*
 * function: func_021BC6BC
 * address:  0x021BC6BC
 * packet:   pkt_021BC6BC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALANM_TransferPalettes 0x02021D50  thumb
 *
 * Loads the word at +8 and tail-calls the function at 0x02021D51 (the thumb
 * address of the ARM9 function at 0x02021D50).
 *
 */
#include "../include/Obj18185.h"

struct S02021D50;
extern void PALANM_TransferPalettes(struct S02021D50 *p);

void func_021BC6BC(char *p)
{
    PALANM_TransferPalettes((struct S02021D50 *)(((struct Obj18185 *)p)->f8));
}

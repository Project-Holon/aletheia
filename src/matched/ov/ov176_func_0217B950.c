/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_SetExtraOption
 * address:  0x0217B950
 * packet:   pkt_0217B950
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_PrintMessage  0x021E8738  thumb  ov177
 */
#include "../include/Obj01762.h"

extern void WIFIBATTLEMATCH_UTIL_PrintMessage(int *p, int a, int b, int c);

void BATTLE_CHAMPIONSHIP_FLOW_SetExtraOption(int *p, int b)
{
    WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(*(int *)&((struct Obj01762 *)p)->f18), ((struct Obj01762 *)p)->fC, b, 1);
}

/*
 * function: BTLV_EFFVM_SetEmitterHandle
 * address:  0x021FD19C
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFVM_SetEmitterHandle   0x021FD19C  thumb
 *
 * lane O10 candidate
 */
#include "../include/Obj18571.h"

void BTLV_EFFVM_SetEmitterHandle(char *p, int i, char *q)
{
    *(int *)(p + i * 4 + 0x8c) = ((struct Obj18571 *)q)->f8;
}


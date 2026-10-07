/*
 * function: func_02175F4C
 * address:  0x02175F4C
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_SetMatchStatus: records the new match state, logging a change first.
 *
 * symbols:
 *   g_021AAA20  0x021AAA20  data
 *   func_02176A8C  0x02176A8C  arm  ov009
 */

#include "../include/G_NNThinkGlobal.h"

extern struct NNThinkGlobal g_021AAA20;
extern void func_02176A8C(int a, int b);

void func_02175F4C(int state)
{
    if (*(int *)(*(char **)(((char *)&g_021AAA20) + 4) + 0x61c) != state) {
        func_02176A8C(*(int *)(*(char **)(((char *)&g_021AAA20) + 4) + 0x61c), state);
    }
    *(int *)(*(char **)(((char *)&g_021AAA20) + 4) + 0x61c) = state;
}

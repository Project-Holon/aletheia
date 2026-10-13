/*
 * function: DWCi_SetMatchCnt
 * address:  0x02175F1C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores the argument, calls the pair-returning helper and keeps both words.
 *
 * symbols:
 *   g_021AAA20  0x021AAA20  data
 */

#include "../include/G_NNThinkGlobal.h"

extern struct NNThinkGlobal g_021AAA20;
extern unsigned long long func_020870D0(int a);

void DWCi_SetMatchCnt(int a)
{
    unsigned long long v;

    *(int *)(((char *)&g_021AAA20) + 4) = a;
    v = func_020870D0(a);
    *(int *)(((char *)&g_021AAA20) + 0x18) = (int)v;
    *(int *)(((char *)&g_021AAA20) + 0x1c) = (int)(v >> 32);
}


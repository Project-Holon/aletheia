/*
 * function: func_02177704
 * address: 0x02177704
 * packet: pkt_ov014_02177704
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_pWhPipeWork 0x021797A4 data a4
 *   func_020307B0 0x020307B0 arm
 */

#include "../include/G_W.h"

extern struct W *g_pWhPipeWork;
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_02177704(void)
{
    if (g_pWhPipeWork != 0) {
        func_020307B0(g_pWhPipeWork);
        g_pWhPipeWork = 0;
    }
}

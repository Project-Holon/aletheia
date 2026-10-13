/*
 * function: func_021775AC
 * address: 0x021775AC
 * packet: pkt_ov014_021775AC
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: original preserves incoming r0-r2 and spends r3 on the
 * indirect callback target; legacy void(void) callers omit those inputs.
 * void(void) callback spelling changes the target register to r0 (run 2).
 * symbols:
 *   g_pWhPipeWork 0x021797A4 data a4
 */

#include "../include/G_W.h"

typedef unsigned char u8;
extern struct W *g_pWhPipeWork;
int func_021775AC(int a, int b, int c)
{
    return (*(int (**)(int, int, int))(((u8 *)g_pWhPipeWork) + 4))(a,b,c);
}

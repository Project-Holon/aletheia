/*
 * function: func_06898BFC
 * address: 0x06898BFC
 * packet: pkt_ov095_06898BFC
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_0689E7E0 0x0689E7E0 data a4
 *   func_02082BCC 0x02082BCC arm
 * note: Follower after veneer 0x06898BEC; next function starts with push at 0x06898C10.
 */

#include "../../../matched/include/G_Row.h"

typedef unsigned char u8;
extern struct Row g_0689E7E0;
extern void func_02082BCC(void *p, int v, int n);
void func_06898BFC(void)
{
    func_02082BCC(((u8 *)&g_0689E7E0), 0, 448);
}

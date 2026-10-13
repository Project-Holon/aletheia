/*
 * function: INTRUDE_COMM_ClearSessionTicks
 * address: 0x021759B0
 * packet: pkt_ov011_021759B0
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02175B34 0x02175B34 thumb ov011
 */
#include "../include/Obj19193.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *func_02175B34(u8 *p);
void INTRUDE_COMM_ClearSessionTicks(u8 *p)
{
    u8 *q = func_02175B34(p);
    if (q != 0) ((struct Obj19193 *)q)->f30 = 0;
}

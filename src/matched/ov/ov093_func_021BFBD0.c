/*
 * function: BTL_SERVER_FLOW_PushPendingHpRecovery
 * address: 0x021BFBD0
 * packet: pkt_ov093_021BFBD0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two alignment bytes at 0x021BFC06 precede the next labelled function.
 * symbols:
 *   BTL_SERVER_CMD_FillReserved 0x021CD568 thumb ov093
 */
#include "../include/Obj05190.h"
#include "../include/Obj21062.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BTL_SERVER_CMD_FillReserved(void *, u32, u32, ...);
void BTL_SERVER_FLOW_PushPendingHpRecovery(u8 *p, u32 fallback, u8 *record, u32 pos)
{
    u32 value = ((struct Obj05190 *)record)->f0;
    if (value == 0) value = fallback;
    BTL_SERVER_CMD_FillReserved(((struct Obj21062 *)p)->fC, (u16)pos, 0x30,
                 record[2], record[3], value, record[4]);
    record[4] = 0;
    record[5] |= 2;
}

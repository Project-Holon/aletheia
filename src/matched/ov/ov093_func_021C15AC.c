/*
 * function: BTL_SERVER_FLOW_PushEffectivenessMessage
 * address: 0x021C15AC
 * packet: pkt_ov093_021C15AC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 */
#include "../include/Obj13320.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void BTL_SERVER_CMD_PushVariable(void *, u8, ...);

void BTL_SERVER_FLOW_PushEffectivenessMessage(u8 *p, int k)
{
    if (k < 3) {
        BTL_SERVER_CMD_PushVariable(((struct Obj13320 *)p)->fC, 0x5a, 0x4f, 0xffff0000);
    } else if (k > 3) {
        BTL_SERVER_CMD_PushVariable(((struct Obj13320 *)p)->fC, 0x5a, 0x4e, 0xffff0000);
    }
}

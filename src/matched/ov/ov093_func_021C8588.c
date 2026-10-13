/*
 * function: BTL_SERVER_FLOW_ResetFrameStack
 * address: 0x021C8588
 * packet: pkt_ov093_021C8588
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SERVER_FLOW_LoadFrame 0x021C85D4 thumb ov093
 */
#include "../include/Obj00294.h"
extern void BTL_SERVER_FLOW_LoadFrame(unsigned char *, int, int);
void BTL_SERVER_FLOW_ResetFrameStack(unsigned char *p)
{
    *(int *)&((struct Obj00294 *)p)->f1A64 = 0;
    BTL_SERVER_FLOW_LoadFrame(p, 0, 1);
}

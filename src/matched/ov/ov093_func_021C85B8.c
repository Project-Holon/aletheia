/*
 * function: BTL_SERVER_FLOW_PopFrame
 * address: 0x021C85B8
 * packet: pkt_ov093_021C85B8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SERVER_FLOW_LoadFrame 0x021C85D4 thumb ov093
 */
#include "../include/Obj00294.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void BTL_SERVER_FLOW_LoadFrame(u8 *, int, int);
void BTL_SERVER_FLOW_PopFrame(u8 *p)
{
    if (((struct Obj00294 *)p)->f1A64 != 0) {
        --((struct Obj00294 *)p)->f1A64;
        BTL_SERVER_FLOW_LoadFrame(p, ((struct Obj00294 *)p)->f1A64, 0);
    }
}

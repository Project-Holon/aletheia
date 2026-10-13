/*
 * function: VCT_MAIN_HandlePacket
 * address: 0x021AEF44
 * packet: pkt_ov013_021AEF44
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Narrow first callee argument follows the explicit lsls/lsrs at 021AEF52;
 * the other two inputs stay live from entry for the three-input callee.
 * symbols:
 *   gVctWork 0x021B3C80 data ov013 a4
 *   VCT_ReceiveFrame 0x021B38B0 arm ov013
 */

#include "../include/G_Work.h"

extern struct Work *gVctWork;
extern int VCT_ReceiveFrame(int a, int b, int c);
int VCT_MAIN_HandlePacket(int a, int b, int c)
{
    if (gVctWork == 0) return 0;
    if (VCT_ReceiveFrame((unsigned char)a, b, c) != 0) return 1;
    return 0;
}

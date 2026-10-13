/*
 * function: DPW_BT_GetRoomNumAsync
 * address: 0x021C941C
 * packet: pkt_ov114_021C941C
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   gDpwBtServerIndex 0x021D3EFC data a4
 *   gDpwBtWork 0x021D4084 data a4
 *   gDpwBtBaseUrl 0x021CF6D4 data a4
 *   gDpwBtPathGetRoomNum 0x021CF714 data a4
 *   gDpwBtRequestPacket 0x021D4098 data a4
 *   DWCi_EncSessionInitialize 0x021C9EE4 arm ov114
 *   DWCi_EncSessionGetAsync 0x021CA470 arm ov114
 *   DWCi_EncSessionShutdown 0x021CA1B4 arm ov114
 */

#include "../include/G_Block.h"

extern void *gDpwBtServerIndex;
extern struct Block gDpwBtRequestPacket;
extern unsigned gDpwBtWork[], gDpwBtBaseUrl[], gDpwBtPathGetRoomNum[];
extern void DWCi_EncSessionInitialize(int server, char *initdata);
extern int DWCi_EncSessionGetAsync(void *, unsigned, void *, unsigned, unsigned);
extern void DWCi_EncSessionShutdown(void);
void DPW_BT_GetRoomNumAsync(unsigned x)
{
    ((unsigned char *)gDpwBtWork)[0x14] = x - 1;
    DWCi_EncSessionInitialize((int)gDpwBtServerIndex, (char *)gDpwBtBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwBtPathGetRoomNum, gDpwBtWork[2], ((unsigned *)&gDpwBtRequestPacket), 1, 0) == 0) {
        gDpwBtWork[0] = 2;
        return;
    }
    gDpwBtWork[0] = 12;
    gDpwBtWork[1] = -5;
    DWCi_EncSessionShutdown();
}

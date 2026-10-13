/*
 * function: DPW_TR_GetServerStateAsync
 * address: 0x021C8DA0
 * packet: pkt_ov114_021C8DA0
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   gDpwTrServerIndex 0x021D3D28 data a4
 *   gDpwTrWork 0x021D3D2C data a4
 *   gDpwTrBaseUrl 0x021CF538 data a4
 *   gDpwTrPathGetServerState 0x021CF69C data a4
 *   gDpwTrRequestPacket 0x021D3D40 data a4
 *   DWCi_EncSessionInitialize 0x021C9EE4 arm ov114
 *   DWCi_EncSessionGetAsync 0x021CA470 arm ov114
 *   DWCi_EncSessionShutdown 0x021CA1B4 arm ov114
 */

#include "../include/G_Six.h"

extern void *gDpwTrServerIndex;
extern struct Six gDpwTrRequestPacket;
extern unsigned gDpwTrWork[], gDpwTrBaseUrl[], gDpwTrPathGetServerState[];
extern void DWCi_EncSessionInitialize(int server, char *initdata);
extern int DWCi_EncSessionGetAsync(void *, unsigned, void *, unsigned, unsigned);
extern void DWCi_EncSessionShutdown(void);
void DPW_TR_GetServerStateAsync(void)
{
    DWCi_EncSessionInitialize((int)gDpwTrServerIndex, (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathGetServerState, gDpwTrWork[2], ((unsigned *)&gDpwTrRequestPacket), 0, 0) == 0) {
        gDpwTrWork[0] = 20;
        return;
    }
    gDpwTrWork[0] = 24;
    gDpwTrWork[1] = -13;
    DWCi_EncSessionShutdown();
}

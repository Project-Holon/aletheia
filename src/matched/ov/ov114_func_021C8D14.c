/*
 * function: DPW_TR_TradeFinishAsync
 * address: 0x021C8D14
 * packet: pkt_ov114_021C8D14
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   gDpwTrKeyHeader 0x021D3D38 data a4
 *   gDpwTrServerIndex 0x021D3D28 data a4
 *   gDpwTrRequestPacket 0x021D3D40 data a4
 *   gDpwTrBaseUrl 0x021CF538 data a4
 *   gDpwTrWork 0x021D3D2C data a4
 *   gDpwTrPathTradeFinish 0x021CF674 data a4
 *   DWCi_EncSessionInitialize 0x021C9EE4 arm ov114
 *   DWCi_EncSessionGetAsync 0x021CA470 arm ov114
 *   DWCi_EncSessionShutdown 0x021CA1B4 arm ov114
 */
#include "../../matched/arm9_sdk/libc/string.h"
extern const unsigned gDpwTrKeyHeader[];
extern void *gDpwTrServerIndex;
extern unsigned gDpwTrWork[], gDpwTrBaseUrl[], gDpwTrPathTradeFinish[], gDpwTrRequestPacket[];
extern void DWCi_EncSessionInitialize(int server, char *initdata);
extern int DWCi_EncSessionGetAsync(void *, unsigned, void *, unsigned, unsigned);
extern void DWCi_EncSessionShutdown(void);
void DPW_TR_TradeFinishAsync(void)
{
    memcpy(gDpwTrRequestPacket, gDpwTrKeyHeader, 8);
    DWCi_EncSessionInitialize((int)gDpwTrServerIndex, (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathTradeFinish, gDpwTrWork[2], gDpwTrRequestPacket, 8, 0) == 0) {
        gDpwTrWork[0] = 18;
        return;
    }
    gDpwTrWork[0] = 24;
    gDpwTrWork[1] = -13;
    DWCi_EncSessionShutdown();
}

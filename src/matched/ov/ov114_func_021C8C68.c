/*
 * function: DPW_TR_TradeAsync
 * address: 0x021C8C68
 * packet: pkt_ov114_021C8C68
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   gDpwTrWork 0x021D3D2C data a4
 *   gDpwTrRequestPacket 0x021D3D40 data a4
 *   gDpwTrWantedData 0x021D3E6C data a4
 *   gDpwTrServerIndex 0x021D3D28 data a4
 *   gDpwTrBaseUrl 0x021CF538 data a4
 *   gDpwTrPathTrade 0x021CF654 data a4
 *   func_02092344 0x02092344 arm
 *   DWCi_EncSessionInitialize 0x021C9EE4 arm ov114
 *   DWCi_EncSessionGetAsync 0x021CA470 arm ov114
 *   DWCi_EncSessionShutdown 0x021CA1B4 arm ov114
 */

#include "../include/G_Six.h"

typedef struct {
    unsigned words[0x4f];
    unsigned a;
    unsigned gap[0x20];
    unsigned count, b, c;
} State;
extern State gDpwTrWork;
extern void *gDpwTrServerIndex;
extern struct Six gDpwTrRequestPacket;
extern unsigned gDpwTrWantedData[], gDpwTrBaseUrl[], gDpwTrPathTrade[];
extern void *func_02092344(void *, const void *, unsigned);
extern void DWCi_EncSessionInitialize(int server, char *initdata);
extern int DWCi_EncSessionGetAsync(void *, unsigned, void *, unsigned, unsigned);
extern void DWCi_EncSessionShutdown(void);
void DPW_TR_TradeAsync(unsigned a, const void *p, unsigned c, const void *q, unsigned n)
{
    gDpwTrWork.c = c;
    func_02092344(((unsigned *)&gDpwTrRequestPacket), p, 0x128);
    gDpwTrWork.a = a;
    func_02092344(gDpwTrWantedData, q, n);
    gDpwTrWork.count = n;
    DWCi_EncSessionInitialize((int)gDpwTrServerIndex, (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathTrade, gDpwTrWork.words[2], ((unsigned *)&gDpwTrRequestPacket), 0x1b0, 0) == 0) {
        gDpwTrWork.words[0] = 16;
        return;
    }
    gDpwTrWork.words[0] = 24;
    gDpwTrWork.words[1] = -13;
    DWCi_EncSessionShutdown();
}

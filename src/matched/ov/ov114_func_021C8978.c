/*
 * function: DPW_TR_UploadFinishAsync
 * address: 0x021C8978
 * packet: pkt_ov114_021C8978
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 * gDpwTrServerIndex 0x021D3D28 data a4
 * gDpwTrWork 0x021D3D2C data a4
 * gDpwTrBaseUrl 0x021CF538 data a4
 * gDpwTrPathUploadFinish 0x021CF614 data a4
 * gDpwTrRequestPacket 0x021D3D40 data a4
 * DWCi_EncSessionInitialize 0x021C9EE4 arm ov114
 * DWCi_EncSessionGetAsync 0x021CA470 arm ov114
 * DWCi_EncSessionShutdown 0x021CA1B4 arm ov114
 */

#include "../include/G_Six.h"

extern unsigned int *gDpwTrServerIndex;
extern struct Six gDpwTrRequestPacket;
extern unsigned int gDpwTrWork[], gDpwTrBaseUrl[], gDpwTrPathUploadFinish[];
extern void DWCi_EncSessionInitialize(int server, char *initdata);
extern int DWCi_EncSessionGetAsync(void *, unsigned int, void *, unsigned int, unsigned int);
extern void DWCi_EncSessionShutdown(void);
void DPW_TR_UploadFinishAsync(void)
{
    DWCi_EncSessionInitialize((int)gDpwTrServerIndex, (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathUploadFinish, gDpwTrWork[2], ((unsigned int *)&gDpwTrRequestPacket), 0, 0) == 0) {
        gDpwTrWork[0] = 12;
        return;
    }
    gDpwTrWork[0] = 0x18;
    gDpwTrWork[1] = -13;
    DWCi_EncSessionShutdown();
}

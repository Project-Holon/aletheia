/*
 * function: DPW_BT_DownloadPlayerAsync
 * address: 0x021C94A0
 * packet: pkt_ov114_021C94A0
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   gDpwBtServerIndex 0x021D3EFC data a4
 *   gDpwBtWork 0x021D4084 data a4
 *   gDpwBtBaseUrl 0x021CF6D4 data a4
 *   gDpwBtPathDownloadPlayer 0x021CF734 data a4
 *   gDpwBtRequestPacket 0x021D4098 data a4
 *   DWCi_EncSessionInitialize 0x021C9EE4 arm ov114
 *   DWCi_EncSessionGetAsync 0x021CA470 arm ov114
 *   DWCi_EncSessionShutdown 0x021CA1B4 arm ov114
 */

#include "../include/G_Block.h"

extern void *gDpwBtServerIndex;
typedef struct {
    unsigned words[5];
    unsigned char first, second;
    unsigned char gap[0x186];
    unsigned value;
} State;
extern State gDpwBtWork;
extern struct Block gDpwBtRequestPacket;
extern unsigned gDpwBtBaseUrl[], gDpwBtPathDownloadPlayer[];
extern void DWCi_EncSessionInitialize(int server, char *initdata);
extern int DWCi_EncSessionGetAsync(void *, unsigned, void *, unsigned, unsigned);
extern void DWCi_EncSessionShutdown(void);
void DPW_BT_DownloadPlayerAsync(unsigned x, unsigned y, unsigned z)
{
    gDpwBtWork.value = z;
    gDpwBtWork.first = x - 1;
    gDpwBtWork.second = y - 1;
    DWCi_EncSessionInitialize((int)gDpwBtServerIndex, (char *)gDpwBtBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwBtPathDownloadPlayer, gDpwBtWork.words[2], ((unsigned *)&gDpwBtRequestPacket), 2, 0) == 0) {
        gDpwBtWork.words[0] = 4;
        return;
    }
    gDpwBtWork.words[0] = 12;
    gDpwBtWork.words[1] = -5;
    DWCi_EncSessionShutdown();
}

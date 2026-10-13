/*
 * function: DPW_TR_DownloadAsync
 * address:  0x021C87FC
 * packet:   pkt_ov114_021C87FC
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbol overlay hints are deliberately omitted: `gDpwTrRequestPacket` lives in
 * overlapping bss, and naming ov114 explicitly makes the hint contested,
 * while leaving it off lets the function's own region disambiguate.
 *
 * symbols:
 *   gDpwTrServerIndex   0x021D3D28  data  a4
 *   gDpwTrWork   0x021D3D2C  data  a4
 *   gDpwTrBaseUrl   0x021CF538  data  a4
 *   gDpwTrPathDownload   0x021CF5B8  data  a4
 *   gDpwTrRequestPacket   0x021D3D40  data  a4
 *   DWCi_EncSessionInitialize 0x021C9EE4  arm
 *   DWCi_EncSessionGetAsync 0x021CA470  arm
 *   DWCi_EncSessionShutdown 0x021CA1B4  arm
 */

#include "../include/G_Six.h"

extern unsigned int *gDpwTrServerIndex;
extern unsigned int gDpwTrWork[];
extern unsigned int gDpwTrBaseUrl[];
extern unsigned int gDpwTrPathDownload[];
extern struct Six gDpwTrRequestPacket;

extern void DWCi_EncSessionInitialize(int server, char *initdata);
extern int DWCi_EncSessionGetAsync(void *, unsigned int, void *, unsigned int, unsigned int);
extern void DWCi_EncSessionShutdown(void);

void DPW_TR_DownloadAsync(unsigned int x)
{
    gDpwTrWork[0x72] = x;
    DWCi_EncSessionInitialize((int)((void *)gDpwTrServerIndex), (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathDownload, gDpwTrWork[2], ((unsigned int *)&gDpwTrRequestPacket), 0x1b0, 0) == 0) {
        gDpwTrWork[0] = 6;
        return;
    }
    gDpwTrWork[0] = 0x18;
    gDpwTrWork[1] = -0x0d;
    DWCi_EncSessionShutdown();
}

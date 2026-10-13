/*
 * function: DPW_TR_ReturnAsync
 * address:  0x021C887C
 * packet:   pkt_ov114_021C887C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Twin of DPW_TR_DownloadAsync: same shape, a different packet-descriptor
 * constant (gDpwTrPathReturn) and a success code of 8 instead of 6.  Overlay
 * hints omitted for the same overlapping-bss reason.
 *
 * symbols:
 *   gDpwTrServerIndex   0x021D3D28  data  a4
 *   gDpwTrWork   0x021D3D2C  data  a4
 *   gDpwTrBaseUrl   0x021CF538  data  a4
 *   gDpwTrPathReturn   0x021CF5D4  data  a4
 *   gDpwTrRequestPacket   0x021D3D40  data  a4
 *   DWCi_EncSessionInitialize 0x021C9EE4  arm
 *   DWCi_EncSessionGetAsync 0x021CA470  arm
 *   DWCi_EncSessionShutdown 0x021CA1B4  arm
 */

#include "../include/G_Six.h"

extern unsigned int *gDpwTrServerIndex;
extern unsigned int gDpwTrWork[];
extern unsigned int gDpwTrBaseUrl[];
extern unsigned int gDpwTrPathReturn[];
extern struct Six gDpwTrRequestPacket;

extern void DWCi_EncSessionInitialize(int server, char *initdata);
extern int DWCi_EncSessionGetAsync(void *, unsigned int, void *, unsigned int, unsigned int);
extern void DWCi_EncSessionShutdown(void);

void DPW_TR_ReturnAsync(unsigned int x)
{
    gDpwTrWork[0x72] = x;
    DWCi_EncSessionInitialize((int)((void *)gDpwTrServerIndex), (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathReturn, gDpwTrWork[2], ((unsigned int *)&gDpwTrRequestPacket), 0x1b0, 0) == 0) {
        gDpwTrWork[0] = 8;
        return;
    }
    gDpwTrWork[0] = 0x18;
    gDpwTrWork[1] = -0x0d;
    DWCi_EncSessionShutdown();
}

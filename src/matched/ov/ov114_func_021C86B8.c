/*
 * function: DPW_TR_UploadAsync
 * address: 0x021C86B8
 * packet: pkt_ov114_021C86B8
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 * gDpwTrServerIndex 0x021D3D28 data a4
 * gDpwTrWork 0x021D3D2C data a4
 * gDpwTrBaseUrl 0x021CF538 data a4
 * gDpwTrRequestPacket 0x021D3D40 data a4
 * DWCi_EncSessionInitialize 0x021C9EE4 arm ov114
 * DWCi_EncSessionGetAsync 0x021CA470 arm ov114
 * DWCi_EncSessionShutdown 0x021CA1B4 arm ov114
 * gDpwTrWantedData 0x021D3E6C data a4
 * gDpwTrPathUpload 0x021CF578 data a4
 * func_02092344 0x02092344 arm
 */

#include "../include/G_Six.h"

extern unsigned int *gDpwTrServerIndex;
typedef struct { unsigned int words[0x4f]; unsigned int a; unsigned int gap[0x20]; unsigned int count, b, c; } State;
extern State gDpwTrWork;
extern struct Six gDpwTrRequestPacket;
extern unsigned int gDpwTrBaseUrl[];
extern void DWCi_EncSessionInitialize(int server, char *initdata);
extern int DWCi_EncSessionGetAsync(void *, unsigned int, void *, unsigned int, unsigned int);
extern void DWCi_EncSessionShutdown(void);
extern unsigned int gDpwTrWantedData[], gDpwTrPathUpload[];
extern void *func_02092344(void *, const void *, unsigned int);
void DPW_TR_UploadAsync(const void *a, const void *b, int c)
{
    func_02092344(((unsigned int *)&gDpwTrRequestPacket), a, 0x128);
    gDpwTrWork.a = 0;
    func_02092344(gDpwTrWantedData, b, c);
    gDpwTrWork.count = c;
    DWCi_EncSessionInitialize((int)gDpwTrServerIndex, (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathUpload, gDpwTrWork.words[2], ((unsigned int *)&gDpwTrRequestPacket), 0x1b0, 0) == 0) {
        gDpwTrWork.words[0] = 2;
        return;
    }
    gDpwTrWork.words[0] = 24;
    gDpwTrWork.words[1] = -13;
    DWCi_EncSessionShutdown();
}

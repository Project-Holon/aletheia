/*
 * function: DPW_TR_SetProfileAsync
 * address: 0x021C8E18
 * packet: pkt_ov114_021C8E18
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   gDpwTrServerIndex 0x021D3D28 data a4
 *   gDpwTrWork 0x021D3D2C data a4
 *   gDpwTrBaseUrl 0x021CF538 data a4
 *   gDpwTrPathSetProfile 0x021CF6B8 data a4
 *   gDpwTrRequestPacket 0x021D3D40 data a4
 *   OS_GetMacAddress 0x02087C6C arm
 *   func_02092344 0x02092344 arm
 *   DWCi_EncSessionInitialize 0x021C9EE4 arm ov114
 *   DWCi_EncSessionGetAsync 0x021CA470 arm ov114
 *   DWCi_EncSessionShutdown 0x021CA1B4 arm ov114
 */

#include "../include/G_Six.h"

extern void *gDpwTrServerIndex;
typedef struct { unsigned words[114]; unsigned value; } State;
extern State gDpwTrWork;
extern struct Six gDpwTrRequestPacket;
extern unsigned gDpwTrBaseUrl[], gDpwTrPathSetProfile[];
extern void OS_GetMacAddress(void *);
extern void *func_02092344(void *, const void *, unsigned);
extern void DWCi_EncSessionInitialize(int server, char *initdata);
extern int DWCi_EncSessionGetAsync(void *, unsigned, void *, unsigned, unsigned);
extern void DWCi_EncSessionShutdown(void);
void DPW_TR_SetProfileAsync(unsigned char *p, unsigned x)
{
    OS_GetMacAddress(p + 0x1c);
    func_02092344(((unsigned *)&gDpwTrRequestPacket), p, 100);
    gDpwTrWork.value = x;
    DWCi_EncSessionInitialize((int)gDpwTrServerIndex, (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathSetProfile, gDpwTrWork.words[2], ((unsigned *)&gDpwTrRequestPacket), 100, 0) == 0) {
        gDpwTrWork.words[0] = 22;
        return;
    }
    gDpwTrWork.words[0] = 24;
    gDpwTrWork.words[1] = -13;
    DWCi_EncSessionShutdown();
}

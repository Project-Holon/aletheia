/*
 * function: DPW_BT_SetProfileAsync
 * address: 0x021C9744
 * packet: pkt_ov114_021C9744
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   gDpwBtServerIndex 0x021D3EFC data a4
 *   gDpwBtWork 0x021D4084 data a4
 *   gDpwBtBaseUrl 0x021CF6D4 data a4
 *   gDpwBtPathSetProfile 0x021CF78C data a4
 *   gDpwBtRequestPacket 0x021D4098 data a4
 *   OS_GetMacAddress 0x02087C6C arm
 *   func_02092344 0x02092344 arm
 *   DWCi_EncSessionInitialize 0x021C9EE4 arm ov114
 *   DWCi_EncSessionGetAsync 0x021CA470 arm ov114
 *   DWCi_EncSessionShutdown 0x021CA1B4 arm ov114
 */

#include "../include/G_Block.h"

extern void *gDpwBtServerIndex;
typedef struct { unsigned words[103]; unsigned value; } State;
extern State gDpwBtWork;
extern struct Block gDpwBtRequestPacket;
extern unsigned gDpwBtBaseUrl[], gDpwBtPathSetProfile[];
extern void OS_GetMacAddress(void *);
extern void *func_02092344(void *, const void *, unsigned);
extern void DWCi_EncSessionInitialize(int server, char *initdata);
extern int DWCi_EncSessionGetAsync(void *, unsigned, void *, unsigned, unsigned);
extern void DWCi_EncSessionShutdown(void);
void DPW_BT_SetProfileAsync(unsigned char *p, unsigned x)
{
    OS_GetMacAddress(p + 0x1c);
    func_02092344(((unsigned *)&gDpwBtRequestPacket), p, 100);
    gDpwBtWork.value = x;
    DWCi_EncSessionInitialize((int)gDpwBtServerIndex, (char *)gDpwBtBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwBtPathSetProfile, gDpwBtWork.words[2], ((unsigned *)&gDpwBtRequestPacket), 100, 0) == 0) {
        gDpwBtWork.words[0] = 10;
        return;
    }
    gDpwBtWork.words[0] = 12;
    gDpwBtWork.words[1] = -5;
    DWCi_EncSessionShutdown();
}

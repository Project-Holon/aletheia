/*
 * function: DPW_BT_UploadPlayerAsync
 * address: 0x021C9530
 * packet: pkt_ov114_021C9530
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * lang: c99
 * status: EXACT
 * final push 2026-10-05 G6L6: the pair copy is memcpy(gDpwBtUploadPairKey, gDpwBtPairKeyInit, 8) from its own pool word 0x4090 (non-const extern; a const source gave 38 B off).
 * symbols:
 *   gDpwBtUploadStaging 0x021D3F00 data a4
 *   gDpwBtUploadPairKey 0x021D3FF8 data a4
 *   gDpwBtUploadLeaderData 0x021D4000 data a4
 *   gDpwBtRequestPacket 0x021D4098 data a4
 *   gDpwBtWork 0x021D4084 data a4
 *   gDpwBtPairKeyInit 0x021D4090 data a4
 *   gDpwBtServerIndex 0x021D3EFC data a4
 *   gDpwBtBaseUrl 0x021CF6D4 data a4
 *   gDpwBtPathUploadPlayer 0x021CF754 data a4
 *   func_02092344 0x02092344 arm
 *   DWCi_EncSessionInitialize 0x021C9EE4 arm ov114
 *   DWCi_EncSessionGetAsync 0x021CA470 arm ov114
 *   DWCi_EncSessionShutdown 0x021CA1B4 arm ov114
 */
#include "../../matched/arm9_sdk/libc/string.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {
    u32 buf[60];
    u8 first, second, third, gap[5];
    u32 pair[2];
    u32 buf2[32];
    u32 value;
} Block;
typedef struct {
    u32 words[5];
    u8 first, second;
    u8 gap[0x186];
    u32 value;
} State;
extern Block gDpwBtUploadStaging;
extern u32 gDpwBtUploadPairKey[], gDpwBtUploadLeaderData[];
extern u32 gDpwBtPairKeyInit[];
extern Block gDpwBtRequestPacket;
extern State gDpwBtWork;
extern void *gDpwBtServerIndex;
extern unsigned gDpwBtBaseUrl[], gDpwBtPathUploadPlayer[];
extern void *func_02092344(void *, const void *, u32);
extern void DWCi_EncSessionInitialize(int server, char *initdata);
extern int DWCi_EncSessionGetAsync(void *, unsigned, void *, unsigned, unsigned);
extern void DWCi_EncSessionShutdown(void);
void DPW_BT_UploadPlayerAsync(u32 a, u32 b, u32 c, const void *p, const void *q, u32 v)
{
    func_02092344(gDpwBtUploadStaging.buf, p, 240);
    gDpwBtUploadStaging.first = a - 1;
    gDpwBtUploadStaging.second = b - 1;
    gDpwBtUploadStaging.third = c;
    memcpy(gDpwBtUploadPairKey, gDpwBtPairKeyInit, 8);
    func_02092344(gDpwBtUploadLeaderData, q, 128);
    gDpwBtUploadStaging.value = v;
    gDpwBtRequestPacket = gDpwBtUploadStaging;
    DWCi_EncSessionInitialize((int)gDpwBtServerIndex, (char *)gDpwBtBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwBtPathUploadPlayer, gDpwBtWork.words[2], &gDpwBtRequestPacket, 388, 0) == 0) {
        gDpwBtWork.words[0] = 6;
        return;
    }
    gDpwBtWork.words[0] = 12;
    gDpwBtWork.words[1] = -5;
    DWCi_EncSessionShutdown();
}

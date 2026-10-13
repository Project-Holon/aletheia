/*
 * function: DWCi_ProcessMatchSynPacketSub_Hybrid
 * address:  0x0216EC84
 * packet:   pkt_ov009_0216EC84
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * notes:    the unaligned four-byte field copies are memcpy(dst, src, 4) calls (the house
 *           string.h makes the compiler expand them to the paired byte loads/stores through a
 *           pointer register, hoisted out of the loop); DWCi_GetMatchCnt() is called before
 *           every access rather than cached; values read from the packet are loaded into a
 *           local before the getter call that precedes the store.  Local declaration order
 *           (i, entry, clientCount) fixes the callee-saved register assignment in the
 *           packet-4 loop.
 *
 * sdk:      DWCi_ProcessMatchSynPacketSub_Hybrid (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt                 0x02175F3C arm
 *   DWCi_IsFullMesh                  0x0217695C arm
 *   DWCi_NodeInfoList_InsertToTop    0x0217604C arm
 *   MI_CpuFill8                      0x02082BCC arm
 *   DWCi_NodeInfoList_GetCount       0x0217603C arm
 *   DWCi_SetMatchStatus              0x02175F4C arm
 *   DWCi_SendMatchSynPacket          0x02173064 arm
 *   DWCi_GetAIDBitmask               0x02173C9C arm
 *   DWCi_GetMathRand32               0x021685CC arm
 *   DWCi_SendTypeMatchAck            0x021735A4 arm
 *   OS_GetTick                       0x020870D0 arm
 *   DWCi_TempNewNodeInfo_Clear       0x0217653C arm
 *   DWCi_PostProcessConnection       0x02172254 arm
 */

#include "../arm9_sdk/libc/string.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct { u8 b[4]; } BYTES4;

struct DWCstNodeInfo {
    u32 f0;                        /* 0x00 */
    u32 f4;                        /* 0x04 */
    u32 f8;                        /* 0x08 */
    u16 f_c;                       /* 0x0C */
    u16 f_e;                       /* 0x0E */
    u8 pad0[0x16 - 0x10];          /* 0x10 */
    u8 f16;                        /* 0x16 */
    u8 f17;                        /* 0x17 */
    u8 pad1[0x24 - 0x18];          /* 0x18 */
    BYTES4 f_24;                   /* 0x24 */
};

struct DWCstMatchControl {
    u8 pad0[0x554];
    struct DWCstNodeInfo myNode;       /* 0x554 */
    struct DWCstNodeInfo srcNode;      /* 0x57C */
    u8 pad1[0x61C - 0x5A4];
    int f_61C;                         /* 0x61C */
    u8 pad2[0x62C - 0x620];
    u8 f_62C;                          /* 0x62C */
    u8 pad3[0x62E - 0x62D];
    u8 f_62E;                          /* 0x62E */
    u8 pad4[0x630 - 0x62F];
    u16 f_630;                         /* 0x630 */
    u8 pad5[0x650 - 0x632];
    u32 f_650;                         /* 0x650 */
    u8 pad6[0x658 - 0x654];
    unsigned long long f_658;          /* 0x658 */
    u8 pad7[0x670 - 0x660];
    long long f_670;                   /* 0x670 */
    u8 pad8[0x680 - 0x678];
    u32 f_680;                         /* 0x680 */
    u8 pad9[0x7C8 - 0x684];
    u32 f_7C8;                         /* 0x7C8 */
};

extern struct DWCstMatchControl *DWCi_GetMatchCnt(void);
extern int DWCi_IsFullMesh(void);
extern int DWCi_NodeInfoList_InsertToTop(struct DWCstNodeInfo *newNode);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int DWCi_NodeInfoList_GetCount(void);
extern void DWCi_SetMatchStatus(int state);
extern void DWCi_SendMatchSynPacket(unsigned char aid, unsigned short type);
extern unsigned long DWCi_GetAIDBitmask(int valid);
extern unsigned long DWCi_GetMathRand32(unsigned long max);
extern void DWCi_SendTypeMatchAck(void);
extern unsigned long long OS_GetTick(void);
extern void DWCi_TempNewNodeInfo_Clear(void);
extern void DWCi_PostProcessConnection(int type);

#define MC() DWCi_GetMatchCnt()

void DWCi_ProcessMatchSynPacketSub_Hybrid(unsigned char aid, unsigned short type, unsigned char *data)
{
    struct DWCstNodeInfo tempNodeInfo;
    struct DWCstNodeInfo tempNodeInfo2;
    int i;
    u32 *entry;
    int clientCount;

    switch (type) {
    case 2:
        if (MC()->f_61C != 1)
            return;
        if (*(u32 *)data == 1) {
            MC()->f_680 = 0;
            MC()->srcNode.f0 = 0;
            {
                u32 v = *(u32 *)(data + 4);

                MC()->f_7C8 = v;
            }
            if (DWCi_IsFullMesh())
                DWCi_NodeInfoList_InsertToTop(&MC()->myNode);
        } else {
            u32 w;
            u32 *p = (u32 *)data;

            MI_CpuFill8(&tempNodeInfo, 0, sizeof(tempNodeInfo));
            w = p[1];
            tempNodeInfo.f16 = (u8)w;
            tempNodeInfo.f17 = (u8)(w >> 16);
            tempNodeInfo.f0 = p[2];
            tempNodeInfo.f4 = p[3];
            tempNodeInfo.f8 = p[4];
            tempNodeInfo.f_c = (u16)(p[5] >> 16);
            tempNodeInfo.f_e = (u16)p[5];
            memcpy(&tempNodeInfo.f_24, data + 0x18, 4);
            MC()->srcNode = tempNodeInfo;
            w = p[7];
            MC()->f_7C8 = w;
            MC()->f_680 = tempNodeInfo.f0;
        }
        {
            int latency;

            if (DWCi_NodeInfoList_GetCount() == 1)
                latency = 0x15f90;
            else
                latency = DWCi_NodeInfoList_GetCount() * 0x2ee0;
            MC()->f_670 = latency;
        }
        MC()->f_62E = 0;
        DWCi_SetMatchStatus(8);
        DWCi_SendMatchSynPacket(aid, 3);
        return;
    case 3: {
        u16 onewayGT2Latency;
        u32 bitmask;

        if (MC()->f_61C == 0x13) {
            onewayGT2Latency = (u16)(data[0] | (data[1] << 8));
            MC()->f_650 |= 1 << aid;
            if (MC()->f_630 < onewayGT2Latency)
                MC()->f_630 = onewayGT2Latency;
            bitmask = DWCi_GetAIDBitmask(0);
            if (bitmask != MC()->f_650)
                return;
            {
                struct DWCstMatchControl *mc = MC();

                mc->f_7C8 = DWCi_GetMathRand32(0 - 2) + 1;
            }
            DWCi_SendTypeMatchAck();
            MC()->f_62C = 0;
            {
                unsigned long long tick = OS_GetTick();

                MC()->f_658 = tick;
            }
        } else {
            DWCi_SendMatchSynPacket(aid, 4);
        }
        return;
    }
    case 4:
        if (MC()->f_61C != 8)
            return;
        clientCount = *(int *)data;
        if (clientCount != 0) {
            u32 v;

            for (i = 0; i < clientCount; i++) {
                entry = (u32 *)(data + 4) + (clientCount - 1 - i) * 6;

                MI_CpuFill8(&tempNodeInfo2, 0, sizeof(tempNodeInfo2));
                tempNodeInfo2.f16 = (u8)entry[0];
                tempNodeInfo2.f17 = (u8)(entry[0] >> 16);
                tempNodeInfo2.f0 = entry[1];
                tempNodeInfo2.f4 = entry[2];
                tempNodeInfo2.f8 = entry[3];
                tempNodeInfo2.f_e = (u16)entry[4];
                tempNodeInfo2.f_c = (u16)(entry[4] >> 16);
                memcpy(&tempNodeInfo2.f_24, (u8 *)entry + 0x14, 4);
                DWCi_NodeInfoList_InsertToTop(&tempNodeInfo2);
            }
            v = ((u32 *)data + clientCount * 6)[1];
            MC()->f_7C8 = v;
            DWCi_NodeInfoList_InsertToTop(&MC()->myNode);
            DWCi_TempNewNodeInfo_Clear();
        } else {
            u32 v = *(u32 *)(data + 4);

            MC()->f_7C8 = v;
        }
        DWCi_PostProcessConnection(3);
        return;
    default:
        return;
    }
}

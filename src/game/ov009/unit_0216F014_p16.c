/*
 * file:     unit_0216F014_p16.c
 * unit:     yes
 * function: func_02173614, func_021736AC
 * address:  0x02173614
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_021763AC  0x021763AC  arm  ov009
 *   func_0216FF2C  0x0216FF2C  arm  ov009
 *   func_021719A4  0x021719A4  arm  ov009
 *   func_020870D0  0x020870D0  arm
 *   DWC_GetState                     0x0216B994 arm
 *   DWCi_GetMatchCnt                 0x02175F3C arm
 *   DWCi_SetMatchStatus              0x02175F4C arm
 *   DWCi_TempNewNodeInfo_Clear       0x0217653C arm
 *   DWCi_SendCancelMatchSynCommand   0x02173614 arm
 *   OS_GetTick                       0x020870D0 arm
 *   _ll_udiv                         0x0209C00C arm
 *   DWCi_GetAIDFromProfileID         0x02173C84 arm
 *   DWCi_GetAIDBitmask               0x02173C9C arm
 *   DWCi_NodeInfoList_GetCount       0x0217603C arm
 *   DWCi_NodeInfoList_GetNodeInfoForIndex 0x0217637C arm
 *   DWCi_RestartFromCancel           0x02172BB8 arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

struct DWCstMatchControl
{
    u8 pad0[0x57c];
    u32 f_57c;
    u8 pad1[0x61c - 0x580];
    int f_61c;
    u8 pad2[0x632 - 0x620];
    u16 f_632;
    u8 pad3[0x654 - 0x634];
    u32 f_654;
    u8 pad4[0x660 - 0x658];
    unsigned long long f_660;
    u8 pad5[0x680 - 0x668];
    u32 f_680;
};

struct DWCstNodeInfo
{
    int f0;
};

extern int func_02175F3C(void);
extern char *func_021763AC(int profileID);
extern int func_0216FF2C(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
extern int func_021719A4(int result);
extern unsigned long long func_020870D0(void);
extern int DWC_GetState(void);
extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern void DWCi_SetMatchStatus(int state);
extern void DWCi_TempNewNodeInfo_Clear(void);
extern int DWCi_SendCancelMatchSynCommand(int profileID, u8 command);
extern unsigned long long OS_GetTick(void);
extern u8 DWCi_GetAIDFromProfileID(int profileID, int reserved);
extern u32 DWCi_GetAIDBitmask(int valid);
extern int DWCi_NodeInfoList_GetCount(void);
extern struct DWCstNodeInfo * DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern void DWCi_RestartFromCancel(int level);
int func_02173614(int profileID, unsigned char command);
int DWCi_ProcessCancelMatchSynCommand(int profileID, u8 command, u32 data);


int func_02173614(int profileID, unsigned char command)
{
    char *pNodeInfo;
    int result;
    int len;
    unsigned long senddata[1];

    if (command != 13) {
        len = 0;
    } else {
        senddata[0] = *(unsigned long *)(func_02175F3C() + 0x680);
        len = 1;
    }
    pNodeInfo = func_021763AC(profileID);
    if (!pNodeInfo)
        return 0;
    result = func_0216FF2C(command, profileID, *(int *)(pNodeInfo + 4), *(unsigned short *)(pNodeInfo + 12), (const unsigned int *)senddata, len);
    if (func_021719A4(result))
        return 0;
    {
        unsigned long long t = func_020870D0();
        *(unsigned long long *)(func_02175F3C() + 0x660) = t;
    }
    return 1;
}


int DWCi_ProcessCancelMatchSynCommand(int profileID, u8 command, u32 data)
{
    struct DWCstNodeInfo * pNodeInfo;
    int i;
    unsigned long long latency;
    unsigned long long baseTime;
    u32 bitmask;
    u8 aid;

    if (DWC_GetState() != 5)
        return 1;

    switch (command) {
    case 0xd:
        if (DWCi_GetMatchCnt()->f_61c != 7) {
            DWCi_SetMatchStatus(7);
            DWCi_GetMatchCnt()->f_680 = data;
            if (DWCi_GetMatchCnt()->f_57c != 0)
                DWCi_GetMatchCnt()->f_57c = 0;
            DWCi_TempNewNodeInfo_Clear();
        }
        if (DWCi_SendCancelMatchSynCommand(profileID, 0xe) != 0)
            break;
        return 0;
    case 0xe:
        if (DWCi_GetMatchCnt()->f_61c == 0x11) {
            baseTime = OS_GetTick();
            if ((baseTime - DWCi_GetMatchCnt()->f_660) * 64 / 0x82ea / 2 > 0x12c) {
                latency = (baseTime - DWCi_GetMatchCnt()->f_660) * 64 / 0x82ea / 2 - 0x12c;
                if (latency > DWCi_GetMatchCnt()->f_632)
                    DWCi_GetMatchCnt()->f_632 = latency;
            }
            aid = DWCi_GetAIDFromProfileID(profileID, 0);
            if (aid != 0xff)
                DWCi_GetMatchCnt()->f_654 |= 1 << aid;
            bitmask = DWCi_GetAIDBitmask(1);
            if (bitmask != DWCi_GetMatchCnt()->f_654)
                break;
            for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++) {
                pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
                if (DWCi_SendCancelMatchSynCommand(pNodeInfo->f0, 0xf) == 0)
                    return 0;
            }
            DWCi_SetMatchStatus(0x12);
        } else if (DWCi_SendCancelMatchSynCommand(profileID, 0xf) == 0) {
            return 0;
        }
        break;
    case 0xf:
        if (DWCi_GetMatchCnt()->f_61c == 7)
            DWCi_RestartFromCancel(2);
        break;
    }
    return 1;
}

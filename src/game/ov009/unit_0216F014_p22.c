/*
 * file:     unit_0216F014_p22.c
 * unit:     yes
 * function: func_021738EC, func_02173AD8, func_02173B18, func_02173B74, func_02173BE4, func_02173C84
 * address:  0x021738EC
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
 *   DWCi_GetMatchCnt                 0x02175F3C arm
 *   OS_GetTick                       0x020870D0 arm
 *   _ll_udiv                         0x0209C00C arm
 *   DWCi_NodeInfoList_GetNodeInfoForIndex 0x0217637C arm
 *   DWCi_SendCancelMatchSynCommand   0x02173614 arm
 *   DWCi_CloseShutdownClientSC       0x02172EAC arm
 *   DWCi_NodeInfoList_GetCount       0x0217603C arm
 *   DWCi_RestartFromCancel           0x02172BB8 arm
 *   d_021AAA40     0x021AAA40  data
 *   g_021AAA40  0x021AAA40  data
 *   DWC_Free  0x0205A1B0  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02168FF0  0x02168FF0  arm  ov009
 *   func_0219E120  0x0219E120  arm  ov009
 *   g_021A21A4     0x021A21A4  data
 *   g_021A21B0     0x021A21B0  data
 *   g_021A2170     0x021A2170  data
 *   g_021A2164     0x021A2164  data
 *   g_021A20A4     0x021A20A4  data
 *   func_021763AC  0x021763AC  arm  ov009
 */
struct SBServer;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32_021738EC;

struct DWCstMatchControl
{
    u8 pad0[0x61c];
    int f_61c;
    u8 pad1[0x62d - 0x620];
    u8 f_62d;
    u8 pad2[0x632 - 0x62e];
    u16 f_632;
    u8 pad3[0x654 - 0x634];
    u32_021738EC f_654;
    u8 pad4[0x660 - 0x658];
    unsigned long long f_660;
};

struct DWCstNodeInfo
{
    int f0;
    u8 pad[0x16 - 4];
    u8 f16;
};

typedef unsigned int   u32_02173AD8;

typedef struct {
    int key;
    void *value;
    int type;
} MatchKey;

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern unsigned long long OS_GetTick(void);
extern struct DWCstNodeInfo * DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern int DWCi_SendCancelMatchSynCommand(int profileID, u8 command);
extern int DWCi_CloseShutdownClientSC(u32_021738EC bitmap);
extern int DWCi_NodeInfoList_GetCount(void);
extern void DWCi_RestartFromCancel(int level);
extern void DWC_Free(int kind, void *p, int size);
extern void MIi_CpuClear32(int v, void *p, int size);
extern char *func_02175F3C(void);
extern int func_02168FF0(int idx);
extern int func_0219E120(struct SBServer *server, char *key, int idefault);
extern unsigned char *func_021763AC(void);
int DWCi_ProcessCancelMatchSynTimeout(void);
/* * Finds the first empty record (stride 0xc) among 0x9a entries and returns * its biased index; 0 when none is free. */ u8 func_02173AD8(void);
/* * DWCi_ClearGameMatchKeys: frees every game match key value and clears the key table. */ void func_02173B18(void);
/* * sdk: DWCi_IsFriendByIdxList (dwc_match.o) */ int func_02173B74(int profileID);
/* * sdk: DWCi_CheckDWCServer (dwc_match.o) */ int func_02173BE4(void *server);
/* * Byte at +0x16 of the block, or 0xff when there is none. */ int func_02173C84(void);
extern u8 d_021AAA40[];
extern MatchKey g_021AAA40[];
extern char g_021A21A4[];
extern char g_021A21B0[];
extern char g_021A2170[];
extern char g_021A2164[];
extern char g_021A20A4[];



int DWCi_ProcessCancelMatchSynTimeout(void)
{
    unsigned long long passTime;
    int i;

    if (DWCi_GetMatchCnt()->f_61c == 7 ||
        DWCi_GetMatchCnt()->f_61c == 0x11 ||
        DWCi_GetMatchCnt()->f_61c == 0x12) {
        passTime = OS_GetTick() - DWCi_GetMatchCnt()->f_660;
        passTime = passTime * 64 / 0x82ea;
    } else {
        return 1;
    }

    switch (DWCi_GetMatchCnt()->f_61c) {
    case 7: {
        struct DWCstNodeInfo * pNodeInfo;

        if (passTime <= 0x1770)
            break;
        pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(0);
        if (DWCi_SendCancelMatchSynCommand(pNodeInfo->f0, 0xe) == 0)
            return 0;
        break;
    }
    case 0x11:
        if (passTime <= 0x1770)
            break;
        DWCi_GetMatchCnt()->f_62d++;
        if (DWCi_GetMatchCnt()->f_62d > 5) {
            if (DWCi_CloseShutdownClientSC(DWCi_GetMatchCnt()->f_654) == 0)
                return 0;
            if (DWCi_NodeInfoList_GetCount() > 1) {
                DWCi_GetMatchCnt()->f_62d = 0;
                passTime = OS_GetTick();
                DWCi_GetMatchCnt()->f_660 = passTime;
            } else {
                DWCi_RestartFromCancel(2);
            }
        } else {
            for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++) {
                struct DWCstNodeInfo * pNodeInfo =
                    DWCi_NodeInfoList_GetNodeInfoForIndex(i);

                if (DWCi_GetMatchCnt()->f_654 & (1 << pNodeInfo->f16))
                    continue;
                if (DWCi_SendCancelMatchSynCommand(pNodeInfo->f0, 0xd) == 0)
                    return 0;
            }
        }
        break;
    case 0x12:
        if (passTime <= DWCi_GetMatchCnt()->f_632)
            break;
        DWCi_RestartFromCancel(2);
        break;
    }
    return 1;
}



/*
 * Finds the first empty record (stride 0xc) among 0x9a entries and returns
 * its biased index; 0 when none is free.
 */
u8 func_02173AD8(void)
{
    u8 i;

    for (i = 0; i < 0x9a; i++) {
        if (d_021AAA40[i * 0xc] == 0)
            return (i + 0x64) & 0xff;
    }
    return 0;
}



/*
 * DWCi_ClearGameMatchKeys: frees every game match key value and clears the key table.
 */
void func_02173B18(void)
{
    int i;

    for (i = 0; i < 0x9a; i++) {
        if (g_021AAA40[i].value != 0) {
            DWC_Free(4, g_021AAA40[i].value, 0);
        }
    }
    MIi_CpuClear32(0, g_021AAA40, sizeof(MatchKey) * 0x9a);
}



/*
 * sdk:      DWCi_IsFriendByIdxList (dwc_match.o)
 */
int func_02173B74(int profileID)
{
    int i;
    int id;

    if (*(int *)(func_02175F3C() + 0x68c) == 0)
        return 0;
    for (i = 0; i < *(int *)(func_02175F3C() + 0x6d4); i++) {
        id = func_02168FF0(*(unsigned char *)(func_02175F3C() + i + 0x694));
        if (id > 0 && id == profileID)
            return 1;
    }
    return 0;
}



/*
 * sdk:      DWCi_CheckDWCServer (dwc_match.o)
 */
int func_02173BE4(void *server)
{
    if (func_0219E120(server, g_021A21A4, -1) == -1)
        return 0;
    if (func_0219E120(server, g_021A21B0, -1) == -1)
        return 0;
    if (func_0219E120(server, g_021A2170, -1) == -1)
        return 0;
    if (func_0219E120(server, g_021A2164, -1) == -1)
        return 0;
    return func_0219E120(server, g_021A20A4, 0);
}



/*
 * Byte at +0x16 of the block, or 0xff when there is none.
 */
int func_02173C84(void)
{
    unsigned char *p = func_021763AC();

    return p == 0 ? 0xff : *(unsigned char *)(p + 0x16);
}

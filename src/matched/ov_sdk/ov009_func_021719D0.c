/*
 * function: DWCi_SendResvCommand
 * address:  0x021719D0
 * packet:   pkt_ov009_021719D0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SendResvCommand (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt                 0x02175F3C arm
 *   OS_GetTick                       0x020870D0 arm
 *   gpIsBuddy                        0x021861A8 arm
 *   DWCi_NodeInfoList_GetMyNodeInfo  0x02176344 arm
 *   DWCi_GetMathRand32               0x021685CC arm
 *   DWCi_SendMatchCommand            0x0216FF2C arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct DWCstMatchControl
{
    void *f0;
    u8 pad0[0x15 - 4];
    u8 f_15;
    u8 pad1[0x558 - 0x16];
    u32 f_558;
    u8 pad2[0x560 - 0x55c];
    u16 f_560;
    u8 pad3[0x5a4 - 0x562];
    u32 f_5a4;
    u8 pad4[0x5d4 - 0x5a8];
    u16 f_5d4;
    u8 pad5[0x5d8 - 0x5d6];
    u32 f_5d8;
    u8 pad6[0x634 - 0x5dc];
    u32 f_634;
    u32 f_638;
    unsigned long long f_63c;
    u32 f_644;
    unsigned long long f_648;
    u8 pad7[0x67c - 0x650];
    u32 f_67c;
    u8 pad8[0x798 - 0x680];
    u32 f_798;
    u8 pad9[0x7b0 - 0x79c];
    u32 f_7b0;
    u8 pad10[0x7b6 - 0x7b4];
    u8 f_7b6;
    u8 pad11[0x7bc - 0x7b7];
    u32 f_7bc;
};

struct DWCstNodeInfo
{
    int f0;
    u32 f4;
    u32 f8;
    u16 f_c;
    u16 f_e;
    u16 pad0;
    u8 pad1[0x17 - 0x12];
    u8 f17;
};

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern unsigned long long OS_GetTick(void);
extern int gpIsBuddy(void * connection, int profile);
extern struct DWCstNodeInfo * DWCi_NodeInfoList_GetMyNodeInfo(void);
extern u32 DWCi_GetMathRand32(u32 max);
extern int DWCi_SendMatchCommand(u8 command, int profileID, u32 ip, u16 port, u32 * data, int len);

int DWCi_SendResvCommand(int profileID, int delay)
{
    u32 senddata[16];
    u32 remoteQR2ip = 0;
    u16 remoteQR2port = 0;
    struct DWCstNodeInfo * pMyNodeInfo;
    unsigned long long tick;
    int result;

    if (delay != 0)
        goto setTimer;
    if (DWCi_GetMatchCnt()->f_5d8 != 0 || DWCi_GetMatchCnt()->f_5d4 != 0)
        goto send;

setTimer:
    DWCi_GetMatchCnt()->f_638 = 1;
    tick = OS_GetTick();
    DWCi_GetMatchCnt()->f_63c = tick;
    DWCi_GetMatchCnt()->f_67c = 0;
    return 0;

send:
    if (DWCi_GetMatchCnt()->f_15 == 0) {
        remoteQR2ip = DWCi_GetMatchCnt()->f_558;
        remoteQR2port = DWCi_GetMatchCnt()->f_560;
        DWCi_GetMatchCnt()->f_67c = profileID;
    } else {
        DWCi_GetMatchCnt()->f_67c = profileID;
        if (gpIsBuddy(DWCi_GetMatchCnt()->f0, profileID) == 0) {
            remoteQR2ip = DWCi_GetMatchCnt()->f_558;
            remoteQR2port = DWCi_GetMatchCnt()->f_560;
        }
    }
    if (DWCi_GetMatchCnt()->f_15 == 3 ||
        (DWCi_GetMatchCnt()->f_798 != 0 &&
         gpIsBuddy(DWCi_GetMatchCnt()->f0, profileID))) {
        DWCi_GetMatchCnt()->f_7b6 = 0;
        DWCi_GetMatchCnt()->f_644 = 0x7530;
    } else {
        DWCi_GetMatchCnt()->f_7b6 = 5;
        DWCi_GetMatchCnt()->f_644 = 0x2ee0;
    }
    tick = OS_GetTick();
    DWCi_GetMatchCnt()->f_648 = tick;
    DWCi_GetMatchCnt()->f_638 = 0;
    pMyNodeInfo = DWCi_NodeInfoList_GetMyNodeInfo();
    senddata[0] = DWCi_GetMatchCnt()->f_15;
    senddata[1] = pMyNodeInfo->f4;
    senddata[2] = pMyNodeInfo->f_c;
    senddata[3] = pMyNodeInfo->f8;
    senddata[4] = pMyNodeInfo->f_e;
    senddata[5] = pMyNodeInfo->f17;
    senddata[6] = DWCi_GetMatchCnt()->f_798;
    senddata[7] = DWCi_GetMatchCnt()->f_7b0;
    senddata[8] = DWCi_GetMatchCnt()->f_7bc;
    DWCi_GetMatchCnt()->f_634 = DWCi_GetMathRand32((u32)-2) + 1;
    senddata[9] = DWCi_GetMatchCnt()->f_634;
    senddata[10] = DWCi_GetMatchCnt()->f_5a4 != 0;
    result = DWCi_SendMatchCommand(1, profileID, remoteQR2ip, remoteQR2port, senddata, 0xb);
    return result;
}


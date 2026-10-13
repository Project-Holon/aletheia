/*
 * function: DWCi_CheckResvCommand
 * address:  0x021713CC
 * packet:   pkt_ov009_021713CC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CheckResvCommand (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   func_02175F3C                0x02175F3C arm   ov009
 *   func_02175FB8                0x02175FB8 arm   ov009
 *   DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID 0x02176500 arm   ov009
 *   DWCi_ClearMeshMakingTempInfo 0x02176870 arm   ov009
 *   DWCi_NodeInfoList_GetMyNodeInfo                0x02176344 arm   ov009
 *   func_020870D0                0x020870D0 arm
 *   func_02171524                0x02171524 arm   ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

struct DWCstMatchControl {
    u8 pad0[0x554];
    int f554;
    u8 pad1[0x57c - 0x558];
    int f57c;
    u8 pad2[0x5a4 - 0x580];
    int f5a4;
    u8 pad3[0x61c - 0x5a8];
    int f61c;
    u8 pad4[0x768 - 0x620];
    u64 f768;
    u8 pad5[0x7b4 - 0x770];
    u8 f7b4;
};

struct DWCstNodeInfo {
    int profileID;
};

extern int func_02175F3C(void);
extern unsigned char func_02175FB8(void);
extern int DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID(int profileID);
extern void DWCi_ClearMeshMakingTempInfo(void);
extern char *DWCi_NodeInfoList_GetMyNodeInfo(void);
extern u64 func_020870D0(void);
extern u8 func_02171524(int profileID, u32 qr2IP, u16 qr2Port, u32 matchType, int connectGroupID, u32 topologyType, u8 *newClientUserData, int meshReserve);

u8 DWCi_CheckResvCommand(int profileID, u32 qr2IP, u16 qr2Port, u32 matchType, int connectGroupID, u32 topologyType, u8 *newClientUserData, int meshReserve)
{
    struct DWCstNodeInfo *pMyNodeInfo;
    u8 sendCommand;
    u64 tick;

    ((struct DWCstMatchControl *)func_02175F3C())->f7b4 = 1;
    switch (func_02175FB8()) {
    case 1:
        if (DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID(profileID)) {
            if (((struct DWCstMatchControl *)func_02175F3C())->f5a4 == 0) {
                if (((struct DWCstMatchControl *)func_02175F3C())->f61c == 1) {
                    if (((struct DWCstMatchControl *)func_02175F3C())->f57c != 0) {
                        sendCommand = 4;
                    } else {
                        ((struct DWCstMatchControl *)func_02175F3C())->f5a4 = 1;
                        DWCi_ClearMeshMakingTempInfo();
                        goto send;
                    }
                } else {
                    sendCommand = 4;
                }
            } else {
                if (((struct DWCstMatchControl *)func_02175F3C())->f61c == 3) {
                    pMyNodeInfo = (struct DWCstNodeInfo *)DWCi_NodeInfoList_GetMyNodeInfo();
                    if (profileID == ((struct DWCstMatchControl *)func_02175F3C())->f554) {
                        if (pMyNodeInfo->profileID >= profileID) {
                            sendCommand = 0xff;
                        } else {
                        send:
                            sendCommand = 2;
                            tick = func_020870D0();
                            ((struct DWCstMatchControl *)func_02175F3C())->f768 = tick;
                        }
                    } else {
                        sendCommand = 4;
                    }
                } else {
                    sendCommand = 4;
                }
            }
        } else {
            sendCommand = 3;
            ((struct DWCstMatchControl *)func_02175F3C())->f7b4 = 0x14;
        }
        break;
    case 0:
    case 2:
        sendCommand = func_02171524(profileID, qr2IP, qr2Port, matchType, connectGroupID, topologyType, newClientUserData, meshReserve);
        break;
    }
    return sendCommand;
}

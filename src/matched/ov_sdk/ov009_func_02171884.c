/*
 * function: DWCi_ProcessResvOK
 * address:  0x02171884
 * packet:   pkt_ov009_02171884
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ProcessResvOK (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   func_02175F3C                0x02175F3C arm   ov009
 *   qr2_send_statechanged        0x0219B490 arm   ov009
 *   DWCi_NodeInfoList_GetFreeAID                0x02176474 arm   ov009
 *   DWCi_NodeInfoList_GetMyNodeInfo                0x02176344 arm   ov009
 *   DWCi_NodeInfoList_GetCount                0x0217603C arm   ov009
 *   DWCi_NodeInfoList_GetNodeInfoForIndex                0x0217637C arm   ov009
 *   DWCi_SendMatchCommand                0x0216FF2C arm   ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct DWCstMatchControl {
    u8 pad0[0x10];
    void *qr2Obj;
    u8 pad1[0x18 - 0x14];
    u8 f18;
    u8 pad2[0x554 - 0x19];
    u32 f554;
    u8 pad3[0x56a - 0x558];
    u8 aid;
    u8 pad4[0x5a4 - 0x56b];
    int f5a4;
    u8 pad5[0x5dc - 0x5a8];
    int f5dc;
    u8 pad6[0x638 - 0x5e0];
    int f638;
    u8 pad7[0x644 - 0x63c];
    int f644;
    u8 pad8[0x67c - 0x648];
    int f67c;
};

struct DWCstNodeInfo {
    int profileID;
    u32 ip;
    u8 pad0[0xc - 0x8];
    u16 port;
};

extern int func_02175F3C(void);
extern void qr2_send_statechanged(void *qrec);
extern u8 DWCi_NodeInfoList_GetFreeAID(void);
extern char *DWCi_NodeInfoList_GetMyNodeInfo(void);
extern int DWCi_NodeInfoList_GetCount(void);
extern char *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern int DWCi_SendMatchCommand(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);

int DWCi_ProcessResvOK(int profileID)
{
    u32 senddata[16];
    int result;
    int i;
    u8 aid;
    struct DWCstNodeInfo *pMyNodeInfo;
    struct DWCstNodeInfo *pNodeInfo;

    if (((struct DWCstMatchControl *)func_02175F3C())->f18 != 0 && profileID == ((struct DWCstMatchControl *)func_02175F3C())->f5dc)
        return 0;
    ((struct DWCstMatchControl *)func_02175F3C())->f18 = 1;
    ((struct DWCstMatchControl *)func_02175F3C())->f5dc = profileID;
    ((struct DWCstMatchControl *)func_02175F3C())->f638 = 0;
    ((struct DWCstMatchControl *)func_02175F3C())->f644 = 0;
    qr2_send_statechanged(((struct DWCstMatchControl *)func_02175F3C())->qr2Obj);
    ((struct DWCstMatchControl *)func_02175F3C())->f67c = 0;
    aid = DWCi_NodeInfoList_GetFreeAID();
    ((struct DWCstMatchControl *)func_02175F3C())->aid = aid;
    if (((struct DWCstMatchControl *)func_02175F3C())->f5a4 == 0) {
        senddata[0] = ((struct DWCstMatchControl *)func_02175F3C())->f554;
        senddata[1] = ((struct DWCstMatchControl *)func_02175F3C())->aid;
        pMyNodeInfo = (struct DWCstNodeInfo *)DWCi_NodeInfoList_GetMyNodeInfo();
        for (i = 0; i < DWCi_NodeInfoList_GetCount(); i++) {
            pNodeInfo = (struct DWCstNodeInfo *)DWCi_NodeInfoList_GetNodeInfoForIndex(i);
            if (pMyNodeInfo->profileID != pNodeInfo->profileID) {
                result = DWCi_SendMatchCommand(7, pNodeInfo->profileID, pNodeInfo->ip, pNodeInfo->port, (const unsigned int *)senddata, 2);
                if (result != 0)
                    return result;
            }
        }
    }
    return 0;
}

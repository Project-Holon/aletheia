/*
 * function: DWCi_RequestSuspendMatch
 * address:  0x02175D10
 * packet:   pkt_ov009_02175D10
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RequestSuspendMatch (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * symbols:
 *   DWCi_GetHostStatus  0x02175FB8  arm  ov009
 *   DWCi_NodeInfoList_GetMyNodeInfo  0x02176344  arm  ov009
 *   func_021758C4  0x021758C4  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_020870D0  0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm
 *   DWCi_NodeInfoList_GetNodeInfoForIndex  0x0217637C  arm  ov009
 *   DWCi_SendMatchCommand  0x0216FF2C  arm  ov009
 *   DWCi_HandleMatchCommandError  0x021719A4  arm  ov009
 *
 * The object reads the tick before it calls DWCi_GetMatchCnt for the store, which
 * a block-local copy reproduces (the DWARF lists no tick variable).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

struct DWCstMatchControl {
    u8 pad0[0x20];
    u64 f20;
    u8 pad28[0x30 - 0x28];
    u8 f30;
    u8 pad31[0x61c - 0x31];
    int f61c;
    u8 pad620[0x678 - 0x620];
    u32 f678;
    u8 pad67c[0x7cc - 0x67c];
    u64 f7cc;
};

struct DWCstNodeInfo {
    int profileID;
    u32 ip;
    u8 pad8[0xc - 0x8];
    u16 port;
    u8 pade[0x16 - 0xe];
    u8 aid;
};

extern unsigned char DWCi_GetHostStatus(void);
extern struct DWCstNodeInfo *DWCi_NodeInfoList_GetMyNodeInfo(void);
extern int func_021758C4(u8 AID, int suspend, int immediate);
extern int func_02175F3C(void);
extern u64 func_020870D0(void);
extern char *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern int DWCi_SendMatchCommand(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
extern int DWCi_HandleMatchCommandError(int error);

static int DWCi_RequestSuspendMatch(int suspend)
{
    struct DWCstNodeInfo *pServerNodeInfo;
    struct DWCstNodeInfo *pMyNodeInfo;
    u32 senddata[4];
    int result;

    if (DWCi_GetHostStatus() == 2)
        return func_021758C4(DWCi_NodeInfoList_GetMyNodeInfo()->aid, suspend, 0);
    if (((struct DWCstMatchControl *)func_02175F3C())->f61c != 1)
        return 1;
    if (((struct DWCstMatchControl *)func_02175F3C())->f30) {
        if (((func_020870D0() - ((struct DWCstMatchControl *)func_02175F3C())->f20) * 64) / 33514 < ((struct DWCstMatchControl *)func_02175F3C())->f7cc)
            return 1;
    }
    if (((func_020870D0() - ((struct DWCstMatchControl *)func_02175F3C())->f20) * 64) / 33514 > 3000) {
        pMyNodeInfo = DWCi_NodeInfoList_GetMyNodeInfo();
        pServerNodeInfo = (struct DWCstNodeInfo *)DWCi_NodeInfoList_GetNodeInfoForIndex(0);
        senddata[0] = ((struct DWCstMatchControl *)func_02175F3C())->f678;
        senddata[1] = 0;
        senddata[2] = suspend;
        senddata[3] = pMyNodeInfo->aid;
        result = DWCi_SendMatchCommand(0x82, pServerNodeInfo->profileID, pServerNodeInfo->ip,
                               pServerNodeInfo->port, (const unsigned int *)senddata, 4);
        if (DWCi_HandleMatchCommandError(result))
            return 0;
        {
            u64 now = func_020870D0();
            ((struct DWCstMatchControl *)func_02175F3C())->f20 = now;
        }
        ((struct DWCstMatchControl *)func_02175F3C())->f7cc = 3000;
    }
    return 1;
}

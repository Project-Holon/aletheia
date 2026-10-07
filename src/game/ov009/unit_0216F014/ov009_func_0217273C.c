/*
 * function: func_0217273C
 * address:  0x0217273C
 * packet:   pkt_ov009_0217273C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * measured (U23): rule-4b check done -- all eleven ../2.0/* trees give 388 bytes / 221
 *   concrete against the image's 380, so 1.1p1 (384/177 on the same source) stays right.
 * sdk:      DWCi_PostProcessSVConnectionFullmesh (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02176978  0x02176978  arm  ov009
 *   func_02175F4C  0x02175F4C  arm  ov009
 *   func_0217637C  0x0217637C  arm  ov009
 *   func_02172604  0x02172604  arm  ov009
 *   func_0216FF2C  0x0216FF2C  arm  ov009
 *   func_021719A4  0x021719A4  arm  ov009
 *
 * The `flag = result` store sits inside the `cmdState != 0x13` block: the image's
 * beq at +0xE8 jumps straight to `return 0`, past that store. With the store in
 * the right block, `int result = 0` (the DWARF type) matches; the earlier
 * enum-zero workaround and the r4/r5 swap were both side effects of the
 * misplaced store.
 */

typedef struct {
    int profileID;
    unsigned long publicInetAddress;
    unsigned long privateInetAddress;
    unsigned short publicQueryPort;
    unsigned short privateQueryPort;
    unsigned long gt2IP;
    unsigned short gt2Port;
    unsigned char aid;
    unsigned char hasPrivateAddress;
    int nnTryCount;
    unsigned long long nextMeshMakeTryTick;
    unsigned char connUserData[4];
} NodeInfo;

typedef struct {
    unsigned char pad0[0x554];
    NodeInfo newNodeInfo;
    unsigned char pad1[0x61c - 0x554 - 0x28];
    int cmdState;
    unsigned char linkProgress;
    unsigned char pad2[0x6d9 - 0x621];
    unsigned char flag;
} MatchCnt;

extern MatchCnt *func_02175F3C(void);
extern int func_02176978(void);
extern void func_02175F4C(int state);
extern char *func_0217637C(int index);
extern int func_02172604(void);
extern int func_0216FF2C(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
extern int func_021719A4(int error);

int func_0217273C(void)
{
    unsigned long senddata[16];
    int result;
    NodeInfo tmpNewNodeInfo;
    unsigned char linkProgress;
    NodeInfo *pNodeInfo;
    NodeInfo *pNew;

    result = 0;
    tmpNewNodeInfo = func_02175F3C()->newNodeInfo;
    pNew = &tmpNewNodeInfo;
    if (func_02175F3C()->linkProgress < func_02176978() - 1) {
        linkProgress = func_02176978() - 1 - func_02175F3C()->linkProgress;
        func_02175F4C(0x10);
        pNodeInfo = (NodeInfo *)func_0217637C(linkProgress);
        senddata[0] = pNodeInfo->profileID;
        senddata[1] = linkProgress;
        senddata[2] = pNodeInfo->aid;
        senddata[3] = pNodeInfo->publicInetAddress;
        senddata[4] = pNodeInfo->publicQueryPort;
        senddata[5] = pNodeInfo->privateInetAddress;
        senddata[6] = pNodeInfo->privateQueryPort;
        senddata[7] = pNodeInfo->hasPrivateAddress;
        senddata[8] = *(unsigned long *)pNodeInfo->connUserData;
    } else {
        func_02175F3C()->linkProgress = result;
        return func_02172604();
    }
    if (func_02175F3C()->cmdState != 0x13) {
        if (func_021719A4(func_0216FF2C(8, pNew->profileID, pNew->publicInetAddress,
                                       pNew->publicQueryPort, (const unsigned int *)senddata, 9)))
            return result;
        pNodeInfo = (NodeInfo *)func_0217637C(linkProgress);
        senddata[0] = pNew->profileID;
        senddata[1] = pNew->aid;
        if (func_021719A4(func_0216FF2C(10, pNodeInfo->profileID, pNodeInfo->publicInetAddress,
                                       pNodeInfo->publicQueryPort, (const unsigned int *)senddata, 2)))
            return result;
        func_02175F3C()->flag = result;
    }
    return 0;
}

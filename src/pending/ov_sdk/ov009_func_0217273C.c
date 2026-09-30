/*
 * function: func_0217273C
 * address:  0x0217273C
 * packet:   pkt_ov009_0217273C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
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
 * Near miss (lane w8): 15 concrete bytes differ, all one callee-saved pair swap.
 * The enum-zero lever (docs/idioms/an-enum-typed-zero-keeps-its-own-web-where-a-u32-zero-is-folded.md)
 * fixed the hoist and the frame (177 -> 15 bytes): `ZeroE result; result = Z0;` and moving
 * `pNew = &tmpNewNodeInfo;` after the struct copy keeps the zero live in a register and
 * pushes r3-r7. blocker: the allocator homes the zero in r5 and pNew in r4; the image has
 * the zero in r4 and pNew in r5 (strb r4/r5 at +0x620,+0x6d9; movne r0,r4/r5; ldrh/ldm
 * [r5]/[r4] at +0xfc,+0x104,+0x128,+0x12c). Also +0x84/+0x88 store order and the +0xe8
 * beq target (+0x18ac vs +0x18a4) follow from that swap. Declaring result last and
 * reordering the senddata[0]/[1] stores both moved the diff the wrong way.
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
extern NodeInfo *func_0217637C(int index);
extern int func_02172604(void);
extern int func_0216FF2C(unsigned char command, int profileID, unsigned long ip, unsigned short port,
                         unsigned long *data, int len);
extern int func_021719A4(int error);

typedef enum { Z0 } ZeroE;

int func_0217273C(void)
{
    unsigned long senddata[16];
    ZeroE result;
    NodeInfo tmpNewNodeInfo;
    unsigned char linkProgress;
    NodeInfo *pNodeInfo;
    NodeInfo *pNew;

    result = Z0;
    tmpNewNodeInfo = func_02175F3C()->newNodeInfo;
    pNew = &tmpNewNodeInfo;
    if (func_02175F3C()->linkProgress < func_02176978() - 1) {
        linkProgress = func_02176978() - 1 - func_02175F3C()->linkProgress;
        func_02175F4C(0x10);
        pNodeInfo = func_0217637C(linkProgress);
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
                                       pNew->publicQueryPort, senddata, 9)))
            return result;
        pNodeInfo = func_0217637C(linkProgress);
        senddata[0] = pNew->profileID;
        senddata[1] = pNew->aid;
        if (func_021719A4(func_0216FF2C(10, pNodeInfo->profileID, pNodeInfo->publicInetAddress,
                                       pNodeInfo->publicQueryPort, senddata, 2)))
            return result;
    }
    func_02175F3C()->flag = result;
    return 0;
}

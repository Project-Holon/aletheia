/*
 * function: func_0216B65C
 * address:  0x0216B65C
 * packet:   pkt_ov009_0216B65C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_CloseAllConnectionsHard (libdwcmatch.TWL.HYB.a dwc_main.o)
 *
 * symbols:
 *   DWC_CancelMatch              0x0216C858 arm   ov009
 *   func_02059F38                0x02059F38 arm
 *   func_0217603C                0x0217603C arm   ov009
 *   func_0216F20C                0x0216F20C arm   ov009
 *   DWCi_NNFreeNegotiateList     0x02176B34 arm   ov009
 *   func_0216BC84                0x0216BC84 arm   ov009
 *   DWCi_ClearQR2Key             0x0216EC18 arm   ov009
 *   func_0217601C                0x0217601C arm   ov009
 *   func_02175F4C                0x02175F4C arm   ov009
 *   func_0216F6C0                0x0216F6C0 arm   ov009
 *   func_02195DE4                0x02195DE4 arm   ov009
 *   func_0217637C                0x0217637C arm   ov009
 *   func_0216C230                0x0216C230 arm   ov009
 *   func_0216B994                0x0216B994 arm   ov009
 *   g_021AA878                   0x021AA878 data
 *   g_021AA8A0                   0x021AA8A0 data
 */

typedef unsigned char u8;

struct GT2Socket { int pad; };

struct DWCControl {
    struct GT2Socket *socket;
    u8 pad0[0x24 - 0x4];
    int state;
    u8 pad1[0x2d - 0x28];
    u8 f2d;
    u8 pad2[0x64 - 0x2e];
    int myProfileID;
    u8 pad3[0xb05 - 0x68];
    u8 fb05;
};

struct DWCModule {
    int lastSocketError;
    struct DWCControl *ctrl;
};

struct DWCstNodeInfo {
    int profileID;
    u8 pad0[0x16 - 0x4];
    u8 aid;
};

extern struct DWCModule g_021AA878;
extern void *g_021AA8A0[32];

extern int DWC_CancelMatch(void);
extern int func_02059F38(void);
extern int func_0217603C(void);
struct GTI2Connection;
extern int func_0216F20C(int status);
extern void DWCi_NNFreeNegotiateList(void);
extern void func_0216BC84(int state);
extern void DWCi_ClearQR2Key(void);
extern void func_0217601C(void);
extern void func_02175F4C(int state);
extern void func_0216F6C0(void);
extern void func_02195DE4(int *p);
extern char *func_0217637C(int index);
extern void func_0216C230(struct GTI2Connection *connection, int reason, int isPseudClose, unsigned char closeAid);
extern int func_0216B994(void);

int func_0216B65C(void)
{
    struct DWCstNodeInfo *pNodeInfo;
    int i;
    int anyGT2ConnectionExist = 0;

    g_021AA878.ctrl->fb05 = 1;
    if (DWC_CancelMatch())
        return 1;
    if (g_021AA878.ctrl == 0 || func_02059F38() ||
        (g_021AA878.ctrl->state != 4 && g_021AA878.ctrl->state != 5))
        return -1;
    for (i = 0; i < 32; i++) {
        if (g_021AA8A0[i] != 0) {
            anyGT2ConnectionExist = 1;
            break;
        }
    }
    if (anyGT2ConnectionExist == 0) {
        func_0217603C();
        func_0216F20C(1);
        DWCi_NNFreeNegotiateList();
        func_0216BC84(3);
        DWCi_ClearQR2Key();
        func_0217601C();
        func_02175F4C(0);
        func_0216F6C0();
        return 1;
    }
    g_021AA878.ctrl->f2d = 1;
    func_02195DE4((int *)g_021AA878.ctrl->socket);
    while (func_0217603C() > 1) {
        for (i = 0; i < func_0217603C(); i++) {
            pNodeInfo = (struct DWCstNodeInfo *)func_0217637C(i);
            if (pNodeInfo->profileID != g_021AA878.ctrl->myProfileID)
                func_0216C230(0, 0, 1, pNodeInfo->aid);
        }
    }
    g_021AA878.ctrl->f2d = 0;
    func_0217601C();
    func_02175F4C(0);
    func_0216F6C0();
    if (func_0216B994() != 3) {
        DWCi_NNFreeNegotiateList();
        func_0216BC84(3);
        DWCi_ClearQR2Key();
    }
    return 0;
}

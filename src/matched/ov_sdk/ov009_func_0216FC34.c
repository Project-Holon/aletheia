/*
 * function: DWCi_NNStartupAsync
 * address:  0x0216FC34
 * packet:   pkt_ov009_0216FC34
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_NNStartupAsync (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt                 0x02175F3C arm
 *   NNCancel                         0x02199FB4 arm
 *   ServerBrowserGetMyPublicIPAddr   0x0219F0D8 arm
 *   SOC_GetHostID                    0x0215F7B0 arm
 *   IsPrivateAddr                    0x0216FBB8 arm
 *   DWCi_GetMathRand32               0x021685CC arm
 *   gt2GetLocalPort                  0x02195E40 arm
 *   DWCi_SendMatchCommand            0x0216FF2C arm
 *   DWCi_DoNatNegotiationAsync       0x0216FE34 arm
 *   gt2GetSocketSOCKET               0x02195E60 arm
 *   DWCi_NNCompletedCallback         0x02174FE8 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct DWCstMatchControl
{
    u8 pad0[4];
    void *f4;
    u8 pad1[0x5e0 - 8];
    void *f_5e0;
    u8 pad2[0x5fa - 0x5e4];
    u16 f_5fa;
    u8 pad3[0x608 - 0x5fc];
    int f_608;
    int f_60c;
    u8 f_610;
    u8 f_611;
    u16 f_612;
    u32 f_614;
    int f_618;
    u8 pad4[0x678 - 0x61c];
    int f_678;
    u8 pad5[0x6d9 - 0x67c];
    u8 f_6d9;
};

struct DWCstNodeInfo
{
    int f0;
    u32 f4;
    u32 f8;
    u16 f_c;
    u16 f_e;
    u32 f10;
    u16 f14;
    u8 pad1[0x17 - 0x16];
    u8 f17;
};

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern void NNCancel(int cookie);
extern u32 ServerBrowserGetMyPublicIPAddr(void * sb);
extern long SOC_GetHostID(void);
extern int IsPrivateAddr(u32 addr);
extern u32 DWCi_GetMathRand32(u32 max);
extern u32 gt2GetLocalPort(int socket);
extern int DWCi_SendMatchCommand(u8 command, int profileID, u32 ip, u16 port, u32 * data, int len);
extern int DWCi_DoNatNegotiationAsync(void * nnInfo);
extern int gt2GetSocketSOCKET(int gt2);
extern void DWCi_NNCompletedCallback(int result, int addr, int userdata, void * nnInfo);

int DWCi_NNStartupAsync(int isQR2, int cookie, struct DWCstNodeInfo * node)
{
    u32 senddata[2];
    int nnValid;
    int nnError = 0;
    int result;

    NNCancel(DWCi_GetMatchCnt()->f_618);

    if (isQR2 == 0) {
        cookie = (DWCi_GetMatchCnt()->f_678 & 0xffff) |
                 (DWCi_GetMatchCnt()->f_5fa << 16);
        if (node->f17 != 0) {
            if (node->f4 != ServerBrowserGetMyPublicIPAddr(DWCi_GetMatchCnt()->f_5e0)) {
                nnValid = 1;
            } else {
                node->f10 = node->f8;
                node->f14 = node->f_e;
                nnValid = 0;
            }
        } else {
            if (IsPrivateAddr(SOC_GetHostID())) {
                nnValid = 1;
            } else {
                node->f10 = node->f4;
                node->f14 = node->f_c;
                nnValid = 0;
            }
        }
        if (nnValid) {
            DWCi_GetMatchCnt()->f_5fa = DWCi_GetMathRand32(0x10000);
            DWCi_GetMatchCnt()->f_618 = cookie;
        } else {
            senddata[0] = SOC_GetHostID();
            senddata[1] = gt2GetLocalPort(*(int *)DWCi_GetMatchCnt()->f4);
            result = DWCi_SendMatchCommand(6, node->f0, node->f4, node->f_c, senddata, 2);
            DWCi_GetMatchCnt()->f_6d9 = 0;
            if (result != 0)
                return 2;
            DWCi_GetMatchCnt()->f_618 = 0;
        }
        DWCi_GetMatchCnt()->f_610 = 0;
        DWCi_GetMatchCnt()->f_611 = 0;
        DWCi_GetMatchCnt()->f_612 = node->f_c;
        DWCi_GetMatchCnt()->f_614 = node->f4;
    } else {
        DWCi_GetMatchCnt()->f_610 = 1;
        DWCi_GetMatchCnt()->f_611 = 0;
        DWCi_GetMatchCnt()->f_612 = 0;
        DWCi_GetMatchCnt()->f_614 = 0;
        DWCi_GetMatchCnt()->f_618 = cookie;
        nnValid = 1;
    }

    if (nnValid) {
        nnError = DWCi_DoNatNegotiationAsync(&DWCi_GetMatchCnt()->f_610);
    } else {
        struct DWCstMatchControl * cnt;

        DWCi_NNCompletedCallback(0, gt2GetSocketSOCKET(*(int *)DWCi_GetMatchCnt()->f4), 0,
                                 &DWCi_GetMatchCnt()->f_610);
        cnt = DWCi_GetMatchCnt();
        cnt->f_608 = 0;
        cnt->f_60c = 0;
    }
    return nnError;
}


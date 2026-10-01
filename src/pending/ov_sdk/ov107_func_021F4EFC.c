/*
 * function: func_021F4EFC
 * address:  0x021F4EFC
 * packet:   pkt_ov107_021F4EFC
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk: MBi_ChildCallback (libmb.TWL.HYB.a mb_wm_base.o).
 * Vendor stamp: 4.0.0.1024 (dsi/1.1p1) — fully matchable.
 * Relocations: WM_SetLifeTime, MBi_CheckWmErrcode, WM_StartScanEx,
 *   MBi_CheckMBParent, DC_InvalidateRange, MIi_DmaCopy16, MI_CpuCopy8,
 *   MIi_CpuCopy16, changeScanChannel, MBi_CommEnd, WM_StartConnectEx,
 *   WM_SetPortCallback, WM_StartMPEx, MBi_IsSendEnabled, WM_End,
 *   MBi_EndCommon, OS_Terminate, OS_SpinWaitSysCycles
 *
 * blocker (wave 8, 2026-10-01): case 0x26 state==5 arm now WRITTEN but not
 *   byte-exact. compiled 2636 vs original 2464 (overshoot 172 B), 2265
 *   concrete diffs, 38 relocation sites. The arm transcribed from the
 *   listing 0x021F50F0..0x021F53F4: outer while(n<bssDescCount) with the
 *   4-bool validity chain on bd[0x3C]/[0x4A]/[0x40]/length, MBi_CheckMBParent,
 *   the g(d_021F6E58)+0x10/0x14 mask gate, the 0x180-stride parent scan
 *   (bd[4..9] vs parent+0xCA..0xCF), then both copy blocks (ldm/stm for the
 *   duplicate case, MI_CpuCopy8/MIi_CpuCopy16 for the append case),
 *   DC_InvalidateRange / MIi_DmaCopy16, callback(4,...), and the shared
 *   rescan tail. All five previously-missing callees now appear. The new
 *   data relocs d_021F6E58 (0x021F6E58) and d_021F6FC0 (0x021F6FC0) are
 *   emitted as wildcards (no symbols: entry yet, so attestation needs them).
 *   Remaining structural mismatches: prologue/frame still differs from the
 *   image's {r3,r4,r5,r6,r7,r8,sb,sl,fp,lr}/0x28; the switch compare chain is
 *   vendor-ordered but we emit a balanced tree; state==4 tail is duplicated
 *   in source-vs-image. Too many cascading mismatches to reach EXACT in the
 *   15-minute window; parked.
 *   Reference (from the listing):
 *     state==4 (0x5488): callback(5,arg); if(!work[0x5E4]) return;
 *       if(work[0x5E8] != 0){ if(changeScanChannel(work) == 0) MBi_CommEnd(); }
 *       errcode = WM_StartScanEx(callback, work); MBi_CheckWmErrcode(0x26,errcode);
 *     state==5 (0x50E4): big beacon scan loop as transcribed above.
 *
 * symbols:
 *   WM_SetLifeTime             0x02090DEC  arm
 *   MBi_CheckWmErrcode         0x021F6334  arm
 *   WM_StartScanEx             0x0208F698  arm
 *   MBi_CheckMBParent          0x021F4538  arm
 *   DC_InvalidateRange         0x020862B8  arm
 *   MIi_DmaCopy16              0x020822E8  arm
 *   MI_CpuCopy8                0x02082D44  arm
 *   MIi_CpuCopy16              0x02082A60  arm
 *   changeScanChannel          0x021F4560  arm
 *   MBi_CommEnd                0x021F5EE4  arm
 *   WM_StartConnectEx          0x0208F84C  arm
 *   WM_SetPortCallback         0x0208EB0C  arm
 *   WM_StartMPEx               0x0208FBA8  arm
 *   MBi_IsSendEnabled          0x021F45C8  arm
 *   WM_End                     0x0208F43C  arm
 *   MBi_EndCommon              0x021F4684  arm
 *   OS_Terminate               0x02088234  arm
 *   OS_SpinWaitSysCycles       0x02087A04  arm
 *   d_021F6F90                 0x021F6F90  data
 *   d_021F6E58                 0x021F6E58  data
 *   d_021F6FC0                 0x021F6FC0  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct WMCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
};

struct WMStartScanExCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 channelList;
    u8 reserved[2];
    u16 bssDescCount;
    struct WMBssDesc *bssDesc[16];
    u16 linkLevel[16];
};

struct WMBssDesc {
    u16 length;
    u16 rssi;
    u8 bssid[6];
    u16 ssidLength;
    u8 ssid[32];
    u16 capaInfo;
    struct {
        u16 w0;
        u16 w2;
    } rateSet;
    u16 beaconPeriod;
    u16 dtimPeriod;
    u16 channel;
    u16 cfpPeriod;
    u16 cfpMaxDuration;
    u16 gameInfoLength;
    u16 otherElementCount;
    struct WMGameInfo {
        char _0[40];
    } gameInfo;
};

struct ParentInfo {
    union {
        struct WMBssDesc parentInfo;
        u8 parentInfo_area[192];
    };
    struct WMStartScanCallback {
        char _0[0xB8];
    } scan_data;
    u8 reserved1[8];
};

struct WMScanExParam {
    char _0[6];
    u16 channel;
};

struct MB_CommCommonWork {
    u32 sendbuf[256];
    u32 recvbuf[960];
    u8 user[22];
    u16 isMbInitialized;
    int block_size_max;
    int start_mp_busy;
    int is_started_ex;
};

extern char d_021F6F90[];

extern int WM_SetLifeTime(u16 a, u16 b, u16 c, u16 d);
extern void MBi_CheckWmErrcode(u16 apiid, int errcode);
extern int WM_StartScanEx(void *callback, struct WMScanExParam *param);
extern int MBi_CheckMBParent(void *bssDescp);
extern int DC_InvalidateRange(void *addr, u32 size);
extern int MIi_DmaCopy16(u32 ch, void *src, void *dst, u32 size, u32 mode);
extern int MI_CpuCopy8(void *src, void *dst, u32 size);
extern int MIi_CpuCopy16(void *src, void *dst, u32 size);
extern int changeScanChannel(void *param);
extern char d_021F6FC0[];
extern char d_021F6E58[];
extern void MBi_CommEnd(void);
extern int WM_StartConnectEx(void *callback, u16 a, u16 b, u16 c, u16 d);
extern int WM_SetPortCallback(u16 port, void *callback, void *arg);
extern int WM_StartMPEx(void *callback, u16 *recvBuf, u16 recvBufSize, u16 *sendBuf, u16 sendBufSize, u16 mpFreq, u16 defaultRetryCount, int minPollBmpMode, int singlePacketMode, int fixFreqMode, int ignoreFatalError);
extern int MBi_IsSendEnabled(void);
extern int WM_End(void *callback);
extern void MBi_EndCommon(void *arg);
extern void OS_Terminate(void);
extern void OS_SpinWaitSysCycles(u32 cycle);

static void func_021F4EFC(void *arg)
{
    struct WMCallback *buf = arg;
    void (*callback)(int, void *);
    char *base = base;
    struct ParentInfo *p;
    struct WMBssDesc *buffer;
    int i;
    int j;
    int numInvalidBeacon;
    struct WMStartScanExCallback *tmpBuf;
    int errcode;
    struct WMScanExParam *scanParam;

    callback = *(void (**)(int, void *))(base + 0x51C);
    p = (struct ParentInfo *)(base + 0x600);
    i = 0;
    j = 1;

    switch (buf->apiid) {
    case 0x00: {
        u16 errcode = buf->errcode;
        if (errcode != 0) {
            callback(0x100, arg);
            return;
        }
        callback(0x15, arg);
        {
            struct WMScanExParam *param = *(struct WMScanExParam **)(d_021F6F90 + 0x10);
            u16 a = param[0].channel;
            u16 b = param[1].channel;
            u16 c = param[2].channel;
            u16 d = param[3].channel;
            errcode = WM_SetLifeTime(a, b, c, d);
        }
        MBi_CheckWmErrcode(0x1D, errcode);
        return;
    }
    case 0x1D: {
        u16 errcode = buf->errcode;
        if (errcode != 0) {
            callback(0x100, arg);
            return;
        }
        {
            u16 *field6 = (u16 *)((char *)arg + 6);
            if (*field6 == 0)
                *field6 = 1;
        }
        {
            u16 *field8 = (u16 *)((char *)arg + 8);
            if (*field8 == 0)
                *field8 = 0xC8;
        }
        {
            u8 *base = *(u8 **)(d_021F6F90 + 0x14);
            base[0xA] = 0xFF;
            base[0xB] = 0xFF;
            base[0xC] = 0xFF;
            base[0xD] = 0xFF;
            base[0xE] = 0xFF;
            base[0xF] = 0xFF;
            *(u16 *)(base + 0x10) = 1;
            *(u16 *)(base + 0x12) = 0;
        }
        *(int *)(base + 0x5E4) = 1;
        *(int *)(base + 0x5E8) = 1;
        errcode = WM_StartScanEx(callback, *(struct WMScanExParam **)(d_021F6F90 + 0x10));
        MBi_CheckWmErrcode(0x26, errcode);
        return;
    }
    case 0x26: {
        u16 errcode = buf->errcode;
        if (errcode != 0) {
            callback(0x100, arg);
            return;
        }
        {
            u16 state = *(u16 *)((char *)arg + 8);
            if (state == 3)
                return;
            if (state == 4) {
                callback(5, arg);
                if (*(int *)(base + 0x5E4) == 0)
                    return;
                if (*(int *)(base + 0x5E8) != 0) {
                    if (changeScanChannel(*(char **)(d_021F6F90 + 0x10)) == 0)
                        MBi_CommEnd();
                }
                errcode = WM_StartScanEx(callback, *(struct WMScanExParam **)(d_021F6F90 + 0x10));
                MBi_CheckWmErrcode(0x26, errcode);
                return;
            }
            if (state == 5) {
                struct WMStartScanExCallback *cbArg = arg;
                int numInvalid = 0;
                int n = 0;
                while (n < cbArg->bssDescCount) {
                    struct WMBssDesc *bd = cbArg->bssDesc[n];
                    int a;
                    int b;
                    int c;
                    int d;
                    a = (bd->gameInfoLength >= 0x10 && bd->gameInfoLength <= 0x80);
                    b = a && (bd->gameInfoLength == *(u8 *)((char *)bd + 0x4A) + 0x10);
                    c = b && (*(u16 *)((char *)bd + 0x40) == 1);
                    d = c && (bd->length == (u16)((bd->gameInfoLength + 0x41) >> 1));
                    if (!d || MBi_CheckMBParent(bd) == 0) {
                        numInvalid = (numInvalid + 1) & 0xFF;
                    } else if (*(int *)(d_021F6F90 + 8) == 1 &&
                               ((*(u32 *)((char *)bd + 0x44) & *(u32 *)(d_021F6E58 + 0x14)) ==
                                (*(u32 *)(d_021F6E58 + 0x10) & *(u32 *)(d_021F6E58 + 0x14)))) {
                        numInvalid = (numInvalid + 1) & 0xFF;
                    } else {
                        int pidx = 0;
                        int found = 0;
                        while (pidx < *(u16 *)(base + 0x5E0)) {
                            u8 *par = (u8 *)base + 0x600 + pidx * 0x180;
                            int m = bd->bssid[0] == par[0xCA] && bd->bssid[1] == par[0xCB];
                            if (m)
                                m = bd->bssid[2] == par[0xCC];
                            if (m)
                                m = bd->bssid[3] == par[0xCD];
                            if (m)
                                m = bd->bssid[4] == par[0xCE];
                            if (m)
                                m = bd->bssid[5] == par[0xCF];
                            if (m) {
                                found = 1;
                                break;
                            }
                            pidx++;
                        }
                        if (found || pidx < 0x10) {
                            u8 *par = (u8 *)base + 0x600 + pidx * 0x180;
                            if (found) {
                                int k;
                                *(u16 *)(par + 0xF6) = bd->gameInfoLength;
                                for (k = 0; k < 8; k++)
                                    ((u32 *)(par + 0xF8))[k] = ((u32 *)((char *)bd + 0x40))[k];
                            } else {
                                *(u16 *)(base + 0x5E0) = pidx + 1;
                                MI_CpuCopy8((char *)bd + 4, par + 0xCA, 6);
                                *(u16 *)(par + 0xD0) = bd->channel;
                                *(u16 *)(par + 0xD2) = cbArg->linkLevel[n];
                                MIi_CpuCopy16((char *)bd + 0x40, par + 0xF8, 0x80);
                            }
                            DC_InvalidateRange(par, 0xC0);
                            MIi_DmaCopy16(*(u16 *)d_021F6F90, bd, par, 0xC0, 1);
                            *(int *)(base + 0x5EC) = pidx;
                            callback(4, (char *)arg + 0x50 + n * 2);
                            if (*(int *)(base + 0x5E4) == 0)
                                return;
                            if (*(int *)(base + 0x5E8) != 0) {
                                if (changeScanChannel(d_021F6FC0) == 0)
                                    MBi_CommEnd();
                            }
                            errcode = WM_StartScanEx((void *)func_021F4EFC, (struct WMScanExParam *)d_021F6FC0);
                            MBi_CheckWmErrcode(0x26, errcode);
                            return;
                        }
                    }
                    n = (n + 1) & 0xFF;
                }
                if (cbArg->bssDescCount == numInvalid)
                    callback(5, arg);
                if (*(int *)(base + 0x5E4) == 0)
                    return;
                if (*(int *)(base + 0x5E8) != 0) {
                    if (changeScanChannel(d_021F6FC0) == 0)
                        MBi_CommEnd();
                }
                errcode = WM_StartScanEx((void *)func_021F4EFC, (struct WMScanExParam *)d_021F6FC0);
                MBi_CheckWmErrcode(0x26, errcode);
                return;
            }
        }
        return;
    }
    case 0x0B: {
        u16 errcode = buf->errcode;
        if (errcode != 0) {
            callback(0x100, arg);
            return;
        }
        {
            u16 a = *(u16 *)(base + 0x520);
            u16 b = 0;
            u16 c = 1;
            u16 d = 0;
            errcode = WM_StartConnectEx(func_021F4EFC, a, b, c, d);
        }
        MBi_CheckWmErrcode(0xC, errcode);
        return;
    }
    case 0x0C: {
        u16 errcode = buf->errcode;
        if (errcode != 0) {
            *(u16 *)(base + 0x5E0) = 0;
            callback(0xB, arg);
            return;
        }
        {
            u16 state = *(u16 *)((char *)arg + 8);
            if (state > 9) {
                if (state == 0x1A) {
                    *(int *)(base + 0x5EC) = i;
                    return;
                }
                goto default_case;
            }
            if (state < 6)
                goto default_case;
            if (state == 6) {
                *(u16 *)(base + 0x52A) = 0;
                *(u16 *)(base + 0x528) = 0;
                return;
            }
            if (state == 7) {
                u16 bit = *(u16 *)((char *)arg + 0x10);
                int f = 1;
                *(u16 *)(base + 0x52A) |= (u16)(f << bit);
                callback(0, arg);
                if (*(u16 *)(base + 0x528) == 0 &&
                    ((struct MB_CommCommonWork *)*(char **)(d_021F6F90 + 0x10))->start_mp_busy == 0) {
                    ((struct MB_CommCommonWork *)*(char **)(d_021F6F90 + 0x10))->start_mp_busy = f;
                    f = (*(u16 *)(base + 0x52C) != 0) ? 0 : f;
                    {
                        char *parm = base;
                        errcode = WM_StartMPEx(callback,
                            *(u16 **)(parm + 0x504),
                            *(u16 *)(parm + 0x51A),
                            (u16 *)(parm + 0x40),
                            *(u16 *)(parm + 0x518),
                            f, 0, 0, 0, 1, 1);
                    }
                    return;
                }
                if (MBi_IsSendEnabled()) {
                    callback(0x19, 0);
                }
                return;
            }
            if (state == 8) {
                struct ParentInfo *pi = (struct ParentInfo *)(base + 0x500);
                *(u16 *)(base + 0x52A) &= (u16)~(1 << *(u16 *)((char *)arg + 0x10));
                callback(1, arg);
                return;
            }
            if (state == 9) {
                u16 *field = (u16 *)(base + 0x500 + 0x2A);
                *field = 0;
                *(u16 *)(base + 0x528) = 0;
                return;
            }
        }
    default_case:
    default:
        callback(0x100, arg);
        return;
    }
    case 0x0E: {
        u16 wlCmdID = buf->wlCmdID;
        if (wlCmdID == 0xA) {
            *(u16 *)(base + 0x528) = 1;
            if (*(u16 *)(base + 0x526) != 0)
                return;
            callback(0x19, 0);
            return;
        }
        if (wlCmdID == 0xB) {
            callback(3, *(void **)((char *)arg + 8));
            return;
        }
        callback(0x100, arg);
        return;
    }
    case 0x0F: {
        u16 errcode = buf->errcode;
        *(u8 *)(base + 0x50C) = 0;
        if (errcode == 0) {
            callback(2, arg);
            if (*(u16 *)(base + 0x526) == 0)
                callback(0x19, 0);
            return;
        }
        if (errcode == 0xA) {
            callback(0x2A, arg);
            return;
        }
        callback(0x13, arg);
        if (*(u16 *)(base + 0x526) == 0)
            callback(0x19, 0);
        return;
    }
    case 0x01: {
        u16 errcode = buf->errcode;
        if (errcode != 0) {
            *(u16 *)(base + 0x526) = 0;
            *(u16 *)(base + 0x500 + 0x26) = 0;
            callback(0x100, arg);
            return;
        }
        *(u16 *)(base + 0x500 + 0x2A) = 0;
        *(u16 *)(base + 0x528) = 0;
        {
            char *base = base;
            char *parm = base + 0x500;
            errcode = WM_End(callback);
        }
        MBi_CheckWmErrcode(2, errcode);
        return;
    }
    case 0x02: {
        u16 field2 = *(u16 *)((char *)arg + 2);
        if (field2 == 0) {
            MBi_EndCommon(arg);
            return;
        }
        *(u16 *)(base + 0x500 + 0x26) = 0;
        callback(0x100, arg);
        return;
    }
    case 0x15: {
        if (!MBi_IsSendEnabled())
            return;
        callback(0x19, 0);
        if (*(int *)(base + 0x5E4) != 0)
            return;
        if (*(int *)(base + 0x5E8) != 0)
            return;
        errcode = changeScanChannel(*(char **)(d_021F6F90 + 0x10));
        if (errcode == 0)
            return;
        MBi_CommEnd();
        errcode = WM_StartScanEx(callback, *(struct WMScanExParam **)(d_021F6F90 + 0x10));
        MBi_CheckWmErrcode(0x26, errcode);
        return;
    }
    case 0x80: {
        u16 subcmd = *(u16 *)((char *)arg + 4);
        if (subcmd == 0x16)
            OS_Terminate();
        return;
    }
    }
}

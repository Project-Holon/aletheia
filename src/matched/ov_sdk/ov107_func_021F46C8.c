/*
 * function: MBi_ParentCallback
 * address:  0x021F46C8
 * packet:   pkt_ov107_021F46C8
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_ParentCallback (TwlSDK/libmb.TWL.HYB.a(mb_wm_base.o)).
 *           2004 bytes, EXACT.  Four body-shape facts, each measured:
 *
 *   1. `struct MB_CommCommonWork *` is 0x2c+0x18=0x1340, so
 *      work+0x74C8/0x74E8 land in the 0x7000 limb and work+0x14E8/0x14E8
 *      in the 0x1000 limb, as the object's `add r3,#0x7000` /
 *      `add r0,#0x1000` pairing shows.
 *   2. The case-0x0F loop counters `i` and `n` are u32 and declared
 *      `u32 i; u32 n; char *work;` in that order.  mwcc hands r1/r2/r3 to
 *      the three case-0x0F locals in declaration order, so this exact
 *      order is the image's (work=r3, n=r2, i=r1).  Signed counters emit
 *      `blt`/`bge` for `i < 15` / `n >= 2` where the object has `blo`/`bhs`.
 *   3. The case-0x01 is_started_ex test is written INVERTED
 *      (`== 0` first, the started block after it) so the not-started block
 *      is the fall-through and the started block is the out-of-line branch,
 *      matching `bne 0x021F4CDC`.
 *   4. g_021F6F90.p_parm is read twice at +0x02E0/+0x02E4 -- once for the
 *      case-0x0F `contSend` ternary and once for the WM_StartMPEx argument
 *      list.  mwccarm CSEs the two plain reads into one; the first is
 *      spelled `*(char *volatile *)(gMbWm + 0xC)` to defeat the CSE
 *      (rule 4d's volatile-pointer lever), which restores the load and the
 *      4-byte extent.  A second alias symbol for 0x021F6F90 is worse (2012).
 *   5. The inner wlCmdID switch of case 0x80 ends in `break;`, not
 *      `return;`: that makes its empty cases (0x14, 0x15, 0x17) and the
 *      out-of-range slot share the outer switch's final epilogue at
 *      0x021F4E84 with the default block, where a `return;` routes them to
 *      the identical epilogue at 0x021F4E68 left by `case 0x16:
 *      OS_Terminate();` (4 jump-table words differ, nothing else).
 *
 * symbols:
 *   MBi_OnInitializeDone             0x021f4628 arm ov107
 *   WM_SetParentParameter            0x0208f480 arm
 *   MBi_CheckWmErrcode               0x021f6334 arm ov107
 *   WM_SetBeaconIndication           0x02090d98 arm
 *   WMi_StartParentEx                0x0208f5c8 arm
 *   MBi_EndCommon                    0x021f4684 arm ov107
 *   WM_StartMPEx                     0x0208fba8 arm
 *   MBi_IsSendEnabled                0x021f45c8 arm ov107
 *   OS_SpinWaitSysCycles             0x02087a04 arm
 *   WM_End                           0x0208f43c arm
 *   WM_SetPortCallback               0x0208eb0c arm
 *   WM_SetIndCallback                0x0208eac8 arm
 *   OS_Terminate                     0x02088234 arm
 *   gMbWm                       0x021f6f90 data ov107
 *   MBi_ParentCallback               0x021f46c8 arm ov107
 *   mbi_life_mp                      0x021f6e58 data ov107
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov107_func_021F46C8.c \
 *       --func MBi_ParentCallback --addr 0x021F46C8 --region ov107 --arm \
 *       --cc 1.1p1 --lang c99 --diff
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

struct MBiLife {
    u16 w4;
    u16 w6;
    u16 w2;
    u16 w0;
    int w8;
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

extern char gMbWm[];
extern struct MBiLife mbi_life_mp;

extern void MBi_OnInitializeDone(void);
extern void MBi_EndCommon(void *arg);
extern void MBi_CheckWmErrcode(u16 apiid, int errcode);
extern int MBi_IsSendEnabled(void);
extern void MBi_ParentCallback(void *arg);

extern int WM_SetParentParameter(void (*callback)(void *), void *pparaBuf);
extern int WM_SetBeaconIndication(void (*callback)(void *), u16 flag);
extern int WMi_StartParentEx(void (*callback)(void *), int powerSave);
extern int WM_StartMPEx(void (*callback)(void *), u16 *recvBuf, u16 recvBufSize, u16 *sendBuf, u16 sendBufSize, u16 mpFreq, u16 defaultRetryCount, int minPollBmpMode, int singlePacketMode, int fixFreqMode, int ignoreFatalError);
extern int WM_End(void (*callback)(void *));
extern int WM_SetPortCallback(u16 port, void (*callback)(void *), void *arg);
extern int WM_SetIndCallback(void (*callback)(void *));
extern void OS_SpinWaitSysCycles(u32 cycle);
extern void OS_Terminate(void);

static void MBi_ParentCallback(void *arg)
{
    struct WMCallback *buf = arg;
    void (*callback)(int, void *);
    u32 i;
    u32 n;
    char *work;
    int f;
    u16 bit;

    switch (buf->apiid) {
    case 0x00:
        if (buf->errcode != 0) {
            callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
            callback(0x100, arg);
            return;
        }
        MBi_OnInitializeDone();
        return;
    case 0x1D:
        if (buf->errcode != 0) {
            callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
            callback(0x100, arg);
            return;
        }
        MBi_CheckWmErrcode(7, WM_SetParentParameter(MBi_ParentCallback, *(char **)(gMbWm + 0xC)));
        return;
    case 0x07:
        callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
        callback(0x15, arg);
        MBi_CheckWmErrcode(0x19, WM_SetBeaconIndication(MBi_ParentCallback, 1));
        return;
    case 0x19:
        if (*(u16 *)(*(char **)(gMbWm + 0xC) + 0x526) == 0) {
            if (buf->errcode != 0) {
                callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
                callback(0x100, arg);
                return;
            }
            MBi_CheckWmErrcode(8, WMi_StartParentEx(MBi_ParentCallback, mbi_life_mp.w8));
            return;
        }
        if (buf->errcode != 0) {
            *(u16 *)(*(char **)(gMbWm + 0xC) + 0x526) = 0;
            callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
            callback(0x100, arg);
            return;
        }
        MBi_EndCommon(arg);
        return;
    case 0x08:
        if (buf->errcode != 0) {
            callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
            callback(0x100, arg);
            return;
        }
        switch (*(u16 *)((char *)arg + 8)) {
        case 0x00:
            *(u16 *)(*(char **)(gMbWm + 0xC) + 0x52A) = 0;
            *(u16 *)(*(char **)(gMbWm + 0xC) + 0x528) = 0;
            return;
        case 0x07:
            if (*(u16 *)(*(char **)(gMbWm + 0xC) + 0x526) == 1)
                return;
            f = 1;
            bit = *(u16 *)((char *)arg + 0x10);
            *(u16 *)(*(char **)(gMbWm + 0xC) + 0x52A) |= (u16)(f << bit);
            callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
            callback(0, arg);
            if (*(u16 *)(*(char **)(gMbWm + 0xC) + 0x528) == 0 && ((struct MB_CommCommonWork *)*(char **)(gMbWm + 0x10))->start_mp_busy == 0) {
                ((struct MB_CommCommonWork *)*(char **)(gMbWm + 0x10))->start_mp_busy = f;
                f = (*(u16 *)(*(char *volatile *)(gMbWm + 0xC) + 0x52C) != 0) ? 0 : f;
                {
                    char *parm = *(char **)(gMbWm + 0xC);
                    MBi_CheckWmErrcode(0x0E, WM_StartMPEx(MBi_ParentCallback,
                        *(u16 **)(parm + 0x504),
                        *(u16 *)(parm + 0x51A),
                        (u16 *)(parm + 0x40),
                        *(u16 *)(parm + 0x518),
                        (u16)f, 0, 0, 0, 1, 1));
                }
                return;
            }
            if (MBi_IsSendEnabled()) {
                callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
                callback(0x19, 0);
            }
            return;
        case 0x09:
            bit = *(u16 *)((char *)arg + 0x10);
            *(u16 *)(*(char **)(gMbWm + 0xC) + 0x52A) &= (u16)~(1 << bit);
            callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
            callback(1, arg);
            return;
        case 0x02:
            if (*(u16 *)(*(char **)(gMbWm + 0xC) + 0x526) != 1) {
                callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
                callback(0x1C, arg);
            }
            return;
        case 0x1A:
            return;
        default:
            callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
            callback(0x100, arg);
            return;
        }
    case 0x0E:
        ((struct MB_CommCommonWork *)*(char **)(gMbWm + 0x10))->start_mp_busy = 0;
        switch (buf->wlCmdID) {
        case 0x0A:
            *(u16 *)(*(char **)(gMbWm + 0xC) + 0x528) = 1;
            if (*(u16 *)(*(char **)(gMbWm + 0xC) + 0x526) != 0)
                return;
            callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
            callback(0x19, 0);
            return;
        case 0x0B:
            callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
            callback(3, *(void **)((char *)arg + 8));
            return;
        default:
            callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
            callback(0x100, arg);
            return;
        }
    case 0x0F:
        work = *(char **)(gMbWm + 0x10);
        if (*(u32 *)(work + 0x74C8) != 0) {
            n = 0;
            for (i = 0; i < 15; i++) {
                if (*(u32 *)(work + 0x14E8 + i * 4) != 0) {
                    n++;
                    if (n >= 2)
                        break;
                }
            }
            if (n == 1)
                OS_SpinWaitSysCycles(6500);
        }
        *(u8 *)(*(char **)(gMbWm + 0xC) + 0x50C) = 0;
        if (buf->errcode == 0) {
            callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
            callback(2, arg);
            if (*(u16 *)(*(char **)(gMbWm + 0xC) + 0x526) == 0) {
                callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
                callback(0x19, 0);
            }
            return;
        }
        if (buf->errcode == 0x0A) {
            callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
            callback(0x2A, arg);
            return;
        }
        callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
        callback(0x13, arg);
        if (*(u16 *)(*(char **)(gMbWm + 0xC) + 0x526) == 0) {
            callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
            callback(0x19, 0);
        }
        return;
    case 0x01:
        work = *(char **)(gMbWm + 0x10);
        if (((struct MB_CommCommonWork *)work)->is_started_ex == 0) {
            if (buf->errcode != 0) {
                *(u16 *)(*(char **)(gMbWm + 0xC) + 0x526) = 0;
                callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
                callback(0x100, arg);
                return;
            }
            *(u16 *)(*(char **)(gMbWm + 0xC) + 0x52A) = 0;
            *(u16 *)(*(char **)(gMbWm + 0xC) + 0x528) = 0;
            MBi_CheckWmErrcode(2, WM_End(MBi_ParentCallback));
            return;
        }
        WM_SetPortCallback(1, 0, 0);
        WM_SetIndCallback(0);
        if (buf->errcode != 0) {
            *(u16 *)(*(char **)(gMbWm + 0xC) + 0x526) = 0;
            callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
            callback(0x100, arg);
            return;
        }
        MBi_CheckWmErrcode(0x19, WM_SetBeaconIndication(MBi_ParentCallback, 0));
        return;
    case 0x02:
        if (buf->errcode != 0) {
            *(u16 *)(*(char **)(gMbWm + 0xC) + 0x526) = 0;
            callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
            callback(0x100, arg);
            return;
        }
        MBi_EndCommon(arg);
        return;
    case 0x0D:
        if (buf->errcode != 0)
            return;
        *(u16 *)(*(char **)(gMbWm + 0xC) + 0x52A) &= (u16)~*(u16 *)((char *)arg + 0xA);
        return;
    case 0x80:
        switch (*(u16 *)((char *)arg + 4)) {
        case 0x10:
            callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
            callback(0x1D, arg);
            break;
        case 0x11:
            callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
            callback(0x1F, arg);
            break;
        case 0x12:
            callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
            callback(0x20, arg);
            break;
        case 0x13:
            callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
            callback(0x21, arg);
            break;
        case 0x17:
            break;
        case 0x16:
            OS_Terminate();
            break;
        }
        break;
    default:
        callback = *(void (**)(int, void *))(*(char **)(gMbWm + 0xC) + 0x51C);
        callback(0x100, arg);
        return;
    }
}

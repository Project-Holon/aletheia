/*
 * file:     unit_021F4560_p01.c
 * unit:     yes
 * function: func_021F4560, func_021F45C8, func_021F4628, MBi_EndCommon, func_021F46C8, func_021F4E9C
 * address:  0x021F4560
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   mbi_reject_ggid_mask 0x021F6E6C data
 *   mbi_reject_ggid 0x021F6E68 data
 *   mbi_power_save_mode 0x021F6E60 data
 *   mbi_life_frame 0x021F6E5E data
 *   mbi_life_table_no 0x021F6E5C data
 *   mbi_life_cam 0x021F6E5A data
 *   WM_GetAllowedChannel             0x0208ee60 arm
 *   d_021F6F90   0x021F6F90  data
 *   WM_SetIndCallback                0x0208eac8 arm
 *   MBi_CheckWmErrcode               0x021f6334 arm
 *   WM_SetLifeTime                   0x02090dec arm
 *   mbi_life_mp                      0x021f6e58 data
 *   WM_SetParentParameter            0x0208f480 arm
 *   WM_SetBeaconIndication           0x02090d98 arm
 *   WMi_StartParentEx                0x0208f5c8 arm
 *   WM_StartMPEx                     0x0208fba8 arm
 *   OS_SpinWaitSysCycles             0x02087a04 arm
 *   WM_End                           0x0208f43c arm
 *   WM_SetPortCallback               0x0208eb0c arm
 *   OS_Terminate                     0x02088234 arm
 */
#include "mb_wm.h"

struct WMPortRecvCallback {
    char _0[2];
    u16 field2;
    u16 field4;
};

extern u16 WM_GetAllowedChannel(void);
extern void MBi_CheckWmErrcode(u16 apiid, int errcode);
extern int WM_SetIndCallback(void (*callback)(void *));
extern int WM_SetLifeTime(void (*callback)(void *), u16 tableNumber, u16 camLifeTime, u16 frameLifeTime, u16 mpLifeTime);
extern int WM_SetParentParameter(void (*callback)(void *), void *pparaBuf);
extern int WM_SetBeaconIndication(void (*callback)(void *), u16 flag);
extern int WMi_StartParentEx(void (*callback)(void *), int powerSave);
extern int WM_StartMPEx(void (*callback)(void *), u16 *recvBuf, u16 recvBufSize, u16 *sendBuf, u16 sendBufSize, u16 mpFreq, u16 defaultRetryCount, int minPollBmpMode, int singlePacketMode, int fixFreqMode, int ignoreFatalError);
extern int WM_End(void (*callback)(void *));
extern int WM_SetPortCallback(u16 port, void (*callback)(void *), void *arg);
extern void OS_SpinWaitSysCycles(u32 cycle);
extern void OS_Terminate(void);

static void MBi_ParentCallback(void *arg);




static int changeScanChannel(WMScanExParam *p)
{
    u16 i;
    u16 channel_bmp;
    u16 channel;

    channel_bmp = WM_GetAllowedChannel();
    if (channel_bmp == 0)
        return 0;
    i = 0;
    channel = p->channelList;
    do {
        if ((channel_bmp & channel) != 0 && p->channelList != channel) {
            p->channelList = channel;
            break;
        }
        i = (u16)(i + 1);
        channel = (u16)(channel == 0 ? 1 : channel << 1);
    } while (i < 16);
    return 1;
}




static int MBi_IsSendEnabled(void)
{
    int ret = 0;
    int g = 0;
    int f = 0;
    char *base = *(char **)(d_021F6F90 + 0xC);

    if (*(u16 *)(base + 0x528) == 1 && *(u8 *)(base + 0x50C) == 0)
        f = 1;
    if (f) {
        if (*(u16 *)(base + 0x526) == 0)
            g = 1;
    }
    if (g) {
        if (*(u16 *)(base + 0x52A) != 0)
            ret = 1;
    }
    return ret;
}




static void MBi_OnInitializeDone(void)
{
    MBi_CheckWmErrcode(0x80, WM_SetIndCallback(MBi_ParentCallback));
    MBi_CheckWmErrcode(0x1D, WM_SetLifeTime(MBi_ParentCallback, mbi_life_table_no, mbi_life_cam, mbi_life_frame, mbi_life_mp));
}



static void MBi_EndCommon(void *arg)
{
    void (*callback)(int, void *);

    *(u8 *)(*(char **)(d_021F6F90 + 0xC) + 0x50D) = 0;
    *(u16 *)(*(char **)(d_021F6F90 + 0x10) + 0x1316) = 0;
    callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
    if (callback == 0)
        return;
    callback(0x11, arg);
}



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
            callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
            callback(0x100, arg);
            return;
        }
        MBi_OnInitializeDone();
        return;
    case 0x1D:
        if (buf->errcode != 0) {
            callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
            callback(0x100, arg);
            return;
        }
        MBi_CheckWmErrcode(7, WM_SetParentParameter(MBi_ParentCallback, *(char **)(d_021F6F90 + 0xC)));
        return;
    case 0x07:
        callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
        callback(0x15, arg);
        MBi_CheckWmErrcode(0x19, WM_SetBeaconIndication(MBi_ParentCallback, 1));
        return;
    case 0x19:
        if (*(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x526) == 0) {
            if (buf->errcode != 0) {
                callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
                callback(0x100, arg);
                return;
            }
            MBi_CheckWmErrcode(8, WMi_StartParentEx(MBi_ParentCallback, mbi_power_save_mode));
            return;
        }
        if (buf->errcode != 0) {
            *(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x526) = 0;
            callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
            callback(0x100, arg);
            return;
        }
        MBi_EndCommon(arg);
        return;
    case 0x08:
        if (buf->errcode != 0) {
            callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
            callback(0x100, arg);
            return;
        }
        switch (*(u16 *)((char *)arg + 8)) {
        case 0x00:
            *(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x52A) = 0;
            *(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x528) = 0;
            return;
        case 0x07:
            if (*(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x526) == 1)
                return;
            f = 1;
            bit = *(u16 *)((char *)arg + 0x10);
            *(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x52A) |= (u16)(f << bit);
            callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
            callback(0, arg);
            if (*(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x528) == 0 && ((struct MB_CommCommonWork *)*(char **)(d_021F6F90 + 0x10))->start_mp_busy == 0) {
                ((struct MB_CommCommonWork *)*(char **)(d_021F6F90 + 0x10))->start_mp_busy = f;
                f = (*(u16 *)(*(char *volatile *)(d_021F6F90 + 0xC) + 0x52C) != 0) ? 0 : f;
                {
                    char *parm = *(char **)(d_021F6F90 + 0xC);
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
                callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
                callback(0x19, 0);
            }
            return;
        case 0x09:
            bit = *(u16 *)((char *)arg + 0x10);
            *(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x52A) &= (u16)~(1 << bit);
            callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
            callback(1, arg);
            return;
        case 0x02:
            if (*(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x526) != 1) {
                callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
                callback(0x1C, arg);
            }
            return;
        case 0x1A:
            return;
        default:
            callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
            callback(0x100, arg);
            return;
        }
    case 0x0E:
        ((struct MB_CommCommonWork *)*(char **)(d_021F6F90 + 0x10))->start_mp_busy = 0;
        switch (buf->wlCmdID) {
        case 0x0A:
            *(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x528) = 1;
            if (*(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x526) != 0)
                return;
            callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
            callback(0x19, 0);
            return;
        case 0x0B:
            callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
            callback(3, *(void **)((char *)arg + 8));
            return;
        default:
            callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
            callback(0x100, arg);
            return;
        }
    case 0x0F:
        work = *(char **)(d_021F6F90 + 0x10);
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
        *(u8 *)(*(char **)(d_021F6F90 + 0xC) + 0x50C) = 0;
        if (buf->errcode == 0) {
            callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
            callback(2, arg);
            if (*(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x526) == 0) {
                callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
                callback(0x19, 0);
            }
            return;
        }
        if (buf->errcode == 0x0A) {
            callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
            callback(0x2A, arg);
            return;
        }
        callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
        callback(0x13, arg);
        if (*(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x526) == 0) {
            callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
            callback(0x19, 0);
        }
        return;
    case 0x01:
        work = *(char **)(d_021F6F90 + 0x10);
        if (((struct MB_CommCommonWork *)work)->is_started_ex == 0) {
            if (buf->errcode != 0) {
                *(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x526) = 0;
                callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
                callback(0x100, arg);
                return;
            }
            *(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x52A) = 0;
            *(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x528) = 0;
            MBi_CheckWmErrcode(2, WM_End(MBi_ParentCallback));
            return;
        }
        WM_SetPortCallback(1, 0, 0);
        WM_SetIndCallback(0);
        if (buf->errcode != 0) {
            *(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x526) = 0;
            callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
            callback(0x100, arg);
            return;
        }
        MBi_CheckWmErrcode(0x19, WM_SetBeaconIndication(MBi_ParentCallback, 0));
        return;
    case 0x02:
        if (buf->errcode != 0) {
            *(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x526) = 0;
            callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
            callback(0x100, arg);
            return;
        }
        MBi_EndCommon(arg);
        return;
    case 0x0D:
        if (buf->errcode != 0)
            return;
        *(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x52A) &= (u16)~*(u16 *)((char *)arg + 0xA);
        return;
    case 0x80:
        switch (*(u16 *)((char *)arg + 4)) {
        case 0x10:
            callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
            callback(0x1D, arg);
            break;
        case 0x11:
            callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
            callback(0x1F, arg);
            break;
        case 0x12:
            callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
            callback(0x20, arg);
            break;
        case 0x13:
            callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
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
        callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
        callback(0x100, arg);
        return;
    }
}



static void MBi_ChildPortCallback(void *arg)
{
    struct WMPortRecvCallback *cb = arg;
    void (*callback)(int, void *);

    if (cb->field2 != 0)
        return;
    switch (cb->field4) {
    case 7:
    case 9:
    case 0x19:
    case 0x1A:
        break;
    case 0x15:
        callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
        callback(9, arg);
        break;
    }
}

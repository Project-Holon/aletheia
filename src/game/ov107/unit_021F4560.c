/*
 * file:     unit_021F4560.c
 * unit:     yes
 * function: func_021F4560, func_021F45C8, func_021F4628, MBi_EndCommon, func_021F46C8, func_021F4E9C, MBi_ChildCallback, MBi_GetBeaconPeriodDispersion, MB_Init, func_021F5ADC, func_021F5B4C, func_021F5BE0, func_021F5CAC, MB_StartParentFromIdle, MBi_CallReset, func_021F5ED8, MBi_CommEnd, func_021F5F74, func_021F5FB0, func_021F6148, func_021F6158, func_021F61A4, func_021F628C, func_021F62A0, func_021F62B4, MBi_IsStarted, MBi_CheckWmErrcode
 * address:  0x021F4560
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
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
 *   WM_StartScanEx             0x0208F698  arm
 *   MBi_CheckMBParent          0x021F4538  arm
 *   DC_InvalidateRange         0x020862B8  arm
 *   MIi_DmaCopy16              0x020822E8  arm
 *   MI_CpuCopy8                0x02082D44  arm
 *   MIi_CpuCopy16              0x02082A60  arm
 *   changeScanChannel          0x021F4560  arm
 *   MBi_CommEnd                0x021F5EE4  arm
 *   WM_StartConnectEx          0x0208F84C  arm
 *   MBi_IsSendEnabled          0x021F45C8  arm
 *   MBi_EndCommon              0x021F4684  arm
 *   MBi_ChildPortCallback      0x021F4E9C  arm
 *   WM_DMA_NO                  0x021F6F90  data
 *   mbiScanParam               0x021F6FC0  data
 *   OS_GetMacAddress                 0x02087c6c arm
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 *   func_021F5ADC 0x021F5ADC arm ov107
 *   func_021F6148 0x021F6148 arm ov107
 *   func_0208F370 0x0208F370 arm
 *   func_0208EAC8 0x0208EAC8 arm
 *   func_021F4628 0x021F4628 arm ov107
 *   func_02082A48  0x02082A48  arm
 *   func_021F1B3C  0x021F1B3C  arm  ov107
 *   func_021F6804  0x021F6804  arm  ov107
 *   func_021F6830  0x021F6830  arm  ov107
 *   func_02082BCC  0x02082BCC  arm
 *   func_021F3F78  0x021F3F78  arm  ov107
 *   func_020885EC  0x020885EC  arm
 *   func_021F1D80  0x021F1D80  arm  ov107
 *   func_021F46C8  0x021F46C8  arm  ov107
 *   WM_Reset     0x0208F400  arm
 *   func_021F6334   0x021F6334  arm
 *   OS_DisableInterrupts             0x02087988 arm
 *   MBi_IsTaskAvailable              0x021f6610 arm
 *   MBi_EndTaskThread                0x021f67bc arm
 *   OS_RestoreInterrupts             0x0208799c arm
 *   MBi_OnReset                      0x021f5ed8 arm
 *   func_0208F938  0x0208F938  arm
 *   func_021F6850  0x021F6850  arm  ov107
 *   WM_SetMPDataToPortEx             0x0208fcb4 arm
 *   func_021F6158 0x021F6158 arm ov107
 *   func_021F4EFC 0x021F4EFC arm ov107
 */
#define MB_WM_OWN_STATICS
#include "mb_wm.h"

static u16 mbi_life_frame = 5;
static u16 mbi_life_table_no = 0xffff;
static u16 mbi_life_cam = 0x28;
static u16 mbi_life_mp = 0x28;
static int mbi_power_save_mode = 1;


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


/* MB_Init game name cursor. A function static of an inline helper is emitted
   here (before the reject words) and, unlike a file static, stays outside the
   unknown-memory alias set, as in the image. */
static inline u16 mbi_game_char(int advance)
{
    static const u16 *game = L"multiboot";
    u16 ch = *game;
    if (advance)
        game++;
    return ch;
}
static u32 mbi_reject_ggid = 0xffffffff;
static u32 mbi_reject_ggid_mask = 0xffffffff;

extern int WM_SetLifeTime(void (*callback)(void *), u16 tableNumber, u16 camLifeTime, u16 frameLifeTime, u16 mpLifeTime);
extern void MBi_CheckWmErrcode(u16 apiid, int errcode);
extern int WM_StartScanEx(void (*callback)(void *), WMScanExParam *param);
extern BOOL MBi_CheckMBParent(WMBssDesc *bssDescp);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void MIi_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size, BOOL dmaEnable);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern void MIi_CpuCopy16(const void *srcp, void *destp, u32 size);
extern BOOL changeScanChannel(WMScanExParam *p);
extern BOOL MBi_CommEnd(void);
extern int WM_StartConnectEx(void (*callback)(void *), WMBssDesc *pInfo, u8 *ssid, BOOL powerSave, u16 authMode);
extern int WM_SetPortCallback(u16 port, void (*callback)(void *), void *arg);
extern int WM_StartMPEx(void (*callback)(void *), u16 *recvBuf, u16 recvBufSize, u16 *sendBuf, u16 sendBufSize, u16 mpFreq, u16 defaultRetryCount, BOOL minPollBmpMode, BOOL singlePacketMode, BOOL fixFreqMode, BOOL ignoreFatalError);
extern BOOL MBi_IsSendEnabled(void);
extern int WM_End(void (*callback)(void *));
extern void MBi_EndCommon(void *arg);
extern void OS_Terminate(void);
extern void OS_GetMacAddress(u8 *macAddress);
/* .data anchor at mbi_life_mp (0x021F6E58) */


static void MBi_ChildPortCallback(void *arg);

static void MBi_ChildCallback(void *arg);


static inline BOOL WM_IsBssidEqual(const u8 *idp1, const u8 *idp2)
{
    return idp1[0] == idp2[0] && idp1[1] == idp2[1] && idp1[2] == idp2[2]
        && idp1[3] == idp2[3] && idp1[4] == idp2[4] && idp1[5] == idp2[5];
}


static inline BOOL WM_IsValidGameInfo(const WMGameInfo *gameInfo, u16 gameInfoLength)
{
    return gameInfoLength >= 0x10 && gameInfoLength <= sizeof(WMGameInfo)
        && gameInfoLength == 0x10 + gameInfo->userGameInfoLength
        && gameInfo->magicNumber == 1;
}


static inline BOOL WM_IsValidGameBeacon(const WMBssDesc *bssDesc)
{
    return WM_IsValidGameInfo(&bssDesc->gameInfo, bssDesc->gameInfoLength)
        && bssDesc->length == (sizeof(WMBssDesc) - sizeof(WMGameInfo) + bssDesc->gameInfoLength + 1) / 2;
}


static inline int WM_StartConnect(void (*callback)(void *), WMBssDesc *pInfo, u8 *ssid)
{
    return WM_StartConnectEx(callback, pInfo, ssid, 1, 0);
}


static inline void MI_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size)
{
    MIi_DmaCopy16(dmaNo, src, dest, size, 1);
}


static inline void MI_CpuCopy16(const void *src, void *dest, u32 size)
{
    MIi_CpuCopy16(src, dest, size);
}


static void MBi_ChildCallback(void *arg)
{
    WMCallback *buf = (WMCallback *)arg;
    MBiParam *const p_param = mbWm.work;

    switch (buf->apiid) {
    case 0x00:
        if (buf->errcode != 0) {
            p_param->callback(0x100, arg);
            return;
        }
        p_param->callback(0x15, arg);
        MBi_CheckWmErrcode(0x1D, WM_SetLifeTime(MBi_ChildCallback, mbi_life_table_no,
                                                mbi_life_cam, mbi_life_frame,
                                                mbi_life_mp));
        return;
    case 0x1D:
        if (buf->errcode != 0) {
            p_param->callback(0x100, arg);
            return;
        }
        if (mbiScanParam.channelList == 0)
            mbiScanParam.channelList = 1;
        if (mbiScanParam.maxChannelTime == 0)
            mbiScanParam.maxChannelTime = 200;
        mbiScanParam.bssid[0] = 0xFF;
        mbiScanParam.bssid[1] = 0xFF;
        mbiScanParam.bssid[2] = 0xFF;
        mbiScanParam.bssid[3] = 0xFF;
        mbiScanParam.bssid[4] = 0xFF;
        mbiScanParam.bssid[5] = 0xFF;
        mbiScanParam.scanType = 1;
        mbiScanParam.ssidLength = 0;
        p_param->scanning_flag = 1;
        p_param->scan_channel_flag = 1;
        MBi_CheckWmErrcode(0x26, WM_StartScanEx(MBi_ChildCallback, &mbiScanParam));
        return;
    case 0x26: {
        WMStartScanExCallback *callback = (WMStartScanExCallback *)arg;

        if (callback->errcode != 0) {
            p_param->callback(0x100, arg);
            return;
        }
        switch (callback->state) {
        case 3:
            return;
        case 5: {
            u8 j;
            u8 numInvalidBeacon;
            WMBssDesc *buffer;
            ParentInfo *p;
            int i;

            numInvalidBeacon = 0;
            for (j = 0; j < callback->bssDescCount; j++) {
                buffer = callback->bssDesc[j];
                p = p_param->parent_info;
                if (!WM_IsValidGameBeacon(buffer) || !MBi_CheckMBParent(buffer)) {
                    numInvalidBeacon++;
                    continue;
                }
                if (mbWm.isEnableReject == 1
                    && (buffer->gameInfo.ggid & mbi_reject_ggid_mask)
                       == (mbi_reject_ggid & mbi_reject_ggid_mask)) {
                    numInvalidBeacon++;
                    continue;
                }
                for (i = 0; i < p_param->found_parent_count; i++) {
                    if (WM_IsBssidEqual(buffer->bssid, p[i].scan_data.macAddress)) {
                        p[i].scan_data.gameInfoLength = buffer->gameInfoLength;
                        p[i].scan_data.gameInfo = buffer->gameInfo;
                        DC_InvalidateRange(p_param->parent_info[i].parentInfo, 0xC0);
                        MI_DmaCopy16(mbWm.WM_DMA_NO, buffer, p_param->parent_info[i].parentInfo, 0xC0);
                        p_param->last_found_parent_no = i;
                        p_param->callback(4, &callback->linkLevel[j]);
                        goto scan_retry;
                    }
                }
                if (i < 16) {
                    p_param->found_parent_count = (u16)(i + 1);
                    MI_CpuCopy8(buffer->bssid, p[i].scan_data.macAddress, 6);
                    p[i].scan_data.channel = buffer->channel;
                    p[i].scan_data.linkLevel = callback->linkLevel[j];
                    MI_CpuCopy16(&buffer->gameInfo, &p[i].scan_data.gameInfo, sizeof(WMGameInfo));
                    DC_InvalidateRange(p_param->parent_info[i].parentInfo, 0xC0);
                    MI_DmaCopy16(mbWm.WM_DMA_NO, buffer, p_param->parent_info[i].parentInfo, 0xC0);
                    p_param->last_found_parent_no = i;
                    p_param->callback(4, &callback->linkLevel[j]);
                    goto scan_retry;
                }
            }
            if (callback->bssDescCount == numInvalidBeacon)
                p_param->callback(5, arg);
        scan_retry:
            if (!p_param->scanning_flag)
                return;
            if (p_param->scan_channel_flag) {
                if (!changeScanChannel(&mbiScanParam))
                    MBi_CommEnd();
            }
            MBi_CheckWmErrcode(0x26, WM_StartScanEx(MBi_ChildCallback, &mbiScanParam));
            return;
        }
        case 4:
            p_param->callback(5, arg);
            if (!p_param->scanning_flag)
                return;
            if (p_param->scan_channel_flag) {
                if (!changeScanChannel(&mbiScanParam))
                    MBi_CommEnd();
            }
            MBi_CheckWmErrcode(0x26, WM_StartScanEx(MBi_ChildCallback, &mbiScanParam));
            return;
        default:
            p_param->callback(0x100, arg);
            return;
        }
    }
    case 0x0B:
        if (buf->errcode != 0) {
            p_param->callback(0x100, arg);
            return;
        }
        MBi_CheckWmErrcode(0x0C, WM_StartConnect(MBi_ChildCallback, p_param->pInfo, 0));
        return;
    case 0x0C: {
        WMStartConnectCallback *callback = (WMStartConnectCallback *)arg;

        if (callback->errcode != 0) {
            p_param->found_parent_count = 0;
            p_param->callback(0x0B, arg);
            return;
        }
        switch (callback->state) {
        case 6:
            p_param->child_bitmap = 0;
            p_param->mpStarted = 1;
            return;
        case 7:
            p_param->my_aid = callback->aid;
            p_param->callback(6, arg);
            p_param->child_bitmap = 1;
            if (WM_SetPortCallback(1, MBi_ChildPortCallback, 0) != 0)
                return;
            MBi_CheckWmErrcode(0x0E, WM_StartMPEx(MBi_ChildCallback, p_param->recvBuf, p_param->recvBufSize,
                                                  p_param->sendBuf, p_param->sendBufSize,
                                                  (u16)(p_param->contSend ? 0 : 1), 0, 0, 0, 1, 1));
            return;
        case 9:
            p_param->callback(0x0A, arg);
            p_param->child_bitmap = 0;
            p_param->mpStarted = 0;
            return;
        case 0x1A:
            return;
        default:
            p_param->callback(0x100, arg);
            return;
        }
    }
    case 0x0E: {
        WMStartMPCallback *callback = (WMStartMPCallback *)arg;

        switch (callback->state) {
        case 0x0A:
            p_param->mpStarted = 1;
            if (MBi_IsSendEnabled())
                p_param->callback(0x19, 0);
            return;
        case 0x0C:
        case 0x0D:
            return;
        default:
            p_param->callback(0x100, arg);
            return;
        }
    }
    case 0x0F:
        p_param->mpBusy = 0;
        if (buf->errcode == 0)
            p_param->callback(8, arg);
        else if (buf->errcode == 9)
            p_param->callback(0x29, arg);
        else
            p_param->callback(0x12, arg);
        if (mbWm.work->endReq == 0)
            p_param->callback(0x19, 0);
        return;
    case 0x01:
        if (buf->errcode != 0) {
            p_param->endReq = 0;
            p_param->callback(0x100, arg);
            return;
        }
        mbWm.work->child_bitmap = 0;
        mbWm.work->mpStarted = 0;
        MBi_CheckWmErrcode(0x02, WM_End(MBi_ChildCallback));
        return;
    case 0x02:
        if (buf->errcode != 0) {
            p_param->endReq = 0;
            p_param->callback(0x100, arg);
            return;
        }
        MBi_EndCommon(arg);
        return;
    case 0x15:
        if (MBi_IsSendEnabled())
            p_param->callback(0x19, 0);
        return;
    case 0x80: {
        WMIndCallback *cb = (WMIndCallback *)arg;

        if (cb->state == 0x16)
            OS_Terminate();
        return;
    }
    default:
        p_param->callback(0x100, arg);
        return;
    }
}


static u32 MBi_GetBeaconPeriodDispersion(void)
{
    u8 mac[6];
    long i;
    u32 ret;

    OS_GetMacAddress(mac);
    for (i = 0, ret = 0; i < 6; i++)
        ret += mac[i];
    ret = (ret + *(volatile u32 *)0x02FFFC3C) * 7 % 20;
    return ret;
}

#define WM   (*(u8 **)(d_021F6F90 + 0xC))
#define PBUF (*(u8 **)(d_021F6F90 + 0x10))
typedef struct MBiFileSlot {
    u8 pad0[0x1788];
    MBiParentFileInfo fi;
} MBiFileSlot;

extern u32 WM_GetNextTgid(void);
extern u32 OS_DisableInterrupts(void);
extern void MIi_CpuClear32(u32, void *, u32);
extern void MIi_CpuClear16(u32, void *, u32);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u32 MBi_GetBeaconPeriodDispersion(void);
extern u32 OS_RestoreInterrupts(u32);
extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long state);
extern int func_021F5ADC(unsigned short sendSize, unsigned short recvSize, unsigned short entry_num);
extern void func_021F6148(unsigned short time);
extern int func_0208F370(void *wmSysBuf, void *callback, unsigned short dmaNo);
extern int func_0208EAC8(void *callback);
extern void func_021F4628(void);
extern void func_02082A48(u16 data, void *destp, u32 size);
extern void func_021F1B3C(void (*callback)(u16, u32, void *));
extern void func_021F6804(u16 childMaxSize);
extern void func_021F6830(void *buf);
extern void func_02082BCC(void *dstp, u8 data, u32 size);
extern void func_021F3F78(void);
extern int func_020885EC(int fifotag, int proc);
extern void func_021F1D80(u16 type, void *arg);
extern void func_021F46C8(void *arg);
extern int WM_Reset(u32 param);
extern void func_021F6334(u16 apiid, int errcode);
extern void MBi_EndCommon(void *arg);
extern int MBi_IsTaskAvailable(void);
extern void MBi_EndTaskThread(void (*callback)(struct MBiTaskInfo *));
extern void MBi_OnReset(void);
extern void OS_Terminate(void);
extern int func_0208F938(void (*callback)(void *), u16 aid);
extern void func_021F6850(u16 child_aid);
extern int WM_SetMPDataToPortEx(void (*callback)(void *), void *arg, u16 *sendData, u16 sendDataSize, u16 destBitmap, u16 port, u16 prio);
extern int func_021F6158(void *callback, unsigned short *sendData, unsigned short sendDataSize, unsigned short arg3, unsigned short pollbmp);
extern void func_021F4EFC(void *arg);
int MB_Init(void *work, const MBUserInfo *user, u32 ggid, u32 tgid, u32 dma);
int func_021F5B4C(unsigned short sendSize, unsigned short maxChildren);
int func_021F5BE0(void);
int func_021F5CAC(int channel);
int MB_StartParentFromIdle(int channel);
int MBi_CallReset(void);
int func_021F5ED8(void);
int MBi_CommEnd(void);
void MB_EndToIdle(void);
void func_021F5FB0(u16 aid);
void MBi_SetMaxScanTime(u16 time);
int func_021F61A4(unsigned short *buf, int len, int pollbmp);
u32 MBi_GetGgid(void);
u16 MBi_GetTgid(void);
unsigned char MBi_GetAttribute(void);
int MBi_IsStarted(void);
void MBi_CheckWmErrcode(u16 apiid, int errcode);


int MB_Init(void *work, const MBUserInfo *user, u32 ggid, u32 tgid, u32 dma);
int func_021F5B4C(unsigned short sendSize, unsigned short maxChildren);
int func_021F5BE0(void);
int func_021F5CAC(int channel);
int MB_StartParentFromIdle(int channel);
int MBi_CallReset(void);
int func_021F5ED8(void);
int MBi_CommEnd(void);
void MB_EndToIdle(void);
void func_021F5FB0(u16 aid);
void MBi_SetMaxScanTime(u16 time);
int func_021F61A4(unsigned short *buf, int len, int pollbmp);
u32 MBi_GetGgid(void);
u16 MBi_GetTgid(void);
unsigned char MBi_GetAttribute(void);
int MBi_IsStarted(void);
void MBi_CheckWmErrcode(u16 apiid, int errcode);


int MB_Init(void *work, const MBUserInfo *user, u32 ggid, u32 tgid, u32 dma)
{
    struct MBiParam *p_parm;
    struct MB_CommCommonWork *p_com;
    struct WMParentParam *p_parent;
    u32 enabled;
    u16 *c;
    int i;

    if (mbWm.ext != 0 && mbWm.ext->isMbInitialized != 0)
        return 2;
    p_parm = (struct MBiParam *)(((u32)work + 0x1f) & ~0x1fu);
    p_com = (struct MB_CommCommonWork *)(((u32)p_parm + 0x1e00 + 0x1f) & ~0x1fu);
    if (tgid == 0x10000)
        tgid = WM_GetNextTgid();
    enabled = OS_DisableInterrupts();
    mbi_life_table_no = 0xffff;
    mbi_life_frame = 5;
    mbi_life_cam = 0x28;
    mbi_life_mp = 0x28;
    mbi_power_save_mode = 1;
    mbWm.WM_DMA_NO = dma;
    mbWm.work = p_parm;
    mbWm.ext = p_com;
    MIi_CpuClear32(0, p_parm, 0x1e00);
    MIi_CpuClear16(0, p_com, 0x1340);
    c = p_parm->uname;
    for (i = 0; i < user->nameLength; i++) {
        *c++ = user->name[i];
    }
    c = p_parm->gname;
    for (i = 0; i < 16; i++) {
        if (mbi_game_char(0) == 0)
            break;
        *c++ = mbi_game_char(1);
    }
    MI_CpuCopy8(user, &p_com->user, 0x16);
    if (user->nameLength < 10)
        p_com->user.name[user->nameLength] = 0;
    p_parm->p_sendlen = 0x100;
    p_parm->p_recvlen = 8;
    p_parm->sendBufSize = 0;
    p_parm->recvBufSize = 0;
    p_parm->contSend = 1;
    p_parm->recvBuf = p_com->recvbuf;
    p_parent = &p_parm->parentParam;
    p_parent->entryFlag = 0;
    p_parent->multiBootFlag = 0;
    p_parent->CS_Flag = 1;
    p_parent->KS_Flag = 0;
    p_parent->ggid = ggid;
    p_parent->tgid = tgid;
    p_parent->beaconPeriod = MBi_GetBeaconPeriodDispersion() + 200;
    p_parent->maxEntry = 15;
    p_parm->mpBusy = 0;
    p_parm->mbIsStarted = 0;
    p_com->isMbInitialized = 1;
    p_com->start_mp_busy = 0;
    OS_RestoreInterrupts(enabled);
    return 0;
}












static int MBi_IsCommSizeValid(u16 sendSize, u16 recvSize, u16 entry_num)
{
    if (sendSize > 0x1FE || sendSize < 0xE4)
        return 0;
    if (recvSize > 0x10 || recvSize < 8)
        return 0;
    if ((sendSize + 0x26) * 4 + 0x4A + 0x100 +
            entry_num * ((recvSize + 0x20) * 4 + 0x70) < 0x15E0)
        return 1;
    return 0;
}






/*
 * sdk:      MB_SetParentCommParam (libmb.TWL.HYB.a(mb_wm_base.o))
 */
int func_021F5B4C(unsigned short sendSize, unsigned short maxChildren)
{
    unsigned long enabled = func_02087988();

    if ((*(unsigned char **)(d_021F6F90 + 0xC))[0x50D] != 0) {
        func_0208799C(enabled);
        return 0;
    }
    if (func_021F5ADC(sendSize, 8, maxChildren) == 0) {
        func_0208799C(enabled);
        return 0;
    }
    *(unsigned short *)(*(unsigned char **)(d_021F6F90 + 0xC) + 0x10) = maxChildren;
    *(unsigned short *)(*(unsigned char **)(d_021F6F90 + 0xC) + 0x500) = sendSize;
    *(unsigned short *)(*(unsigned char **)(d_021F6F90 + 0xC) + 0x502) = 8;
    func_0208799C(enabled);
    return 1;
}






/*
 * sdk:      MBi_StartCommon (libmb.TWL.HYB.a(mb_wm_base.o))
 */
int func_021F5BE0(void)
{
    int errcode = 0;

    *(unsigned short *)((u8 *)mbWm.work + 0x528) = errcode;
    *(unsigned short *)((u8 *)mbWm.work + 0x52A) = errcode;
    *(unsigned short *)((u8 *)mbWm.work + 0x526) = errcode;
    *(unsigned short *)((u8 *)mbWm.work + 0x548) = errcode;
    func_021F6148(0x1E);
    if (*(int *)(((unsigned char *)mbWm.ext) + 0x1320) == 0) {
        do {
            errcode = func_0208F370(mbWm.wmSysBuf, *(void **)((u8 *)mbWm.work + 0x508), mbWm.WM_DMA_NO);
        } while (errcode == 4);
        if (errcode != 2) {
            return 8;
        }
        func_0208EAC8(*(void **)((u8 *)mbWm.work + 0x508));
        ((u8 *)mbWm.work)[0x50D] = 1;
        return 0;
    }
    func_0208EAC8(*(void **)((u8 *)mbWm.work + 0x508));
    ((u8 *)mbWm.work)[0x50D] = 1;
    func_021F4628();
    return errcode;
}






/*
 * sdk:      MBi_StartParentCore (libmb.TWL.HYB.a(mb_wm_base.o))
 */
int func_021F5CAC(int channel)
{
    int i;
    int ret;
    void (*cb_tmp)(u16, u32, void *);
    u32 enabled;

    enabled = func_02087988();
    *(u16 *)(WM + 0x32) = channel;
    *(u32 *)(d_021F6F90 + 4) = ((u32)PBUF + 0x1f + 0x7d00) & ~0x1f;
    cb_tmp = *(void (**)(u16, u32, void *))(PBUF + 0x1000 + 0x4e4);
    func_02082A48(0, PBUF + 0x1340, 0x69c0);
    func_021F1B3C(cb_tmp);
    *(int *)(PBUF + 0x1000 + 0x318) = *(u16 *)(WM + 0x500) - 6;
    func_021F6804(*(u16 *)(WM + 0x502));
    func_021F6830(PBUF + 0x138 + 0x1400);
    ret = 0;
    for (i = 0; i < 15; i++) {
        *(int *)(PBUF + i * 4 + 0x1000 + 0x4e8) = ret;
        *(signed char *)(PBUF + i + 0x1000 + 0x526) = -1;
    }
    *(u8 *)(PBUF + 0x1000 + 0x524) = ret;
    func_02082A48(ret, PBUF + 0x388 + 0x1400, 0x5d40);
    func_02082BCC(PBUF + 0x354 + 0x1400, ret, 0x1e);
    ret = 1;
    *(u16 *)(WM + 0x500 + 0x24) = ret;
    *(void **)(WM + 0x51c) = (void *)func_021F1D80;
    *(void **)(WM + 0x508) = (void *)func_021F46C8;
    *(u16 *)(WM + 0x34) = *(u16 *)(WM + 0x500);
    *(u16 *)(WM + 0x500 + 0x18) = (*(u16 *)(WM + 0x34) + 0x23) & ~0x1f;
    *(u16 *)(WM + 0x36) = *(u16 *)(WM + 0x502);
    *(u16 *)(WM + 0x500 + 0x1a) = (((*(u16 *)(WM + 0x36) + 0xe) * 15 + 0x29) & ~0x1f) << 1;
    func_021F3F78();
    i = func_021F5BE0();
    func_0208799C(enabled);
    *(int *)(PBUF + 0x7000 + 0x4c8) = func_020885EC(0xf, ret);
    return i;
}




int MB_StartParentFromIdle(int channel)
{
    *(u32 *)(*(char **)(d_021F6F90 + 0x10) + 0x1320) = 1;
    return func_021F5CAC(channel);
}



int MBi_CallReset(void)
{
    int errcode = WM_Reset(*(u32 *)(*(char **)(d_021F6F90 + 0xC) + 0x508));

    func_021F6334(1, errcode);
    return errcode == 2 ? 0 : errcode;
}


int func_021F5ED8(void)
{
    return MBi_CallReset();
}



/*
 * The object adds fid * 0x5d4 to mbc before the member offset (0x1788 +
 * field); `mbc->fileinfo[fid].field` folds the constant first and indexes
 * last (48 bytes differ).  Stepping mbc by whole file slots reproduces it.
 */
#define FILEINFO(id)     (((MBiFileSlot *)((u8 *)((MBCommPWork *)mbWm.ext) + (id) * sizeof(MBiParentFileInfo)))->fi)







int MBi_CommEnd(void)
{
    int ret = 1;
    u32 enabled;

    enabled = OS_DisableInterrupts();
    if (*(u8 *)(*(char **)(d_021F6F90 + 0xC) + 0x50D) == 0) {
        MBi_EndCommon(0);
    } else if (*(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x526) == 0) {
        *(u32 *)(*(char **)(d_021F6F90 + 0xC) + 0x5E4) = 0;
        *(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0x526) = 1;
        if (MBi_IsTaskAvailable()) {
            MBi_EndTaskThread((void (*)(struct MBiTaskInfo *))MBi_OnReset);
            ret = 0;
        } else {
            ret = MBi_CallReset();
        }
    }
    OS_RestoreInterrupts(enabled);
    return ret;
}








void MB_EndToIdle(void)
{
    u32 enabled = OS_DisableInterrupts();

    if (*(u32 *)(*(char **)(d_021F6F90 + 0x10) + 0x1320) == 0)
        OS_Terminate();
    MBi_CommEnd();
    OS_RestoreInterrupts(enabled);
}








void func_021F5FB0(u16 aid)
{

    func_0208F938(func_021F46C8, aid);
    if (aid == 0 || aid >= 16)
        return;
    ((MBCommPWork *)mbWm.ext)->childversion[aid - 1] = 0;
    func_02082BCC(&((MBCommPWork *)mbWm.ext)->childggid[aid - 1], 0, sizeof(u32));
    func_02082BCC(&((MBCommPWork *)mbWm.ext)->childUser[aid - 1], 0, 0x16);
    func_021F6850(aid);
    ((MBCommPWork *)mbWm.ext)->req2child[aid - 1] = 0;
    if (((MBCommPWork *)mbWm.ext)->fileid_of_child[aid - 1] != -1) {
        u8 fid = (u8)((MBCommPWork *)mbWm.ext)->fileid_of_child[aid - 1];
        u16 child = aid;

        FILEINFO(fid).gameinfo_child_bmp &= (u16)~(1 << child);
        FILEINFO(fid).gameinfo_changed_bmp |= (u16)(1 << child);
        ((MBCommPWork *)mbWm.ext)->fileid_of_child[child - 1] = -1;
        FILEINFO(fid).pollbmp &= (u16)~(1 << child);
    }
    if (((MBCommPWork *)mbWm.ext)->child_entry_bmp & (1 << aid)) {
        ((MBCommPWork *)mbWm.ext)->child_num--;
        ((MBCommPWork *)mbWm.ext)->child_entry_bmp &= (u16)~(1 << aid);
    }
    ((MBCommPWork *)mbWm.ext)->p_comm_state[aid - 1] = 0;
}








void MBi_SetMaxScanTime(u16 time)
{
    mbiScanParam.maxChannelTime = time;
}







static int MBi_SetMPData(void (*callback)(void *), u16 *sendData, u16 sendDataSize, u16 unused, u16 pollbmp)
{
    int errcode;

    errcode = WM_SetMPDataToPortEx(callback, 0, sendData, sendDataSize, pollbmp, 1, 3);
    MBi_CheckWmErrcode(0xF, errcode);
    return errcode;
}







/*
 * sdk:      MBi_SendMP (libmb.TWL.HYB.a(mb_wm_base.o))
 */
int func_021F61A4(unsigned short *buf, int len, int pollbmp)
{
    unsigned short size = len;
    unsigned short pollbitmap = pollbmp;
    int errcode;

    if (*(unsigned short *)((u8 *)mbWm.work + 0x528) == 0 || *(unsigned short *)((u8 *)mbWm.work + 0x526) == 1) {
        return 1;
    }
    switch (*(unsigned short *)((u8 *)mbWm.work + 0x524)) {
    case 1:
        errcode = func_021F6158(*(void **)((u8 *)mbWm.work + 0x508), buf, size, *(unsigned short *)((u8 *)mbWm.work + 0x52C) == 0 ? 0x3E8 : 0, pollbitmap);
        if (errcode == 2) {
            ((u8 *)mbWm.work)[0x50C] = 1;
        }
        return errcode == 2 ? 0 : errcode;
    case 2:
        errcode = func_021F6158(func_021F4EFC, buf, size, 0, pollbitmap);
        if (errcode == 2) {
            ((u8 *)mbWm.work)[0x50C] = 1;
        }
        return errcode == 2 ? 0 : errcode;
    }
    return 1;
}







u32 MBi_GetGgid(void)
{
    return *(u32 *)(*(char **)(d_021F6F90 + 0xC) + 8);
}






u16 MBi_GetTgid(void)
{
    return *(u16 *)(*(char **)(d_021F6F90 + 0xC) + 0xC);
}






unsigned char MBi_GetAttribute(void)
{
    char *base = *(char **)(d_021F6F90 + 0xC);

    return (*(u16 *)(base + 0xE) ? 1 : 0) | (*(u16 *)(base + 0x12) ? 2 : 0) |
           (*(u16 *)(base + 0x14) ? 4 : 0) | (*(u16 *)(base + 0x16) ? 8 : 0);
}




int MBi_IsStarted(void)
{
    return *(u8 *)(*(char **)(d_021F6F90 + 0xC) + 0x50D) == 1;
}



void MBi_CheckWmErrcode(u16 apiid, int errcode)
{
    struct
    {
        u16 apiid;
        u16 errcode;
    } arg;
    void (*callback)(int, void *);

    if (errcode == 2 || errcode == 0)
        return;

    arg.apiid = apiid;
    arg.errcode = (u16)errcode;
    callback = *(void (**)(int, void *))(*(char **)(d_021F6F90 + 0xC) + 0x51C);
    callback(0xFF, &arg);
}

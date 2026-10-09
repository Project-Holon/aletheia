/*
 * file:     unit_021F4560_p02.c
 * unit:     yes
 * function: MBi_ChildCallback, MBi_GetBeaconPeriodDispersion
 * address:  0x021F4EFC
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
 *   d_021F6F90 0x021F6F90 data
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
 *   MBi_ChildPortCallback      0x021F4E9C  arm
 *   WM_DMA_NO                  0x021F6F90  data
 *   mbiScanParam               0x021F6FC0  data
 *   mbi_life_mp                0x021F6E58  data
 *   OS_GetMacAddress                 0x02087c6c arm
 */
#define MB_WM_OWN_STATICS
#include "mb_wm.h"

/*
 * Initialised data at 0x021F6E58 (image layout: mp, cam, table_no, frame,
 * power, game, ggid, mask).  The `game` slot belongs to MB_Init (p04); it is
 * defined here only so that the reject words land at +0x10 and +0x14.
 */
static const u16 *mbi_game = L"";
static u16 mbi_life_cam = 0x28;
static u16 mbi_life_frame = 5;
static u16 mbi_life_table_no = 0xffff;
static u16 mbi_life_mp = 0x28;
static int mbi_power_save_mode = 1;
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

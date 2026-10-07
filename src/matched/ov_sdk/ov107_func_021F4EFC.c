/*
 * function: MBi_ChildCallback
 * address:  0x021F4EFC
 * packet:   pkt_ov107_021F4EFC
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk: MBi_ChildCallback (libmb.TWL.HYB.a mb_wm_base.o), stamp 4.0.0.1024.
 *
 * 2026-10-01 (wave 2 lane 04): full rewrite from the vendor listing and DWARF
 *   (the old draft was 2636 B with an uninitialised base pointer). Statics are
 *   modelled as the two anchors the object addresses them through: WM_DMA_NO
 *   (.bss: +0 WM_DMA_NO, +8 isEnableReject, +0xC p_mbi_param) and mbi_life_mp
 *   (.data: mp/cam/table_no/frame, +0x10 rejectGgid, +0x14 rejectGgidMask).
 *   Measured shape facts: WM_StartConnect is the inline wrapper (TRUE, open
 *   system bound inside); the beacon check is WM_IsValidGameInfo(&gi, u16 len)
 *   nested in WM_IsValidGameBeacon (the int-len variant gives blt); the parent
 *   scan indexes p[i] off `p = p_param->parent_info`, while the DC/DMA
 *   arguments use p_param->parent_info[i]; found paths `goto scan_retry`.
 *   Plain C: 2460 B (image 2464), every case outside the PARENT_FOUND scan loop
 *   is instruction-identical; the loop region differs in register colouring.
 *   The image's loop region has the asm-mode codegen seen across libmb
 *   (MBi_SendVolatBeacon, MBi_ParentCallback's volatile): loops entered by a
 *   branch to the bottom test, no global CSE of p[i] (mla per block, 0x180
 *   rematerialised), found_parent_count re-read in the loop test, constant 1
 *   held in r7 for the materialised && levels. Measured: this exact body plus a
 *   zero-byte `asm { .align 4 }` at the head of `default:` compiles to 2468 B
 *   with 11 bytes differing (only the barrier's pool reload in default). Not
 *   filed (brief rule 10). Plain-C levers tried for the loop: ternary loop
 *   conditions (2384 B), per-byte (u32)/(unsigned)/byte-offset spellings of
 *   p[i] (all canonicalised and CSE'd again), a volatile 4th gameInfoLength
 *   read, dead-code bulk and other -O levels (no mode change).
 *
 * 2026-10-01 (wave 3 lane 01): EXACT. The vendor object defines mbiScanParam
 *   in an align-32 .bss section (ATTRIBUTE_ALIGN(32)); declaring the extern
 *   with __attribute__((aligned(32))) gives the image's asm-mode codegen for
 *   the whole function (brief lever 15). No other change.
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
 *   MBi_ChildPortCallback      0x021F4E9C  arm
 *   MBi_ChildCallback          0x021F4EFC  arm
 *   WM_DMA_NO                  0x021F6F90  data
 *   mbiScanParam               0x021F6FC0  data
 *   mbi_life_mp                0x021F6E58  data
 */

#include "../include/G_MBiData.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

typedef struct WMCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
} WMCallback;

typedef struct WMIndCallback {
    u16 apiid;
    u16 errcode;
    u16 state;
    u16 reason;
} WMIndCallback;

typedef struct WMGameInfo {
    u16 magicNumber;
    u8 ver;
    u8 platform;
    u32 ggid;
    u16 tgid;
    u8 userGameInfoLength;
    u8 gameNameCount_attribute;
    u16 parentMaxSize;
    u16 childMaxSize;
    u16 userGameInfo[56];
} WMGameInfo;

typedef struct WMBssDesc {
    u16 length;
    u16 rssi;
    u8 bssid[6];
    u16 ssidLength;
    u8 ssid[32];
    u16 capaInfo;
    struct {
        u16 basic;
        u16 support;
    } rateSet;
    u16 beaconPeriod;
    u16 dtimPeriod;
    u16 channel;
    u16 cfpPeriod;
    u16 cfpMaxDuration;
    u16 gameInfoLength;
    u16 otherElementCount;
    WMGameInfo gameInfo;
} WMBssDesc;

typedef struct WMStartScanCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u8 macAddress[6];
    u16 channel;
    u16 linkLevel;
    u16 ssidLength;
    u16 ssid[16];
    u16 gameInfoLength;
    WMGameInfo gameInfo;
} WMStartScanCallback;

typedef struct WMStartScanExCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 channelList;
    u8 reserved[2];
    u16 bssDescCount;
    WMBssDesc *bssDesc[16];
    u16 linkLevel[16];
} WMStartScanExCallback;

typedef struct WMStartConnectCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 aid;
    u16 reason;
    u16 wlStatus;
    u8 macAddress[6];
    u16 parentSize;
    u16 childSize;
} WMStartConnectCallback;

typedef struct WMStartMPCallback {
    u16 apiid;
    u16 errcode;
    u16 state;
    u8 reserved[2];
    void *recvBuf;
    u16 timeStamp;
    u16 rate_rssi;
    u8 destAdrs[6];
    u8 srcAdrs[6];
    u16 seqNum;
    u16 tmptt;
    u16 pollbmp;
    u16 reserved2;
} WMStartMPCallback;

typedef struct WMScanExParam {
    WMBssDesc *scanBuf;
    u16 scanBufSize;
    u16 channelList;
    u16 maxChannelTime;
    u8 bssid[6];
    u16 scanType;
    u16 ssidLength;
    u8 ssid[32];
    u16 ssidMatchLength;
    u16 rsv2[7];
} WMScanExParam;

typedef struct ParentInfo {
    union {
        WMBssDesc parentInfo[1];
        u8 parentInfo_area[192];
    };
    WMStartScanCallback scan_data;
    u8 reserved1[8];
} ParentInfo;

typedef struct MBiParam {
    u8 parentParam_area[64];
    u16 sendBuf[512];
    u8 parentInfoBuf_area[192];
    u16 p_sendlen;
    u16 p_recvlen;
    void *recvBuf;
    void (*callback_ptr)(void *);
    u8 mpBusy;
    u8 mbIsStarted;
    u8 reserved0[10];
    u16 sendBufSize;
    u16 recvBufSize;
    void (*callback)(u16, void *);
    WMBssDesc *pInfo;
    u16 mode;
    u16 endReq;
    u16 mpStarted;
    u16 child_bitmap;
    u16 contSend;
    u8 reserved1[2];
    u8 uname[8];
    u8 gname[16];
    u16 currentTgid;
    u8 reserved2[22];
    u16 userGameInfo[64];
    u16 found_parent_count;
    u16 my_aid;
    BOOL scanning_flag;
    BOOL scan_channel_flag;
    int last_found_parent_no;
    u8 reserved8[16];
    ParentInfo parent_info[16];
} MBiParam;

/* .bss anchor at WM_DMA_NO (0x021F6F90) */
struct MBiBss {
    u16 WM_DMA_NO;
    u16 pad;
    u32 unk4;
    BOOL isEnableReject;
    MBiParam *p_mbi_param;
};

/* .data anchor at mbi_life_mp (0x021F6E58) */

extern struct MBiBss WM_DMA_NO;
extern struct MBiData mbi_life_mp;
extern WMScanExParam mbiScanParam __attribute__((aligned(32)));

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
    MBiParam *const p_param = WM_DMA_NO.p_mbi_param;

    switch (buf->apiid) {
    case 0x00:
        if (buf->errcode != 0) {
            p_param->callback(0x100, arg);
            return;
        }
        p_param->callback(0x15, arg);
        MBi_CheckWmErrcode(0x1D, WM_SetLifeTime(MBi_ChildCallback, mbi_life_mp.mbi_life_table_no,
                                                mbi_life_mp.cam, mbi_life_mp.frame,
                                                mbi_life_mp.mbi_life_mp));
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
                if (WM_DMA_NO.isEnableReject == 1
                    && (buffer->gameInfo.ggid & mbi_life_mp.rejectGgidMask)
                       == (mbi_life_mp.rejectGgid & mbi_life_mp.rejectGgidMask)) {
                    numInvalidBeacon++;
                    continue;
                }
                for (i = 0; i < p_param->found_parent_count; i++) {
                    if (WM_IsBssidEqual(buffer->bssid, p[i].scan_data.macAddress)) {
                        p[i].scan_data.gameInfoLength = buffer->gameInfoLength;
                        p[i].scan_data.gameInfo = buffer->gameInfo;
                        DC_InvalidateRange(p_param->parent_info[i].parentInfo, 0xC0);
                        MI_DmaCopy16(WM_DMA_NO.WM_DMA_NO, buffer, p_param->parent_info[i].parentInfo, 0xC0);
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
                    MI_DmaCopy16(WM_DMA_NO.WM_DMA_NO, buffer, p_param->parent_info[i].parentInfo, 0xC0);
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
        if (WM_DMA_NO.p_mbi_param->endReq == 0)
            p_param->callback(0x19, 0);
        return;
    case 0x01:
        if (buf->errcode != 0) {
            p_param->endReq = 0;
            p_param->callback(0x100, arg);
            return;
        }
        WM_DMA_NO.p_mbi_param->child_bitmap = 0;
        WM_DMA_NO.p_mbi_param->mpStarted = 0;
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

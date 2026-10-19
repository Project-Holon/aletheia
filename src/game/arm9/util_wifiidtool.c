/*
 * file:     util_wifiidtool.c
 * unit:     yes
 * function: DWCi_Util_WiFiId_scrambleUid, DWCi_AUTH_GetNewWiFiInfo, DWCi_AUTH_MakeWiFiID, DWCi_AUTH_UpDateWiFiID, DWCi_AUTH_RemakeWiFiID, DWC_Auth_GetId, DWC_Auth_CheckWiFiIDNeedCreate
 * address:  0x02058A3C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuCopy8               0x02082D44 arm
 *   DWCi_util_wifiid_ttable   0x020A1608 data a1
 *   DWCi_util_wifiid_exctable 0x020A15F0 data a1
 *   DWCi_BM_GetWiFiInfo              0x02058518 arm
 *   RTC_Init                         0x02088788 arm
 *   RTC_GetDate                      0x02088864 arm
 *   RTC_GetTime                      0x0208890c arm
 *   RTC_ConvertDateTimeToSecond      0x02089004 arm
 *   OS_IsTickAvailable               0x02087058 arm
 *   OS_GetMacAddress                 0x02087c6c arm
 *   DWCi_Util_WiFiId_scrambleUid     0x02058a3c arm
 *   OS_GetTick                       0x020870d0 data
 *   DWCi_AUTH_GetNewWiFiInfo 0x02058BC0 arm
 *   DWCi_BM_SetWiFiInfo      0x020586BC arm
 */
#include "../types.h"

typedef union tagUNI64 {
    u64 data;
    u32 half[2];
    u8  i[8];
} UNI64;

#include "../sdk_rtc.h"

#include "../sdk_dwc.h"

extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern void DWCi_BM_GetWiFiInfo(DWCWiFiInfo *buf);
extern void RTC_Init(void);
extern int  RTC_GetDate(RTCDate *date);
extern int  RTC_GetTime(RTCTime *time);
extern s64  RTC_ConvertDateTimeToSecond(const RTCDate *date, const RTCTime *time);
extern int  OS_IsTickAvailable(void);
extern u64  OS_GetTick(void);
extern void OS_GetMacAddress(u8 *macAddress);
extern u64  DWCi_Util_WiFiId_scrambleUid(u16 rand, u32 mac, u8 vend, u8 mainunit);
extern int DWCi_AUTH_GetNewWiFiInfo(DWCWiFiInfo *wifiinfo);
extern int DWCi_BM_SetWiFiInfo(DWCWiFiInfo *info, void *work);
int DWCi_AUTH_MakeWiFiID(void *work);
int DWCi_AUTH_UpDateWiFiID(DWCWiFiInfo *wifiinfo, void *work);
int DWCi_AUTH_RemakeWiFiID(DWCWiFiInfo *wifiinfo);
void DWC_Auth_GetId(DWCAuthWiFiId *id);
int DWC_Auth_CheckWiFiIDNeedCreate(void);
extern const u8 DWCi_util_wifiid_ttable[16];
extern const u8 DWCi_util_wifiid_exctable[8];

/*
 * sdk:      DWCi_Util_WiFiId_scrambleUid (libdwcbm.TWL.HYB.a util_wifiidtool.o)
 */
u64 DWCi_Util_WiFiId_scrambleUid(u16 rand, u32 mac, u8 vend, u8 mainunit)
{
    UNI64 uni64;
    u8 uidtemp[8];
    int i;

    uni64.data = ((u64)mainunit & 0x3) | (((u64)vend & 0x1) << 2)
               | (((u64)mac & 0xFFFFFF) << 3) | (((u64)rand & 0xFFFF) << 27);
    for (i = 0; i < 6; i++)
        uni64.i[i] ^= 0xD6;
    for (i = 0; i < 5; i++)
        uni64.i[i] = (u8)((DWCi_util_wifiid_ttable[(uni64.i[i] >> 4) & 0xF] << 4) | DWCi_util_wifiid_ttable[uni64.i[i] & 0xF]);
    MI_CpuCopy8(uni64.i, uidtemp, sizeof(uidtemp));
    for (i = 0; i < 5; i++)
        uni64.i[DWCi_util_wifiid_exctable[i]] = uidtemp[i];
    uni64.i[7] = 0;
    uni64.i[6] = 0;
    uni64.i[5] &= 7;
    uni64.data <<= 1;
    uni64.i[0] |= (uni64.i[5] >> 3) & 1;
    for (i = 0; i < 6; i++)
        uni64.i[i] ^= 0x67;
    uni64.i[7] = 0;
    uni64.i[6] = 0;
    uni64.i[5] &= 7;
    return uni64.data;
}

#define DWC_WIFIID_RAND_MUL 0x5D588B65

#define DWC_WIFIID_RAND_ADD 0x00269EC3

#define DWC_NINTENDO_OUI    0x0009BF

/*
 * sdk:      DWCi_AUTH_GetNewWiFiInfo (util_wifiidtool.o)
 */
int DWCi_AUTH_GetNewWiFiInfo(DWCWiFiInfo *wifiinfo)
{
    u8 vend;
    u8 macaddr[6];
    u32 macDW3;
    s64 seed;
    RTCDate rtcd;
    RTCTime time;

    DWCi_BM_GetWiFiInfo(wifiinfo);
    RTC_Init();
    if (RTC_GetDate(&rtcd) != 0)
        return 0;
    if (RTC_GetTime(&time) != 0)
        return 0;
    seed = RTC_ConvertDateTimeToSecond(&rtcd, &time);
    if (seed < 0)
        return 0;
    /* the object adds OS_GetTick's address, not its value */
    if (OS_IsTickAvailable())
        seed += (u32)OS_GetTick;
    OS_GetMacAddress(macaddr);

    vend = (((macaddr[0] << 16) | (macaddr[1] << 8) | macaddr[2]) != DWC_NINTENDO_OUI) ? 1 : 0;
    macDW3 = (macaddr[3] << 16) | (macaddr[4] << 8) | macaddr[5];
    seed = (u32)seed * DWC_WIFIID_RAND_MUL + DWC_WIFIID_RAND_ADD;
    wifiinfo->pass = (u16)((((u32)seed >> 16) * 1000) >> 16);
    wifiinfo->attestedUserId = 0;
    if (wifiinfo->randomHistory == 0) {
        wifiinfo->notAttestedId = 0;
        while (wifiinfo->notAttestedId == 0) {
            seed = (u32)seed * DWC_WIFIID_RAND_MUL + DWC_WIFIID_RAND_ADD;
            while ((u32)seed == 0) {
                seed = (u32)seed * DWC_WIFIID_RAND_MUL + DWC_WIFIID_RAND_ADD;
            }
            wifiinfo->randomHistory = (u16)seed;
            wifiinfo->notAttestedId = DWCi_Util_WiFiId_scrambleUid(wifiinfo->randomHistory, macDW3, vend, 0);
        }
    } else {
        wifiinfo->notAttestedId = 0;
        while (wifiinfo->notAttestedId == 0) {
            wifiinfo->randomHistory++;
            wifiinfo->notAttestedId = DWCi_Util_WiFiId_scrambleUid(wifiinfo->randomHistory, macDW3, vend, 0);
        }
    }
    return 1;
}

/*
 * sdk:      DWCi_AUTH_MakeWiFiID (libdwcbm.TWL.HYB.a util_wifiidtool.o)
 */
int DWCi_AUTH_MakeWiFiID(void *work)
{
    DWCWiFiInfo wifiinfo;

    if (!DWCi_AUTH_GetNewWiFiInfo(&wifiinfo))
        return 0;
    return DWCi_BM_SetWiFiInfo(&wifiinfo, work) ? 1 : 0;
}

/*
 * sdk:      DWCi_AUTH_UpDateWiFiID (libdwcbm.TWL.HYB.a util_wifiidtool.o)
 */
int DWCi_AUTH_UpDateWiFiID(DWCWiFiInfo *wifiinfo, void *work)
{
    DWCWiFiInfo wifiinfotemp;

    DWCi_BM_GetWiFiInfo(&wifiinfotemp);
    wifiinfo->attestedUserId = wifiinfo->notAttestedId;
    wifiinfo->notAttestedId = wifiinfotemp.notAttestedId;
    return DWCi_BM_SetWiFiInfo(wifiinfo, work) ? 1 : 0;
}

#define DWC_WIFIID_RAND_MUL 0x5D588B65

#define DWC_WIFIID_RAND_ADD 0x00269EC3

#define DWC_NINTENDO_OUI    0x0009BF

/*
 * sdk:      DWCi_AUTH_RemakeWiFiID (util_wifiidtool.o)
 */
int DWCi_AUTH_RemakeWiFiID(DWCWiFiInfo *wifiinfo)
{
    u8 vend;
    u8 macaddr[6] = { 0, 0, 0, 0, 0, 0 };
    u32 macDW3;
    s64 seed;
    RTCDate rtcd;
    RTCTime time;

    DWCi_BM_GetWiFiInfo(wifiinfo);
    RTC_Init();
    if (RTC_GetDate(&rtcd) != 0)
        return 0;
    if (RTC_GetTime(&time) != 0)
        return 0;
    seed = RTC_ConvertDateTimeToSecond(&rtcd, &time);
    if (seed < 0)
        return 0;
    /* the object adds OS_GetTick's address, not its value */
    if (OS_IsTickAvailable())
        seed += (u32)OS_GetTick;
    OS_GetMacAddress(macaddr);

    vend = (((macaddr[0] << 16) | (macaddr[1] << 8) | macaddr[2]) != DWC_NINTENDO_OUI) ? 1 : 0;
    macDW3 = (macaddr[3] << 16) | (macaddr[4] << 8) | macaddr[5];
    seed = (u32)seed * DWC_WIFIID_RAND_MUL + DWC_WIFIID_RAND_ADD;
    wifiinfo->pass = (u16)((((u32)seed >> 16) * 1000) >> 16);
    wifiinfo->notAttestedId = 0;
    while (wifiinfo->notAttestedId == 0) {
        seed = (u32)seed * DWC_WIFIID_RAND_MUL + DWC_WIFIID_RAND_ADD;
        while ((u32)seed == 0 || wifiinfo->randomHistory == (u16)seed) {
            seed = (u32)seed * DWC_WIFIID_RAND_MUL + DWC_WIFIID_RAND_ADD;
        }
        wifiinfo->randomHistory = (u16)seed;
        wifiinfo->notAttestedId = DWCi_Util_WiFiId_scrambleUid(wifiinfo->randomHistory, macDW3, vend, 0);
    }
    return 1;
}

/*
 * sdk:      DWC_Auth_GetId (libdwcbm.TWL.HYB.a util_wifiidtool.o)
 */
void DWC_Auth_GetId(DWCAuthWiFiId *id)
{
    DWCWiFiInfo wifiinfo;

    DWCi_BM_GetWiFiInfo(&wifiinfo);
    id->uId = wifiinfo.attestedUserId;
    id->notAttestedId = wifiinfo.notAttestedId;
    if (wifiinfo.attestedUserId != 0)
        id->flg = 1;
    else
        id->flg = 0;
}

/*
 * sdk:      DWC_Auth_CheckWiFiIDNeedCreate (libdwcbm.TWL.HYB.a util_wifiidtool.o)
 */
int DWC_Auth_CheckWiFiIDNeedCreate(void)
{
    DWCWiFiInfo wifiinfo;

    DWCi_BM_GetWiFiInfo(&wifiinfo);
    if (wifiinfo.notAttestedId == 0 && wifiinfo.attestedUserId == 0)
        return 1;
    return 0;
}

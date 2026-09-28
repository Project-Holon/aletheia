/*
 * function: func_02058E20
 * address:  0x02058E20
 * packet:   pkt_02058E20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * notes:    189 bytes: the LCG state is a u32 register (r4) separate from the s64 seed in the object; this draft carries it through seed and schedules the pass/vend block differently. sdk9w2_dwc: the constants 0x5D588B65/0x269EC3 look like an inlined MATHRandContext16 {x, mul, add} (mul in r6, add in r7, loaded once before the first step and reused by the loop); spelling it as a local context with MATH_InitRand16/MATH_Rand16 inlines still gives 189 because mwcc propagates the constant fields
 *
 * sdk:      DWCi_AUTH_RemakeWiFiID (libdwcbm.TWL.HYB.a util_wifiidtool.o)
 *
 * symbols:
 *   DWCi_BM_GetWiFiInfo          0x02058518 arm
 *   RTC_Init                     0x02088788 arm
 *   RTC_GetDate                  0x02088864 arm
 *   RTC_GetTime                  0x0208890C arm
 *   RTC_ConvertDateTimeToSecond  0x02089004 arm
 *   OS_IsTickAvailable           0x02087058 arm
 *   OS_GetMacAddress             0x02087C6C arm
 *   DWCi_Util_WiFiId_scrambleUid 0x02058A3C arm
 *   OS_GetTick                   0x020870D0 arm
 */

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned long      u32;
typedef signed long        s32;
typedef unsigned long long u64;
typedef signed long long   s64;

typedef struct tagDWCWiFiInfo {
    u64 attestedUserId;
    u64 notAttestedId;
    u16 pass;
    u16 randomHistory;
} DWCWiFiInfo;

typedef struct RTCTime {
    u32 hour;
    u32 minute;
    u32 second;
} RTCTime;

typedef struct RTCDate {
    u32 year;
    u32 month;
    u32 day;
    int week;
} RTCDate;

#define DWC_WIFIID_RAND_MUL 0x5D588B65
#define DWC_WIFIID_RAND_ADD 0x00269EC3
#define DWC_NINTENDO_OUI    0x0009BF

extern void DWCi_BM_GetWiFiInfo(DWCWiFiInfo *buf);
extern void RTC_Init(void);
extern int  RTC_GetDate(RTCDate *date);
extern int  RTC_GetTime(RTCTime *time);
extern s64  RTC_ConvertDateTimeToSecond(const RTCDate *date, const RTCTime *time);
extern int  OS_IsTickAvailable(void);
extern u64  OS_GetTick(void);
extern void OS_GetMacAddress(u8 *macAddress);
extern u64  DWCi_Util_WiFiId_scrambleUid(u16 rand, u32 mac, u8 vend, u8 mainunit);

static inline u32 DWCi_WiFiIdRand(u32 x)
{
    return x * DWC_WIFIID_RAND_MUL + DWC_WIFIID_RAND_ADD;
}

int func_02058E20(DWCWiFiInfo *wifiinfo)
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

    seed = DWCi_WiFiIdRand((u32)seed);
    wifiinfo->pass = (u16)((((u32)seed >> 16) * 1000) >> 16);
    vend = (((macaddr[0] << 16) | (macaddr[1] << 8) | macaddr[2]) != DWC_NINTENDO_OUI) ? 1 : 0;
    macDW3 = (macaddr[3] << 16) | (macaddr[4] << 8) | macaddr[5];

    wifiinfo->notAttestedId = 0;
    while (wifiinfo->notAttestedId == 0) {
        do {
            seed = DWCi_WiFiIdRand((u32)seed);
        } while ((u32)seed == 0 || wifiinfo->randomHistory == (u16)seed);
        wifiinfo->randomHistory = (u16)seed;
        wifiinfo->notAttestedId = DWCi_Util_WiFiId_scrambleUid(wifiinfo->randomHistory, macDW3, vend, 0);
    }
    return 1;
}

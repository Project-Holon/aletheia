/*
 * function: DWCi_AUTH_UpDateWiFiID
 * address:  0x02058DD0
 * packet:   pkt_02058DD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AUTH_UpDateWiFiID (libdwcbm.TWL.HYB.a util_wifiidtool.o)
 *
 * symbols:
 *   DWCi_BM_GetWiFiInfo 0x02058518 arm
 *   DWCi_BM_SetWiFiInfo 0x020586BC arm
 */

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned long      u32;
typedef signed long        s32;
typedef unsigned long long u64;

typedef struct tagDWCWiFiInfo {
    u64 attestedUserId;
    u64 notAttestedId;
    u16 pass;
    u16 randomHistory;
} DWCWiFiInfo;

extern void DWCi_BM_GetWiFiInfo(DWCWiFiInfo *buf);
extern int  DWCi_BM_SetWiFiInfo(DWCWiFiInfo *info, void *work);

int DWCi_AUTH_UpDateWiFiID(DWCWiFiInfo *wifiinfo, void *work)
{
    DWCWiFiInfo wifiinfotemp;

    DWCi_BM_GetWiFiInfo(&wifiinfotemp);
    wifiinfo->attestedUserId = wifiinfo->notAttestedId;
    wifiinfo->notAttestedId = wifiinfotemp.notAttestedId;
    return DWCi_BM_SetWiFiInfo(wifiinfo, work) ? 1 : 0;
}

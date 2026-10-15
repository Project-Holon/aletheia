/*
 * function: DWCi_AUTH_MakeWiFiID
 * address:  0x02058D88
 * packet:   pkt_02058D88
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AUTH_MakeWiFiID (libdwcbm.TWL.HYB.a util_wifiidtool.o)
 *
 * symbols:
 *   DWCi_AUTH_GetNewWiFiInfo 0x02058BC0 arm
 *   DWCi_BM_SetWiFiInfo      0x020586BC arm
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

extern int DWCi_AUTH_GetNewWiFiInfo(DWCWiFiInfo *wifiinfo);
extern int DWCi_BM_SetWiFiInfo(DWCWiFiInfo *info, void *work);

int DWCi_AUTH_MakeWiFiID(void *work)
{
    DWCWiFiInfo wifiinfo;

    if (!DWCi_AUTH_GetNewWiFiInfo(&wifiinfo))
        return 0;
    return DWCi_BM_SetWiFiInfo(&wifiinfo, work) ? 1 : 0;
}

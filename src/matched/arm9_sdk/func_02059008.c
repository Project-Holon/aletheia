/*
 * function: func_02059008
 * address:  0x02059008
 * packet:   pkt_02059008
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Auth_CheckWiFiIDNeedCreate (libdwcbm.TWL.HYB.a util_wifiidtool.o)
 *
 * symbols:
 *   DWCi_BM_GetWiFiInfo 0x02058518 arm
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

int func_02059008(void)
{
    DWCWiFiInfo wifiinfo;

    DWCi_BM_GetWiFiInfo(&wifiinfo);
    if (wifiinfo.notAttestedId == 0 && wifiinfo.attestedUserId == 0)
        return 1;
    return 0;
}

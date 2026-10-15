/*
 * function: DWC_Auth_GetId
 * address:  0x02058FB4
 * packet:   pkt_02058FB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Auth_GetId (libdwcbm.TWL.HYB.a util_wifiidtool.o)
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

typedef struct {
    u64 uId;
    u64 notAttestedId;
    u32 flg;
} DWCAuthWiFiId;

extern void DWCi_BM_GetWiFiInfo(DWCWiFiInfo *buf);

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

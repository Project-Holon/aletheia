/*
 * file:     unit_021B83FC_p01.c
 * unit:     yes
 * function: func_021B83FC, func_021B8488
 * address:  0x021B83FC
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MIi_CpuCopy16  0x02082A60  arm
 *   rateset_table  0x021DAB28  data
 *   MIi_CpuClear16  0x02082A48  arm
 *   MI_CpuCopy8     0x02082D44  arm
 */
struct wlla_ssid {
    unsigned long Len;
    unsigned char Ssid[32];
};

struct wlla_rateset {
    unsigned long Count;
    unsigned char Rate[16];
};

struct wlla_bss_info {
    struct wlla_ssid    Ssid;
    unsigned long       Channel;
    unsigned long       Noise;
    unsigned long       Signal;
    unsigned char       Bssid[6];
    struct wlla_rateset SupportRates;
    unsigned long       BeaconPeriod;
    unsigned long       Capability;
};

typedef struct {
    unsigned short basic;
    unsigned short support;
} WMRateSet;

struct WMBssDesc {
    unsigned short length;
    unsigned short rssi;
    unsigned char  bssid[6];
    unsigned short ssidLength;
    unsigned char  ssid[32];
    unsigned short capaInfo;
    WMRateSet      rateSet;
    unsigned short beaconPeriod;
    unsigned short dtimPeriod;
    unsigned short channel;
    unsigned short cfpPeriod;
    unsigned short cfpMaxDuration;
    unsigned short gameInfoLength;
    unsigned short otherElementCount;
    unsigned char  gameInfo[0x80];   /* struct WMGameInfo, not needed here */
};

typedef struct {
    unsigned short apc;
    unsigned char  wlla;
    unsigned char  dummy;
} RATESET;

extern void MIi_CpuCopy16(void *srcp, void *destp, unsigned long size);
extern void MIi_CpuClear16(unsigned short data, void *destp, unsigned long size);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
void Set_WLLA_BSS_INFO(struct WMBssDesc *bd, struct wlla_bss_info *bi);
void Get_WLLA_SSID_PARAM(struct wlla_ssid *ssid, struct WMBssDesc *bd);
extern RATESET rateset_table[12];


void Set_WLLA_BSS_INFO(struct WMBssDesc *bd, struct wlla_bss_info *bi)
{
    int i;
    unsigned long support_rate_count;

    bi->Ssid.Len = bd->ssidLength;
    MIi_CpuCopy16(bd->ssid, bi->Ssid.Ssid, 32);
    bi->Channel = bd->channel;
    MIi_CpuCopy16(bd->bssid, bi->Bssid, 6);
    support_rate_count = 0;
    for (i = 0; i < 12; i++) {
        if (rateset_table[i].apc & bd->rateSet.support) {
            bi->SupportRates.Rate[support_rate_count] = rateset_table[i].wlla;
            if (rateset_table[i].apc & bd->rateSet.basic)
                bi->SupportRates.Rate[support_rate_count] |= 0x80;
            support_rate_count++;
        }
    }
    bi->SupportRates.Count = support_rate_count;
    bi->BeaconPeriod = bd->beaconPeriod;
    if ((bd->capaInfo & 3) == 1)
        bi->Capability = 1;
    else if ((bd->capaInfo & 3) == 2)
        bi->Capability = 2;
    else
        bi->Capability = 0;
}


void Get_WLLA_SSID_PARAM(struct wlla_ssid *ssid, struct WMBssDesc *bd)
{
    MIi_CpuClear16(0, bd->ssid, 32);
    bd->ssidLength = ssid->Len;
    MI_CpuCopy8(ssid->Ssid, bd->ssid, bd->ssidLength);
}

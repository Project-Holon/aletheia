/*
 * function: Set_WLLA_BSS_INFO
 * address:  0x021B83FC
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MIi_CpuCopy16  0x02082A60  arm
 *   rateset_table  0x021DAB28  data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aosslink.o), symbol Set_WLLA_BSS_INFO (name from the vendor object).
 * aosslink.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B83FC.c \
 *       --func Set_WLLA_BSS_INFO --addr 0x021B83FC --region ov016 --cc ../2.0/sp1p2 --thumb
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

extern RATESET rateset_table[12];
extern void MIi_CpuCopy16(void *srcp, void *destp, unsigned long size);

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

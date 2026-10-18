/*
 * function: Get_WLLA_SSID_PARAM
 * address:  0x021B8488
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MIi_CpuClear16  0x02082A48  arm
 *   MI_CpuCopy8     0x02082D44  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aosslink.o), symbol Get_WLLA_SSID_PARAM (name from the vendor object).
 * aosslink.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B8488.c \
 *       --func Get_WLLA_SSID_PARAM --addr 0x021B8488 --region ov016 --cc ../2.0/sp1p2 --thumb
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

extern void MIi_CpuClear16(unsigned short data, void *destp, unsigned long size);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);

void Get_WLLA_SSID_PARAM(struct wlla_ssid *ssid, struct WMBssDesc *bd)
{
    MIi_CpuClear16(0, bd->ssid, 32);
    bd->ssidLength = ssid->Len;
    MI_CpuCopy8(ssid->Ssid, bd->ssid, bd->ssidLength);
}

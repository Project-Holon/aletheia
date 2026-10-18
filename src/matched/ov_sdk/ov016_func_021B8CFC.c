/*
 * function: APC_GetAPList
 * address:  0x021B8CFC
 * packet:   pkt_ov016_021B89DC
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WCM_LockApList   0x02165C28  arm
 *   WCM_CountApList  0x02165BD0  arm
 *   WCM_PointApList  0x02165CA0  arm
 *   MIi_CpuCopy32    0x02082A90  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(apc.o), symbol APC_GetAPList (name from the vendor object).
 * apc.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B8CFC.c \
 *       --func APC_GetAPList --addr 0x021B8CFC --region ov016 --cc ../2.0/sp1p2 --thumb
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

extern int WCM_LockApList(int lock);
extern int WCM_CountApList(void);
extern struct WMBssDesc *WCM_PointApList(unsigned short index);
extern void MIi_CpuCopy32(void *srcp, void *destp, unsigned long size);

int APC_GetAPList(struct WMBssDesc *WMBssdescBuf, int list_max)
{
    int ap_count;
    int ap_index;
    struct WMBssDesc *wmbssdesc;
    struct WMBssDesc *dest;

    WCM_LockApList(1);
    ap_count = WCM_CountApList();
    if (ap_count > 0) {
        for (ap_index = 0; ap_index < ap_count; ap_index++) {
            if (ap_index >= list_max)
                break;
            wmbssdesc = WCM_PointApList(ap_index);
            dest = &WMBssdescBuf[ap_index];
            MIi_CpuCopy32(wmbssdesc, dest, sizeof(struct WMBssDesc));
        }
    }
    WCM_LockApList(0);
    return ap_count;
}

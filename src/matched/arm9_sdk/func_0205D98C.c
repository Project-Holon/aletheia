/*
 * function: func_0205D98C
 * address:  0x0205D98C
 * packet:   pkt_0205D98C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_AC_ProcessGetWDSInfo (nintendospot.o)
 *
 * symbols:
 *   s_nspot                        0x02146ADC  data  a4
 *   WDS_Initialize                 0x0205A4D4  arm
 *   WDS_StartScan                  0x0205A598  arm
 *   _ll_udiv                       0x0209C00C  arm
 *   WDS_EndScan                    0x0205A650  arm
 *   WDS_GetApInfoAll               0x0205A724  arm
 *   WDS_IsAvailableForAutoConnect  0x0205A8FC  arm
 *   WDS_End                        0x0205A558  arm
 *   WDS_Initialize_CB              0x0205DCC8  arm
 *   WDS_StartScan_CB               0x0205DCDC  arm
 *   WDS_EndScan_CB                 0x0205DCF0  arm
 *   WDS_End_CB                     0x0205DD04  arm
 *   WDS_Error_End_CB               0x0205DD18  arm
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;
typedef unsigned long long u64;
typedef int BOOL;

typedef struct tagDWCWDSData {
    u8 ssid[32];
    u8 wep[32];
    int wepMode;
    u16 mtu;
    char apnum[10];
} DWCWDSData;

typedef struct WDSApInfo {
    u8 ssid[32];
    u8 apnum[10];
    u8 pad0[0x44 - 0x2a];
    u8 wep[32];
    u8 pad1;
    u8 wepMode;
    u8 pad2[0x6c - 0x66];
    u16 mtu;
    u8 pad3[0x72 - 0x6e];
} WDSApInfo;

typedef struct WDSBriefApInfo {
    int isvalid;
    u16 rssi;
    WDSApInfo apinfo;
} WDSBriefApInfo;

typedef struct DWCWDSWork {
    DWCWDSData *nspotInfoBuf;
    u16 dmaNo;
    u64 wdsScanBeginTick;
    WDSBriefApInfo briefapinfo[16];
    int selectedIndex;
} DWCWDSWork;

static struct {
    DWCWDSWork *gDwcWdsWork;
    void *wdsSysBuf;
    int gAppstate;
} s_nspot;

extern BOOL WDS_Initialize(void *wdsWork, void (*callback)(void *), u16 dmaNo);
extern BOOL WDS_StartScan(void (*callback)(void *));
extern u64 OS_GetTick(void);
extern BOOL WDS_EndScan(void (*callback)(void *));
extern BOOL WDS_GetApInfoAll(WDSBriefApInfo *briefapinfo);
extern BOOL WDS_IsAvailableForAutoConnect(WDSApInfo *apinfo);
extern BOOL WDS_End(void (*callback)(void *));
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern void WDS_Initialize_CB(void);
extern void WDS_StartScan_CB(void);
extern void WDS_EndScan_CB(void);
extern void WDS_End_CB(void);
extern void WDS_Error_End_CB(void);

int func_0205D98C(void)
{
    int i;
    u16 maxRssi;
    u64 now;
    int result;

    if (s_nspot.wdsSysBuf == 0 || s_nspot.gDwcWdsWork == 0) {
        return 3;
    }
    result = 1;
    switch (s_nspot.gAppstate) {
    case 0:
        s_nspot.gAppstate = 1;
        if (WDS_Initialize(s_nspot.wdsSysBuf, (void (*)(void *))WDS_Initialize_CB, s_nspot.gDwcWdsWork->dmaNo)) {
            s_nspot.gAppstate = 0xb;
        }
        break;
    case 2:
        s_nspot.gAppstate = 3;
        if (WDS_StartScan((void (*)(void *))WDS_StartScan_CB) == 0) {
            if (s_nspot.gDwcWdsWork->wdsScanBeginTick == 0) {
                s_nspot.gDwcWdsWork->wdsScanBeginTick = OS_GetTick();
            }
        } else {
            s_nspot.gAppstate = 0xa;
        }
        break;
    case 4:
        now = OS_GetTick();
        if (((now - s_nspot.gDwcWdsWork->wdsScanBeginTick) * 64) / 0x82ea < 3000) {
            s_nspot.gAppstate = 2;
        } else {
            s_nspot.gAppstate = 5;
        }
        break;
    case 5:
        s_nspot.gAppstate = 6;
        if (WDS_EndScan((void (*)(void *))WDS_EndScan_CB)) {
            s_nspot.gAppstate = 0xa;
        }
        break;
    case 7:
        if (WDS_GetApInfoAll(s_nspot.gDwcWdsWork->briefapinfo)) {
            s_nspot.gAppstate = 0xa;
        }
        i = 0;
        maxRssi = 0;
        s_nspot.gDwcWdsWork->selectedIndex = -1;
        for (; i < 16; i++) {
            if (WDS_IsAvailableForAutoConnect(&s_nspot.gDwcWdsWork->briefapinfo[i].apinfo) &&
                s_nspot.gDwcWdsWork->briefapinfo[i].isvalid != 0 &&
                s_nspot.gDwcWdsWork->briefapinfo[i].rssi >= maxRssi) {
                s_nspot.gDwcWdsWork->selectedIndex = i;
                maxRssi = s_nspot.gDwcWdsWork->briefapinfo[i].rssi;
            }
        }
        s_nspot.gAppstate = 8;
        if (WDS_End((void (*)(void *))WDS_End_CB)) {
            s_nspot.gAppstate = 0xb;
        }
        break;
    case 9:
        if (s_nspot.gDwcWdsWork->selectedIndex < 0) {
            s_nspot.gAppstate = 0xb;
            break;
        }
        MI_CpuCopy8(s_nspot.gDwcWdsWork->briefapinfo[s_nspot.gDwcWdsWork->selectedIndex].apinfo.ssid,
                    s_nspot.gDwcWdsWork->nspotInfoBuf->ssid, 32);
        MI_CpuCopy8(s_nspot.gDwcWdsWork->briefapinfo[s_nspot.gDwcWdsWork->selectedIndex].apinfo.wep,
                    s_nspot.gDwcWdsWork->nspotInfoBuf->wep, 32);
        s_nspot.gDwcWdsWork->nspotInfoBuf->wepMode =
            s_nspot.gDwcWdsWork->briefapinfo[s_nspot.gDwcWdsWork->selectedIndex].apinfo.wepMode;
        s_nspot.gDwcWdsWork->nspotInfoBuf->mtu =
            s_nspot.gDwcWdsWork->briefapinfo[s_nspot.gDwcWdsWork->selectedIndex].apinfo.mtu;
        MI_CpuCopy8(s_nspot.gDwcWdsWork->briefapinfo[s_nspot.gDwcWdsWork->selectedIndex].apinfo.apnum,
                    s_nspot.gDwcWdsWork->nspotInfoBuf->apnum, 10);
        result = 2;
        break;
    case 10:
        s_nspot.gAppstate = 8;
        if (WDS_End((void (*)(void *))WDS_Error_End_CB)) {
            s_nspot.gAppstate = 0xb;
        }
        break;
    case 11:
        result = 3;
        break;
    }
    return result;
}

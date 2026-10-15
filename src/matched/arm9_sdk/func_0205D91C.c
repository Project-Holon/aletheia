/*
 * function: DWC_AC_StartupGetWDSInfo
 * address:  0x0205D91C
 * packet:   pkt_0205D91C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_AC_StartupGetWDSInfo (nintendospot.o)
 *
 * symbols:
 *   s_nspot  0x02146ADC  data  a4
 *   DWC_Alloc  0x0205A16C  arm
 *   WDS_GetWorkAreaSize  0x0205A4C8  arm
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

extern u32 WDS_GetWorkAreaSize(void);
extern void *DWC_Alloc(int name, u32 size);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);

BOOL DWC_AC_StartupGetWDSInfo(DWCWDSData *nspotInfo, u16 dmaNo)
{
    s_nspot.wdsSysBuf = DWC_Alloc(1, WDS_GetWorkAreaSize());
    s_nspot.gDwcWdsWork = DWC_Alloc(1, sizeof(DWCWDSWork));
    MI_CpuFill8(s_nspot.gDwcWdsWork, 0, sizeof(DWCWDSWork));
    s_nspot.gDwcWdsWork->nspotInfoBuf = nspotInfo;
    s_nspot.gDwcWdsWork->dmaNo = dmaNo;
    s_nspot.gAppstate = 0;
    return 1;
}

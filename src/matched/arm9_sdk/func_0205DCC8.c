/*
 * function: WDS_Initialize_CB
 * address:  0x0205DCC8
 * packet:   pkt_0205DCC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WDS_Initialize_CB (nintendospot.o)
 *
 * symbols:
 *   s_nspot  0x02146ADC  data  a4
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

void WDS_Initialize_CB(void)
{
    s_nspot.gAppstate = 2;
}

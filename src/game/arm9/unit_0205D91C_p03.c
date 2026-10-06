/*
 * file:     unit_0205D91C_p03.c
 * unit:     yes
 * function: func_0205DCC8, func_0205DCDC, func_0205DCF0, func_0205DD04, func_0205DD18
 * address:  0x0205DCC8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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

void func_0205DCC8(void);
void func_0205DCDC(void);
void func_0205DCF0(void);
void func_0205DD04(void);
void func_0205DD18(void);


static struct {
    DWCWDSWork *gDwcWdsWork;
    void *wdsSysBuf;
    int gAppstate;
} s_nspot;


/*
 * sdk:      WDS_Initialize_CB (nintendospot.o)
 */
void func_0205DCC8(void)
{
    s_nspot.gAppstate = 2;
}


/*
 * sdk:      WDS_StartScan_CB (nintendospot.o)
 */
void func_0205DCDC(void)
{
    s_nspot.gAppstate = 4;
}


/*
 * sdk:      WDS_EndScan_CB (nintendospot.o)
 */
void func_0205DCF0(void)
{
    s_nspot.gAppstate = 7;
}


/*
 * sdk:      WDS_End_CB (nintendospot.o)
 */
void func_0205DD04(void)
{
    s_nspot.gAppstate = 9;
}


/*
 * sdk:      WDS_Error_End_CB (nintendospot.o)
 */
void func_0205DD18(void)
{
    s_nspot.gAppstate = 0xb;
}

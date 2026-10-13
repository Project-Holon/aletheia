/*
 * file:     search.c
 * unit:     yes
 * function: DWCi_SEARCHlInit, DWCi_SEARCHlEnd, DWCi_SEARCHlBegin, startScan, DWCi_SEARCHlStop, DWCi_SEARCHlGetApInfo, callback, renewInfo
 * address:  0x021CEF20
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   gSearchWork  0x021DE640  data
 *   WM_GetAllowedChannel  0x0208EE60  arm
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   g_021DE640_b  0x021DE640  data
 *   MIi_CpuClear16  0x02082A48  arm
 *   WM_Initialize  0x0208F370  arm
 *   WM_ReadStatus  0x0208EBE4  arm
 *   WM_GetDispersionScanPeriod  0x0208EFC4  arm
 *   sSearchScanParam  0x021DA8CC  data
 *   WM_StartScanEx  0x0208F698  arm
 *   WM_Reset  0x0208F400  arm
 *   WM_End  0x0208F43C  arm
 *   memcmp  0x020923F0  arm
 *   sSearchZeroBssid  0x021DA8C4  data
 *   OS_Terminate  0x02088234  arm
 *   DC_InvalidateRange  0x020862B8  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   WM_GetOtherElements  0x0208F05C  arm
 *   sSearchBeaconTag  0x021DA8C0  data
 */
#include "../../matched/arm9_sdk/libc/memcmp/string.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef struct {
    u16 length;
    u16 rssi;
    u8 bssid[6];
    u16 ssidLength;
    u8 ssid[32];
    u16 capaInfo;
    u8 rateSet[4];
    u16 beaconPeriod;
    u16 dtimPeriod;
    u16 channel;
    u16 cfpPeriod;
    u16 cfpMaxDuration;
    u16 gameInfoLength;
    u16 otherElementCount;
    u8 gameInfo[0x80];
} WMBssDesc;

typedef struct {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 channelList;
    u8 reserved[2];
    u16 bssDescCount;
    WMBssDesc *bssDesc[16];
    u16 linkLevel[16];
} WMStartScanExCallback;

typedef struct {
	unsigned char ssid[32];
	unsigned char bssid[6];
	unsigned short level;
	unsigned char wep;
	unsigned char pad;
} tagAPINFO;

typedef struct {
	void *buf;
	int w1;
	unsigned short period;
	unsigned short pad;
	int rest[14];
} SCANPRM;

typedef struct {
	unsigned short state;
	char pad[0x7ce];
} WMSTAT;

typedef struct {
	unsigned char wmBuf[0xf00];
	unsigned char scanBuf[0x400];
	tagAPINFO info[20];
	SCANPRM scan;
	WMSTAT status;
	unsigned char flag;
	char pad1[3];
} tagMEMSEARCH;

typedef struct {
    u8 id;
    u8 length;
    u8 rsv[2];
    u8 *body;
} WMOtherElement;

typedef struct {
    u8 count;
    u8 rsv[3];
    WMOtherElement element[16];
} WMOtherElements;

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern unsigned short WM_GetAllowedChannel(void);
extern void DWCi_HEAPlFree_(void **mem);
extern void MIi_CpuClear16(unsigned short data, void *destp, unsigned long size);
extern int WM_Initialize(void *wmSysBuf, void (*callback)(void *), unsigned short dmaNo);
extern int WM_ReadStatus(void *statusBuf);
extern unsigned short WM_GetDispersionScanPeriod(void);
extern int WM_StartScanEx(void (*callback)(void *), void *param);
extern int WM_Reset(void (*callback)(void *));
extern int WM_End(void (*callback)(void *));
extern int memcmp(const void *a, const void *b, unsigned long n);
extern void OS_Terminate(void);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void MI_CpuCopy8(void *srcp, void *dstp, u32 size);
extern WMOtherElements WM_GetOtherElements(WMBssDesc *bssDesc);
void DWCi_SEARCHlInit(void);
void DWCi_SEARCHlEnd(void);
int DWCi_SEARCHlBegin(void);
int DWCi_SEARCHlStop(void);
int DWCi_SEARCHlGetApInfo(tagAPINFO **info);
extern tagMEMSEARCH *gSearchWork;
extern tagMEMSEARCH *g_021DE640_b;
extern SCANPRM sSearchScanParam;
extern unsigned char sSearchZeroBssid[6];
extern u8 sSearchBeaconTag[4];


/*
 * sdk:      DWCi_SEARCHlInit (libdwcutil.TWL.HYB.a(search.o))
 */

static int startScan(void);
static void callback(void *arg);
static void renewInfo(WMStartScanExCallback *prm);
void DWCi_SEARCHlInit(void)
{
	if (gSearchWork == 0)
		gSearchWork = (tagMEMSEARCH *)DWCi_HEAPlAllocEx(0x1e60, 0x20);
}


/*
 * sdk:      DWCi_SEARCHlEnd (libdwcutil.TWL.HYB.a(search.o))
 *
 * notes:    the two pool words are the same address (MemSearch); the second
 *           extern g_021DE640_b keeps them apart.
 */
void DWCi_SEARCHlEnd(void)
{
	if (gSearchWork != 0) {
		while (WM_GetAllowedChannel() != 0x8000) {
		}
		DWCi_HEAPlFree_((void **)&g_021DE640_b);
	}
}


/*
 * sdk:      DWCi_SEARCHlBegin (libdwcutil.TWL.HYB.a(search.o))
 */
int DWCi_SEARCHlBegin(void)
{
	int rs;

	MIi_CpuClear16(0, gSearchWork->info, 0x348);
	rs = WM_Initialize(gSearchWork, callback, 3);
	if (rs != 2)
		return 0;
	do {
		WM_ReadStatus(&gSearchWork->status);
	} while (gSearchWork->status.state != 2);
	gSearchWork->scan = sSearchScanParam;
	gSearchWork->scan.buf = gSearchWork->scanBuf;
	gSearchWork->scan.period = WM_GetDispersionScanPeriod();
	return startScan() != 0;
}


/*
 * sdk:      startScan (libdwcutil.TWL.HYB.a(search.o))
 */
static int startScan(void)
{
	return WM_StartScanEx(callback, &gSearchWork->scan) == 2;
}


/*
 * sdk:      DWCi_SEARCHlStop (libdwcutil.TWL.HYB.a(search.o))
 */
int DWCi_SEARCHlStop(void)
{
	int rs;

	gSearchWork->flag = 1;
	WM_ReadStatus(&gSearchWork->status);
	if (gSearchWork->status.state != 2) {
		rs = WM_Reset(callback);
		if (rs != 2)
			return 0;
		do {
			WM_ReadStatus(&gSearchWork->status);
		} while (gSearchWork->status.state != 2);
	}
	rs = WM_End(callback);
	if (rs != 2)
		return 0;
	return 1;
}


/*
 * sdk:      DWCi_SEARCHlGetApInfo (libdwcutil.TWL.HYB.a(search.o))
 */
int DWCi_SEARCHlGetApInfo(tagAPINFO **info)
{
	int num;
	int i;
	tagAPINFO *ap;

	num = 0;
	ap = gSearchWork->info;
	*info = ap;
	for (i = 0; i < 20; i++) {
		if (memcmp(ap[i].bssid, sSearchZeroBssid, 6) != 0)
			num++;
	}
	return num;
}


/*
 * sdk:      callback (libdwcutil.TWL.HYB.a(search.o))
 */
static void callback(void *arg)
{
	WMStartScanExCallback *prm = (WMStartScanExCallback *)arg;

	if (prm->errcode != 0 || gSearchWork->flag != 0 || prm->apiid != 0x26)
		return;
	switch (prm->state) {
	case 5:
		renewInfo(prm);
		startScan();
		break;
	case 4:
		startScan();
		break;
	default:
		OS_Terminate();
		break;
	}
}


/*
 * sdk:      renewInfo (libdwcutil.TWL.HYB.a(search.o))
 */
static void renewInfo(WMStartScanExCallback *prm)
{
    tagAPINFO *info;
    WMBssDesc *desc;
    WMOtherElements elems;
    int i;
    int j;
    int k;

    info = gSearchWork->info;
    DC_InvalidateRange(gSearchWork->scanBuf, 1024);
    for (i = 0; i < prm->bssDescCount; i++) {
        desc = prm->bssDesc[i];
        if (desc->ssid[0] == 0 || desc->gameInfoLength != 0)
            continue;
        for (j = 0; j < 20; j++) {
            if (memcmp(desc->bssid, info[j].bssid, 6) == 0)
                break;
        }
        if (j == 20) {
            for (j = 0; j < 20; j++) {
                if (memcmp(info[j].bssid, sSearchZeroBssid, 6) == 0)
                    break;
            }
            if (j == 20)
                return;
        }
        MI_CpuCopy8(desc->bssid, info[j].bssid, 6);
        MI_CpuCopy8(desc->ssid, info[j].ssid, 32);
        info[j].level = prm->linkLevel[i];
        if ((desc->capaInfo & 0x10) == 0) {
            info[j].wep = 0;
            continue;
        }
        info[j].wep = 1;
        elems = WM_GetOtherElements(desc);
        for (k = 0; k < elems.count; k++) {
            if (elems.element[k].id == 0x30) {
                info[j].wep = 2;
                break;
            }
            if (elems.element[k].id == 0xdd && elems.element[k].length >= 4 &&
                memcmp(elems.element[k].body, sSearchBeaconTag, 4) == 0) {
                info[j].wep = 2;
                break;
            }
        }
    }
}

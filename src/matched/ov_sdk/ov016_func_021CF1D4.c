/*
 * function: func_021CF1D4
 * address:  0x021CF1D4
 * packet:   pkt_ov016_021CF1D4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      renewInfo (libdwcutil.TWL.HYB.a(search.o))
 *
 * symbols:
 *   func_020862B8  0x020862B8  arm
 *   memcmp  0x020923F0  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0208F05C  0x0208F05C  arm
 *   g_021DE640  0x021DE640  data
 *   g_021DA8C4  0x021DA8C4  data
 *   g_021DA8C0  0x021DA8C0  data
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

typedef struct {
    u8 ssid[32];
    u8 bssid[6];
    u16 level;
    u8 wep;
    u8 pad;
} tagAPINFO;

typedef struct {
    u8 wmBuf[3840];
    u8 scanBuf[1024];
    tagAPINFO info[20];
} tagMEMSEARCH;

extern void func_020862B8(void *startAddr, u32 nBytes);
extern void func_02082D44(void *srcp, void *dstp, u32 size);
extern WMOtherElements func_0208F05C(WMBssDesc *bssDesc);

extern tagMEMSEARCH *g_021DE640;
extern u8 g_021DA8C4[6];
extern u8 g_021DA8C0[4];

void func_021CF1D4(WMStartScanExCallback *prm)
{
    tagAPINFO *info;
    WMBssDesc *desc;
    WMOtherElements elems;
    int i;
    int j;
    int k;

    info = g_021DE640->info;
    func_020862B8(g_021DE640->scanBuf, 1024);
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
                if (memcmp(info[j].bssid, g_021DA8C4, 6) == 0)
                    break;
            }
            if (j == 20)
                return;
        }
        func_02082D44(desc->bssid, info[j].bssid, 6);
        func_02082D44(desc->ssid, info[j].ssid, 32);
        info[j].level = prm->linkLevel[i];
        if ((desc->capaInfo & 0x10) == 0) {
            info[j].wep = 0;
            continue;
        }
        info[j].wep = 1;
        elems = func_0208F05C(desc);
        for (k = 0; k < elems.count; k++) {
            if (elems.element[k].id == 0x30) {
                info[j].wep = 2;
                break;
            }
            if (elems.element[k].id == 0xdd && elems.element[k].length >= 4 &&
                memcmp(elems.element[k].body, g_021DA8C0, 4) == 0) {
                info[j].wep = 2;
                break;
            }
        }
    }
}

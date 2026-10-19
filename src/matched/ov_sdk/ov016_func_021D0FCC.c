/*
 * function: scanWait
 * address:  0x021D0FCC
 * packet:   pkt_ov016_021D0FCC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      scanWait (libdwcutil.TWL.HYB.a usbap.o)
 *
 * symbols:
 *   DC_InvalidateRange  0x020862B8  arm
 *   memcmp  0x020923F0  arm
 *   gUsbapWork  0x021DE654  data
 *   sUsbApSsid  0x021DA94E  data
 */

#include "../arm9_sdk/libc/memcmp/string.h"

typedef unsigned short u16;

typedef struct {
    u16 length;
    u16 rssi;
    unsigned char bssid[6];
    u16 ssidLength;
    unsigned char ssid[32];
} BssDescT;

typedef struct {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 channelList;
    unsigned char reserved[2];
    u16 bssDescCount;
    BssDescT *bssDesc[16];
} ScanCbT;

typedef struct {
    unsigned char bssid[6];
    unsigned char used;
} UsbApT;

typedef struct {
    unsigned char wmBuf[3840];
    unsigned char scanBuf[1024];
    UsbApT ap[16];
    void (*callback)(int);
    unsigned char pad[0x1b88 - 0x1374];
    unsigned char start[8];
    void *task;
    unsigned char end;
    unsigned char stack;
} MemUsbT;

extern void DC_InvalidateRange(void *ptr, unsigned long nBytes);
extern MemUsbT *gUsbapWork;
extern char sUsbApSsid[9];

void scanWait(ScanCbT *prm)
{
    BssDescT *info;
    int i;
    int j;

    if (gUsbapWork->stack) {
        if (gUsbapWork->callback)
            gUsbapWork->callback(gUsbapWork->stack);
        return;
    }
    DC_InvalidateRange(gUsbapWork->scanBuf, 1024);
    for (i = 0; i < prm->bssDescCount; i++) {
        info = prm->bssDesc[i];
        if (memcmp(info->ssid, sUsbApSsid, 8) != 0)
            continue;
        if (!(info->ssid[9] & 1))
            continue;
        for (j = 0; j < 16; j++) {
            if (memcmp(info->bssid, gUsbapWork->ap[j].bssid, 6) == 0) {
                if (gUsbapWork->ap[j].used)
                    goto next;
                if (gUsbapWork->callback == 0) {
                    gUsbapWork->stack = 1;
                    return;
                }
                gUsbapWork->callback(1);
                return;
            }
        }
    next:;
    }
}

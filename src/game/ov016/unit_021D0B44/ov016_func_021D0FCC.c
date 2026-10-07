/*
 * function: func_021D0FCC
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
 *   g_021DE654  0x021DE654  data
 *   g_021DA94E  0x021DA94E  data
 */

#include "../../../matched/arm9_sdk/libc/memcmp/string.h"

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
extern MemUsbT *g_021DE654;
extern char g_021DA94E[9];

void func_021D0FCC(ScanCbT *prm)
{
    BssDescT *info;
    int i;
    int j;

    if (g_021DE654->stack) {
        if (g_021DE654->callback)
            g_021DE654->callback(g_021DE654->stack);
        return;
    }
    DC_InvalidateRange(g_021DE654->scanBuf, 1024);
    for (i = 0; i < prm->bssDescCount; i++) {
        info = prm->bssDesc[i];
        if (memcmp(info->ssid, g_021DA94E, 8) != 0)
            continue;
        if (!(info->ssid[9] & 1))
            continue;
        for (j = 0; j < 16; j++) {
            if (memcmp(info->bssid, g_021DE654->ap[j].bssid, 6) == 0) {
                if (g_021DE654->ap[j].used)
                    goto next;
                if (g_021DE654->callback == 0) {
                    g_021DE654->stack = 1;
                    return;
                }
                g_021DE654->callback(1);
                return;
            }
        }
    next:;
    }
}

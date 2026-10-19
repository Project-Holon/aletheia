/*
 * function: scanFirst
 * address:  0x021D0E74
 * packet:   pkt_ov016_021D0E74
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     EXACT (2026-10-01). The homed prm is register pressure, not a front-end
 *           quirk: the image's copy destination recomputes MemUsb+0x1300 in
 *           loop 2 (no CSE with the memcmp operand), which keeps MemUsb live and
 *           pushes prm to the stack. Spelled as `((struct ApT *)MemUsb->ap)[j].bssid`;
 *           with the DWARF's single function-scope j (declared info, i, j) the
 *           allocation then lands exactly.
 *
 * symbols:
 *   DC_InvalidateRange  0x020862B8  arm
 *   memcmp  0x020923F0  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   sUsbApSsid  0x021DA94E  data
 *   gUsbapWork  0x021DE654  data
 *   sUsbApZeroBssid  0x021DA948  data
 */

#include "../../matched/arm9_sdk/libc/memcmp/string.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 length;
    u16 rssi;
    u8 bssid[6];
    u16 ssidLength;
    u8 ssid[32];
} BssDescT;

typedef struct {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 channelList;
    u8 reserved[2];
    u16 bssDescCount;
    BssDescT *bssDesc[16];
} ScanCbT;

typedef struct {
    u8 wmBuf[3840];
    u8 scanBuf[1024];
    struct ApT {
        u8 bssid[6];
        u8 used;
    } ap[16];
    void (*callback)(int);
} MemUsbT;

extern void DC_InvalidateRange(void *ptr, unsigned long nBytes);
extern void MI_CpuCopy8(const void *src, void *dst, unsigned long size);
extern MemUsbT *gUsbapWork;
extern char sUsbApSsid[9];
extern u8 sUsbApZeroBssid[6];

void scanFirst(ScanCbT *prm)
{
    BssDescT *info;
    int i;
    int j;

    for (i = 0; i < prm->bssDescCount; i++) {
        info = prm->bssDesc[i];
        DC_InvalidateRange(info, 0xc0);
        if (memcmp(info->ssid, sUsbApSsid, 8) != 0)
            continue;
        for (j = 0; j < 16; j++) {
            if (memcmp(info->bssid, gUsbapWork->ap[j].bssid, 6) == 0) {
                if (gUsbapWork->ap[j].used)
                    goto next;
                if (!(info->ssid[9] & 1))
                    goto next;
                if (gUsbapWork->callback)
                    gUsbapWork->callback(1);
                return;
            }
        }
        for (j = 0; j < 16; j++) {
            if (memcmp(gUsbapWork->ap[j].bssid, sUsbApZeroBssid, 6) == 0) {
                MI_CpuCopy8(info->bssid, ((struct ApT *)gUsbapWork->ap)[j].bssid, 6);
                gUsbapWork->ap[j].used = (info->ssid[9] & 1) ? 1 : 0;
                break;
            }
        }
    next:;
    }
}

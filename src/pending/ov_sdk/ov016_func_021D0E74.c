/*
 * function: func_021D0E74
 * address:  0x021D0E74
 * packet:   pkt_ov016_021D0E74
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  vendor front end (4.0.0.1025) homes the `prm` parameter (str r0,[sp]) and
 *           keeps the loop counter `i` in fp; dsi/1.1p1 keeps prm in fp and i in r7.  332
 *           vs 344 B, all 12 missing bytes are the home store + two reloads.  Documented
 *           unforceable in docs/idioms/a-vendor-front-end-homed-parameter-cannot-be-forced-by-source.md
 *           (names this exact scanFirst).  This lane re-tried decl-swap (i/info), a named
 *           nonzero-offset live alias ((u8*)prm+0x10 -> frame appears but body recolours,
 *           336 B), and the prior volatile/copy/BLOCK levers; none reproduce the vendor's
 *           colouring.  Frame IS recoverable, exact bytes are not.
 *
 * sdk:      scanFirst (libdwcutil.TWL.HYB.a usbap.o)
 *
 * wave10 lane2: the DWARF homes prm at [fb+0] (the image stores it into the r3 pad slot of
 * the prologue push and reloads it per iteration, i=fp, info=r7, j=r6).  A `ScanCbT *volatile`
 * copy of prm forces a spill but gives 364 B (image 344): extra sub sp and reloads.  The
 * spill is a register-pressure decision of the 1025 build, not a source qualifier.
 *
 * symbols:
 *   DC_InvalidateRange  0x020862B8  arm
 *   memcmp  0x020923F0  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   g_021DA94E  0x021DA94E  data
 *   g_021DE654  0x021DE654  data
 *   g_021DA948  0x021DA948  data
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
    struct {
        u8 bssid[6];
        u8 used;
    } ap[16];
    void (*callback)(int);
} MemUsbT;

extern void DC_InvalidateRange(void *ptr, unsigned long nBytes);
extern void MI_CpuCopy8(const void *src, void *dst, unsigned long size);
extern MemUsbT *g_021DE654;
extern char g_021DA94E[9];
extern u8 g_021DA948[6];

void func_021D0E74(ScanCbT *prm)
{
    int i;
    BssDescT *info;

    for (i = 0; i < prm->bssDescCount; i++) {
        info = prm->bssDesc[i];
        DC_InvalidateRange(info, 0xc0);
        if (memcmp(info->ssid, g_021DA94E, 8) != 0)
            continue;
        {
        int j;
        for (j = 0; j < 16; j++) {
            if (memcmp(info->bssid, g_021DE654->ap[j].bssid, 6) == 0) {
                if (g_021DE654->ap[j].used)
                    goto next;
                if (!(info->ssid[9] & 1))
                    goto next;
                if (g_021DE654->callback)
                    g_021DE654->callback(1);
                return;
            }
        }
        }
        {
        int j;
        for (j = 0; j < 16; j++) {
            if (memcmp(g_021DE654->ap[j].bssid, g_021DA948, 6) == 0) {
                MI_CpuCopy8(info->bssid, g_021DE654->ap[j].bssid, 6);
                g_021DE654->ap[j].used = (info->ssid[9] & 1) ? 1 : 0;
                break;
            }
        }
        }
    next:;
    }
}

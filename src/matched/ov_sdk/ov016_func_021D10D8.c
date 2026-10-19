/*
 * function: taskFirst
 * address:  0x021D10D8
 * packet:   pkt_ov016_021D10D8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskFirst (libdwcutil.TWL.HYB.a usbap.o)
 *
 * symbols:
 *   OS_GetTick  0x020870D0  arm
 *   memcmp  0x020923F0  arm
 *   DWCi_TSKlDelete  0x021D7724  arm  ov016
 *   gUsbapWork  0x021DE654  data
 *   sUsbApZeroBssid  0x021DA948  data
 */

#include "../arm9_sdk/libc/memcmp/string.h"

typedef unsigned char u8;
typedef unsigned long long u64;

typedef struct {
    u8 wmBuf[3840];
    u8 scanBuf[1024];
    struct {
        u8 bssid[6];
        u8 used;
    } ap[16];
    void (*callback)(int);
    u8 param[0x1b88 - 0x1374];
    u64 start;
    void *task;
    u8 end;
    u8 stack;
    u8 wait;
} MemUsbT;

extern u64 OS_GetTick(void);
extern void DWCi_TSKlDelete(int kind, void *task);
extern MemUsbT *gUsbapWork;
extern u8 sUsbApZeroBssid[6];

void taskFirst(void *task)
{
    u64 tick;
    int i;
    int admit;
    int not;

    tick = OS_GetTick();
    if (tick < gUsbapWork->start + 0x17F898)
        return;
    not = 0;
    admit = 0;
    for (i = 0; i < 16; i++) {
        if (memcmp(gUsbapWork->ap[i].bssid, sUsbApZeroBssid, 6) != 0) {
            if (gUsbapWork->ap[i].used)
                admit = 1;
            else
                not = 1;
        }
    }
    if (admit && not) {
        if (gUsbapWork->callback)
            gUsbapWork->callback(2);
    } else if (admit) {
        if (gUsbapWork->callback)
            gUsbapWork->callback(1);
    } else if (!not) {
        if (gUsbapWork->callback)
            gUsbapWork->callback(0);
    }
    gUsbapWork->task = 0;
    gUsbapWork->wait = 1;
    DWCi_TSKlDelete(0, task);
}

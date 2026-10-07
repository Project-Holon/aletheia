/*
 * function: func_021D10D8
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
 *   func_021D7724  0x021D7724  arm  ov016
 *   g_021DE654  0x021DE654  data
 *   g_021DA948  0x021DA948  data
 */

#include "../../../matched/arm9_sdk/libc/memcmp/string.h"

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
extern void func_021D7724(int kind, void *task);
extern MemUsbT *g_021DE654;
extern u8 g_021DA948[6];

void func_021D10D8(void *task)
{
    u64 tick;
    int i;
    int admit;
    int not;

    tick = OS_GetTick();
    if (tick < g_021DE654->start + 0x17F898)
        return;
    not = 0;
    admit = 0;
    for (i = 0; i < 16; i++) {
        if (memcmp(g_021DE654->ap[i].bssid, g_021DA948, 6) != 0) {
            if (g_021DE654->ap[i].used)
                admit = 1;
            else
                not = 1;
        }
    }
    if (admit && not) {
        if (g_021DE654->callback)
            g_021DE654->callback(2);
    } else if (admit) {
        if (g_021DE654->callback)
            g_021DE654->callback(1);
    } else if (!not) {
        if (g_021DE654->callback)
            g_021DE654->callback(0);
    }
    g_021DE654->task = 0;
    g_021DE654->wait = 1;
    func_021D7724(0, task);
}

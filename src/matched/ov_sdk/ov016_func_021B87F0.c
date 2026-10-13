/*
 * function: AOSSi_WLANConnect
 * address:  0x021B87F0
 * packet:   pkt_ov016_021B87F0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * sdk:      AOSSi_WLANConnect (libdwcutil.TWL.HYB.a(aosslink.o))
 *
 * symbols:
 *   MI_CpuFill8          0x02082BCC  arm
 *   MI_CpuCopy8          0x02082D44  arm
 *   WCM_ClearApList      0x02165B80  arm
 *   func_021B8D40        0x021B8D40  thumb  ov016
 *   OS_CreateAlarm       0x02087254  arm
 *   OS_SetAlarm          0x0208738C  arm
 *   OS_ReceiveMessage    0x02085E50  arm
 *   OS_CancelAlarm       0x020873F8  arm
 *   func_021B8CFC        0x021B8CFC  thumb  ov016
 *   func_021B8488        0x021B8488  thumb  ov016
 *   func_021B8EFC        0x021B8EFC  thumb  ov016
 *   func_021B84AC        0x021B84AC  thumb  ov016
 *   func_021B84D0        0x021B84D0  thumb  ov016
 *   gAosslinkBlock2           0x021DCF20  data
 *   gAosslinkEventQueue           0x021DCE40  data
 *   gAosslinkBlock1           0x021DCE60  data
 *
 * notes: 2026-10-01 (wave 3 lane 10) EXACT. Earlier waves parked two residues
 *   (the empty ssidLength loop's r0/r1 roles and the case-19 jump-table slot)
 *   as front-end colouring. Both were asm-mode codegen (lever 15): the vendor
 *   object's .bss is align 32 and holds connect_bssdesc (static, 192 B, at
 *   +0x40), i.e. `static WMBssDesc connect_bssdesc ATTRIBUTE_ALIGN(32)`. With
 *   the aligned static the plain empty `for` survives with i in r0, the
 *   initialised definition gives the loop its own pool word (no second extern
 *   name needed), and the DWARF-only local `connect_lock` is a dead store in
 *   `case 19` that keeps the arm's block (table slot on case 18's `b`).
 *   Also: `while (loop_flag)` instead of gotos, u8 wep_id per DWARF, no `cp`.
 */

#include "../include/G_OSMessageQueue.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef struct OSiAlarm {
    void (*handler)(void *);
    void *arg;
    u32 tag;
    u64 fire;
    struct OSiAlarm *prev;
    struct OSiAlarm *next;
    u64 period;
    u64 start;
} OSiAlarm;

typedef struct _OSThreadQueue {
    void *head;
    void *tail;
} OSThreadQueue;

typedef struct OSMessageQueue OSMessageQueue;

typedef struct WMBssDesc {
    u16 length;
    u16 rssi;
    u8 bssid[6];
    u16 ssidLength;
    u8 pad[0xc0 - 0xc];
} WMBssDesc;

typedef struct wlla_connect_param {
    u32 ssidLen;            /* +0x00 */
    u8 ssid[0x20];          /* +0x04 */
    u32 AuthAlgo;           /* +0x24 */
    u32 keyLen;             /* +0x28 */
    u8 key[0x10];           /* +0x2c */
} wlla_connect_param;

typedef struct wlla_link_stat wlla_link_stat;

extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void MI_CpuCopy8(void *srcp, void *dstp, u32 size);
extern void WCM_ClearApList(void);
extern int func_021B8D40(u8 *bssid, u8 *essid, int essid_len, u32 option);
extern void OS_CreateAlarm(OSiAlarm *alarm);
extern void OS_SetAlarm(OSiAlarm *alarm, u64 tick, void (*handler)(void *), void *arg);
extern int OS_ReceiveMessage(OSMessageQueue *mq, void **msg, long flags);
extern void OS_CancelAlarm(OSiAlarm *alarm);
extern int func_021B8CFC(WMBssDesc *buf, int list_max);
extern void func_021B8488(wlla_connect_param *ssid, WMBssDesc *bd);
extern int func_021B8EFC(WMBssDesc *bd, u8 *wep_buf, u32 option);
extern void func_021B84AC(int *p, int a, int c);
extern void func_021B84D0(void *event);

extern u8 gAosslinkBlock2[96];
extern struct OSMessageQueue gAosslinkEventQueue;
static WMBssDesc gAosslinkBlock1 __attribute__((aligned(32))) = {0};

int AOSSi_WLANConnect(wlla_connect_param *conParam, wlla_link_stat *linkStat)
{
    void *msg;
    OSiAlarm alarm;
    int loop_flag;
    int ret_code;
    int connect_retry_count;
    int connect_lock;
    u32 link_status;
    u32 connect_option;
    u8 wep_id;
    int i;

    loop_flag = 1;
    ret_code = -1;
    wep_id = 0;
    if (conParam->AuthAlgo == 0) {
        connect_option = 0x80000;
    } else if (conParam->AuthAlgo == 1) {
        connect_option = 0xC0000;
    }
    connect_option |= 0x30000;

    MI_CpuFill8(gAosslinkBlock2, 0, 96);
    if (conParam->keyLen == 5) {
        gAosslinkBlock2[0] = 1;
    } else if (conParam->keyLen == 13) {
        gAosslinkBlock2[0] = 2;
    } else if (conParam->keyLen == 16) {
        gAosslinkBlock2[0] = 3;
    } else {
        return -1;
    }
    gAosslinkBlock2[1] = wep_id;
    MI_CpuCopy8(conParam->key, &gAosslinkBlock2[wep_id * 20 + 2], conParam->keyLen);

    WCM_ClearApList();
    if (func_021B8D40(0, conParam->ssid, conParam->ssidLen, 0x30BFFE)) {
        connect_retry_count = 0;
        OS_CreateAlarm(&alarm);
        OS_SetAlarm(&alarm, 0x3FEC42, func_021B84D0, (void *)0x12);
        while (loop_flag) {
            OS_ReceiveMessage(&gAosslinkEventQueue, &msg, 1);
            switch ((int)msg) {
            case 18:
                if (wep_id == 0)
                    loop_flag = 0;
            case 19:
                connect_lock = 0;
                break;
            case 5:
                if (wep_id != 0)
                    break;
                OS_CancelAlarm(&alarm);
                if (func_021B8CFC(&gAosslinkBlock1, 1) != 1) {
                    loop_flag = 0;
                } else {
                    func_021B8488(conParam, &gAosslinkBlock1);
                    for (i = 0; i < gAosslinkBlock1.ssidLength; i++)
                        ;
                    if (func_021B8EFC(&gAosslinkBlock1, gAosslinkBlock2, connect_option) == 0)
                        loop_flag = 0;
                    else
                        wep_id = 1;
                }
                break;
            case 10:
                func_021B8488(conParam, &gAosslinkBlock1);
                if (func_021B8EFC(&gAosslinkBlock1, gAosslinkBlock2, connect_option) == 0)
                    loop_flag = 0;
                break;
            case 12:
                loop_flag = 0;
                ret_code = 0;
                break;
            case 13:
                connect_retry_count++;
                if (connect_retry_count < 3) {
                    if (func_021B8EFC(&gAosslinkBlock1, gAosslinkBlock2, connect_option) == 0)
                        loop_flag = 0;
                } else {
                    loop_flag = 0;
                }
                break;
            default:
                loop_flag = 0;
                break;
            case 4:
            case 8:
                break;
            }
        }
        OS_CancelAlarm(&alarm);
        do {
        } while (OS_ReceiveMessage(&gAosslinkEventQueue, &msg, 0) == 1);
    }
    link_status = (ret_code == 0) ? 1 : 0;
    func_021B84AC((int *)linkStat, (int)(&gAosslinkBlock1), link_status);
    return ret_code;
}
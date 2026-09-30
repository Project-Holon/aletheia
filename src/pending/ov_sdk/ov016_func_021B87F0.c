/*
 * function: func_021B87F0
 * address:  0x021B87F0
 * packet:   pkt_ov016_021B87F0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
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
 *   g_021DCF20           0x021DCF20  data
 *   g_021DCE40           0x021DCE40  data
 *   g_021DCE60           0x021DCE60  data
 *   g_021DCE60_b         0x021DCE60  data
 *
 * notes: DIFF, 464 vs 464 bytes, 6 bytes off.
 *   Control flow, switch table (case 4/8/18/19), pool words and register
 *   allocation now match byte-for-byte. Residue: (1) the msg19 switch-table
 *   halfword (object 0x2C = case 18 tail, ours 0xB6 = loop test); (2) the
 *   empty ssidLength loop - only the post-increment condition form survives
 *   -O4,p dead-loop elimination, and its compiled shape inserts a temp copy
 *   (adds r1,r0,#0) before the compare, shifting the ldrh register, the
 *   compare and the back-edge by 2 bytes.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef enum { WEP_OFF = 0, WEP_ON = 1 } wep_state;

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

typedef struct OSMessageQueue {
    OSThreadQueue queueSend;
    OSThreadQueue queueReceive;
    void **msgArray;
    long msgCount;
    long firstIndex;
    long usedCount;
} OSMessageQueue;

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
extern void func_021B84AC(wlla_link_stat *ls, WMBssDesc *bd, u32 link_status);
extern void func_021B84D0(void *event);

extern u8 g_021DCF20[96];
extern OSMessageQueue g_021DCE40;
extern WMBssDesc g_021DCE60;
extern WMBssDesc g_021DCE60_b;

int func_021B87F0(wlla_connect_param *conParam, wlla_link_stat *linkStat)
{
    void *msg;
    OSiAlarm alarm;
    int loop_flag;
    int ret_code;
    int connect_retry_count;
    u32 link_status;
    u32 connect_option;
    wep_state wep_id;
    int i;

    wlla_connect_param *cp = conParam;
    loop_flag = 1;
    ret_code = -1;
    wep_id = WEP_OFF;
    if (cp->AuthAlgo == 0) {
        connect_option = 0x80000;
    } else if (cp->AuthAlgo == 1) {
        connect_option = 0xC0000;
    }
    connect_option |= 0x30000;

    MI_CpuFill8(g_021DCF20, 0, 96);
    if (cp->keyLen == 5) {
        g_021DCF20[0] = 1;
    } else if (cp->keyLen == 13) {
        g_021DCF20[0] = 2;
    } else if (cp->keyLen == 16) {
        g_021DCF20[0] = 3;
    } else {
        return -1;
    }
    g_021DCF20[1] = wep_id;
    MI_CpuCopy8(cp->key, &g_021DCF20[wep_id * 20 + 2], cp->keyLen);

    u32 gbase = (u32)&g_021DCE60;

    WCM_ClearApList();
    if (func_021B8D40(0, cp->ssid, cp->ssidLen, 0x30BFFE)) {
        connect_retry_count = 0;
        OS_CreateAlarm(&alarm);
        OS_SetAlarm(&alarm, 0x3FEC42, func_021B84D0, (void *)0x12);
        goto lstest;
        lreceive:
            OS_ReceiveMessage(&g_021DCE40, &msg, 1);
            switch ((int)msg) {
            case 4:
            case 8:
                break;
            case 18:
                if (wep_id == WEP_OFF)
                    loop_flag = 0;
                break;
            case 19:
                break;
            case 5:
                if (wep_id != WEP_OFF)
                    break;
                OS_CancelAlarm(&alarm);
                if (func_021B8CFC((WMBssDesc *)gbase, 1) != 1) {
                    loop_flag = 0;
                } else {
                    func_021B8488(conParam, &g_021DCE60);
                    for (i = 0; i++ < g_021DCE60_b.ssidLength; )
                        ;
                    if (func_021B8EFC((WMBssDesc *)gbase, g_021DCF20, connect_option) == 0)
                        loop_flag = 0;
                    else
                        wep_id = WEP_ON;
                }
                break;
            case 10:
                func_021B8488(conParam, &g_021DCE60);
                if (func_021B8EFC((WMBssDesc *)gbase, g_021DCF20, connect_option) == 0)
                    loop_flag = 0;
                break;
            case 12:
                loop_flag = 0;
                ret_code = 0;
                break;
            case 13:
                connect_retry_count++;
                if (connect_retry_count < 3) {
                    if (func_021B8EFC((WMBssDesc *)gbase, g_021DCF20, connect_option) == 0)
                        loop_flag = 0;
                } else {
                    loop_flag = 0;
                }
                break;
            default:
                loop_flag = 0;
                break;
            }
        lstest:
            if (loop_flag != 0)
                goto lreceive;
        OS_CancelAlarm(&alarm);
        do {
        } while (OS_ReceiveMessage(&g_021DCE40, &msg, 0) == 1);
    }
    link_status = (ret_code == 0) ? 1 : 0;
    func_021B84AC(linkStat, &g_021DCE60, link_status);
    return ret_code;
}
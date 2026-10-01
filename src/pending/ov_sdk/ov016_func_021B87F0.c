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
 * blocker:  two residues, both front-end colouring on an sp1p2 object, not
 *           source-reachable by the idiom levers: (1) +00EA, case 19's
 *           jump-table halfword -- every 2.0 front end threads the empty
 *           `case 19: break;` to the shared exit (0xb6 -> 0x21b896c) while
 *           the object keeps a distinct block (0x2c -> the `b` at
 *           0x21b88e2); (2) +0116..+0122, the empty ssidLength loop's r0/r1
 *           role swap (object len r1 / i r0; ours len r0 / i r1) with every
 *           instruction otherwise identical. See the Wave 8 note below.
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
 *
 * Lane U37 re-measured both residues with 8 further spellings, all flat at 6 concrete bytes /
 * 464 exact: case 18 with an explicit break in each arm, case 19 written before case 18,
 * `case 19:;`, an `if (...) { loop_flag = 0; break; }` arm, an added `int len`/`u32 len` local,
 * a plain `i < len` for (this one drops the frame to 460 and breaks the whole function: the
 * `(i < X) ? 1 : 0` test is what stops -O4,p dead-loop elimination), a flipped compare and an
 * `unsigned i` (7 bytes).  Image `movs r4, r5` | ours `lsls r6, r6, #2` at the case-19 table
 * entry (image 0x2c -> the b at 0x21b88e2, ours 0xb6 -> the shared exit at 0x21b896c) and the
 * ssidLength loop's r0/r1 roles (image len r1 / i r0, ours len r0 / i r1) are front-end
 *   colouring on a 3.0.0.126-stamped object.  Pin scan: ../2.0/base 464/6 == ../2.0/sp1p2;
 *   every dsi build 448/200.
 *
 * Wave 8 (this lane) re-attacked both residues and they held.  Source levers tried, all
 * flat at 464 bytes / 6 concrete: `case 18` with its own explicit `break` in each arm;
 * `case 19: goto lstest;` (still threaded through the single `b`); a named `u16 ssid_len`
 * local declared after `i` and loaded before the loop; `i = 0;` split out in front of the
 * loop; the loop as a `while` with `i++` in the body; the bound written on the left
 * (`ssidLength > i`); plus `tools/permute.py --mode hill --budget 160` (55 mutations, 158
 * compiles, best still 6).  A compiler probe over every 2.0 front end (base, sp1, sp1p2,
 * sp1p5..sp2p4) gives the same 464/6 for all, so the residue is not a stamp mismatch.  The
 * two bytes at +00EA are the front end's jump-table threading of an empty arm and the four
 * at +0116..+0122 are a caller-saved r0/r1 tie from the empty loop's preheader, neither of
 * which the idiom index has a lever for; parked rather than guessed at.
 *
 * Wave 8 re-lane (cursor idea): rewriting the ssidLength loop as a `char *`
 * cursor makes the compare unsigned/inequality (`bne`/`blo`) where the image
 * keeps a signed `blt`, and measured 7 concrete bytes.  A cursor cannot
 * reproduce a signed integer loop, so the idea is a dead end here.
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

    WCM_ClearApList();
    if (func_021B8D40(0, cp->ssid, cp->ssidLen, 0x30BFFE)) {
        connect_retry_count = 0;
        OS_CreateAlarm(&alarm);
        OS_SetAlarm(&alarm, 0x3FEC42, func_021B84D0, (void *)0x12);
        goto lstest;
        lreceive:
            OS_ReceiveMessage(&g_021DCE40, &msg, 1);
            switch ((int)msg) {
            case 18:
                if (wep_id == WEP_OFF)
                    loop_flag = 0;
            case 19:
                break;
            case 5:
                if (wep_id != WEP_OFF)
                    break;
                OS_CancelAlarm(&alarm);
                if (func_021B8CFC(&g_021DCE60, 1) != 1) {
                    loop_flag = 0;
                } else {
                    func_021B8488(conParam, &g_021DCE60);
                    for (i = 0; (i < g_021DCE60_b.ssidLength) ? 1 : 0; i++)
                        ;
                    if (func_021B8EFC(&g_021DCE60, g_021DCF20, connect_option) == 0)
                        loop_flag = 0;
                    else
                        wep_id = WEP_ON;
                }
                break;
            case 10:
                func_021B8488(conParam, &g_021DCE60);
                if (func_021B8EFC(&g_021DCE60, g_021DCF20, connect_option) == 0)
                    loop_flag = 0;
                break;
            case 12:
                loop_flag = 0;
                ret_code = 0;
                break;
            case 13:
                connect_retry_count++;
                if (connect_retry_count < 3) {
                    if (func_021B8EFC(&g_021DCE60, g_021DCF20, connect_option) == 0)
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
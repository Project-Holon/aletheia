/*
 * function: AOSSi_WLANGetBSSList
 * address:  0x021B8678
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   aosslink_bss       0x021DCE20  data
 *   aoss_mq            0x021DCE40  data
 *   alarmCallback      0x021B84D0  thumb
 *   APC_SearchStart    0x021B8D40  thumb
 *   OS_CreateAlarm     0x02087254  arm
 *   OS_SetAlarm        0x0208738C  arm
 *   OS_ReceiveMessage  0x02085E50  arm
 *   APC_GetAPList      0x021B8CFC  thumb
 *   APC_SearchEnd      0x021B8E30  thumb
 *   Set_WLLA_BSS_INFO  0x021B83FC  thumb
 *   OS_CancelAlarm     0x020873F8  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aosslink.o), symbol AOSSi_WLANGetBSSList (name from the vendor object).
 * aosslink.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B8678.c \
 *       --func AOSSi_WLANGetBSSList --addr 0x021B8678 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

#include "../../../matched/include/G_OSMessageQueue.h"
#include "../../../matched/include/G_AOSSLINK_BSS.h"

typedef struct _OSThreadQueue {
    void *head;
    void *tail;
} OSThreadQueue;

typedef struct OSMessageQueue OSMessageQueue;

/*
 * aosslink.o's .bss statics from 0x021DCE20: the vendor object addresses AOSSi_Free and
 * aoss_workbuffer through AOSSi_Alloc's pool word plus an offset, so the four words are
 * declared as one object in the object's own order; member names are the vendor symbols.
 */
typedef struct {
    void *(*AOSSi_Alloc)(unsigned long size);
    void  (*aoss_callback)(int event);
    void   *aoss_workbuffer;
    void  (*AOSSi_Free)(void *ptr);
} AOSSLINK_BSS;

extern struct AOSSLINK_BSS aosslink_bss;

typedef struct OSiAlarm OSAlarm;
struct OSiAlarm {
    void             (*handler)(void *);
    void              *arg;
    unsigned long      tag;
    unsigned long long fire;
    OSAlarm           *prev;
    OSAlarm           *next;
    unsigned long long period;
    unsigned long long start;
};

struct wlla_ssid {
    unsigned long Len;
    unsigned char Ssid[32];
};

struct wlla_rateset {
    unsigned long Count;
    unsigned char Rate[16];
};

struct wlla_bss_info {
    struct wlla_ssid    Ssid;
    unsigned long       Channel;
    unsigned long       Noise;
    unsigned long       Signal;
    unsigned char       Bssid[6];
    struct wlla_rateset SupportRates;
    unsigned long       BeaconPeriod;
    unsigned long       Capability;
};

typedef struct {
    unsigned short basic;
    unsigned short support;
} WMRateSet;

struct WMBssDesc {
    unsigned short length;
    unsigned short rssi;
    unsigned char  bssid[6];
    unsigned short ssidLength;
    unsigned char  ssid[32];
    unsigned short capaInfo;
    WMRateSet      rateSet;
    unsigned short beaconPeriod;
    unsigned short dtimPeriod;
    unsigned short channel;
    unsigned short cfpPeriod;
    unsigned short cfpMaxDuration;
    unsigned short gameInfoLength;
    unsigned short otherElementCount;
    unsigned char  gameInfo[0x80];   /* struct WMGameInfo, not needed here */
};

struct wlla_bss_list {
    unsigned long        Num;
    struct wlla_bss_info BssInfo[1];
};

extern struct OSMessageQueue aoss_mq;
extern void alarmCallback(void *event);
extern int APC_SearchStart(unsigned char *bssid, unsigned char *essid, int essid_len, unsigned long option);
extern void OS_CreateAlarm(OSAlarm *alarm);
extern void OS_SetAlarm(OSAlarm *alarm, unsigned long long tick, void (*handler)(void *), void *arg);
extern int OS_ReceiveMessage(OSMessageQueue *mq, void **msg, long flags);
extern int APC_GetAPList(struct WMBssDesc *WMBssdescBuf, int list_max);
extern int APC_SearchEnd(void);
extern void Set_WLLA_BSS_INFO(struct WMBssDesc *bd, struct wlla_bss_info *bi);
extern void OS_CancelAlarm(OSAlarm *alarm);

int AOSSi_WLANGetBSSList(struct wlla_bss_list **bssList)
{
    int i;
    void *msg;
    OSAlarm alarm;
    int rc;
    int loop_flag;
    int search_end_flag;
    struct wlla_bss_list *ptr;
    struct WMBssDesc *bssdesc_array;
    struct WMBssDesc *bssdesc_org;
    int num_bss_info;
    int ap_found_event_count;

    rc = -1;
    loop_flag = 1;
    search_end_flag = 0;
    num_bss_info = 0;
    ap_found_event_count = 0;
    if (aosslink_bss.AOSSi_Alloc == 0 || aosslink_bss.AOSSi_Free == 0)
        return -1;
    bssdesc_array = aosslink_bss.AOSSi_Alloc(0x3000);
    if (bssdesc_array == 0)
        return -1;
    bssdesc_org = bssdesc_array;
    if (APC_SearchStart(0, 0, 0, 0x30BFFE) == 0)
        goto free_desc;
    OS_CreateAlarm(&alarm);
    OS_SetAlarm(&alarm, 0x3FEC42, alarmCallback, (void *)0x13);
    do {
        OS_ReceiveMessage(&aoss_mq, &msg, 1);
        switch ((int)msg) {
        case 4:
        case 8:
        case 18:
            break;
        case 19:
            if (search_end_flag == 0) {
                if (ap_found_event_count != 0)
                    num_bss_info = APC_GetAPList(bssdesc_array, 64);
                if (APC_SearchEnd() == 0)
                    goto end;
                search_end_flag = 1;
            }
            break;
        case 5:
            if (search_end_flag == 0) {
                if (ap_found_event_count < 8) {
                    ap_found_event_count++;
                } else {
                    num_bss_info = APC_GetAPList(bssdesc_array, 64);
                    if (APC_SearchEnd() == 0)
                        goto end;
                    search_end_flag = 1;
                }
            }
            break;
        case 10:
            loop_flag = 0;
            rc = 0;
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 6:
        case 7:
        case 9:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        default:
            goto end;
        }
    } while (loop_flag);

    if (num_bss_info != 0) {
        ptr = aosslink_bss.AOSSi_Alloc(sizeof(struct wlla_bss_list) + (num_bss_info - 1) * sizeof(struct wlla_bss_info));
        if (ptr == 0)
            goto end;
    } else {
        ptr = aosslink_bss.AOSSi_Alloc(sizeof(struct wlla_bss_list));
        if (ptr == 0)
            goto end;
    }
    *bssList = ptr;
    ptr->Num = num_bss_info;
    for (i = 0; i < num_bss_info; i++) {
        Set_WLLA_BSS_INFO(bssdesc_array, &ptr->BssInfo[i]);
        bssdesc_array++;
    }

end:
    OS_CancelAlarm(&alarm);
    while (OS_ReceiveMessage(&aoss_mq, &msg, 0) == 1)
        ;
free_desc:
    aosslink_bss.AOSSi_Free(bssdesc_org);
    return rc;
}

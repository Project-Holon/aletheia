/*
 * file:     aosslink.c
 * unit:     yes
 * function: Set_WLLA_BSS_INFO, Get_WLLA_SSID_PARAM, Set_WLLA_LINK_STAT, aoss_apc_callback, alarmCallback, AOSSi_InitLocal, AOSSi_EndLocal, AOSSi_Disconnect, AOSSi_WLANGetBSSList, AOSSi_WLANConnect, AOSSi_Sleep, AOSSi_Status
 * address:  0x021B83FC
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Thumb tail-call thunk into OS_Sleep.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/AOSSi_Sleep.c \
 *       --func AOSSi_Sleep --addr 0x021B89C0 --region ov016 --cc dsi/../2.0/sp1p2 --thumb
 * Dispatch the caller argument through slot 1 of the 0x021DCE20 handler table when set; always return 0.
 * The data symbol carries NO region token on purpose: 0x021DCE20 is a bss
 * address nine overlays share and another one starts an object at, so an
 * `ov016` hint is contested and refused (see scratch/ov_ov016/o27/report.md).
 * Without the token _overlay_pool() fixes the overlay from the region this
 * function is compiled in, and the site attests sole-ref/self.
 *   python tools/match.py one --src src/matched/AOSSi_Status.c \
 *       --func AOSSi_Status --addr 0x021B89C8 --region ov016 --cc dsi/../2.0/sp1p2 --thumb
 *
 * symbols:
 *   OS_Sleep                       0x02085A38  arm  arm9
 *   MIi_CpuCopy16  0x02082A60  arm
 *   rateset_table  0x021DAB28  data
 *   MIi_CpuClear16  0x02082A48  arm
 *   MI_CpuCopy8     0x02082D44  arm
 *   Set_WLLA_BSS_INFO   0x021B83FC  thumb  ov016
 *   OS_SendMessage               0x02085DBC  arm
 *   gAosslinkEventQueue                   0x021DCE40  data
 *   aosslink_bss          0x021DCE20  data
 *   aoss_mq               0x021DCE40  data
 *   aoss_msgArray         0x021DCE30  data
 *   OS_InitMessageQueue   0x02085D94  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   APC_Init              0x021B8F80  thumb
 *   OS_ReceiveMessage     0x02085E50  arm
 *   APC_End               0x021B8EA4  thumb
 *   APC_Disconnect     0x021B8E6C  thumb
 *   APC_SearchStart    0x021B8D40  thumb
 *   OS_CreateAlarm     0x02087254  arm
 *   OS_SetAlarm        0x0208738C  arm
 *   APC_GetAPList      0x021B8CFC  thumb
 *   APC_SearchEnd      0x021B8E30  thumb
 *   OS_CancelAlarm     0x020873F8  arm
 *   MI_CpuFill8          0x02082BCC  arm
 *   WCM_ClearApList      0x02165B80  arm
 *   Get_WLLA_SSID_PARAM        0x021B8488  thumb  ov016
 *   APC_Connect        0x021B8EFC  thumb  ov016
 *   alarmCallback        0x021B84D0  thumb  ov016
 *   gAosslinkBlock2           0x021DCF20  data
 *   gAosslinkEventQueue           0x021DCE40  data
 *   gAosslinkBlock1           0x021DCE60  data
 *   AOSSi_Alloc   0x021DCE20  data
 */
#include "../../matched/include/G_OSMessageQueue.h"
#include "../../matched/include/G_AOSSLINK_BSS.h"

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

typedef struct WMBssDesc {
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
} WMBssDesc;

typedef struct {
    unsigned short apc;
    unsigned char  wlla;
    unsigned char  dummy;
} RATESET;

typedef struct _OSThreadQueue {
    void *head;
    void *tail;
} OSThreadQueue;

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

typedef struct OSMessageQueue OSMessageQueue;

typedef struct OSiAlarm {
    void (*handler)(void *);
    void *arg;
    unsigned long tag;
    unsigned long long fire;
    struct OSiAlarm *prev;
    struct OSiAlarm *next;
    unsigned long long period;
    unsigned long long start;
} OSiAlarm;

struct wlla_bss_list {
    unsigned long        Num;
    struct wlla_bss_info BssInfo[1];
};

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef unsigned long long u64;

typedef struct wlla_connect_param {
    u32 ssidLen;            /* +0x00 */
    u8 ssid[0x20];          /* +0x04 */
    u32 AuthAlgo;           /* +0x24 */
    u32 keyLen;             /* +0x28 */
    u8 key[0x10];           /* +0x2c */
} wlla_connect_param;

typedef struct wlla_link_stat wlla_link_stat;

extern void MIi_CpuCopy16(void *srcp, void *destp, unsigned long size);
extern void MIi_CpuClear16(unsigned short data, void *destp, unsigned long size);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern int OS_SendMessage(OSMessageQueue *mq, void *msg, long flags);
extern void OS_InitMessageQueue(OSMessageQueue *mq, void **msgArray, long msgCount);
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern int APC_Init(void (*user_callback)(int, void *), void *workbuffer, int work_size);
extern int OS_ReceiveMessage(OSMessageQueue *mq, void **msg, long flags);
extern int APC_End(void);
extern int APC_Disconnect(void);
extern int APC_SearchStart(unsigned char *bssid, unsigned char *essid, int essid_len, unsigned long option);
extern void OS_CreateAlarm(struct OSiAlarm *alarm);
extern void OS_SetAlarm(struct OSiAlarm *alarm, unsigned long long tick, void (*handler)(void *), void *arg);
extern int APC_GetAPList(struct WMBssDesc *WMBssdescBuf, int list_max);
extern int APC_SearchEnd(void);
extern void OS_CancelAlarm(struct OSiAlarm *alarm);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void WCM_ClearApList(void);
extern int APC_Connect(WMBssDesc *bd, u8 *wep_buf, u32 option);
extern void OS_Sleep(unsigned int msec);
void Set_WLLA_BSS_INFO(struct WMBssDesc *bd, struct wlla_bss_info *bi);
void Get_WLLA_SSID_PARAM(struct wlla_ssid *ssid, struct WMBssDesc *bd);
int AOSSi_InitLocal(void *(*alloc)(unsigned long), void (*free)(void *));
int AOSSi_EndLocal(void);
int AOSSi_Disconnect(void);
int AOSSi_WLANGetBSSList(struct wlla_bss_list **bssList);
int AOSSi_WLANConnect(wlla_connect_param *conParam, wlla_link_stat *linkStat);
void AOSSi_Sleep(unsigned int msec);
int AOSSi_Status(int a);
extern RATESET rateset_table[12];
extern struct OSMessageQueue gAosslinkEventQueue;
extern struct AOSSLINK_BSS aosslink_bss;
extern struct OSMessageQueue aoss_mq;
extern void *aoss_msgArray[4];
extern u8 gAosslinkBlock2[96];
extern struct OSMessageQueue gAosslinkEventQueue;

static void Set_WLLA_LINK_STAT(unsigned long *link, struct WMBssDesc *bd, unsigned long stat);
static void aoss_apc_callback(void *event);
static void alarmCallback(void *event);


void Set_WLLA_BSS_INFO(struct WMBssDesc *bd, struct wlla_bss_info *bi)
{
    int i;
    unsigned long support_rate_count;

    bi->Ssid.Len = bd->ssidLength;
    MIi_CpuCopy16(bd->ssid, bi->Ssid.Ssid, 32);
    bi->Channel = bd->channel;
    MIi_CpuCopy16(bd->bssid, bi->Bssid, 6);
    support_rate_count = 0;
    for (i = 0; i < 12; i++) {
        if (rateset_table[i].apc & bd->rateSet.support) {
            bi->SupportRates.Rate[support_rate_count] = rateset_table[i].wlla;
            if (rateset_table[i].apc & bd->rateSet.basic)
                bi->SupportRates.Rate[support_rate_count] |= 0x80;
            support_rate_count++;
        }
    }
    bi->SupportRates.Count = support_rate_count;
    bi->BeaconPeriod = bd->beaconPeriod;
    if ((bd->capaInfo & 3) == 1)
        bi->Capability = 1;
    else if ((bd->capaInfo & 3) == 2)
        bi->Capability = 2;
    else
        bi->Capability = 0;
}


void Get_WLLA_SSID_PARAM(struct wlla_ssid *ssid, struct WMBssDesc *bd)
{
    MIi_CpuClear16(0, bd->ssid, 32);
    bd->ssidLength = ssid->Len;
    MI_CpuCopy8(ssid->Ssid, bd->ssid, bd->ssidLength);
}


/*
 * Store c, then tail-call Set_WLLA_BSS_INFO with a and p+1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/Set_WLLA_LINK_STAT.c \
 *       --func Set_WLLA_LINK_STAT --addr 0x021B84AC --region ov016 --cc dsi/1.1p1 --thumb
 */
static void Set_WLLA_LINK_STAT(unsigned long *link, struct WMBssDesc *bd, unsigned long stat)
{
    *link = stat;
    Set_WLLA_BSS_INFO(bd, (struct wlla_bss_info *)(link + 1));
}


static void aoss_apc_callback(void *event)
{
    OS_SendMessage(&gAosslinkEventQueue, event, 0);
}


static void alarmCallback(void *event)
{
    OS_SendMessage(&gAosslinkEventQueue, event, 0);
}


int AOSSi_InitLocal(void *(*alloc)(unsigned long), void (*free)(void *))
{
    void *msg;
    unsigned long enabled;
    int loop_flag;

    loop_flag = 1;
    OS_InitMessageQueue(&aoss_mq, aoss_msgArray, 4);
    if (alloc == 0 || free == 0)
        return -1;
    enabled = OS_DisableInterrupts();
    aosslink_bss.AOSSi_Alloc = alloc;
    aosslink_bss.AOSSi_Free = free;
    OS_RestoreInterrupts(enabled);
    aosslink_bss.aoss_workbuffer = aosslink_bss.AOSSi_Alloc(0x5890);
    if (aosslink_bss.aoss_workbuffer == 0)
        return -1;
    if (APC_Init((void (*)(int, void *))aoss_apc_callback, aosslink_bss.aoss_workbuffer, 0x5890) == 0)
        loop_flag = 0;
    while (loop_flag) {
        OS_ReceiveMessage(&aoss_mq, &msg, 1);
        switch ((int)msg) {
        case 4:
        case 5:
            break;
        case 6:
            return 0;
        case 0:
        case 1:
        case 2:
        case 3:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        default:
            loop_flag = 0;
            break;
        }
    }
    aosslink_bss.AOSSi_Free(aosslink_bss.aoss_workbuffer);
    return -1;
}


int AOSSi_EndLocal(void)
{
    void *msg;
    unsigned long enabled;
    int loop_flag;
    int rc;

    loop_flag = 1;
    rc = -1;
    if (aosslink_bss.AOSSi_Free == 0)
        return rc;
    if (APC_End() == 0)
        return -1;
    while (loop_flag) {
        OS_ReceiveMessage(&aoss_mq, &msg, 1);
        switch ((int)msg) {
        case 4:
        case 5:
            break;
        case 20:
            loop_flag = 0;
            rc = 0;
            aosslink_bss.AOSSi_Free(aosslink_bss.aoss_workbuffer);
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        default:
            loop_flag = 0;
            break;
        }
    }
    enabled = OS_DisableInterrupts();
    aosslink_bss.AOSSi_Alloc = 0;
    aosslink_bss.AOSSi_Free = 0;
    OS_RestoreInterrupts(enabled);
    return rc;
}


int AOSSi_Disconnect(void)
{
    void *msg;
    int loop_flag;
    int rc;

    rc = -1;
    if (APC_Disconnect() != 0) {
        do {
            OS_ReceiveMessage(&aoss_mq, &msg, 1);
            if ((int)msg == 14) {
                loop_flag = 0;
                rc = 0;
            } else {
                loop_flag = 0;
            }
        } while (loop_flag);
    }
    return rc;
}


int AOSSi_WLANGetBSSList(struct wlla_bss_list **bssList)
{
    int i;
    void *msg;
    OSiAlarm alarm;
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


static WMBssDesc gAosslinkBlock1 __attribute__((aligned(32))) = {0};


/*
 * sdk:      AOSSi_WLANConnect (libdwcutil.TWL.HYB.a(aosslink.o))
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
    if (APC_SearchStart(0, conParam->ssid, conParam->ssidLen, 0x30BFFE)) {
        connect_retry_count = 0;
        OS_CreateAlarm(&alarm);
        OS_SetAlarm(&alarm, 0x3FEC42, alarmCallback, (void *)0x12);
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
                if (APC_GetAPList(&gAosslinkBlock1, 1) != 1) {
                    loop_flag = 0;
                } else {
                    Get_WLLA_SSID_PARAM((struct wlla_ssid *)conParam, &gAosslinkBlock1);
                    for (i = 0; i < gAosslinkBlock1.ssidLength; i++)
                        ;
                    if (APC_Connect(&gAosslinkBlock1, gAosslinkBlock2, connect_option) == 0)
                        loop_flag = 0;
                    else
                        wep_id = 1;
                }
                break;
            case 10:
                Get_WLLA_SSID_PARAM((struct wlla_ssid *)conParam, &gAosslinkBlock1);
                if (APC_Connect(&gAosslinkBlock1, gAosslinkBlock2, connect_option) == 0)
                    loop_flag = 0;
                break;
            case 12:
                loop_flag = 0;
                ret_code = 0;
                break;
            case 13:
                connect_retry_count++;
                if (connect_retry_count < 3) {
                    if (APC_Connect(&gAosslinkBlock1, gAosslinkBlock2, connect_option) == 0)
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
    Set_WLLA_LINK_STAT((unsigned long *)linkStat, &gAosslinkBlock1, link_status);
    return ret_code;
}


void AOSSi_Sleep(unsigned int msec)
{
    OS_Sleep(msec);
}

extern void (*AOSSi_Alloc[])(int);


int AOSSi_Status(int a)
{
    if (AOSSi_Alloc[1])
        AOSSi_Alloc[1](a);
    return 0;
}

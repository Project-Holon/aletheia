/*
 * function: ConnectAP
 * address:  0x021B98A4
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   atermset_data      0x021DAB58  data
 *   atermset_bss       0x021DCFD0  data
 *   APC_Connect        0x021B9568  thumb
 *   OS_CreateAlarm     0x02087254  arm
 *   OS_SetAlarm        0x0208738C  arm
 *   GetTickCount       0x021BC584  thumb
 *   OS_Sleep           0x02085A38  arm
 *   AtermApc_GetEvent  0x021B9734  thumb
 *   OS_CancelAlarm     0x020873F8  arm
 *   SOC_Startup        0x0215F8FC  arm
 *   alarmCallback      0x021B979C  thumb
 *   AtermSOConfig      0x021DAB6C  data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol ConnectAP (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Was MATCH on the ABS32 to alarmCallback (0x021B979C) until that static was matched.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B98A4.c \
 *       --func ConnectAP --addr 0x021B98A4 --region ov016 --cc ../2.0/sp1p2 --thumb
 */
/*
 * atermset.o's .bss scalars from 0x021DCFD0 (btAutoResult): the vendor object addresses
 * every word here through btAutoResult's pool word plus an offset, so they are declared as
 * one object in the object's own order; member names are the vendor symbols. The arrays
 * and the pointer and aggregates of the same section (apci_user_callback, event_buf, AllocLock, gAtermThread,
 * gAtermApConfigParam, AutoProfile) are pooled by their own symbols and declared apart.
 */
struct WCMConfig;
struct WMBssDesc;
struct _ATERMApConfigState;

typedef struct {
    unsigned char             btAutoResult;
    void                   *(*gAtermAlloc)(unsigned long size);
    struct WCMConfig         *apci_IWConfig;
    void                    (*gAtermFree)(void *ptr);
    int                       bAtermApCanceled;
    int                       cbFrameData;
    int                       gAPId;
    int                       AutoPhase;          /* enum PHASE */
    int                       bApConnect;
    int                       bSO_Startup;
    unsigned char            *apci_Wep;
    int                       apci_state;         /* enum */
    unsigned long long       *gThreadStack;
    int                       cbElementData;
    int                       gAtermApState;
    unsigned char            *apci_IWBuffer;
    unsigned char            *apc_work;
    unsigned char            *apci_bssid_ptr;
    unsigned char            *apci_essid_ptr;
    struct WMBssDesc         *apci_wmbssdesc;
    int                       bDualCfg;
    unsigned char            *atermapc_work;
    unsigned long             apci_connect_option;
    struct WMBssDesc         *ap_list;
    unsigned long             apci_search_option;
    int                       gAtermThreadId;
    int                       event_set_ptr;
    int                       event_get_ptr;
    int                       gMaxApList;
    int                       bInitAtermApNetwork;
    int                       gAtermApResult;
    void                    (*gAtermNotify)(struct _ATERMApConfigState *state);
} ATERMSET_BSS;

extern ATERMSET_BSS atermset_bss;

/*
 * atermset.o's .data words from 0x021DAB58 (lpElementData), addressed through
 * lpElementData's pool word plus an offset; member names are the vendor symbols.
 */
typedef struct {
    unsigned char *lpElementData;
    int            bDebug;
    unsigned long  gThreadStackSize;
    unsigned long  gAtermApTimeout;
    int            gMaxBssIdList;
} ATERMSET_DATA;

extern ATERMSET_DATA atermset_data;

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

typedef struct SOCConfig SOCConfig;

extern SOCConfig AtermSOConfig;
extern void alarmCallback(void *arg);
extern int APC_Connect(struct WMBssDesc *wmbssdesc, unsigned char *wep_buf, unsigned long option);
extern void OS_CreateAlarm(OSAlarm *alarm);
extern void OS_SetAlarm(OSAlarm *alarm, unsigned long long tick, void (*handler)(void *), void *arg);
extern unsigned long GetTickCount(void);
extern void OS_Sleep(unsigned long msec);
extern int AtermApc_GetEvent(void);
extern void OS_CancelAlarm(OSAlarm *alarm);
extern int SOC_Startup(SOCConfig *config);

#define WMBSSDESC_SIZE 0xC0

int ConnectAP(void)
{
    int loop_flag;
    struct WMBssDesc *wmbssdesc;
    int ret;
    int retv;
    OSAlarm alarm;

    loop_flag = 1;
    retv = -2;
    wmbssdesc = (struct WMBssDesc *)((unsigned char *)atermset_bss.ap_list + atermset_bss.gAPId * WMBSSDESC_SIZE);
    if (wmbssdesc == 0)
        return 0;
    if (APC_Connect(wmbssdesc, 0, 0x30000) == 0)
        return -2;
    OS_CreateAlarm(&alarm);
    OS_SetAlarm(&alarm, 0x3FEC42, alarmCallback, (void *)0x12);
    while (loop_flag) {
        if (GetTickCount() >= atermset_data.gAtermApTimeout) {
            retv = -3;
            break;
        }
        if (atermset_bss.bAtermApCanceled) {
            retv = -8;
            break;
        }
        OS_Sleep(10);
        while ((ret = AtermApc_GetEvent()) != 0) {
            switch (ret) {
            case 4:
            case 5:
            case 18:
            case 19:
                break;
            case 12:
                loop_flag = 0;
                retv = 1;
                break;
            case 13:
                if (atermset_bss.bAtermApCanceled) {
                    loop_flag = 0;
                    retv = -8;
                } else if (APC_Connect(wmbssdesc, 0, 0x30000) == 0) {
                    return retv;
                }
                break;
            default:
                loop_flag = 0;
                break;
            }
        }
    }
    OS_CancelAlarm(&alarm);
    while (AtermApc_GetEvent() != 0)
        ;
    if (retv > 0) {
        atermset_bss.bApConnect = 1;
        if (SOC_Startup(&AtermSOConfig) < 0)
            retv = -2;
        else
            atermset_bss.bSO_Startup = 1;
    }
    return retv;
}

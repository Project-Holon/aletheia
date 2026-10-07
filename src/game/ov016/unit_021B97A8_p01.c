/*
 * file:     unit_021B97A8_p01.c
 * unit:     yes
 * function: func_021B97A8, func_021B984C
 * address:  0x021B97A8
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   AtermApc_InitEventBuf  0x021B970C  thumb  ov016
 *   APC_Init  0x021B95EC  thumb  ov016
 *   OS_Sleep  0x02085A38  arm
 *   AtermApc_GetEvent  0x021B9734  thumb  ov016
 *   AtermApc_callback  0x021B976C  thumb  ov016
 *   atermset_bss  0x021DCFD0  data
 *   APC_End            0x021B9510  thumb
 */
#define APC_WORK_SIZE(n) ((n) * 0xd0 + 0x2490)
#define ROUNDUP32(x) (((x) + 31LL) & ~31LL)
struct WCMConfig;
struct _ATERMApConfigState;
struct WMBssDesc;
typedef unsigned char u8;

typedef unsigned long u32;

struct WMBssDesc { u8 data[0xc0]; };

typedef struct {
    unsigned char             btAutoResult;
    void                   *(*gAtermAlloc)(unsigned long size);
    struct WCMConfig         *apci_IWConfig;
    void                    (*gAtermFree)(void *ptr);
    int                       bAtermApCanceled;
    int                       cbFrameData;
    int                       gAPId;
    int                       AutoPhase;
    int                       bApConnect;
    int                       bSO_Startup;
    unsigned char            *apci_Wep;
    int                       apci_state;
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
    void                    (*apci_user_callback)(int event, void *arg);
} ATERMSET_BSS;

extern void AtermApc_InitEventBuf(void);
extern int APC_Init(void (*user_callback)(int, void *), void *workbuffer, int work_size);
extern void OS_Sleep(unsigned long msec);
extern int AtermApc_GetEvent(void);
extern void AtermApc_callback(int event);
extern int APC_End(void);
int InitAtermApcNetwork(int maxap);
int FreeAtermApcNetwork(void);
extern ATERMSET_BSS atermset_bss;


int InitAtermApcNetwork(int maxap)
{
    int loop_flag;
    int retv;

    loop_flag = 1;
    atermset_bss.gMaxApList = maxap;
    AtermApc_InitEventBuf();
    atermset_bss.atermapc_work = atermset_bss.gAtermAlloc(APC_WORK_SIZE(maxap) + 64 + maxap * sizeof(struct WMBssDesc));
    if (atermset_bss.atermapc_work == 0)
        return -1;
    atermset_bss.apc_work = (u8 *)ROUNDUP32((u32)atermset_bss.atermapc_work);
    atermset_bss.ap_list = (struct WMBssDesc *)ROUNDUP32((u32)atermset_bss.apc_work + APC_WORK_SIZE(maxap));
    if (APC_Init((void (*)(int, void *))AtermApc_callback, atermset_bss.apc_work, APC_WORK_SIZE(maxap)) == 0)
        return -2;
    do {
        int event;

        OS_Sleep(10);
        while ((event = AtermApc_GetEvent()) != 0) {
            switch (event) {
            case 4:
            case 5:
                break;
            case 6:
                loop_flag = 0;
                retv = 1;
                break;
            default:
                loop_flag = 0;
                retv = -2;
                break;
            }
        }
    } while (loop_flag);
    return retv;
}


int FreeAtermApcNetwork(void)
{
    int loop_flag;

    loop_flag = 1;
    if (APC_End()) {
        while (loop_flag) {
            int event;

            OS_Sleep(10);
            while ((event = AtermApc_GetEvent()) != 0) {
                switch (event) {
                case 4:
                case 5:
                    break;
                case 20:
                    loop_flag = 0;
                    break;
                default:
                    loop_flag = 0;
                    break;
                }
            }
        }
    }
    if (atermset_bss.atermapc_work) {
        atermset_bss.gAtermFree(atermset_bss.atermapc_work);
        atermset_bss.atermapc_work = 0;
    }
    return 1;
}

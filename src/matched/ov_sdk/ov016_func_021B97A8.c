/*
 * function: InitAtermApcNetwork
 * address:  0x021B97A8
 * packet:   pkt_ov016_021B97A8
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * sdk:      InitAtermApcNetwork (libdwcutil.TWL.HYB.a(atermset.o))
 *
 * 2026-10-01 (w3 lane13): EXACT.  The image's `movs #0x1f` held in r1 for
 * both `+31` adds, with -32 derived from it (`subs #0x3f`) and `ands`, is what
 * 2.0/sp1p2 emits when the round-up constants are 64-bit (`31LL`, `~31LL`):
 * the 64-bit AND is lowered with a materialised mask instead of the 32-bit
 * `bics` pattern, and the 64-bit 31 is kept in a register for both adds.
 * Plain `& ~31` (all 32-bit spellings) gives bics, 160 B.  The vendor object
 * is stamped 3.0.0.126 (no build in the tree), so the vendor source may have
 * had plain 32-bit constants; this spelling is the 2.0 route to the same bytes.
 * Earlier stand-ins (enum mask local, named size temps) are gone.  The inner
 * `event` local is not in the DWARF (maxap, loop_flag, retv only); kept as the
 * loop needs the value for the switch.
 *
 * symbols:
 *   AtermApc_InitEventBuf  0x021B970C  thumb  ov016
 *   APC_Init  0x021B95EC  thumb  ov016
 *   OS_Sleep  0x02085A38  arm
 *   AtermApc_GetEvent  0x021B9734  thumb  ov016
 *   AtermApc_callback  0x021B976C  thumb  ov016
 *   atermset_bss  0x021DCFD0  data
 */

typedef unsigned char u8;
typedef unsigned long u32;
struct WMBssDesc { u8 data[0xc0]; };
struct WCMConfig;
struct _ATERMApConfigState;

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

extern ATERMSET_BSS atermset_bss;

extern void AtermApc_InitEventBuf(void);
extern int APC_Init(void (*user_callback)(int, void *), void *workbuffer, int work_size);
extern void OS_Sleep(unsigned long msec);
extern int AtermApc_GetEvent(void);
extern void AtermApc_callback(int event);

#define APC_WORK_SIZE(n) ((n) * 0xd0 + 0x2490)
#define ROUNDUP32(x) (((x) + 31LL) & ~31LL)

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

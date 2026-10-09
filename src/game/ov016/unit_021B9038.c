/*
 * file:     unit_021B9038.c
 * unit:     yes
 * function: APCi_Notify, APCi_MoveIdleState
 * address:  0x021B9038
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
 *   atermset_bss        0x021DCFD0  data
 *   apci_user_callback  0x021DD050  data
 *   WCM_SearchAsync     0x02165144  arm
 *   WCM_ConnectAsync    0x021652A4  arm
 *   WCM_CleanupAsync    0x02165088  arm
 *   WCM_Finish          0x02164EE0  arm
 *   WCM_DisconnectAsync  0x02165478  arm
 *   WCM_StartupAsync     0x02164F98  arm
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
struct WCMNotice;
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

typedef union {
    void *p;
} WCMNoticeParameter;

typedef struct WCMNotice {
    short              notify;
    short              result;
    WCMNoticeParameter parameter[3];
} WCMNotice;

struct WCMConfig {
    long  dmano;
    void *pbdbuffer;
    long  nbdbuffer;
    long  nbdmode;
};

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern int WCM_SearchAsync(void *bssid, void *essid, unsigned long option);
extern int WCM_ConnectAsync(void *bssDesc, void *wepDesc, unsigned long option);
extern int WCM_CleanupAsync(void);
extern long WCM_Finish(void);
extern int WCM_DisconnectAsync(void);
extern int WCM_StartupAsync(struct WCMConfig *config, void (*notify)(struct WCMNotice *));
void APCi_Notify(WCMNotice *notice);
int APCi_MoveIdleState(void);
extern ATERMSET_BSS atermset_bss;


extern void (*apci_user_callback)(int event, void *arg);


#define APCI_CALLBACK(event)                                  \
    if (apci_user_callback != 0)                      \
        apci_user_callback((event), 0)


void APCi_Notify(WCMNotice *notice)
{
    if (notice == 0)
        return;
    switch (notice->notify) {
    case 1:
        if (notice->result == 0) {
            if (atermset_bss.apci_state == 4) {
                atermset_bss.apci_state = 3;
                APCI_CALLBACK(6);
            } else if (atermset_bss.apci_state == 6) {
                if (WCM_SearchAsync(atermset_bss.apci_bssid_ptr, atermset_bss.apci_essid_ptr, atermset_bss.apci_search_option) != 3) {
                    atermset_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            } else if (atermset_bss.apci_state == 8) {
                if (WCM_ConnectAsync(atermset_bss.apci_wmbssdesc, atermset_bss.apci_Wep, atermset_bss.apci_connect_option) != 3) {
                    atermset_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            }
        } else {
            atermset_bss.apci_state = 1;
            APCI_CALLBACK(2);
        }
        break;
    case 3:
        if (notice->result == 0) {
            if (atermset_bss.apci_state == 6) {
                atermset_bss.apci_state = 5;
                APCI_CALLBACK(8);
            }
        } else {
            atermset_bss.apci_state = 3;
            APCI_CALLBACK(9);
        }
        break;
    case 5:
        if (notice->result == 0) {
            if (atermset_bss.apci_state == 8) {
                atermset_bss.apci_state = 7;
                APCI_CALLBACK(12);
            }
        } else {
            atermset_bss.apci_state = 3;
            APCI_CALLBACK(13);
        }
        break;
    case 4:
        if (notice->result == 0) {
            if (atermset_bss.apci_state == 4) {
                atermset_bss.apci_state = 3;
                APCI_CALLBACK(10);
            } else if (atermset_bss.apci_state == 6) {
                if (WCM_SearchAsync(atermset_bss.apci_bssid_ptr, atermset_bss.apci_essid_ptr, atermset_bss.apci_search_option) != 3) {
                    atermset_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            } else if (atermset_bss.apci_state == 2) {
                if (WCM_CleanupAsync() != 3) {
                    atermset_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            } else if (atermset_bss.apci_state == 8) {
                if (WCM_ConnectAsync(atermset_bss.apci_wmbssdesc, atermset_bss.apci_Wep, atermset_bss.apci_connect_option) != 3) {
                    atermset_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            }
        } else {
            atermset_bss.apci_state = 3;
            APCI_CALLBACK(11);
        }
        break;
    case 6:
        if (notice->result == 0) {
            if (atermset_bss.apci_state == 4) {
                atermset_bss.apci_state = 3;
                APCI_CALLBACK(14);
            } else if (atermset_bss.apci_state == 6) {
                if (WCM_SearchAsync(atermset_bss.apci_bssid_ptr, atermset_bss.apci_essid_ptr, atermset_bss.apci_search_option) != 3) {
                    atermset_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            } else if (atermset_bss.apci_state == 2) {
                if (WCM_CleanupAsync() != 3) {
                    atermset_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            } else if (atermset_bss.apci_state == 8) {
                if (WCM_ConnectAsync(atermset_bss.apci_wmbssdesc, atermset_bss.apci_Wep, atermset_bss.apci_connect_option) != 3) {
                    atermset_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            } else if (atermset_bss.apci_state == 7) {
                atermset_bss.apci_state = 3;
            }
        } else {
            atermset_bss.apci_state = 3;
            APCI_CALLBACK(15);
        }
        break;
    case 2:
        if (notice->result == 0) {
            if (atermset_bss.apci_state == 2) {
                WCM_Finish();
                atermset_bss.apci_state = 0;
                APCI_CALLBACK(20);
            }
        } else {
            atermset_bss.apci_state = 3;
            APCI_CALLBACK(2);
        }
        break;
    case 7:
        if (atermset_bss.apci_state == 5) {
            APCI_CALLBACK(5);
        }
        break;
    case 8:
        APCI_CALLBACK(4);
        break;
    case 9:
        atermset_bss.apci_state = 0;
        APCI_CALLBACK(3);
        break;
    case 0:
    default:
        APCI_CALLBACK(1);
        break;
    }
}


int APCi_MoveIdleState(void)
{
    switch (atermset_bss.apci_state) {
    case 5:
        if (WCM_SearchAsync(0, 0, 0) != 3)
            return 0;
        break;
    case 7:
        if (WCM_DisconnectAsync() != 3)
            return 0;
        break;
    case 1:
        if (WCM_StartupAsync(atermset_bss.apci_IWConfig, APCi_Notify) != 3)
            return 0;
        break;
    case 0:
    case 2:
    case 3:
    case 4:
    case 6:
    case 8:
    default:
        return 0;
    }
    return 1;
}

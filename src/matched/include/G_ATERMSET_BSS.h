#ifndef ALETHEIA_G_ATERMSET_BSS_H
#define ALETHEIA_G_ATERMSET_BSS_H
/* g_021DCFD0 (arm9) */
struct WCMConfig;
struct WMBssDesc;
struct _ATERMApConfigState;
struct ATERMSET_BSS {
    unsigned char btAutoResult;
    unsigned char pad_1[0x3];
    void * (*gAtermAlloc)(unsigned long);
    struct WCMConfig *apci_IWConfig;
    void (*gAtermFree)(void *);
    int bAtermApCanceled;
    int cbFrameData;
    int gAPId;
    int AutoPhase;
    int bApConnect;
    int bSO_Startup;
    unsigned char *apci_Wep;
    int apci_state;
    unsigned long long *gThreadStack;
    int cbElementData;
    int gAtermApState;
    unsigned char *apci_IWBuffer;
    unsigned char *apc_work;
    unsigned char *apci_bssid_ptr;
    unsigned char *apci_essid_ptr;
    struct WMBssDesc *apci_wmbssdesc;
    int bDualCfg;
    unsigned char *atermapc_work;
    unsigned long apci_connect_option;
    struct WMBssDesc *ap_list;
    unsigned long apci_search_option;
    int gAtermThreadId;
    int event_set_ptr;
    int event_get_ptr;
    int gMaxApList;
    int bInitAtermApNetwork;
    int gAtermApResult;
    void (*gAtermNotify)(struct _ATERMApConfigState *);
    void (*apci_user_callback)();
};
#endif

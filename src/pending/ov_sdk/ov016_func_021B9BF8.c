/*
 * function: ScanAP
 * address:  0x021B9BF8
 * packet:   pkt_ov016_021B9BF8
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * sdk:      ScanAP (libdwcutil.TWL.HYB.a(atermset.o))
 *
 * blocker: codegen on the frame/loop shape, no external evidence missing.
 *          atermset.o's .comment is Metrowerks C/C++ for ARM 3.0.0.126; the
 *          bundled ../2.0/sp1p2 front end writes that stamp and this object
 *          compiles under it (sibling AutoConfigThread 0x021BABE8 in this
 *          same object is EXACT with --cc ../2.0/sp1p2), so this function is
 *          NOT provenance-blocked, only hard.  This body is a genuine
 *          reconstruction from the object DWARF + full disassembly: it
 *          compiles 616 bytes vs the original 660, and bytes 0x00..0xE4
 *          already follow the original instruction-for-instruction with only
 *          a uniform -4 stack-slot shift (original frame sub sp,#0x70 with
 *          pOldList at fb+8; this source wants sub sp,#0x68 with pOldList at
 *          fb+4, i.e. one 4-byte stack temp short).  From 0xE4 the case-5
 *          body and the loop/branch layout diverge.  Next pass: recover the
 *          source that reserves the extra outgoing/8-byte arg slot and the
 *          original while-loop inversion; the switch table itself is already
 *          reproduced.
 *
 * stack map recovered from the listing (original):
 *   fb+0 out arg, fb+4 copy-loop pointer temp, fb+8 pOldList, fb+0xc
 *   pBssList, fb+0x10 BssListSize, fb+0x14 n, fb+0x18 i, fb+0x1c retry,
 *   fb+0x20 ApNo, fb+0x24 OSiAlarm alarm (44 B), fb+0x50 apBSSID[32].
 *
 * switch (AtermApc_GetEvent()) targets, read from the halfword table at
 * 0x021B9CA8: {1,2,3,6,7,9,0xB..0x11}->0x021B9CFE loop_flag=0;
 * 0xA->0x021B9CFA; 0x13->0x021B9CD0; 4,8,0x12->0x021B9D00 (no-op);
 * 5->0x021B9CD4 (APC_GetAPList refresh); 0 handled before the switch.
 *
 * symbols:
 *   Calloc                         0x021BC5A0  thumb
 *   GetTickCount                   0x021BC584  thumb
 *   APC_SearchStart                0x021B93F0  thumb
 *   OS_CreateAlarm                 0x02087254  arm
 *   OS_SetAlarm                    0x0208738C  arm
 *   OS_Sleep                       0x02085A38  arm
 *   AtermApc_GetEvent              0x021B9734  thumb
 *   APC_GetAPList                  0x021B93AC  thumb
 *   OS_CancelAlarm                 0x020873F8  arm
 *   memcpy                         0x02092344  arm
 *   CheckAccessPoint               0x021B9A2C  thumb
 *   strcpy                         0x02094798  arm
 *   PutMac                         0x021BC608  thumb
 *   SendNotify                     0x021BC804  thumb
 *   Free                           0x021BC5C4  thumb
 *   alarmCallback                  0x021B979C  thumb
 *   btAutoResult                   0x021DCFD0  data
 *   lpElementData                  0x021DAB58  data
 *   gAPSSID                        0x021DD4E0  data
 *   gAPMac                         0x021DD480  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    void (*handler)(void *);
    void *arg;
    u32 tag;
    unsigned long long fire;
    void *prev;
    void *next;
    unsigned long long period;
    unsigned long long start;
} OSiAlarm;

typedef struct {
    u32 length;
    u8 ssid[32];
    u8 pad04[4];
    u8 MacAddress[6];
    u16 Privacy;
} _WLAN_BSSID;

typedef struct {
    u32 NumberOfItems;
    _WLAN_BSSID Bssid[1];
} _BSSID_LIST;

typedef struct {
    u16 length;
    u16 rssi;
    u8 bssid[6];
    u16 ssidLength;
    u8 ssid[32];
    u16 capaInfo;
    u8 rest[192 - 0x2e];
} WMBssDesc;

typedef struct {
    u8 btAutoResult;
    void *gAtermAlloc;
    void *apci_IWConfig;
    void *gAtermFree;
    int bAtermApCanceled;
    int cbFrameData;
    int gAPId;
    int AutoPhase;
    int bApConnect;
    int bSO_Startup;
    u8 *apci_Wep;
    int apci_state;
    void *gThreadStack;
    int cbElementData;
    int gAtermApState;
    u8 *apci_IWBuffer;
    u8 *apc_work;
    u8 *apci_bssid_ptr;
    u8 *apci_essid_ptr;
    WMBssDesc *apci_wmbssdesc;
    int bDualCfg;
    u8 *atermapc_work;
    u32 apci_connect_option;
    WMBssDesc *ap_list;
    u32 apci_search_option;
    int gAtermThreadId;
    int event_set_ptr;
    int event_get_ptr;
    int gMaxApList;
    int bInitAtermApNetwork;
    int gAtermApResult;
    void (*gAtermNotify)(void *);
} ATERMSET_BSS;

typedef struct {
    u8 *lpElementData;
    int bDebug;
    u32 gThreadStackSize;
    u32 gAtermApTimeout;
    int gMaxBssIdList;
} ATERMSET_DATA;

extern ATERMSET_BSS atermset_bss;
extern ATERMSET_DATA atermset_data;

extern void *Calloc(u32 nmemb, u32 size);
extern u32 GetTickCount(void);
extern int APC_SearchStart(u8 *bssid, u8 *essid, int essid_len, u32 option);
extern void OS_CreateAlarm(OSiAlarm *alarm);
extern void OS_SetAlarm(OSiAlarm *alarm, unsigned long long tick,
                        void (*handler)(void *), void *arg);
extern void OS_Sleep(u32 msec);
extern int AtermApc_GetEvent(void);
extern int APC_GetAPList(WMBssDesc *buf, int list_max);
extern void OS_CancelAlarm(OSiAlarm *alarm);
extern void memcpy(void *dst, const void *src, u32 len);
extern int CheckAccessPoint(_BSSID_LIST *pNewList, _BSSID_LIST *pOldList, u32 *ApNo);
extern void strcpy(char *dst, const char *src);
extern int PutMac(char *lpwrite, char *lps);
extern void SendNotify(void);
extern void Free(void *ptr);
extern void alarmCallback(void *event);

extern u8 gAPSSID[34];
extern u8 gAPMac[6];

int ScanAP(void)
{
    char apBSSID[32];
    OSiAlarm alarm;
    u32 ApNo;
    int retry;
    int i;
    int n;
    u32 BssListSize;
    _BSSID_LIST *pBssList;
    _BSSID_LIST *pOldList;
    int nfound;
    WMBssDesc *wmbssdesc;
    _WLAN_BSSID *pBssid;
    int ap_count;
    int loop_flag;
    int retv;

    retv = -1;
    pOldList = 0;
    ApNo = 0;
    ap_count = 0;
    BssListSize = atermset_bss.gMaxApList * 0x30 + 0x34;
    pBssList = Calloc(1, BssListSize);
    if (pBssList == 0)
        goto cleanup;
    pOldList = Calloc(1, BssListSize);
    if (pOldList == 0)
        goto cleanup;

    retry = 0;
    while (retry < 30 && atermset_bss.bAtermApCanceled == 0) {
        int event;
        if (GetTickCount() >= atermset_data.gAtermApTimeout)
            break;
        if (APC_SearchStart(0, 0, 0, 0x30bffe) == 0) {
            retv = -2;
            goto cleanup;
        }
        OS_CreateAlarm(&alarm);
        OS_SetAlarm(&alarm, 0xffb10, alarmCallback, (void *)0x13);
        loop_flag = 1;
        ap_count = 0;
        for (;;) {
            OS_Sleep(10);
            if (GetTickCount() >= atermset_data.gAtermApTimeout)
                break;
            if (atermset_bss.bAtermApCanceled != 0)
                break;
            event = AtermApc_GetEvent();
            if (event == 0)
                goto check_flag;
            for (;;) {
                if (event > 0x13) {
                    loop_flag = 0;
                } else {
                    switch (event) {
                    case 1: case 2: case 3: case 6: case 7: case 9:
                    case 0x0b: case 0x0c: case 0x0d: case 0x0e:
                    case 0x0f: case 0x10: case 0x11:
                    case 0x0a:
                    case 0x13:
                        loop_flag = 0;
                        break;
                    case 5:
                        n = APC_GetAPList(atermset_bss.ap_list,
                                          atermset_bss.gMaxApList);
                        if (n > ap_count) {
                            ap_count = n;
                            OS_CancelAlarm(&alarm);
                            OS_SetAlarm(&alarm, 0xffb10, alarmCallback, (void *)0x13);
                        }
                        break;
                    case 4: case 8: case 0x12:
                        break;
                    }
                }
                event = AtermApc_GetEvent();
                if (event == 0)
                    break;
            }
        check_flag:
            if (loop_flag != 0)
                continue;
            break;
        }
        OS_CancelAlarm(&alarm);
        while (AtermApc_GetEvent() != 0)
            ;
        if (atermset_bss.bAtermApCanceled != 0)
            goto end;
        n = 0;
        if (ap_count >= atermset_bss.gMaxApList) {
            retv = n - 6;
            goto cleanup;
        }
        i = n;
        wmbssdesc = atermset_bss.ap_list;
        for (; i < ap_count; i++) {
            int k;
            memcpy(pBssList->Bssid[i].ssid, wmbssdesc->ssid, 32);
            pBssList->Bssid[i].length = wmbssdesc->ssidLength;
            pBssList->Bssid[i].ssid[wmbssdesc->ssidLength] = 0;
            pBssList->Bssid[i].Privacy = (wmbssdesc->capaInfo & 0x10) ? 1 : 0;
            for (k = 0; k < 6; k++)
                pBssList->Bssid[i].MacAddress[k] = wmbssdesc->bssid[k];
            wmbssdesc++;
            n++;
        }
        pBssList->NumberOfItems = ap_count;
        if (atermset_bss.gAtermApState == 1)
            goto update;
        if (CheckAccessPoint(pBssList, pOldList, &ApNo) == 0)
            goto update;
        pBssid = &pBssList->Bssid[ApNo];
        atermset_bss.gAPId = ApNo;
        strcpy((char *)gAPSSID, (char *)pBssid + 4);
        {
            int k;
            for (k = 0; k < 6; k++)
                gAPMac[k] = pBssid->MacAddress[k];
        }
        PutMac(apBSSID, (char *)gAPMac);
        goto end;
    update:
        memcpy(pOldList, pBssList, BssListSize);
        atermset_bss.gAtermApState = 2;
        SendNotify();
        retry++;
    }

end:
    if (retry < 30 && GetTickCount() <= atermset_data.gAtermApTimeout) {
        if (atermset_bss.bAtermApCanceled != 0) {
            retv = -8;
            goto cleanup;
        }
        retv = 1;
        goto cleanup;
    }
    retv = -3;
cleanup:
    if (pBssList != 0)
        Free(pBssList);
    if (pOldList != 0)
        Free(pOldList);
    return retv;
}

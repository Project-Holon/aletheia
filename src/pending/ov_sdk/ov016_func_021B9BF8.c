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
 * blocker:  lattice reconstructed (the 20-entry event switch with cases 0..19,
 *           BssListSize as one expression, retv = -1 first, i = 0 after
 *           wmbssdesc = ap_list, the 6-byte MAC struct copy); it now reaches
 *           652 of 660 bytes and 187 diff lines, up from the older parked body's
 *           616 of 660 and 268 lines.  Frame (sub sp,#0x70) and every switch
 *           slot match.  Two residues, probably one cause:
 *           (1) the loop tail: the image increments retry through its stack slot
 *           and re-reads it for the bound test (ldr/adds/str/ldr/cmp), this
 *           front end keeps retry in a register, which is the missing 8 bytes
 *           and also moves the two break branches that chain onto the
 *           canceled-check in the image.
 *           (2) the found block's copy into gAPMac: the image computes
 *           pBssid+0x28 twice (byte 0 through one register, bytes 1..5 through a
 *           copy held in another with [r0,#k]); a loop unrolled by the front end
 *           kills n and moves (1) with it.
 *           Full residue in docs/notes/lane_t17_ov016_rows26_33.md.
 *
 * symbols:
 *   atermset_bss                   0x021DCFD0  data
 *   atermset_data                  0x021DAB58  data
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
    u8 mac[6];
} MACADDR;

typedef struct {
    void (*handler)(void *);
    void *arg;
    u32 tag;
    unsigned long long fire;
    void *prev;
    void *next;
    unsigned long long period;
    unsigned long long start;
} OSAlarm;

typedef struct {
    u32 SsidLength;
    u8 Ssid[32];
    u8 pad04[4];
} _NDIS_802_11_SSID;

typedef struct {
    _NDIS_802_11_SSID Ssid;
    u8 MacAddress[6];
    u16 Privacy;
} WLAN_BSSID;

typedef struct {
    u32 NumberOfItems;
    WLAN_BSSID Bssid[1];
} BSSID_LIST;

typedef struct {
    u16 length;
    u16 rssi;
    u8 bssid[6];
    u16 ssidLength;
    u8 ssid[32];
    u16 capainfo;
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
extern void OS_CreateAlarm(OSAlarm *alarm);
extern void OS_SetAlarm(OSAlarm *alarm, unsigned long long tick,
                        void (*handler)(void *), void *arg);
extern void OS_Sleep(u32 msec);
extern int AtermApc_GetEvent(void);
extern int APC_GetAPList(WMBssDesc *buf, int list_max);
extern void OS_CancelAlarm(OSAlarm *alarm);
extern void memcpy(void *dst, const void *src, u32 len);
extern int CheckAccessPoint(BSSID_LIST *pNewList, BSSID_LIST *pOldList, u32 *ApNo);
extern void strcpy(char *dst, const char *src);
extern int PutMac(char *lpwrite, char *lps);
extern void SendNotify(void);
extern void Free(void *ptr);
extern void alarmCallback(void *event);

extern u8 gAPSSID[34];
extern u8 gAPMac[6];

int ScanAP(void)
{
    int retv;
    int retry;
    int i;
    int n;
    unsigned long ApNo;
    unsigned long BssListSize;
    BSSID_LIST *pBssList;
    BSSID_LIST *pOldList;
    WLAN_BSSID *pBssid;
    char apBSSID[32];
    int loop_flag;
    OSAlarm alarm;
    int ap_count;
    int nfound;
    WMBssDesc *wmbssdesc;

    retv = -1;
    pOldList = 0;
    ApNo = 0;
    BssListSize = sizeof(BSSID_LIST) + atermset_bss.gMaxApList * sizeof(WLAN_BSSID);
    pBssList = Calloc(1, BssListSize);
    if (pBssList == 0)
        goto end;
    pOldList = Calloc(1, BssListSize);
    if (pOldList == 0)
        goto end;
    for (retry = 0; retry < 30 && !atermset_bss.bAtermApCanceled; retry++) {
        if (GetTickCount() >= atermset_data.gAtermApTimeout)
            break;
        if (APC_SearchStart(0, 0, 0, 0x30BFFE) == 0) {
            retv = -2;
            goto end;
        }
        OS_CreateAlarm(&alarm);
        OS_SetAlarm(&alarm, 0xFFB10, alarmCallback, (void *)0x13);
        loop_flag = 1;
        ap_count = 0;
        while (loop_flag) {
            OS_Sleep(10);
            if (GetTickCount() >= atermset_data.gAtermApTimeout)
                break;
            if (atermset_bss.bAtermApCanceled)
                break;
            while ((nfound = AtermApc_GetEvent()) != 0) {
                switch (nfound) {
                case 4:
                case 8:
                case 18:
                    break;
                case 19:
                    loop_flag = 0;
                    break;
                case 5:
                    nfound = APC_GetAPList(atermset_bss.ap_list, atermset_bss.gMaxApList);
                    if (nfound > ap_count) {
                        ap_count = nfound;
                        OS_CancelAlarm(&alarm);
                        OS_SetAlarm(&alarm, 0xFFB10, alarmCallback, (void *)0x13);
                    }
                    break;
                case 10:
                    loop_flag = 0;
                    break;
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
                    loop_flag = 0;
                    break;
                }
            }
        }
        OS_CancelAlarm(&alarm);
        while (AtermApc_GetEvent() != 0)
            ;
        if (atermset_bss.bAtermApCanceled)
            break;
        n = 0;
        if (ap_count >= atermset_bss.gMaxApList) {
            retv = -6;
            goto end;
        }
        wmbssdesc = atermset_bss.ap_list;
        i = 0;
        if (ap_count > 0) {
            for (; i < ap_count; i++) {
                memcpy(pBssList->Bssid[n].Ssid.Ssid, wmbssdesc->ssid, 32);
                pBssList->Bssid[n].Ssid.SsidLength = wmbssdesc->ssidLength;
                pBssList->Bssid[n].Ssid.Ssid[wmbssdesc->ssidLength] = 0;
                pBssList->Bssid[n].Privacy = (wmbssdesc->capainfo & 0x10) ? 1 : 0;
                *(MACADDR *)pBssList->Bssid[n].MacAddress = *(MACADDR *)wmbssdesc->bssid;
                wmbssdesc++;
                n++;
            }
        }
        pBssList->NumberOfItems = ap_count;
        if (atermset_bss.gAtermApState != 1 && CheckAccessPoint(pBssList, pOldList, &ApNo)) {
            pBssid = &pBssList->Bssid[ApNo];
            atermset_bss.gAPId = ApNo;
            strcpy((char *)gAPSSID, (char *)pBssid->Ssid.Ssid);
            for (n = 0; n < 6; n++)
                gAPMac[n] = pBssid->MacAddress[n];
            PutMac(apBSSID, (char *)gAPMac);
            break;
        }
        memcpy(pOldList, pBssList, BssListSize);
        atermset_bss.gAtermApState = 2;
        SendNotify();
    }
    if (retry >= 30 || GetTickCount() > atermset_data.gAtermApTimeout)
        retv = -3;
    else if (atermset_bss.bAtermApCanceled)
        retv = -8;
    else
        retv = 1;
end:
    if (pBssList)
        Free(pBssList);
    if (pOldList)
        Free(pOldList);
    return retv;
}

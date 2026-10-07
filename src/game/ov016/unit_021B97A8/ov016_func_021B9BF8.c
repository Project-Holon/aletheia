/*
 * function: ScanAP
 * address:  0x021B9BF8
 * packet:   pkt_ov016_021B9BF8
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p -ipa file
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note 2026-10-01 (w3 lane07): locals now in DWARF declaration order
 *           (retv, retry, i, n, ApNo, ...); `volatile` on retry is not needed,
 *           same 652/660, 355 concrete.  Real residue is one cause: the vendor
 *           object keeps the dead induction variable n (n = 0, n++ stores at
 *           [sp,#0x14], VN loads for i = n and retv = n - 6) although nothing
 *           reads it after the first loop, and the gAPMac copy is a base held
 *           in a register: `{u8 *mac = pBssid->MacAddress; gAPMac[0] = mac[0];
 *           ... gAPMac[5] = mac[5];}`.  That copy alone makes this front end
 *           delete n (frame 0x6c); any zero-code use of n is folded away.  With
 *           `#pragma opt_dead_assignments off` that body is EXACT 660/660, but
 *           the same pragma breaks 4 of 52 matched atermset.o siblings
 *           (Encode 021BC4D4, 021BA3F4, 021BAC20, 021BADD8), so it is not the
 *           object's build setting; not applied.  Pragma-free alternative with a
 *           store use of n (`ApNo = n;` after the copy) is 664/660, 157 concrete.
 *
 * note 2026-10-01 (w4): vendor .debug_line + DWARF decl lines: `int i, n;` on
 *           one line (512), n = 0 at 618, n++ alone at 634 (last loop stmt),
 *           i init/guard/wmbssdesc++/i++/test all on the for line 627, found-
 *           block copy is one line (643).  `memcpy(gAPMac, pBssid->MacAddress,
 *           6)` through house string.h (intrinsic) gives the image's copy shape
 *           exactly; with the pragma that body is EXACT too.  sp1p2 stamps
 *           3.0.0.126 = vendor stamp, and base..sp2p4 all drop n, so it is
 *           source.  Measured inert (n still deleted, 652): (void)n, (void)&n,
 *           dead pointer to n, dead local t = n, empty inline taking n,
 *           if/switch/goto/while/do on n, if (0) call(n), empty counting loop
 *           bounded by n, i = n, MAC via pBssid = &Bssid[n] or pNew pointer,
 *           for-header forms, 60 unused locals, function 400 calls bigger,
 *           -g; 13 other opt_ pragmas (only opt_dead_assignments keeps n).
 *           Every use that keeps n costs code (>= 664).  Open.
 *
 * note 2026-10-01 (w4 restart): the Debug build of the same archive
 *           (sdk/TwlDWC/lib/ARM9-TS/Debug, atermset.o, same 3.0.0.126 stamp,
 *           same line numbers) shows every statement: no `if (ap_count > 0)`
 *           (the loop is `for (i = 0, wmbssdesc = ap_list; i < ap_count;
 *           i++, wmbssdesc++)` on line 627), MAC copies are memcpy(.., 6),
 *           and line 632 is OS_Printf(fmt, i + 1, Bssid[n].Ssid.Ssid,
 *           Bssid[n].Privacy) which FINALROM removes.  This body is that
 *           source.  It is EXACT 660/660 with `flags: -O4,p -ipa file` (both
 *           the doubled ble and the kept dead n come from file-level IPA);
 *           the fully literal Debug text (ret, buflen, event, retv = -8,
 *           OS_Printf as ((void)0)) is EXACT with it too.  Under the pinned
 *           -O4,p it is 648, n deleted (the old if-guard draft was 652).
 *           Sibling check with -ipa file: all 55 matched atermset.o rows stay
 *           EXACT/EXACT* (statics need a reference to survive -ipa file in a
 *           one-function TU) except AutoConfigThreadEx 021BA804, whose
 *           invented `if (bAtermApCanceled) break;` stand-in must become the
 *           Debug text `else { if (DAT.bDebug) OS_Printf(..); }` (then EXACT).
 *           Not applied: flags are pinned; needs an object-level decision.
 *
 * Build setting: atermset.o was built with `-O4,p -ipa file` (file-level IPA). Evidence
 *   (2026-10-01, user-approved): the Debug/Release libdwcutil archives give ScanAP's and
 *   AutoConfigThreadEx's literal statements (debug OS_Printf calls compile to nothing in Rom);
 *   with -ipa file both are EXACT, plain -O4,p is not; all 55 other matched atermset.o
 *   functions stay EXACT under -ipa file (statics tested with an address-taking reference).
 *   Only these two files carry the flag; the rest stay on -O4,p and match both ways.
 *
 * sdk:      ScanAP (libdwcutil.TWL.HYB.a(atermset.o))
 *
 * blocker:  pinned -O4,p deletes the dead counter n (648 of 660); the object
 *           was built with -ipa file (see the w4 restart note).
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

#include "../../../matched/arm9_sdk/libc/string.h"
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
extern int CheckAccessPoint(BSSID_LIST *pNewList, BSSID_LIST *pOldList, u32 *ApNo);
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
    int i, n;
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
        for (i = 0, wmbssdesc = atermset_bss.ap_list; i < ap_count; i++, wmbssdesc++) {
            memcpy(pBssList->Bssid[n].Ssid.Ssid, wmbssdesc->ssid, 32);
            pBssList->Bssid[n].Ssid.SsidLength = wmbssdesc->ssidLength;
            pBssList->Bssid[n].Ssid.Ssid[wmbssdesc->ssidLength] = 0;
            pBssList->Bssid[n].Privacy = (wmbssdesc->capainfo & 0x10) ? 1 : 0;
            memcpy(pBssList->Bssid[n].MacAddress, wmbssdesc->bssid, 6);
            n++;
        }
        pBssList->NumberOfItems = ap_count;
        if (atermset_bss.gAtermApState != 1 && CheckAccessPoint(pBssList, pOldList, &ApNo)) {
            pBssid = &pBssList->Bssid[ApNo];
            atermset_bss.gAPId = ApNo;
            strcpy((char *)gAPSSID, (char *)pBssid->Ssid.Ssid);
            memcpy(gAPMac, pBssid->MacAddress, 6);
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

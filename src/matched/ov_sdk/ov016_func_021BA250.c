/*
 * function: SetSearchRes
 * address:  0x021BA250
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   atermset_data    0x021DAB58  data
 *   atermset_bss     0x021DCFD0  data
 *   SetElementData   0x021BA0A4  thumb
 *   SetFrameData     0x021B9FE0  thumb
 *   atermset_rodata  0x021D77C8  data
 *   btAdapterMAC     0x021DD478  data
 *   ElementData      0x021DD504  data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol SetSearchRes (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * SupportEnc's initialiser is the compiler's @9007 at the head of atermset.o's .rodata
 * (0x021D77C8), declared as atermset_rodata and copied, as for aoss_rodata in AOSS_Init_old.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BA250.c \
 *       --func SetSearchRes --addr 0x021BA250 --region ov016 --cc ../2.0/sp1p2 --thumb
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

typedef struct {
    unsigned char b[7];
} SUPPORTENC;

extern const SUPPORTENC atermset_rodata;
extern unsigned char btAdapterMAC[6];
extern unsigned char ElementData[2048];
extern unsigned char *SetElementData(unsigned char *lpb, int eid, unsigned char *pele, int esize);
extern int SetFrameData(unsigned char *lpframe, int id, unsigned char *pbody, int size, unsigned char *lpkey);

int SetSearchRes(unsigned char *lpframe)
{
    unsigned char *lpb;
    unsigned short wd;
    SUPPORTENC SupportEnc;

    wd = 0x100;
    SupportEnc = atermset_rodata;
    lpb = SetElementData(atermset_data.lpElementData, 1, (unsigned char *)&wd, 2);
    lpb = SetElementData(lpb, 2, (unsigned char *)&wd, 2);
    if (atermset_bss.bDualCfg)
        lpb = SetElementData(lpb, 5, (unsigned char *)&wd, 2);
    lpb = SetElementData(lpb, 3, SupportEnc.b, 7);
    if (atermset_bss.bDualCfg)
        lpb = SetElementData(lpb, 4, btAdapterMAC, 6);
    return SetFrameData(lpframe, 2, ElementData, (lpb - atermset_data.lpElementData) + 8, 0);
}

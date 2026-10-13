/*
 * function: WCMi_EntryApList
 * address:  0x02165D04
 * packet:   pkt_ov009_02165D04
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_EntryApList (aplist.o)
 *
 * symbols:
 *   WCMi_GetSystemWork  0x021657C8  arm  ov009
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   WCMi_GetGameInfo  0x021661F0  arm  ov009
 *   func_02165EC8  0x02165EC8  arm  ov009
 *   WcmAllocApList  0x02165DCC  arm  ov009
 *   func_02165E98  0x02165E98  arm  ov009
 *   WCMi_BssDescCopy  0x02166040  arm  ov009
 *   WcmAppendApList  0x02165F88  arm  ov009
 */

struct WCMBssDesc {
    unsigned short length;
    unsigned short rssi;
    unsigned char bssid[6];
    unsigned char pad[0x32];
    unsigned short gameInfoLength;
};
struct WCMApList {
    unsigned char state;
    unsigned char reserved;
    unsigned short linkLevel;
    unsigned long index;
    struct WCMApList *previous;
    struct WCMApList *next;
    unsigned long data[48];
};
struct WCMWork {
    char pad[0x12c0];
    struct {
        unsigned long dmano;
        void *pbdbuffer;
        unsigned long nbdbuffer;
        unsigned long nbdmode;
    } config;
    char pad2[0xc];
    unsigned char apListLock;
    unsigned char resetting;
    unsigned char phase;
    unsigned char deviceId;
};
extern int WCMi_GetSystemWork(void);
extern int OS_IsRunOnTwl(void);
struct WMGameInfo;
extern struct WMGameInfo *WCMi_GetGameInfo(struct WCMBssDesc *bssDesc);
extern struct WCMApList *func_02165EC8(unsigned char *bssid);
extern struct WCMApList *WcmAllocApList(void);
extern struct WCMApList *func_02165E98(void);
extern void WCMi_BssDescCopy(struct WCMBssDesc *src, struct WCMBssDesc *dest);
extern void WcmAppendApList(struct WCMApList *aplist);

void WCMi_EntryApList(struct WCMBssDesc *bssDesc, unsigned short linkLevel)
{
    struct WCMApList *aplist;
    struct WCMWork *w;

    w = (struct WCMWork *)WCMi_GetSystemWork();
    if (w == 0)
        return;
    if (w->apListLock)
        return;
    if (OS_IsRunOnTwl() && w->deviceId == 2) {
        if (WCMi_GetGameInfo(bssDesc))
            return;
    }
    if (w->deviceId == 1 && bssDesc->gameInfoLength != 0)
        return;

    aplist = func_02165EC8(bssDesc->bssid);
    if (aplist == 0)
        aplist = WcmAllocApList();
    if (aplist == 0 && w->config.nbdmode == 1)
        aplist = func_02165E98();
    if (aplist == 0)
        return;
    WCMi_BssDescCopy(bssDesc, (struct WCMBssDesc *)aplist->data);
    aplist->linkLevel = linkLevel;
    WcmAppendApList(aplist);
}

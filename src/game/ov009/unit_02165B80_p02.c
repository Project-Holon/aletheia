/*
 * file:     unit_02165B80_p02.c
 * unit:     yes
 * function: WCM_PointApListEx, func_02165D04, func_02165DCC
 * address:  0x02165CAC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_DisableInterrupts      0x02087988  arm
 *   WCMi_GetSystemWork        0x021657C8  arm
 *   OS_RestoreInterrupts      0x0208799C  arm
 *   WcmSearchIndexedApList    0x02165F34  arm
 *   func_021657C8  0x021657C8  arm  ov009
 *   func_02085D3C  0x02085D3C  arm
 *   func_021661F0  0x021661F0  arm  ov009
 *   func_02165EC8  0x02165EC8  arm  ov009
 *   func_02165E98  0x02165E98  arm  ov009
 *   func_02166040  0x02166040  arm  ov009
 *   func_02165F88  0x02165F88  arm  ov009
 */
struct WMGameInfo;
struct WCMBssDesc_02165CAC {
    unsigned short length;
    unsigned short rssi;
    unsigned char  bssid[6];
};

struct WCMApList_02165CAC {
    unsigned long       field0;
    unsigned long       index;
    unsigned long       field8;
    struct WCMApList_02165CAC   *next;
    struct WCMBssDesc_02165CAC   bssDesc;
};

struct WCMApListHeader_02165CAC {
    unsigned long      count;
    struct WCMApList_02165CAC  *head;
    unsigned long      field8;
};

struct WCMWork {
    unsigned char pad0[0x12C4];
    struct WCMApListHeader_02165CAC *pHeader;
    unsigned long           apListSize;
    unsigned char           pad1[0x10];
    unsigned char           lockFlag;
};

struct WCMBssDesc_02165B80 {
    unsigned short length;
    unsigned short rssi;
    unsigned char bssid[6];
    unsigned char pad[0x32];
    unsigned short gameInfoLength;
};

struct WCMApList_02165B80 {
    unsigned char state;
    unsigned char reserved;
    unsigned short linkLevel;
    unsigned long index;
    struct WCMApList_02165B80 *previous;
    struct WCMApList_02165B80 *next;
    unsigned long data[48];
};

struct WCMWork_02165D04 {
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

struct WCMApListHeader_02165B80 {
    unsigned long count;
    struct WCMApList_02165B80 *head;
    struct WCMApList_02165B80 *tail;
};

struct WCMWork_02165DCC {
    char pad[0x12c0];
    struct {
        unsigned long dmano;
        void *pbdbuffer;
        unsigned long nbdbuffer;
        unsigned long nbdmode;
    } config;
};

extern unsigned long OS_DisableInterrupts(void);
extern struct WCMWork *WCMi_GetSystemWork(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern struct WCMApList_02165CAC *WcmSearchIndexedApList(unsigned long index);
extern int func_021657C8(void);
extern int func_02085D3C(void);
extern struct WMGameInfo *func_021661F0(struct WCMBssDesc_02165B80 *bssDesc);
extern struct WCMApList_02165B80 *func_02165EC8(unsigned char *bssid);
extern struct WCMApList_02165B80 *func_02165E98(void);
extern void func_02166040(struct WCMBssDesc_02165B80 *src, struct WCMBssDesc_02165B80 *dest);
extern void func_02165F88(struct WCMApList_02165B80 *aplist);
void func_02165D04(struct WCMBssDesc_02165B80 *bssDesc, unsigned short linkLevel);
struct WCMApList_02165B80 *func_02165DCC(void);
struct WCMBssDesc_02165CAC *WCM_PointApListEx(long index);


struct WCMBssDesc_02165CAC *WCM_PointApListEx(long index)
{
    struct WCMWork *w;
    unsigned long e;
    struct WCMApList_02165CAC *p;

    e = OS_DisableInterrupts();
    w = WCMi_GetSystemWork();
    if (w == 0) {
        OS_RestoreInterrupts(e);
        return 0;
    }
    p = WcmSearchIndexedApList(index);
    if (p == 0) {
        OS_RestoreInterrupts(e);
        return 0;
    }
    OS_RestoreInterrupts(e);
    return &p->bssDesc;
}



/*
 * sdk:      WCMi_EntryApList (aplist.o)
 */
void func_02165D04(struct WCMBssDesc_02165B80 *bssDesc, unsigned short linkLevel)
{
    struct WCMApList_02165B80 *aplist;
    struct WCMWork_02165D04 *w;

    w = (struct WCMWork_02165D04 *)func_021657C8();
    if (w == 0)
        return;
    if (w->apListLock)
        return;
    if (func_02085D3C() && w->deviceId == 2) {
        if (func_021661F0(bssDesc))
            return;
    }
    if (w->deviceId == 1 && bssDesc->gameInfoLength != 0)
        return;

    aplist = func_02165EC8(bssDesc->bssid);
    if (aplist == 0)
        aplist = func_02165DCC();
    if (aplist == 0 && w->config.nbdmode == 1)
        aplist = func_02165E98();
    if (aplist == 0)
        return;
    func_02166040(bssDesc, (struct WCMBssDesc_02165B80 *)aplist->data);
    aplist->linkLevel = linkLevel;
    func_02165F88(aplist);
}


/*
 * sdk:      WcmAllocApList (aplist.o)
 */
struct WCMApList_02165B80 *func_02165DCC(void)
{
    unsigned long maxBlock;
    long i;
    struct WCMApList_02165B80 *pList;
    struct WCMApList_02165B80 *p;
    struct WCMApListHeader_02165B80 *pHeader;
    struct WCMWork_02165DCC *w;

    w = (struct WCMWork_02165DCC *)func_021657C8();
    pHeader = (struct WCMApListHeader_02165B80 *)w->config.pbdbuffer;
    p = 0;

    if (pHeader == 0)
        return 0;
    if (w->config.nbdbuffer <= sizeof(struct WCMApListHeader_02165B80))
        return 0;
    maxBlock = (w->config.nbdbuffer - sizeof(struct WCMApListHeader_02165B80)) / sizeof(struct WCMApList_02165B80);
    if (maxBlock == 0)
        return 0;
    if (maxBlock <= pHeader->count)
        return 0;

    i = 0;
    if (i < maxBlock) {
        pList = (struct WCMApList_02165B80 *)(pHeader + 1);
        do {
            p = pList + i;
            if (p->state == 0)
                break;
            i++;
        } while (i < maxBlock);
    }
    if (i < maxBlock) {
        p->state = 1;
        p->index = pHeader->count;
        p->next = 0;
        p->previous = pHeader->tail;
        pHeader->tail = p;
        if (p->previous)
            p->previous->next = p;
        else
            pHeader->head = p;
        pHeader->count++;
    }
    return p;
}

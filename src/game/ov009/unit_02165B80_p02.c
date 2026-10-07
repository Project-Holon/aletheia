/*
 * file:     unit_02165B80_p02.c
 * unit:     yes
 * function: func_02165D04, func_02165DCC
 * address:  0x02165D04
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
 *   func_021657C8  0x021657C8  arm  ov009
 *   func_02085D3C  0x02085D3C  arm
 *   func_021661F0  0x021661F0  arm  ov009
 *   func_02165EC8  0x02165EC8  arm  ov009
 *   func_02165E98  0x02165E98  arm  ov009
 *   func_02166040  0x02166040  arm  ov009
 *   func_02165F88  0x02165F88  arm  ov009
 */
struct WMGameInfo;
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

struct WCMApListHeader {
    unsigned long count;
    struct WCMApList *head;
    struct WCMApList *tail;
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

extern int func_021657C8(void);
extern int func_02085D3C(void);
extern struct WMGameInfo *func_021661F0(struct WCMBssDesc *bssDesc);
extern struct WCMApList *func_02165EC8(unsigned char *bssid);
extern struct WCMApList *func_02165E98(void);
extern void func_02166040(struct WCMBssDesc *src, struct WCMBssDesc *dest);
extern void func_02165F88(struct WCMApList *aplist);
void func_02165D04(struct WCMBssDesc *bssDesc, unsigned short linkLevel);
struct WCMApList *func_02165DCC(void);


/*
 * sdk:      WCMi_EntryApList (aplist.o)
 */
void func_02165D04(struct WCMBssDesc *bssDesc, unsigned short linkLevel)
{
    struct WCMApList *aplist;
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
    func_02166040(bssDesc, (struct WCMBssDesc *)aplist->data);
    aplist->linkLevel = linkLevel;
    func_02165F88(aplist);
}


/*
 * sdk:      WcmAllocApList (aplist.o)
 */
struct WCMApList *func_02165DCC(void)
{
    unsigned long maxBlock;
    long i;
    struct WCMApList *pList;
    struct WCMApList *p;
    struct WCMApListHeader *pHeader;
    struct WCMWork_02165DCC *w;

    w = (struct WCMWork_02165DCC *)func_021657C8();
    pHeader = (struct WCMApListHeader *)w->config.pbdbuffer;
    p = 0;

    if (pHeader == 0)
        return 0;
    if (w->config.nbdbuffer <= sizeof(struct WCMApListHeader))
        return 0;
    maxBlock = (w->config.nbdbuffer - sizeof(struct WCMApListHeader)) / sizeof(struct WCMApList);
    if (maxBlock == 0)
        return 0;
    if (maxBlock <= pHeader->count)
        return 0;

    i = 0;
    if (i < maxBlock) {
        pList = (struct WCMApList *)(pHeader + 1);
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

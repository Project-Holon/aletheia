/*
 * file:     unit_02165B80_p03.c
 * unit:     yes
 * function: WcmGetOldestApList, WcmSearchApList, WcmSearchIndexedApList, func_02165F88, func_02166040, func_021661F0
 * address:  0x02165E98
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   WCMi_GetSystemWork     0x021657C8  arm
 *   WCM_CompareBssID       0x021666B8  arm
 *   func_021657C8  0x021657C8  arm  ov009
 *   func_02082AC0  0x02082AC0  arm
 *   func_02082B0C  0x02082B0C  arm
 *   func_02082E74  0x02082E74  arm
 *   func_02082EA4  0x02082EA4  arm
 *   @12407  0x021A19B4  data
 *   @12409  0x021A19B8  data
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   func_02703250  0x02703250  arm  twl
 *   @12437         0x021A19B0  data
 */
struct WCMApList_02165E98;
struct WCMApListHeader_02165E98 {
    unsigned long      count;
    struct WCMApList_02165E98  *head;
    unsigned long      field8;
};

struct WCMWork {
    unsigned char pad0[0x12C4];
    struct WCMApListHeader_02165E98 *pHeader;
    unsigned long           apListSize;
    unsigned char           pad1[0x10];
    unsigned char           lockFlag;
};

struct WCMBssDesc {
    unsigned short length;
    unsigned short rssi;
    unsigned char  bssid[6];
};

struct WCMApList_02165E98 {
    unsigned long       field0;
    unsigned long       index;
    unsigned long       field8;
    struct WCMApList_02165E98   *next;
    struct WCMBssDesc   bssDesc;
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

struct WCMApListHeader_02165B80 {
    unsigned long count;
    struct WCMApList_02165B80 *head;
    struct WCMApList_02165B80 *tail;
};

struct WCMWork_02165F88 {
    char pad[0x12c0];
    struct {
        unsigned long dmano;
        void *pbdbuffer;
        unsigned long nbdbuffer;
        unsigned long nbdmode;
    } config;
};

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef struct WCMBssDesc_02166040 {
    u16 length;             /* +0x00 */
    u16 rssi;               /* +0x02 */
    u8 bssid[6];            /* +0x04 */
    u16 ssidLength;         /* +0x0a */
    u8 ssid[32];            /* +0x0c */
    u16 capaInfo;           /* +0x2c */
    u16 rateSet[2];         /* +0x2e */
    u16 beaconPeriod;       /* +0x32 */
    u16 dtimPeriod;         /* +0x34 */
    u16 channel;            /* +0x36 */
    u16 cfpPeriod;          /* +0x38 */
    u16 cfpMaxDuration;     /* +0x3a */
    u16 gameInfoLength;     /* +0x3c */
    u16 elementCount;       /* +0x3e */
    u16 elements[64];       /* +0x40 */
} WCMBssDesc_02166040;

typedef struct WCMWork_02166040 {
    char pad[0x12df];
    u8 deviceId;            /* +0x12df */
} WCMWork_02166040;

typedef struct WMGameInfo {
    unsigned short magicNumber;
    unsigned char ver;
    unsigned char platform;
    unsigned long ggid;
    unsigned short tgid;
    unsigned char userGameInfoLength;
    unsigned char attribute;
    unsigned short parentMaxSize;
    unsigned short childMaxSize;
    unsigned short userGameInfo[56];
} WMGameInfo;

typedef struct WCMBssDesc_021661F0 {
    unsigned short length;
    unsigned char pad0[0x3C - 2];
    unsigned short gameInfoLength;
    unsigned short elementCount;
    WMGameInfo gameInfo;
} WCMBssDesc_021661F0;

typedef struct NWMInfoElements {
    unsigned char id;
    unsigned char length;
    unsigned short element[1];
} NWMInfoElements;

typedef struct WCMWork_021661F0 {
    unsigned char pad0[0x12DF];
    unsigned char deviceId;
} WCMWork_021661F0;

extern struct WCMWork *WCMi_GetSystemWork(void);
extern int WCM_CompareBssID(unsigned char *a, unsigned char *b);
extern int func_021657C8(void);
extern void func_02082AC0(u32 data, void *destp, u32 size);
extern void func_02082B0C(const void *srcp, void *destp, u32 size);
extern int func_02082E74(const void *mem1, const void *mem2, u32 size);
extern void func_02082EA4(const void *srcp, void *destp, u32 size);
extern int OS_IsRunOnTwl(void);
extern NWMInfoElements *func_02703250();
void func_02165F88(struct WCMApList_02165B80 *aplist);
void func_02166040(WCMBssDesc_02166040 *srcBssDesc, WCMBssDesc_02166040 *destBssDesc);
WMGameInfo *func_021661F0(WCMBssDesc_021661F0 *bssDesc);




static struct WCMApList_02165E98 *WcmGetOldestApList(void)
{
    struct WCMWork *w;
    struct WCMApListHeader_02165E98 *pHeader;

    w = WCMi_GetSystemWork();
    pHeader = w->pHeader;
    if (pHeader != 0 && w->apListSize > 12)
        return pHeader->head;
    return 0;
}




static struct WCMApList_02165E98 *WcmSearchApList(unsigned char *bssid)
{
    struct WCMWork *w;
    struct WCMApListHeader_02165E98 *pHeader;
    struct WCMApList_02165E98 *p;

    w = WCMi_GetSystemWork();
    p = 0;
    pHeader = w->pHeader;
    if (bssid == 0)
        return p;
    if (pHeader != 0 && w->apListSize > 12) {
        p = pHeader->head;
        while (p != 0) {
            if (WCM_CompareBssID(p->bssDesc.bssid, bssid))
                break;
            p = p->next;
        }
    }
    return p;
}



static struct WCMApList_02165E98 *WcmSearchIndexedApList(unsigned long index)
{
    struct WCMWork *w;
    struct WCMApListHeader_02165E98 *pHeader;
    struct WCMApList_02165E98 *p;

    w = WCMi_GetSystemWork();
    p = 0;
    pHeader = w->pHeader;
    if (pHeader != 0 && w->apListSize > 12) {
        p = pHeader->head;
        while (p != 0) {
            if (p->index == index)
                break;
            p = p->next;
        }
    }
    return p;
}



/*
 * sdk:      WcmAppendApList (aplist.o)
 */
void func_02165F88(struct WCMApList_02165B80 *aplist)
{
    struct WCMWork_02165F88 *w = (struct WCMWork_02165F88 *)func_021657C8();
    struct WCMApListHeader_02165B80 *pHeader = (struct WCMApListHeader_02165B80 *)w->config.pbdbuffer;
    struct WCMApList_02165B80 *p;

    if (aplist == 0 || pHeader == 0)
        return;
    if (w->config.nbdbuffer <= sizeof(struct WCMApListHeader_02165B80))
        return;

    for (p = pHeader->head; p != 0; p = p->next) {
        if (p == aplist) {
            if (p->previous)
                p->previous->next = p->next;
            else
                pHeader->head = p->next;
            if (p->next)
                p->next->previous = p->previous;
            else
                pHeader->tail = p->previous;
            break;
        }
    }
    aplist->next = 0;
    aplist->previous = pHeader->tail;
    pHeader->tail = aplist;
    if (aplist->previous)
        aplist->previous->next = aplist;
    else
        pHeader->head = aplist;
    if (p == 0) {
        aplist->index = pHeader->count;
        pHeader->count++;
    }
}


/*
 * sdk:      WCMi_BssDescCopy (libwcm.TWL.HYB.a(aplist.o))
 *
 * wpaTag and wmmTag are initialized from their templates after the length store,
 * so they live in an inner block. The DWARF has both tags at function scope; this
 * compiler rejects a declaration after a statement. The TWL branch's final add
 * zero-extends ieLength through lsl/lsr, which (ieLength & 0xffff) reproduces.
 */
void func_02166040(WCMBssDesc_02166040 *srcBssDesc, WCMBssDesc_02166040 *destBssDesc)
{
    WCMWork_02166040 *w;
    u8 *pSrc;
    u8 *pDest;
    u8 ieLength;
    u16 i;
    u8 id;
    u8 len;

    w = (WCMWork_02166040 *)func_021657C8();
    func_02082AC0(0, destBssDesc, sizeof(WCMBssDesc_02166040));
    func_02082B0C(srcBssDesc, destBssDesc, 0x40);
    destBssDesc->elementCount = 0;
    if (w->deviceId == 1)
        destBssDesc->length = 0x20;
    else
        destBssDesc->length = 0x40;
    {
        u8 wpaTag[4] = { 0x00, 0x50, 0xf2, 0x01 };
        u8 wmmTag[5] = { 0x00, 0x50, 0xf2, 0x02, 0x00 };

        ieLength = 0;
        pSrc = (u8 *)srcBssDesc->elements;
        pDest = (u8 *)destBssDesc->elements;
        for (i = 0; i < srcBssDesc->elementCount; i++) {
            id = pSrc[0];
            len = pSrc[1];
            if (id == 0x32 || id == 0x2a || id == 0x2f || id == 0x07 || id == 0x30) {
                func_02082EA4(pSrc, pDest, (u8)(len + 2));
                pDest += len + 2;
                ieLength += (u8)(len + 2);
                destBssDesc->elementCount++;
            } else if (id == 0xdd) {
                if (func_02082E74(pSrc + 2, wpaTag, 4) == 0 || func_02082E74(pSrc + 2, wmmTag, 5) == 0) {
                    func_02082EA4(pSrc, pDest, (u8)(len + 2));
                    pDest += len + 2;
                    ieLength += (u8)(len + 2);
                    destBssDesc->elementCount++;
                }
            }
            pSrc += len + 2;
        }
    }
    if (w->deviceId == 1)
        destBssDesc->length += (u16)(ieLength & 0xffff);
    else
        destBssDesc->length += ieLength;
}


/*
 * sdk:      WCMi_GetGameInfo (libwcm.TWL.HYB.a aplist.o)
 *
 * Returns the WMGameInfo of a BSS descriptor: NWM vendor element path on TWL, validated inline gameInfo on DS. The tag initializer copies from the vendor template @12437 at 0x021A19B0 (template class, ov009 scope).
 */
WMGameInfo *func_021661F0(WCMBssDesc_021661F0 *bssDesc)
{
    WCMWork_021661F0 *w = (WCMWork_021661F0 *)func_021657C8();
    NWMInfoElements *elem;
    WMGameInfo *gameInfo;
    unsigned char tag[4] = { 0x00, 0x09, 0xBF, 0x00 };

    if (bssDesc == 0) return 0;
    if (OS_IsRunOnTwl()) {
        if (w->deviceId == 2) {
            elem = 0;
            if (bssDesc->elementCount != 0) {
                elem = func_02703250(bssDesc, 0xDD, tag);
            }
            if (elem != 0) {
                gameInfo = (WMGameInfo *)&elem->element[4];
                if (gameInfo->magicNumber == 1) return gameInfo;
            }
        }
    } else {
        if (w->deviceId == 1) {
            unsigned short len = bssDesc->gameInfoLength;
            if (len != 0) {
                int ok = 0;
                if (len >= 0x10 && len <= 0x80) {
                    if (len == bssDesc->gameInfo.userGameInfoLength + 0x10 && bssDesc->gameInfo.magicNumber == 1 && bssDesc->length == ((unsigned long)(len + 0x41) >> 1)) ok = 1;
                }
                if (ok == 1) return &bssDesc->gameInfo;
            }
        }
    }
    return 0;
}

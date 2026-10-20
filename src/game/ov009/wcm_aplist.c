/*
 * file:     wcm_aplist.c
 * unit:     yes
 * function: WCM_ClearApList, WCM_CountApList, WCM_LockApList, WCM_PointApList, WCM_PointApListEx, WCMi_EntryApList, WcmAllocApList, WcmGetOldestApList, WcmSearchApList, WcmSearchIndexedApList, WcmAppendApList, WCMi_BssDescCopy, WCMi_GetGameInfo
 * address:  0x02165B80
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
 *   OS_DisableInterrupts   0x02087988  arm
 *   WCMi_GetSystemWork     0x021657C8  arm
 *   OS_RestoreInterrupts   0x0208799C  arm
 *   MI_CpuFill8            0x02082BCC  arm
 *   WCM_PointApListEx  0x02165CAC  arm  ov009
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   WCM_CompareBssID       0x021666B8  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   MI_CpuComp8  0x02082E74  arm
 *   MI_CpuCopy  0x02082EA4  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   NWM_GetVenderInfoElements  0x02703250  arm  twl
 *   @12407  0x021A19B4  data
 *   @12409  0x021A19B8  data
 *   @12437         0x021A19B0  data
 */
#include "wcm_types.h"

#include "../types.h"

typedef struct NWMInfoElements {
    unsigned char id;
    unsigned char length;
    unsigned short element[1];
} NWMInfoElements;

typedef unsigned int OSIntrMode;
#include "../arm9/os_system.h"
#include "wcm_system.h"
#include "../arm9/mi_memory.h"
extern int WCM_CompareBssID(unsigned char *a, unsigned char *b);
#include "../arm9/os_emulator.h"
#include "../twl/nwm_startscan.h"
void WCM_ClearApList(void);
int WCM_CountApList(void);
int WCM_LockApList(int lock);
WMBssDesc *WCM_PointApList(unsigned short index);
WMBssDesc *WCM_PointApListEx(long index);
void WCMi_EntryApList(WMBssDesc *bssDesc, unsigned short linkLevel);
WCMApList *WcmAllocApList(void);
void WcmAppendApList(WCMApList *aplist);
void WCMi_BssDescCopy(WMBssDesc *srcBssDesc, WMBssDesc *destBssDesc);
WMGameInfo *WCMi_GetGameInfo(WMBssDesc *bssDesc);

void WCM_ClearApList(void)
{
    WCMWork *w;
    unsigned long e;

    e = OS_DisableInterrupts();
    w = WCMi_GetSystemWork();
    if (w == 0) {
        OS_RestoreInterrupts(e);
        return;
    }
    if (((WCMApListHeader *)w->config.pbdbuffer) != 0 && (long)w->config.nbdbuffer > 0)
        MI_CpuFill8(((WCMApListHeader *)w->config.pbdbuffer), 0, w->config.nbdbuffer);
    OS_RestoreInterrupts(e);
}

int WCM_CountApList(void)
{
    WCMWork *w;
    unsigned long e;
    long count;

    e = OS_DisableInterrupts();
    w = WCMi_GetSystemWork();
    count = 0;
    if (w == 0) {
        OS_RestoreInterrupts(e);
        return count;
    }
    if (((WCMApListHeader *)w->config.pbdbuffer) != 0 && (unsigned long)w->config.nbdbuffer > 12)
        count = ((WCMApListHeader *)w->config.pbdbuffer)->count;
    OS_RestoreInterrupts(e);
    return count;
}

int WCM_LockApList(int lock)
{
    WCMWork *w;
    unsigned long e;
    long ret;

    e = OS_DisableInterrupts();
    w = WCMi_GetSystemWork();
    if (w == 0) {
        OS_RestoreInterrupts(e);
        return 0;
    }
    if (lock) {
        ret = (w->apListLock == 0) ? 0 : 1;
        w->apListLock = 1;
    } else {
        ret = (w->apListLock == 0) ? 0 : 1;
        w->apListLock = 0;
    }
    OS_RestoreInterrupts(e);
    return ret;
}

WMBssDesc *WCM_PointApList(unsigned short index)
{
    return WCM_PointApListEx(index);
}

static WCMApList *WcmGetOldestApList(void);

static WCMApList *WcmSearchApList(unsigned char *bssid);

static WCMApList *WcmSearchIndexedApList(unsigned long index);

WMBssDesc *WCM_PointApListEx(long index)
{
    WCMWork *w;
    unsigned long e;
    WCMApList *p;

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
void WCMi_EntryApList(WMBssDesc *bssDesc, unsigned short linkLevel)
{
    WCMApList *aplist;
    WCMWork *w;

    w = WCMi_GetSystemWork();
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

    aplist = WcmSearchApList(bssDesc->bssid);
    if (aplist == 0)
        aplist = WcmAllocApList();
    if (aplist == 0 && w->config.nbdmode == 1)
        aplist = WcmGetOldestApList();
    if (aplist == 0)
        return;
    WCMi_BssDescCopy(bssDesc, &aplist->bssDesc);
    aplist->linkLevel = linkLevel;
    WcmAppendApList(aplist);
}

/*
 * sdk:      WcmAllocApList (aplist.o)
 */
WCMApList *WcmAllocApList(void)
{
    unsigned long maxBlock;
    long i;
    WCMApList *pList;
    WCMApList *p;
    WCMApListHeader *pHeader;
    WCMWork *w;

    w = WCMi_GetSystemWork();
    pHeader = w->config.pbdbuffer;
    p = 0;

    if (pHeader == 0)
        return 0;
    if (w->config.nbdbuffer <= sizeof(WCMApListHeader))
        return 0;
    maxBlock = (w->config.nbdbuffer - sizeof(WCMApListHeader)) / sizeof(WCMApList);
    if (maxBlock == 0)
        return 0;
    if (maxBlock <= pHeader->count)
        return 0;

    i = 0;
    if (i < maxBlock) {
        pList = (WCMApList *)(pHeader + 1);
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

static WCMApList *WcmGetOldestApList(void)
{
    WCMWork *w;
    WCMApListHeader *pHeader;

    w = WCMi_GetSystemWork();
    pHeader = ((WCMApListHeader *)w->config.pbdbuffer);
    if (pHeader != 0 && (unsigned long)w->config.nbdbuffer > 12)
        return pHeader->head;
    return 0;
}

static WCMApList *WcmSearchApList(unsigned char *bssid)
{
    WCMWork *w;
    WCMApListHeader *pHeader;
    WCMApList *p;

    w = WCMi_GetSystemWork();
    p = 0;
    pHeader = ((WCMApListHeader *)w->config.pbdbuffer);
    if (bssid == 0)
        return p;
    if (pHeader != 0 && (unsigned long)w->config.nbdbuffer > 12) {
        p = pHeader->head;
        while (p != 0) {
            if (WCM_CompareBssID(p->bssDesc.bssid, bssid))
                break;
            p = p->next;
        }
    }
    return p;
}

static WCMApList *WcmSearchIndexedApList(unsigned long index)
{
    WCMWork *w;
    WCMApListHeader *pHeader;
    WCMApList *p;

    w = WCMi_GetSystemWork();
    p = 0;
    pHeader = ((WCMApListHeader *)w->config.pbdbuffer);
    if (pHeader != 0 && (unsigned long)w->config.nbdbuffer > 12) {
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
void WcmAppendApList(WCMApList *aplist)
{
    WCMWork *w = WCMi_GetSystemWork();
    WCMApListHeader *pHeader = w->config.pbdbuffer;
    WCMApList *p;

    if (aplist == 0 || pHeader == 0)
        return;
    if (w->config.nbdbuffer <= sizeof(WCMApListHeader))
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
void WCMi_BssDescCopy(WMBssDesc *srcBssDesc, WMBssDesc *destBssDesc)
{
    WCMWork *w;
    u8 *pSrc;
    u8 *pDest;
    u8 ieLength;
    u16 i;
    u8 id;
    u8 len;

    w = WCMi_GetSystemWork();
    MIi_CpuClearFast(0, destBssDesc, sizeof(WMBssDesc));
    MIi_CpuCopyFast(srcBssDesc, destBssDesc, 0x40);
    destBssDesc->otherElementCount = 0;
    if (w->deviceId == 1)
        destBssDesc->length = 0x20;
    else
        destBssDesc->length = 0x40;
    {
        u8 wpaTag[4] = { 0x00, 0x50, 0xf2, 0x01 };
        u8 wmmTag[5] = { 0x00, 0x50, 0xf2, 0x02, 0x00 };

        ieLength = 0;
        pSrc = (u8 *)&srcBssDesc->gameInfo;
        pDest = (u8 *)&destBssDesc->gameInfo;
        for (i = 0; i < srcBssDesc->otherElementCount; i++) {
            id = pSrc[0];
            len = pSrc[1];
            if (id == 0x32 || id == 0x2a || id == 0x2f || id == 0x07 || id == 0x30) {
                MI_CpuCopy(pSrc, pDest, (u8)(len + 2));
                pDest += len + 2;
                ieLength += (u8)(len + 2);
                destBssDesc->otherElementCount++;
            } else if (id == 0xdd) {
                if (MI_CpuComp8(pSrc + 2, wpaTag, 4) == 0 || MI_CpuComp8(pSrc + 2, wmmTag, 5) == 0) {
                    MI_CpuCopy(pSrc, pDest, (u8)(len + 2));
                    pDest += len + 2;
                    ieLength += (u8)(len + 2);
                    destBssDesc->otherElementCount++;
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
WMGameInfo *WCMi_GetGameInfo(WMBssDesc *bssDesc)
{
    WCMWork *w = WCMi_GetSystemWork();
    NWMInfoElements *elem;
    WMGameInfo *gameInfo;
    unsigned char tag[4] = { 0x00, 0x09, 0xBF, 0x00 };

    if (bssDesc == 0) return 0;
    if (OS_IsRunOnTwl()) {
        if (w->deviceId == 2) {
            elem = 0;
            if (bssDesc->otherElementCount != 0) {
                elem = (struct NWMInfoElements *)NWM_GetVenderInfoElements((u8 *)bssDesc, 0xDD, tag);
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

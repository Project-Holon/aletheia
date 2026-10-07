/*
 * file:     unit_021B9EEC.c
 * unit:     yes
 * function: func_021B9EEC, func_021B9F5C, func_021B9FAC, func_021B9FE0, func_021BA0A4, func_021BA104, func_021BA12C, func_021BA200, func_021BA250
 * address:  0x021B9EEC
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BAC20  0x021bac20  thumb  ov016
 *   func_02092344  0x02092344  arm
 *   memcpy  0x02092344  arm
 *   memset  0x020923B0  arm
 *   keywrap_decrypt  0x021BADD8  thumb
 *   atermset_data    0x021DAB58  data
 *   atermset_bss     0x021DCFD0  data
 *   SetFrameData     0x021B9FE0  thumb
 *   atermset_rodata  0x021D77C8  data
 *   btAdapterMAC     0x021DD478  data
 *   ElementData      0x021DD504  data
 */
#include "../../matched/arm9_sdk/libc/string.h"

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
typedef struct _FRAMEHEADER {
    unsigned short FrameID;
    unsigned short DataLength;
    unsigned short Reserved;
} FRAMEHEADER;

typedef struct _ELEMENTINFO {
    unsigned short ElementID;
    unsigned short ElementLength;
} ELEMENTINFO;

typedef struct _ELEMENTHEADER {
    unsigned short FullLength;
    unsigned short Reserved[3];
} ELEMENTHEADER;

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

typedef struct {
    unsigned char b[7];
} SUPPORTENC;

extern int func_021BAC20(char *dest, char *src, unsigned long buflen, char *keyptr, unsigned long keylen);
extern void *memset(void *dst, int c, unsigned long n);
extern void *memcpy(void *dst, const void *src, unsigned long n);
extern int keywrap_decrypt(char *dest, char *src, unsigned long buflen, char *keyptr, unsigned long keylen);
extern int SetFrameData(unsigned char *lpframe, int id, unsigned char *pbody, int size, unsigned char *lpkey);
unsigned char *GetFrameData(unsigned char *lpframe, int *pid, int *psize);
unsigned char *GetElementData(unsigned char **lplpb, unsigned char *lplimit, int *pid, int *psize);
unsigned char *GetFirstElement(unsigned char *lpelement, int *pid, int *psize);
int func_021B9FE0(unsigned char *lpframe, int id, unsigned char *pbody, register int size, const unsigned char *lpkey);
unsigned char *SetElementData(unsigned char *lpb, int eid, unsigned char *pele, int esize);
int SetSingleElement(unsigned char *lpbuff, int eid, unsigned char *pele, int esize);
int IsSearchCommand(unsigned char *lpframe, int *pdual);
int GetCommandElement(unsigned char *lpframe, int cmdid, unsigned char *lpelement, unsigned char *lpkey);
int SetSearchRes(unsigned char *lpframe);
extern ATERMSET_BSS atermset_bss;
extern ATERMSET_DATA atermset_data;
extern const SUPPORTENC atermset_rodata;
extern unsigned char btAdapterMAC[6];
extern unsigned char ElementData[2048];


#define SWAP16(x) ((unsigned short)((unsigned char)((x) >> 8) | (((x) << 8) & 0xFF00)))


unsigned char *GetFrameData(unsigned char *lpframe, int *pid, int *psize)
{
    FRAMEHEADER *pfh;
    unsigned short *psum;
    unsigned long dwsum;
    unsigned char *lps;

    pfh = (FRAMEHEADER *)lpframe;
    dwsum = 0;
    *pid = SWAP16(pfh->FrameID);
    *psize = SWAP16(pfh->DataLength);
    psum = (unsigned short *)(lpframe + sizeof(FRAMEHEADER) + *psize);
    for (lps = lpframe; lps < (unsigned char *)psum; lps++)
        dwsum += *lps;
    if ((unsigned short)dwsum != SWAP16(*psum))
        return 0;
    return lpframe + sizeof(FRAMEHEADER);
}

#undef SWAP16

#define SWAP16(x) ((unsigned short)((unsigned char)((x) >> 8) | (((x) << 8) & 0xFF00)))


unsigned char *GetElementData(unsigned char **lplpb, unsigned char *lplimit, int *pid, int *psize)
{
    unsigned char *lpb;
    ELEMENTINFO *pele;

    lpb = *lplpb;
    if (lpb >= lplimit)
        return 0;
    pele = (ELEMENTINFO *)lpb;
    *pid = SWAP16(pele->ElementID);
    *psize = SWAP16(pele->ElementLength);
    lpb += sizeof(ELEMENTINFO);
    *lplpb = lpb + (((*psize + 11) & ~7) - 4);
    return lpb;
}

#undef SWAP16

#define SWAP16(x) ((unsigned short)((unsigned char)((x) >> 8) | (((x) << 8) & 0xFF00)))


unsigned char *GetFirstElement(unsigned char *lpelement, int *pid, int *psize)
{
    unsigned char *lpb;

    lpb = lpelement + 8;
    return GetElementData(&lpb, lpb + SWAP16(((ELEMENTHEADER *)lpelement)->FullLength), pid, psize);
}

#undef SWAP16

#define SWAP16(x) ((unsigned short)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))


/*
 * sdk:      SetFrameData (libdwcutil.TWL.HYB.a(atermset.o))
 *
 * 2026-10-01 (w4 restart): EXACT. Closed from the Debug/Release libdwcutil
 * atermset.o (-O0): its DWARF homes size and lpb in registers (`register`)
 * and shows the real statements: lpb = lpframe at its declaration,
 * `lpb += sizeof(FRAMEHEADER); lpb += size; psum = (u16 *)lpb;` after the
 * header stores, and the return as `lpb += 2; return lpb - lpframe;`.
 * Earlier lanes computed psum from lpb + size directly and lost the copy.
 */
int func_021B9FE0(unsigned char *lpframe, int id, unsigned char *pbody, register int size, const unsigned char *lpkey)
{
    FRAMEHEADER *pfh = (FRAMEHEADER *)lpframe;
    ELEMENTHEADER *peh = (ELEMENTHEADER *)pbody;
    register unsigned char *lpb = lpframe;
    unsigned char *lps;
    unsigned short *psum;
    unsigned long dwsum = 0;

    memset(peh, 0, sizeof(ELEMENTHEADER));
    peh->FullLength = SWAP16((unsigned short)(size - sizeof(ELEMENTHEADER)));
    if (lpkey) {
        func_021BAC20((char *)(lpframe + sizeof(FRAMEHEADER)), (char *)pbody, size, (char *)lpkey, 16);
        size += 8;
    } else {
        memcpy(lpframe + sizeof(FRAMEHEADER), pbody, size);
    }
    memset(pfh, 0, sizeof(FRAMEHEADER));
    pfh->FrameID = SWAP16((unsigned short)id);
    pfh->DataLength = SWAP16((unsigned short)size);
    lpb += sizeof(FRAMEHEADER);
    lpb += size;
    psum = (unsigned short *)lpb;
    for (lps = lpframe; lps < (unsigned char *)psum; lps++)
        dwsum += *lps;
    *psum = SWAP16((unsigned short)dwsum);
    lpb += sizeof(unsigned short);
    return lpb - lpframe;
}

#undef SWAP16

#define SWAP16(x) ((unsigned short)((unsigned char)((x) >> 8) | (((x) << 8) & 0xFF00)))


unsigned char *SetElementData(unsigned char *lpb, int eid, unsigned char *pele, int esize)
{
    ELEMENTINFO *pei;
    int size;

    pei = (ELEMENTINFO *)lpb;
    lpb[0] = 0;
    lpb[1] = 0;
    lpb[2] = 0;
    lpb[3] = 0;
    pei->ElementID = SWAP16((unsigned short)eid);
    size = ((esize + 11) & ~7) - 4;
    pei->ElementLength = SWAP16((unsigned short)esize);
    lpb = (unsigned char *)(pei + 1);
    memset(lpb, 0, size);
    memcpy(lpb, pele, esize);
    return lpb + size;
}


int SetSingleElement(unsigned char *lpbuff, int eid, unsigned char *pele, int esize)
{
    ELEMENTHEADER *peh;
    unsigned char *lpb;

    peh = (ELEMENTHEADER *)lpbuff;
    lpbuff[0] = 0;
    lpbuff[1] = 0;
    lpbuff[2] = 0;
    lpbuff[3] = 0;
    lpbuff[4] = 0;
    lpbuff[5] = 0;
    lpbuff[6] = 0;
    lpbuff[7] = 0;
    lpb = SetElementData(lpbuff + 8, eid, pele, esize);
    peh->FullLength = (lpb - lpbuff) - 8;
    return lpb - lpbuff;
}

#undef SWAP16

#define SWAP16(x) ((unsigned short)((unsigned char)((x) >> 8) | (((x) << 8) & 0xFF00)))


int IsSearchCommand(unsigned char *lpframe, int *pdual)
{
    int id;
    int size;
    int eid;
    int esize;
    unsigned char *lpb;
    unsigned char *lplimit;
    int iMajor;
    int iMinor;
    int iSP;

    lpb = GetFrameData(lpframe, &id, &size);
    iMajor = 0;
    iMinor = 0;
    iSP = 0;
    if (lpb == 0)
        return 0;
    if (id != 1)
        return 0;
    lplimit = lpb + size;
    lpb += 8;
    while ((lpframe = GetElementData(&lpb, lplimit, &eid, &esize)) != 0) {
        switch (eid) {
        case 1:
            iMajor = SWAP16(*(unsigned short *)lpframe);
            break;
        case 2:
            iMinor = SWAP16(*(unsigned short *)lpframe);
            break;
        case 5:
            iSP = SWAP16(*(unsigned short *)lpframe);
            break;
        }
    }
    if (iMajor != 1 || iMinor != 1)
        return 0;
    if (iSP >= 1)
        *pdual = 1;
    else
        *pdual = 0;
    return 1;
}


int GetCommandElement(unsigned char *lpframe, int cmdid, unsigned char *lpelement, unsigned char *lpkey)
{
    int id;
    int size;
    unsigned char *lpb;

    lpb = GetFrameData(lpframe, &id, &size);
    if (lpb == 0)
        return 0;
    if (id != cmdid)
        return 0;
    if (lpkey != 0) {
        keywrap_decrypt((char *)lpelement, (char *)lpb, size, (char *)lpkey, 16);
        size -= 8;
    } else {
        memcpy(lpelement, lpb, size);
    }
    return size;
}


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

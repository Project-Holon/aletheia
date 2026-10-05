/*
 * function: func_021B9FE0
 * address:  0x021B9FE0
 * packet:   pkt_ov016_021B9FE0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * sdk:      SetFrameData (libdwcutil.TWL.HYB.a(atermset.o))
 *
 * symbols:
 *   func_021BAC20  0x021bac20  thumb  ov016
 *   func_02092344  0x02092344  arm
 *   memcpy  0x02092344  arm
 * 2026-10-01 (w4 restart): EXACT. Closed from the Debug/Release libdwcutil
 * atermset.o (-O0): its DWARF homes size and lpb in registers (`register`)
 * and shows the real statements: lpb = lpframe at its declaration,
 * `lpb += sizeof(FRAMEHEADER); lpb += size; psum = (u16 *)lpb;` after the
 * header stores, and the return as `lpb += 2; return lpb - lpframe;`.
 * Earlier lanes computed psum from lpb + size directly and lost the copy.
 */


#include "../../matched/arm9_sdk/libc/string.h"

typedef struct _ELEMENTHEADER {
    unsigned short FullLength;
    unsigned short Reserved[3];
} ELEMENTHEADER;

typedef struct _FRAMEHEADER {
    unsigned short FrameID;
    unsigned short DataLength;
    unsigned short Reserved;
} FRAMEHEADER;

#define SWAP16(x) ((unsigned short)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))

extern int func_021BAC20(char *dest, char *src, unsigned long buflen, char *keyptr, unsigned long keylen);

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

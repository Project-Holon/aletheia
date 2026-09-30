/*
 * function: func_021B9FE0
 * address:  0x021B9FE0
 * packet:   pkt_ov016_021B9FE0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * sdk:      SetFrameData (libdwcutil.TWL.HYB.a(atermset.o))
 *
 * T6: 186 B vs 196. The object runs a real frame (`sub sp,#8`) that spills
 * id to [sp,#4] and reloads the fifth parameter lpkey from [sp,#0x20], and it
 * interleaves the eight ELEMENTHEADER byte stores with the FullLength SWAP16
 * chain; this build does the lpkey/copy branch first, needs no frame at all and
 * computes both SWAP16 chains after it. The extra live value that forces the
 * object's spill is the structural gap.
 * symbols:
 *   func_021BAC20  0x021bac20  thumb  ov016
 *   func_02092344  0x02092344  arm
 *   memcpy  0x02092344  arm
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

#define SWAP16(x) ((unsigned short)((unsigned char)((x) >> 8) | (((x) << 8) & 0xFF00)))

extern int func_021BAC20(char *dest, char *src, unsigned long buflen, char *keyptr, unsigned long keylen);

int func_021B9FE0(unsigned char *lpframe, int id, unsigned char *pbody, int size, unsigned char *lpkey)
{
    FRAMEHEADER *pfh;
    ELEMENTHEADER *peh;
    unsigned char *lpb;
    unsigned char *lps;
    unsigned short *psum;
    unsigned long dwsum;

    dwsum = 0;
    peh = (ELEMENTHEADER *)pbody;
    memset(peh, 0, 8);
    peh->FullLength = SWAP16((unsigned short)(size - 8));
    psum = (unsigned short *)lpframe;
    if (lpkey) {
        func_021BAC20((char *)(lpframe + 6), (char *)pbody, size, (char *)lpkey, 16);
        size += 8;
    } else {
        memcpy(lpframe + 6, pbody, size);
    }
    pfh = (FRAMEHEADER *)lpframe;
    memset(pfh, 0, 6);
    pfh->FrameID = SWAP16((unsigned short)id);
    pfh->DataLength = SWAP16((unsigned short)size);
    psum = (unsigned short *)((unsigned char *)psum + 6 + size);
    for (lps = lpframe; lps < (unsigned char *)psum; lps++)
        dwsum += *lps;
    *psum = SWAP16((unsigned short)dwsum);
    return (unsigned char *)(psum + 1) - lpframe;
}

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
 * T6: 192 B vs 196. A distinct second live pointer across the call forces the
 * object's frame (`sub sp,#8`, id homed at [sp,#4], lpkey reloaded from
 * [sp,#0x20]): introduce a named `pend` byte cursor that is set from `psum`
 * BEFORE the branch and advanced after the call. With `pend` it reaches the
 * 5-live-value pressure and emits the frame; the remaining 105-byte diff is
 * that distinct value. `pend` must carry a NONZERO offset (`psum + 6`) to stay
 * a separate SSA value; the object instead keeps a redundant copy of `lpframe`
 * itself (r4 = r6, offset 0) and adds the `+6` at the end, so its early add is
 * `adds r4,r6,#0` while ours is `adds r7,r5,#6`, which recolours every later
 * register. Writing `pend = psum` (offset 0) copy-propagates away (184 B, no
 * frame), exactly as the vendor's missed coalesce cannot be spelled.
 *
 * blocker: the vendor DWARF (tools/sdkobj.py SetFrameData --region ov016) pins
 * the object's allocation exactly: lpframe r6, size r7, dwsum r5, psum r4, and
 * id homed at [fb+4]. The vendor kept psum as a redundant copy of lpframe
 * (offset 0) live across the call; our dsi/1.1p1 copy-propagates `psum =
 * lpframe` (and any offset-0 alias, incl. integer-spelled) into the lpframe
 * register, so it never reaches the object's 5-live-value pressure without an
 * offset, and any offset that does stay distinct shifts the early add and
 * recolours the whole body. Forcing id to memory (volatile) blows up to 202 B.
 * See docs/notes/vendor-debug-line-gives-statement-grouping.md and
 * docs/sessions/2026-09-29/reports/w5_s1.md (14 psum/lpb/lps spellings tried)
 * and docs/idioms/a-vendor-front-end-homed-parameter-cannot-be-forced-by-source.md.
 * symbols:
 *   func_021BAC20  0x021bac20  thumb  ov016
 *   func_02092344  0x02092344  arm
 *   memcpy  0x02092344  arm
 * lane 05 (2026-10-01): the image's sum loop tests `lps < psum` (bhs/blo),
 * not `!=`; spelled that way now, same 192/105.  The DWARF-faithful shape
 * (psum = lpframe before the branch, lpb = (u8 *)psum + 6, psum = lpb + size)
 * copy-propagates psum away under 1.1p1 (186 B, no frame); pend declaration
 * position is inert.  Object stamp is 3.0.0.126, not a 4.0 build.
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

int func_021B9FE0(unsigned char *lpframe, int id, unsigned char *pbody, int size, const unsigned char *lpkey)
{
    FRAMEHEADER *pfh;
    ELEMENTHEADER *peh;
    unsigned char *lps;
    unsigned char *pend;
    unsigned short *psum;
    unsigned long dwsum;

    dwsum = 0;
    peh = (ELEMENTHEADER *)pbody;
    memset(peh, 0, 8);
    peh->FullLength = SWAP16((unsigned short)(size - 8));
    psum = (unsigned short *)lpframe;
    pend = (unsigned char *)psum + 6;
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
    psum = (unsigned short *)(pend + size);
    for (lps = lpframe; lps < (unsigned char *)psum; lps++)
        dwsum += *lps;
    *psum = SWAP16((unsigned short)dwsum);
    return (unsigned char *)(psum + 1) - lpframe;
}

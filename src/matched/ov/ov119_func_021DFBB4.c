/*
 * function: POKETRADE_MCSS_SlideCreateWithOffsets
 * address:  0x021DFBB4
 * packet:   pkt_ov119_021DFBB4
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: the alloc + store callee named by the parked
 * ov118 POKETRADE_DEMO_MIDDLE_CreateOfferSlide (+0014 / +001E... it is the same pokemontrade_mcss.c
 * helper family as ov119 0x021DFB84) and by all three ov119 0x021DFBxx
 * entries.  POKETRADE_MCSS_SlideCreate is the four-argument form (line 0xD2) and this is
 * the five-argument form (a3 stored at +0x34, line 0xE7); the heap id is the
 * fifth parameter and reaches the debug allocator through its own stack home
 * (`ldrh r0,[sp,#0x20]`, a u16), which is what forces the 8-byte frame.
 *
 * symbols:
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   POKETRADE_MCSS_SlideBegin  0x021DFB4C  thumb  ov119
 *   d_021E80F4     0x021E80F4  data   ov119
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10369.h"

typedef unsigned int u32;
typedef unsigned short u16;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void POKETRADE_MCSS_SlideBegin(void *, void *, void *);

void *POKETRADE_MCSS_SlideCreateWithOffsets(void *a0, void *a1, void *a2, void *a3, u16 heapId)
{
    void *r = GFL_HEAP_Alloc(heapId, 0x38, 1, (const char *)0x021E80F4, 0xE7);

    ((struct Obj10369 *)r)->f0 = a0;
    POKETRADE_MCSS_SlideBegin(r, a1, a2);
    ((struct Obj10369 *)r)->fC = 0;
    ((struct Obj10369 *)r)->f34 = (u32)a3;
    return r;
}

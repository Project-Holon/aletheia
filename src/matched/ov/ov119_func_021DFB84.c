/*
 * function: POKETRADE_MCSS_SlideCreate
 * address:  0x021DFB84
 * packet:   pkt_ov119_021DFB84
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   POKETRADE_MCSS_SlideBegin  0x021DFB4C  thumb  ov119
 *   d_021E80F4     0x021E80F4  data  ov119
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13906.h"

typedef unsigned int u32;

typedef unsigned short u16;
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void POKETRADE_MCSS_SlideBegin(void *, void *, void *);

void *POKETRADE_MCSS_SlideCreate(void *a0, void *a1, void *a2, u32 heapId)
{
    void *r = sub_02030734(heapId, 0x38, 1, (const char *)0x021E80F4, 0xD2);

    ((struct Obj13906 *)r)->f0 = a0;
    POKETRADE_MCSS_SlideBegin(r, a1, a2);
    ((struct Obj13906 *)r)->fC = 0;
    return r;
}

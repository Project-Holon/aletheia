/*
 * function: POKETRADE_MCSS_SlideBegin
 * address:  0x021DFB4C
 * packet:   pkt_ov119_021DFB4C
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MCSS_GetPosition   0x02015C30  thumb
 *   MI_CpuCopy8     0x02082D44  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10368.h"

typedef unsigned int u32;
typedef unsigned char u8;

extern void MCSS_GetPosition(void *p, u32 *out);
extern void MI_CpuCopy8(const void *, void *, u32);

void POKETRADE_MCSS_SlideBegin(void *p, void *a1, void *a2)
{
    u8 buf[12];

    MCSS_GetPosition((void *)(((struct Obj10368 *)p)->f0), (u32 *)buf);
    ((struct Obj10368 *)p)->f8 = 0;
    ((struct Obj10368 *)p)->f4 = (u32)a1;
    MI_CpuCopy8(a2, (char *)p + 0x28, 0xC);
    MI_CpuCopy8(buf, (char *)p + 0x1C, 0xC);
}

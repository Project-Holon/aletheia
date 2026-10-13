/*
 * function: NHTTP_RAP_AllocPostData
 * address:  0x021B98A0
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   NHTTP_RAP_WritePostHeader  0x021B984C  thumb  ov114
 *   GFL_NET_AllocAligned  0x0203D7C8  arm  arm9
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 *
 *
 * Binds a 0x130-stride sub-table to the record and zeroes its first 0x130 bytes.
 */
#include "../include/Obj03250.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern void *GFL_NET_AllocAligned(unsigned int a, unsigned int size, const char *c, unsigned short d);
extern void MI_CpuFill8(int, int, int);
extern void NHTTP_RAP_WritePostHeader(u8 *, int);

void NHTTP_RAP_AllocPostData(u8 *p, int a, int b, int c)
{
    void *q;

    if (p == 0)
        return;
    q = GFL_NET_AllocAligned(a, b + 0x130, (const char *)0x021CE310, 0x1f5);
    ((struct Obj03250 *)p)->f0 = (u32)q;
    MI_CpuFill8((int)q, 0, b + 0x130);
    NHTTP_RAP_WritePostHeader(p, c);
}

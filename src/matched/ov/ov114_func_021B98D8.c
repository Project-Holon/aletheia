/*
 * function: NHTTP_RAP_AppendPostData
 * address:  0x021B98D8
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * Appends `n` bytes at the write cursor and advances it.
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 */
#include "../include/Obj10328.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern void MI_CpuCopy8(int, int, int);

void NHTTP_RAP_AppendPostData(u8 *p, int a, int n)
{
    if (p == 0)
        return;
    MI_CpuCopy8(a, ((struct Obj10328 *)p)->f0 + ((struct Obj10328 *)p)->f4, n);
    ((struct Obj10328 *)p)->f4 += n;
}

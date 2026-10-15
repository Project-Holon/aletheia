/*
 * function: WIFIBATTLEMATCH_UTIL_CreateCallback
 * address:  0x021E8A3C
 * packet:   pkt_021E8A3C
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021E8DD4      0x021E8DD4  data
 *   func_02030734   0x02030734  arm
 *   MI_CpuFill8   0x02082BCC  arm
 *   WIFIBATTLEMATCH_UTIL_SetCallback   0x021E8AA0  thumb
 *
 * Allocate and clear a 0x10-byte record, attach a and b, and return it.
 */
#include "../include/Obj24452.h"


extern unsigned char d_021E8DD4[];
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern void MI_CpuFill8(int *, int, int);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *, int);

int *WIFIBATTLEMATCH_UTIL_CreateCallback(int a, int b, int c)
{
    int *p;
    p = func_02030734(c, 0x10, 0, (const char *)d_021E8DD4, 0x246);
    MI_CpuFill8(p, 0, 0x10);
    ((struct Obj24452 *)p)->f8 = a;
    WIFIBATTLEMATCH_UTIL_SetCallback(p, b);
    return p;
}

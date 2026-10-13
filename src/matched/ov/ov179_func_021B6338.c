/*
 * function: func_021B6338
 * address:  0x021B6338
 * packet:   pkt_ov179_021B6338
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_UTIL_LoadPaletteBlockFromHandle  0x02049F78  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj14384.h"
#include "../include/Obj14385.h"
#include "../include/Obj24470.h"

typedef unsigned int   u32;
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void MIi_CpuCopy32(int, int, int);
extern u32 func_020307B0(void *p);

void func_021B6338(void *obj, int a, int b)
{
    void *ptr;
    int t;
    char *p;

    t = (int)ARC_UTIL_LoadPaletteBlockFromHandle((void *)(((struct Obj24470 *)obj)->f4), b, (u32)(&ptr), 0x807f);
    p = (char *)obj + 8 + a * 0x2004;
    ((struct Obj14385 *)p)->f2000 = ((struct Obj14384 *)ptr)->f8;
    MIi_CpuCopy32(((struct Obj14384 *)ptr)->fC, (int)p, ((struct Obj14385 *)p)->f2000);
    func_020307B0((void *)t);
}

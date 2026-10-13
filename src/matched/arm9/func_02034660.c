/*
 * function: VMAN_Alloc
 * address:  0x02034660
 * packet:   pkt_02034660
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   AREAMAN_Alloc  0x02033CA8  arm
 *   _u32_div_f     0x0209C2B0  arm
 */
#include "../include/Obj11332.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
struct AreaMan;
extern s32 AREAMAN_Alloc(struct AreaMan *p, u32 len);

int VMAN_Alloc(u8 *p, u32 a, void **out)
{
    u16 d = ((struct Obj11332 *)p)->f4;
    u32 q = a / d;
    u32 v;

    if (a % d != 0) {
        q++;
    }
    v = AREAMAN_Alloc((struct AreaMan *)(((struct Obj11332 *)p)->f0), q);
    if (v != (u32)-1) {
        out[0] = (void *)v;
        out[1] = (void *)q;
        return 1;
    }
    return 0;
}

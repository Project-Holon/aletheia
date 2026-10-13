/*
 * function: ICA_ANIME_AllocBuffer
 * address:  0x02011770
 * packet:   pkt_020116E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   _IcaAnimeFileName      0x020A7270  data
 */
#include "../include/Obj00064.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 a, u32 b, int c, const char *d, u16 e);
extern u8    _IcaAnimeFileName[];

void ICA_ANIME_AllocBuffer(u8 *p, int n)
{
    *(u32 *)&((struct Obj00064 *)p)->f18 = (u32)n;
    if (((struct Obj00064 *)p)->f28 != 0) {
        *(u32 *)&((struct Obj00064 *)p)->f1C = (u32)func_02030734((u32)((struct Obj00064 *)p)->f0, n * 0xc,
                                                  0, (const char *)_IcaAnimeFileName, 0x25c);
    }
    if (((struct Obj00064 *)p)->f2C != 0) {
        *(u32 *)&((struct Obj00064 *)p)->f20 = (u32)func_02030734((u32)((struct Obj00064 *)p)->f0, n * 0xc,
                                                  0, (const char *)_IcaAnimeFileName, 0x260);
    }
    if (((struct Obj00064 *)p)->f30 != 0) {
        *(u32 *)&((struct Obj00064 *)p)->f24 = (u32)func_02030734((u32)((struct Obj00064 *)p)->f0, n * 0xc,
                                                  0, (const char *)_IcaAnimeFileName, 0x264);
    }
    ((struct Obj00064 *)p)->f34 = 1;
}

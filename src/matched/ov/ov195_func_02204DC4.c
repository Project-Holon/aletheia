/*
 * function: func_02204DC4
 * address:  0x02204DC4
 * packet:   pkt_02204DC4
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb  arm9
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24942.h"
#include "../include/Obj24943.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void GFL_USE_FadeOutBgm(u32);

void func_02204DC4(u8 *p, u8 *q)
{
    if (((struct Obj24942 *)p)->fC != 0) {
        GFL_USE_FadeOutBgm(0x1e);
    }
    ((struct Obj24943 *)q)->f30 = 1;
}


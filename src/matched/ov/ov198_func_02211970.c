/*
 * function: B_PLIST_MAIN_PlaySe
 * address:  0x02211970
 * packet:   pkt_02211970
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25286.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void GFL_USE_PlaySeDefaultVolume(u32);

void B_PLIST_MAIN_PlaySe(u8 **p, u32 b)
{
    if (((struct Obj25286 *)(*p))->f40 == 1) {
        GFL_USE_PlaySeDefaultVolume(b);
    }
}


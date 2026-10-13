/*
 * function: NHTTP_RAP_FreePostData
 * address:  0x021B99B8
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * Frees the owned buffer, empties the record and clears the 0x021CF960 global.
 *
 * symbols:
 *   GFL_NET_FreeAligned  0x0203D7FC  arm  arm9
 */
#include "../include/Obj08036.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern void GFL_NET_FreeAligned(void *);

void NHTTP_RAP_FreePostData(u8 *p)
{
    if (p != 0) {
        if (((struct Obj08036 *)p)->f0 != 0)
            GFL_NET_FreeAligned((void *)((struct Obj08036 *)p)->f0);
        ((struct Obj08036 *)p)->f0 = 0;
        ((struct Obj08036 *)p)->f4 = 0;
    }
    *(u32 *)0x021CF960 = 0;
}

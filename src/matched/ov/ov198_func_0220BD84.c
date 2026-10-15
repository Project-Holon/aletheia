/*
 * function: B_PLIST_DRAW_DeleteAuxWindow
 * address:  0x0220BD84
 * packet:   pkt_0220BD84
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Delete  0x020452E8  arm  arm9
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14554.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);

void B_PLIST_DRAW_DeleteAuxWindow(u8 *p)
{
    u32 t = ((struct Obj14554 *)p)->f2170;

    if (t != 0) {
        BMP_WIN_Delete((struct Descriptor *)t);
        ((struct Obj14554 *)p)->f2170 = 0;
    }
}


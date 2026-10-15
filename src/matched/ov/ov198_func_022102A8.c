/*
 * function: B_PLIST_MAIN_ClearPrintStream
 * address:  0x022102A8
 * packet:   pkt_022102A8
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb  arm9
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25235.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);

u32 B_PLIST_MAIN_ClearPrintStream(u8 *p)
{
    BMP_MENUWORK_DrawWindowBorder((void *)(((struct Obj25235 *)p)->f1F68), 0);
    return 4;
}


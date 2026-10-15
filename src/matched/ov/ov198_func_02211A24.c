/*
 * function: B_PLIST_MAIN_LayoutCursorActors
 * address:  0x02211A24
 * packet:   pkt_02211A24
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CURSOR_MOVE_GetEntry  0x0202616C  thumb
 *   B_APP_TOOL_LayoutActors  0x0220B000  thumb  ov196
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10855.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *CURSOR_MOVE_GetEntry(void **obj, u32 idx);
extern void B_APP_TOOL_LayoutActors(int *p, u8 *q);

void B_PLIST_MAIN_LayoutCursorActors(u8 *p, u32 idx)
{
    void *t = CURSOR_MOVE_GetEntry(*(void ** *)&((struct Obj10855 *)p)->f2184, idx);

    B_APP_TOOL_LayoutActors((int *)(((struct Obj10855 *)p)->f2188), (u8 *)((u32)t));
}


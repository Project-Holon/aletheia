/*
 * function: func_0220D98C
 * address:  0x0220D98C
 * packet:   pkt_0220D98C
 * region:   ov197
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CURSOR_MOVE_GetEntry  0x0202616C  thumb
 *   B_APP_TOOL_LayoutActors  0x0220B000  thumb  ov196
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06649.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *CURSOR_MOVE_GetEntry(void **obj, u32 idx);
extern void B_APP_TOOL_LayoutActors(int *p, u8 *q);

void func_0220D98C(u8 *p, u32 idx)
{
    void *t = CURSOR_MOVE_GetEntry(*(void ** *)&((struct Obj06649 *)p)->f144, idx);

    B_APP_TOOL_LayoutActors((int *)(((struct Obj06649 *)p)->f148), (u8 *)((u32)t));
}


/*
 * function: SHORTCUT_MENU_FreeList
 * address:  0x021C5424
 * packet:   pkt_021C5424
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   SHORTCUT_MENU_DeleteList  0x021C59A8  thumb  ov021
 *   BMP_WIN_Delete  0x020452E8  arm
 *   MI_CpuFill8  0x02082BCC  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18305.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 MI_CpuFill8(u32, u32, u32);
extern int SHORTCUT_MENU_DeleteList(u32 a, u32 b, u32 c);

int SHORTCUT_MENU_FreeList(u32 a, u32 b)
{
SHORTCUT_MENU_DeleteList(a, b, (b + 2));
BMP_WIN_Delete((struct Descriptor *)(((struct Obj18305 *)((u8 *)(a)))->f8));
return MI_CpuFill8(a, 0, 76);
}


/*
 * function: SHORTCUT_MENU_DeleteList
 * address:  0x021C59A8
 * packet:   pkt_021C59A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   BMP_MENULIST_Delete  0x0202020C  thumb
 *   BMP_MENUWORK_Delete  0x0201F868  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12133.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 BMP_MENUWORK_Delete(void *p);
struct Obj;
extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);

int SHORTCUT_MENU_DeleteList(u32 a, u32 b, u32 c)
{
BMP_MENULIST_Delete((struct Obj *)(((struct Obj12133 *)((u8 *)(a)))->f4), (u16 *)b, (u16 *)c);
return BMP_MENUWORK_Delete((void *)(((struct Obj12133 *)((u8 *)(a)))->f0));
}


/*
 * function: SCRCMD_PROC_FLD_FreeItemListMenu
 * address:  0x021B46FC
 * packet:   pkt_ov021_021B46FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_MENULIST_Delete  0x0202020C  thumb
 */
#include "../include/Obj19998.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Obj;
extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);

void SCRCMD_PROC_FLD_FreeItemListMenu(u8 *w)
{
    u16 a;
    u16 b;

    BMP_MENULIST_Delete((struct Obj *)(((struct Obj19998 *)w)->f1A4), &a, &b);
}

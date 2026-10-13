/*
 * function: SHORTCUT_MENU_OnKeyDown
 * address:  0x021C54C8
 * packet:   pkt_ov021_021C54C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_MENULIST_GetPos  0x020202FC  thumb
 *   BMP_MENULIST_GetRowY  0x02020324  thumb
 *   SHORTCUT_MENU_SetActorsY  0x021C59F8  thumb  ov021
 *   SHORTCUT_MENU_DeleteList  0x021C59A8  thumb  ov021
 *   SHORTCUT_MENU_CreateList  0x021C58CC  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 */
#include "../include/Obj04281.h"

typedef unsigned short u16;
typedef unsigned int u32;

struct Obj;
extern void BMP_MENULIST_GetPos(struct Obj *obj, u16 *a, u16 *b);
extern u16 BMP_MENULIST_GetRowY(struct Obj *obj, u32 n);
extern void SHORTCUT_MENU_SetActorsY(int *a, int b);
extern int SHORTCUT_MENU_DeleteList(u32 a, u32 b, u32 c);
extern void SHORTCUT_MENU_CreateList(char *p, u16 a, u16 b, u32 heap);
extern void func_020061E4(u32 a);

void SHORTCUT_MENU_OnKeyDown(int *a, int b, int c, int *d)
{
    u16 v;
    u16 w;

    if (b == c - 1) {
        if (a[9] == 1) {
            BMP_MENULIST_GetPos((struct Obj *)a[1], 0, &v);
            w = BMP_MENULIST_GetRowY((struct Obj *)a[1], (u16)(v + 1)) >> 3;
            SHORTCUT_MENU_SetActorsY(a, (w + 0xc) << 3);
            a[16] ^= 1;
        }
        if (a[16] == 0) {
            SHORTCUT_MENU_DeleteList((u32)a, 0, 0);
            SHORTCUT_MENU_CreateList((char *)a, 0, 0, ((struct Obj04281 *)a)->f34);
        }
        func_020061E4(0x548);
        *d = 1;
        return;
    }
    a[16] = 0;
}

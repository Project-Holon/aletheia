/*
 * function: SHORTCUT_MENU_UpdateCursorBg
 * address:  0x021C577C
 * packet:   pkt_ov021_021C577C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_MENULIST_GetAttr 0x02020350 thumb
 *   BMP_MENULIST_GetCursorY 0x02020314 thumb
 *   BMP_MENULIST_GetRowY 0x02020324 thumb
 *   BMP_MENULIST_GetPos 0x020202FC thumb
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   SHORTCUT_MENU_SetActorsY 0x021C59F8 thumb ov021
 */
#include "../include/Obj04282.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;
extern u32 BMP_MENULIST_GetAttr(struct Obj *obj, u32 what);
extern u16 BMP_MENULIST_GetCursorY(struct Obj *obj);
extern u16 BMP_MENULIST_GetRowY(struct Obj *obj, u32 n);
extern void BMP_MENULIST_GetPos(struct Obj *obj, u16 *a, u16 *b);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);
extern void SHORTCUT_MENU_SetActorsY(char *w, int b);

void SHORTCUT_MENU_UpdateCursorBg(void *list)
{
    u16 v[2];
    char *w;
    u16 x;
    u32 y;
    u32 s;
    u32 t;
    u32 d;
    u16 a;

    w = (char *)BMP_MENULIST_GetAttr(list, 0x13);
    x = BMP_MENULIST_GetCursorY(list) >> 3;
    y = BMP_MENULIST_GetAttr(list, 9) >> 3;
    if (((struct Obj04282 *)w)->f24 == 0) {
        func_020413B0(1, 1, 12, 30, 12, 11);
        func_020413B0(1, 1, x + 12, 30, y, 12);
        func_020413B0(1, 0, 11, 32, 1, 10);
        func_02041B6C(1);
    } else if (((struct Obj04282 *)w)->f24 == 1) {
        func_020413B0(1, 1, 12, 30, 12, 11);
        BMP_MENULIST_GetPos(list, &v[1], &v[0]);
        s = BMP_MENULIST_GetAttr(list, 8);
        t = BMP_MENULIST_GetAttr(list, 9);
        d = ((struct Obj04282 *)w)->f1E + ((struct Obj04282 *)w)->f1C - v[1];
        s = s + d * t;
        func_020413B0(1, 1, (s >> 3) + 12, 30, y, 12);
        func_020413B0(1, 0, 11, 32, 1, 10);
        func_02041B6C(1);
    }
    if (((struct Obj04282 *)w)->f40 == 1) {
        a = BMP_MENULIST_GetAttr(((struct Obj04282 *)w)->f4, 3);
        a = BMP_MENULIST_GetRowY(((struct Obj04282 *)w)->f4, a) >> 3;
        SHORTCUT_MENU_SetActorsY(w, (a + 12) << 3);
    } else {
        SHORTCUT_MENU_SetActorsY(w, (x + 12) << 3);
    }
}

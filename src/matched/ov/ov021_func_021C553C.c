/*
 * function: SHORTCUT_MENU_UpdateInput
 * address:  0x021C553C
 * packet:   pkt_ov021_021C553C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020355D8 0x020355D8 arm
 *   BMP_MENULIST_GetListIndex 0x020202EC thumb
 *   BMP_MENULIST_GetAttr 0x02020350 thumb
 *   KEY_GetRepeat 0x0203633C arm
 *   KEY_GetTrg 0x020362DC arm
 *   SHORTCUT_MENU_OnKeyUp 0x021C5440 thumb ov021
 *   SHORTCUT_MENU_OnKeyDown 0x021C54C8 thumb ov021
 *   BMP_MENULIST_Main 0x020200CC thumb
 *   BMP_MENULIST_GetItemValue 0x02020344 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   RECENT_ID_LIST_SAVEDATA_InsertId 0x0200C480 thumb
 *   SHORTCUT_MENU_DeleteList 0x021C59A8 thumb ov021
 *   SHORTCUT_MENU_CreateList 0x021C58CC thumb ov021
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   SHORTCUT_MENU_UpdateCursorBg 0x021C577C thumb ov021
 *   BMP_MENULIST_GetPos 0x020202FC thumb
 */
#include "../include/Obj00523.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
struct Obj;
extern void func_020355D8(u8 v);
extern void BMP_MENULIST_GetListIndex(struct Obj *obj, u16 *out);
extern u32 BMP_MENULIST_GetAttr(struct Obj *obj, u32 what);
extern unsigned int KEY_GetRepeat(void);
extern u32 KEY_GetTrg(void);
extern void SHORTCUT_MENU_OnKeyUp(char *p, int b, int c, int *d);
extern void SHORTCUT_MENU_OnKeyDown(int *a, int b, int c, int *d);
extern s32 BMP_MENULIST_Main(struct Obj *o);
extern u32 BMP_MENULIST_GetItemValue(struct Obj *obj, u32 n);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern u8 RECENT_ID_LIST_SAVEDATA_InsertId(u8 *a, int id, u8 pos);
extern int SHORTCUT_MENU_DeleteList(u32 a, u32 b, u32 c);
extern void SHORTCUT_MENU_CreateList(char *p, u16 a, u16 b, u32 heap);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void SHORTCUT_MENU_UpdateCursorBg(void *list, int a, int b);
extern void BMP_MENULIST_GetPos(struct Obj *obj, u16 *a, u16 *b);

void SHORTCUT_MENU_UpdateInput(char *p)
{
    int flag;
    u16 c[2];
    u16 b[2];
    u16 a[2];
    int redraw;
    int sel;
    u32 n;
    int i;

    sel = -1;
    redraw = 0;
    flag = 0;
    func_020355D8(0);
    BMP_MENULIST_GetListIndex(((struct Obj00523 *)p)->f4, &c[1]);
    n = BMP_MENULIST_GetAttr(((struct Obj00523 *)p)->f4, 2);
    if (KEY_GetRepeat() & 0x40) {
        SHORTCUT_MENU_OnKeyUp(p, c[1], n, &flag);
    } else if (KEY_GetRepeat() & 0x80) {
        SHORTCUT_MENU_OnKeyDown((int *)p, c[1], n, &flag);
    }
    if (flag == 0) {
        sel = BMP_MENULIST_Main(((struct Obj00523 *)p)->f4);
    }
    if (sel == -1) {
        if (KEY_GetTrg() & 0x400) {
            sel = -2;
            GFL_USE_PlaySeDefaultVolume(0x551);
        } else if (KEY_GetTrg() & 0x800) {
            BMP_MENULIST_GetListIndex(((struct Obj00523 *)p)->f4, &c[0]);
            sel = BMP_MENULIST_GetItemValue(((struct Obj00523 *)p)->f4, c[0]);
            GFL_USE_PlaySeDefaultVolume(0x54C);
        } else if ((KEY_GetTrg() & 4) && ((struct Obj00523 *)p)->f24 == 1) {
            BMP_MENULIST_GetListIndex(((struct Obj00523 *)p)->f4, &b[1]);
            sel = BMP_MENULIST_GetItemValue(((struct Obj00523 *)p)->f4, b[1]);
            GFL_USE_PlaySeDefaultVolume(0x54C);
        }
    }
    if (((struct Obj00523 *)p)->f24 == 0) {
        ((struct Obj00523 *)p)->f18 = sel;
    } else if (((struct Obj00523 *)p)->f24 == 1) {
        if (sel == -2) {
            redraw = 1;
        } else if (sel != -1) {
            sel = BMP_MENULIST_GetItemValue(((struct Obj00523 *)p)->f4, (u16)(((struct Obj00523 *)p)->f1C + ((struct Obj00523 *)p)->f1E));
            BMP_MENULIST_GetListIndex(((struct Obj00523 *)p)->f4, &b[0]);
            if (((struct Obj00523 *)p)->f40 != 0) {
                sel = RECENT_ID_LIST_SAVEDATA_InsertId(((struct Obj00523 *)p)->f20, sel, 0xFF);
            } else {
                sel = RECENT_ID_LIST_SAVEDATA_InsertId(((struct Obj00523 *)p)->f20, sel, b[0]);
            }
            SHORTCUT_MENU_DeleteList((u32)p, (u32)(&a[0]), (u32)(&a[1]));
            if (b[0] - 1 == sel) {
                a[1]--;
            }
            SHORTCUT_MENU_CreateList(p, a[0], a[1], ((struct Obj00523 *)p)->f34);
            redraw = 1;
        }
    }
    if ((KEY_GetTrg() & 4) && ((struct Obj00523 *)p)->f24 == 0 && BMP_MENULIST_GetAttr(((struct Obj00523 *)p)->f4, 2) > 1) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        redraw = 1;
    }
    if (redraw) {
        ((struct Obj00523 *)p)->f24 ^= 1;
        if (((struct Obj00523 *)p)->f24 == 0) {
            ((struct Obj00523 *)p)->f40 = 0;
            for (i = 0; i < 3; i++) {
                CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)(p + 0x28 + i * 4), 0);
            }
            SHORTCUT_MENU_UpdateCursorBg(((struct Obj00523 *)p)->f4, 0, 0);
            return;
        }
        if (((struct Obj00523 *)p)->f24 == 1) {
            BMP_MENULIST_GetPos(((struct Obj00523 *)p)->f4, (u16 *)(p + 0x1C), (u16 *)(p + 0x1E));
            ((struct Obj00523 *)p)->f48 = 1;
        }
    }
}

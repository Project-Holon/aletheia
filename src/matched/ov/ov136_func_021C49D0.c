/*
 * function: func_021C49D0
 * address:  0x021C49D0
 * packet:   pkt_ov136_021C49D0
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   APP_TASKMENU_WIN_ResetDecide 0x020282A4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   PALANM_BlendChannel 0x02021FD8 thumb
 *   APP_TASKMENU_WIN_TransChar 0x02028454 thumb
 *   func_021C47C4 0x021C47C4 thumb ov136
 *   func_021C44FC 0x021C44FC thumb ov136
 *   func_021C48FC 0x021C48FC thumb ov136
 *   func_021C4998 0x021C4998 thumb ov136
 */
#include "../include/Obj00275.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Chan02021FD8;
struct Descriptor;
struct Obj;
struct Rec3;
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void APP_TASKMENU_WIN_ResetDecide(struct Obj *obj);
extern u32 func_0201CE30(void *h);
extern void func_0201CE48(struct Rec3 *p);
extern void APP_TASKMENU_UpdateMenu(void *p);
extern void func_0201F7A8(void *p, u32 a);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern void APP_TASKMENU_WIN_TransChar(u8 *p);
extern void func_021C47C4(u8 *p, int n);
extern void func_021C44FC(u8 *p);
extern void func_021C48FC(u8 *p);
extern int func_021C4998(u8 *p);

int func_021C49D0(u8 *p)
{
    int r;
    void *w;

    switch (((struct Obj00275 *)p)->f8) {
    case 0:
        APP_TASKMENU_WIN_SetActive(((struct Obj00275 *)p)->f128, 0);
        APP_TASKMENU_WIN_SetDecide(((struct Obj00275 *)p)->f12C, 1);
        break;
    case 1:
        if (APP_TASKMENU_WIN_IsFinish(((struct Obj00275 *)p)->f12C)) {
            APP_TASKMENU_WIN_ResetDecide(((struct Obj00275 *)p)->f12C);
            APP_TASKMENU_WIN_SetActive(((struct Obj00275 *)p)->f12C, 1);
            ((struct Obj00275 *)p)->f10 = 1;
            func_021C47C4(p, 3);
            func_021C44FC(p);
            p[0x1B] = p[0x1A];
            break;
        }
        return 0;
    case 2:
        if (func_0201CE30(((struct Obj00275 *)p)->f9C) == 2) {
            func_0201CE48(((struct Obj00275 *)p)->f9C);
            func_021C48FC(p);
            ((struct Obj00275 *)p)->f8 = 3;
        }
        return 0;
    case 3:
        APP_TASKMENU_UpdateMenu(((struct Obj00275 *)p)->f10C);
        r = func_021C4998(p);
        if (r < 0)
            return 0;
        func_0201F7A8(((struct Obj00275 *)p)->f5C, 2);
        w = ((struct Obj00275 *)p)->f5C;
        BMP_WIN_ClearScreen(w);
        func_020409B4(func_02045730(w));
        ((struct Obj00275 *)p)->f8 = 0;
        if (r == 0) {
            **(u16 * *)&((struct Obj00275 *)p)->f1C = 0xFFFF;
            p[0xB] = p[0xC];
            return 1;
        }
        ((struct Obj00275 *)p)->f10 = 0;
        p[0xB] = p[0xC];
        PALANM_BlendChannel(((struct Obj00275 *)p)->f38, 0, 0, 0x30, 0, 0);
        APP_TASKMENU_WIN_TransChar(((struct Obj00275 *)p)->f128);
        APP_TASKMENU_WIN_TransChar(((struct Obj00275 *)p)->f12C);
        return 0;
    }
    (((struct Obj00275 *)p)->f8)++;
    return 0;
}

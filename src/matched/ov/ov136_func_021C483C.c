/*
 * function: func_021C483C
 * address: 0x021C483C
 * packet: pkt_ov136_021C483C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 0x021C48FA..0x021C48FC is a zero alignment halfword.
 * symbols:
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   func_021C47C4 0x021C47C4 thumb ov136
 *   func_021C44FC 0x021C44FC thumb ov136
 *   func_020362DC 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   APP_TASKMENU_WIN_SetActive  0x02028218  thumb  arm9
 *   APP_TASKMENU_WIN_IsFinish  0x02028230  thumb  arm9
 *   APP_TASKMENU_WIN_ResetDecide  0x020282A4  thumb  arm9
 */
#include "../include/Obj01413.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct Obj;
struct Rec3;
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void APP_TASKMENU_WIN_ResetDecide(struct Obj *obj);
extern void func_021C47C4(u8 *, int);
extern u32 func_0201CE30(void *p);
extern u32 func_020362DC(void);
extern int TOUCHPANEL_GetTrg(void);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_021C44FC(u8 *);
int func_021C483C(u8 *p)
{
    void *q;
    switch (((struct Obj01413 *)p)->f8) {
    case 0:
        APP_TASKMENU_WIN_SetDecide(((struct Obj01413 *)p)->f128, 1);
        APP_TASKMENU_WIN_SetActive(((struct Obj01413 *)p)->f12C, 0);
        ((struct Obj01413 *)p)->f8 = 1;
        break;
    case 1:
        if (APP_TASKMENU_WIN_IsFinish(((struct Obj01413 *)p)->f128) != 0) {
            APP_TASKMENU_WIN_ResetDecide(((struct Obj01413 *)p)->f128);
            APP_TASKMENU_WIN_SetActive(((struct Obj01413 *)p)->f128, 1);
            func_021C47C4(p, 2);
            ((struct Obj01413 *)p)->f8 = 2;
        }
        break;
    case 2:
        if (func_0201CE30(((struct Obj01413 *)p)->f9C) == 2) {
            if ((func_020362DC() & 1) || TOUCHPANEL_GetTrg()) {
                func_0201CE48(((struct Obj01413 *)p)->f9C);
                ((struct Obj01413 *)p)->f8 = 3;
            }
        }
        break;
    case 3:
        func_0201F7A8(((struct Obj01413 *)p)->f5C, 2);
        q = ((struct Obj01413 *)p)->f5C;
        BMP_WIN_ClearScreen(q);
        func_020409B4(func_02045730(q));
        func_021C44FC(p);
        ((struct Obj01413 *)p)->f8 = 0;
        p[0xB] = p[0xC];
        break;
    }
    return 0;
}

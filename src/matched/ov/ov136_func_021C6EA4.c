/*
 * function: func_021C6EA4
 * address:  0x021C6EA4
 * packet:   pkt_ov136_021C6EA4
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008FA4 0x02008FA4 thumb
 *   func_020213AC 0x020213AC thumb
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb
 *   BGWINFRM_HideFrame  0x0202CC70  thumb
 *   func_021C5B30 0x021C5B30 thumb
 *   func_021C61CC 0x021C61CC thumb
 *   func_021C62F4 0x021C62F4 thumb
 *   func_021C630C 0x021C630C thumb
 *   func_021C66A0 0x021C66A0 thumb
 *   func_021C66B8 0x021C66B8 thumb
 *   func_021C6884 0x021C6884 thumb
 *   func_021C7178 0x021C7178 thumb
 *   func_021C71A8 0x021C71A8 thumb
 *   func_021C7298 0x021C7298 thumb
 *   func_021C730C 0x021C730C thumb
 *   func_021C7350 0x021C7350 thumb
 *   func_021C7430 0x021C7430 thumb
 */
#include "../include/Obj00127.h"
#include "../include/Obj23624.h"
#include "../include/Obj23625.h"
#include "../include/Obj23626.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinMgr;
extern void APP_TASKMENU_UpdateMenu(void *);
struct Sub02008F80Obj;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void func_021C5B30(u8 *);
extern void func_021C62F4(u8 *);
extern void func_021C66B8(u8 *, int, u32);
extern void func_021C61CC(u8 *);
extern void func_021C6884(u8 *);
extern void func_021C7350(u8 *);
extern void func_021C66A0(u8 *p, int i, u32 v);
extern void func_021C730C(void *p);
extern void func_021C630C(u8 *p, unsigned int i);
extern int func_021C71A8(char *p, int v, int w);
extern u8 func_02008FA4(const struct Sub02008F80Obj *obj);
extern u16 func_020213AC(u32);
extern void func_021C7430(u8 *, int, u16, u16);
extern int func_021C7178(u8 *, u32);
extern void BGWINFRM_HideFrame(struct WinMgr *mgr, u32 idx);
extern void func_021C7298(void *p, int v);
int func_021C6EA4(u8 *p)
{
    APP_TASKMENU_UpdateMenu(((struct Obj23624 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f310);
    if (APP_TASKMENU_IsFinish(((struct Obj23625 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f310) == 0) {
        return 0xE;
    }
    switch (APP_TASKMENU_GetCursorPos(((struct Obj23626 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f310)) {
    case 0:
        func_021C5B30(p);
        func_021C62F4(p);
        func_021C66B8(*(u8 * *)&((struct Obj00127 *)p)->f8, 2, 0);
        func_021C61CC(*(u8 * *)&((struct Obj00127 *)p)->f8);
        func_021C6884(*(u8 * *)&((struct Obj00127 *)p)->f8);
        func_021C7350(p);
        func_021C66A0(*(u8 * *)&((struct Obj00127 *)p)->f8, 7, 0xE);
        func_021C730C(*(u8 * *)&((struct Obj00127 *)p)->f8);
        return 0xF;
    case 1:
        func_021C5B30(p);
        func_021C630C(p, 0);
        return func_021C71A8((char *)p, 0, 0x11);
    case 2: {
        u8 k;
        func_021C5B30(p);
        k = p[0x1F];
        func_021C7430(p, 0xE, func_020213AC(func_02008FA4(*(void **)(*(u8 * *)&((struct Obj00127 *)p)->f8 + k * 4 + 0x298))), k);
        ((struct Obj00127 *)p)->f14 = 0;
        ((struct Obj00127 *)p)->f28 = 6;
        return func_021C7178(p, 1);
    }
    case -2:
    case 3:
        func_021C5B30(p);
        func_021C62F4(p);
        BGWINFRM_HideFrame(**(void ** *)&((struct Obj00127 *)p)->f8, 10);
        func_021C7298(*(u8 * *)&((struct Obj00127 *)p)->f8, 0);
        func_021C66B8(*(u8 * *)&((struct Obj00127 *)p)->f8, 2, 1);
        return 9;
    default:
        return 0xE;
    }
}

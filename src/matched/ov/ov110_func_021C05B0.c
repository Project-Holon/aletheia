/*
 * function: PMS_SELECT_GRAPHIC_Teardown
 * address: 0x021C05B0
 * packet: pkt_ov110_021C05B0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 90-byte function followed by two zero alignment bytes.
 * lever: inline Clear returns its stored zero, preserving r4 across calls.
 * prototype: own 020355D8 takes u8; the stored zero and returned flag
 *   retain that width through the inline helper and caller local.
 * symbols:
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   UI_SCENE_FreeActorGfx 0x021B6284 thumb ov067
 *   PMS_SELECT_GRAPHIC_DeleteTouchBar 0x021C0AB4 thumb ov110
 *   PMS_SELECT_GRAPHIC_DeleteRows 0x021C0C18 thumb ov110
 *   PMS_SELECT_GRAPHIC_DeleteBg 0x021C07E8 thumb ov110
 *   PMS_SELECT_GRAPHIC_DeleteScene 0x021C16B0 thumb ov110
 *   UI_SetInputMode 0x020355D8 arm
 */
#include "../include/Obj06395.h"
struct PrintSys;
struct TaskMenuState;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
typedef unsigned char u8;
extern void UI_SCENE_FreeActorGfx(unsigned int *);
extern void PMS_SELECT_GRAPHIC_DeleteTouchBar(u8 *);
typedef unsigned int   u32;
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void PMS_SELECT_GRAPHIC_DeleteRows(u8 *);
extern void PMS_SELECT_GRAPHIC_DeleteBg(u8 *);
extern void PMS_SELECT_GRAPHIC_DeleteScene(u8 *);
extern void UI_SetInputMode(u8);
static inline u8 Clear(char *p, u8 i) {
    u8 zero;
    zero = i;
    for (; i < 4; i++) *(int *)(p + 0x7c + i * 4) = zero;
    return zero;
}
void PMS_SELECT_GRAPHIC_Teardown(char *p) {
    u8 z;
    PRINTSYS_QUE_Clear(((struct Obj06395 *)p)->f5C);
    z=Clear(p, 0);
    ((struct Obj06395 *)p)->f4C=z;
    UI_SCENE_FreeActorGfx((unsigned int *)(p+0xc));
    PMS_SELECT_GRAPHIC_DeleteTouchBar((u8 *)p);
    APP_TASKMENU_RES_Delete(((struct Obj06395 *)p)->f64);
    PMS_SELECT_GRAPHIC_DeleteRows((u8 *)p);
    PMS_SELECT_GRAPHIC_DeleteBg((u8 *)(p+0x24));
    PMS_SELECT_GRAPHIC_DeleteScene(((struct Obj06395 *)p)->f50);
    if (((struct Obj06395 *)p)->fA8) z=1;
    UI_SetInputMode(z);
}

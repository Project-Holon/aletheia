/*
 * function: BOX2_SEQ_DeleteBox2Main
 * address:  0x021E1F90
 * packet:   pkt_021E1F90
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_DeleteVBlankTask  0x021DC964  thumb  ov170
 *   BOX2_MAIN_DeleteTaskMenu  0x021DCF30  thumb  ov170
 *   BOX2_UI_DeleteCursorMove  0x021EE3CC  thumb  ov170
 *   BOX2_UI_DeleteWindowFrames  0x021EF310  thumb  ov170
 *   BOX2_SEQ_DeleteBox2UiScene  0x021EBDD8  thumb  ov170
 *   BOX2_SEQ_DeleteBmpWins  0x021EAAC4  thumb  ov170
 *   BOX2_MAIN_DeleteFormTable  0x021DD8F8  thumb  ov170
 *   BOX2_MAIN_DeleteTextSystem  0x021DCE80  thumb  ov170
 *   BOX2_MAIN_DeletePalAnm  0x021DCDD8  thumb  ov170
 *   BOX2_MAIN_DeleteBgSys  0x021DCB48  thumb  ov170
 *   KEY_SetRepeatSpeed  0x02036270  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   ov067_id       0x00000043  data
 */
#include "../include/Obj00000.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void BOX2_MAIN_DeleteVBlankTask(char *p);
extern void BOX2_MAIN_DeleteTaskMenu(char *p);
extern void BOX2_UI_DeleteCursorMove(int *p);
extern void BOX2_UI_DeleteWindowFrames(char *p);
extern void BOX2_SEQ_DeleteBox2UiScene(char *p);
extern void BOX2_SEQ_DeleteBmpWins(char *p);
extern void BOX2_MAIN_DeleteFormTable(char *p);
extern void BOX2_MAIN_DeleteTextSystem(char *p);
extern void BOX2_MAIN_DeletePalAnm(int *p);
extern void BOX2_MAIN_DeleteBgSys(void *p);
extern int KEY_SetRepeatSpeed(int a0, int a1);
extern void ARC_TOOL_DeleteHandle(u32 a);
extern u32 func_020307B0(void *p);
extern void GFL_HEAP_DeleteChecked(unsigned int a);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void func_02034A5C(int a);
extern u8 ov067_id[];

int BOX2_SEQ_DeleteBox2Main(u8 *p)
{
    BOX2_MAIN_DeleteVBlankTask((char *)p);
    BOX2_MAIN_DeleteTaskMenu((char *)p);
    BOX2_UI_DeleteCursorMove((int *)p);
    BOX2_UI_DeleteWindowFrames(((struct Obj00000 *)p)->f2C);
    BOX2_SEQ_DeleteBox2UiScene(((struct Obj00000 *)p)->f2C);
    BOX2_SEQ_DeleteBmpWins((char *)p);
    BOX2_MAIN_DeleteFormTable((char *)p);
    BOX2_MAIN_DeleteTextSystem((char *)p);
    BOX2_MAIN_DeletePalAnm((int *)p);
    BOX2_MAIN_DeleteBgSys(p);
    KEY_SetRepeatSpeed(*(u32 *)(*(u32 *)&((struct Obj00000 *)p)->f2C + 0x4c), *(u32 *)(*(u32 *)&((struct Obj00000 *)p)->f2C + 0x50));
    ARC_TOOL_DeleteHandle(*(u32 *)(*(u32 *)&((struct Obj00000 *)p)->f2C + 0x1b0));
    func_020307B0(((struct Obj00000 *)p)->f2C);
    GFL_HEAP_DeleteChecked(0x4c);
    *(u32 *)&((struct Obj00000 *)p)->f2C = 0;
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    func_02034A5C((int)ov067_id);
    return *(u32 *)&((struct Obj00000 *)p)->f28;
}

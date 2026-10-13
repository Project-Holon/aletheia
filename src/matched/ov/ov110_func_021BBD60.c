/*
 * function: PMSIV_EDIT_Setup
 * address: 0x021BBD60
 * packet: pkt_ov110_021BBD60
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: legacy 02040618 fourth input is unused by its full 02042360 target; caller sets only r0-r2.
 * symbols:
 *   PMSIV_EDIT_LoadPalette 0x021BC068 thumb ov110
 *   PMSIV_EDIT_InitSlotPositions 0x021BC120 thumb ov110
 *   PMSIV_EDIT_CreateWordIcons 0x021BC160 thumb ov110
 *   PMSIV_EDIT_Redraw 0x021BC23C thumb ov110
 *   PMSIV_EDIT_CreateCursors 0x021BC1B8 thumb ov110
 *   func_020498F4 0x020498F4 arm
 *   func_02040618 0x02040618 arm
 *   func_02049658 0x02049658 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BGWINFRM_AddFrame 0x0202CA3C thumb
 *   BGWINFRM_SetFrameDataArcHandle 0x0202CB18 thumb
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   BGWINFRM_PutBmpWin 0x0202CEBC thumb
 *   BGWINFRM_ShowFrame 0x0202CC58 thumb
 */
#include "../include/Obj01922.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef short s16;
typedef signed char s8;
struct WinMgr;
extern void PMSIV_EDIT_LoadPalette(u8 *,void *);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02040618(u32,u32,u32);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void PMSIV_EDIT_InitSlotPositions(u8 *);
extern void PMSIV_EDIT_CreateWordIcons(void *);
extern void PMSIV_EDIT_Redraw(void *);
extern void PMSIV_EDIT_CreateCursors(u8 *);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void BGWINFRM_SetFrameDataArcHandle(struct WinMgr *mgr, u32 idx, void *arc, u32 member, u32 alloc);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void BGWINFRM_PutBmpWin(struct WinMgr *mgr, u32 idx, void *a);
extern void BGWINFRM_ShowFrame(struct WinMgr *mgr, u32 idx);
void PMSIV_EDIT_Setup(u8 *p,u32 a)
{
    PMSIV_EDIT_LoadPalette(p,(void *)a);
    func_020498F4((void *)a,25,0,0,0,0,42);
    func_020498F4((void *)a,25,4,0,0,0,42);
    ((struct Obj01922 *)p)->f19A=-192;
    func_02040618(4,3,((struct Obj01922 *)p)->f19A);
    func_02049658((void *)a,14,0,0,0,0,42);
    func_02049658((void *)a,14,4,0,0,0,42);
    *(u32 *)&((struct Obj01922 *)p)->fC=BMP_WIN_Create(0,3,1,28,4,0,1);
    *(u32 *)&((struct Obj01922 *)p)->f10=BMP_WIN_Create(4,3,1,28,4,0,1);
    BMP_WIN_MakeScreen(((struct Obj01922 *)p)->fC);
    BMP_WIN_MakeScreen(((struct Obj01922 *)p)->f10);
    PMSIV_EDIT_InitSlotPositions(p);
    PMSIV_EDIT_CreateWordIcons(p);
    PMSIV_EDIT_Redraw(p);
    PMSIV_EDIT_CreateCursors(p);
    BGWINFRM_AddFrame(((struct Obj01922 *)p)->f1B4,0,0,32,6);
    BGWINFRM_SetFrameDataArcHandle(((struct Obj01922 *)p)->f1B4,0,(void *)a,25,0);
    BGWINFRM_PutFrame(((struct Obj01922 *)p)->f1B4,0,0,0);
    BGWINFRM_PutBmpWin(((struct Obj01922 *)p)->f1B4,0,((struct Obj01922 *)p)->fC);
    BGWINFRM_ShowFrame(((struct Obj01922 *)p)->f1B4,0);
    ((struct Obj01922 *)p)->f1B8=0;
}

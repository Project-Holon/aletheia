/*
 * function: PMS_INPUT_VIEW_TaskInit
 * address: 0x021B9CE4
 * packet: pkt_ov110_021B9CE4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware DISPCNT words re-read at 9CF6/9D00 and 9D14/9D1C;
 *   BLDCNT halfwords at 04000050 and 04001050 are reset at 9CEC/9CF2.
 * abi: F7C4 live return is the bit test from its tail target ARM9 24158.
 * symbols:
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_020490F4 0x020490F4 arm
 *   PMS_INPUT_VIEW_InitDisplay 0x021BA070 thumb ov110
 *   PMS_INPUT_VIEW_RegisterSpriteResources 0x021B9F34 thumb ov110
 *   PMSIV_EDIT_Create 0x021BBC5C thumb ov110
 *   PMSIV_EDIT_Setup 0x021BBD60 thumb ov110
 *   PMSIV_CATEGORY_Create 0x021BB290 thumb ov110
 *   PMSIV_CATEGORY_Setup 0x021BB328 thumb ov110
 *   PMSIV_WORDWIN_Create 0x021BF844 thumb ov110
 *   PMSIV_WORDWIN_Setup 0x021BF8F4 thumb ov110
 *   func_020498F4 0x020498F4 arm
 *   func_02049658 0x02049658 arm
 *   func_02040588 0x02040588 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   func_02061CA4 0x02061CA4 arm
 *   func_020413B0 0x020413B0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PMS_INPUT_HasInitialSentence 0x021BF7C4 thumb ov110
 *   PMS_INPUT_GetInputMode 0x021BF6D8 thumb ov110
 *   PMS_INPUT_VIEW_PrintHelpMessage 0x021BAD68 thumb ov110
 *   PMS_INPUT_VIEW_LoadBgPalette 0x021BAD2C thumb ov110
 *   PMSIV_MENU_Create 0x021BC990 thumb ov110
 *   PMSIV_MENU_ShowEditEntries 0x021BCB50 thumb ov110
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   GX_DispOn 0x0207D46C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   PMS_INPUT_VIEW_EndTask 0x021B9CBC thumb ov110
 */
#include "../include/Obj00135.h"
#include "../include/Obj22315.h"
#include "../include/Obj22316.h"
#include "../include/Obj22317.h"
#include "../include/Obj22318.h"
#include "../include/Obj22319.h"
#include "../include/Obj22320.h"
#include "../include/Obj22321.h"
#include "../include/Obj22322.h"
#include "../include/Obj22323.h"
#include "../include/Obj22324.h"
#include "../include/Obj22325.h"
#include "../include/Obj22326.h"
#include "../include/Obj22327.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BG_SYS_ClearGraphicsMemory(unsigned);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void PMS_INPUT_VIEW_InitDisplay(u8 *);
extern void PMS_INPUT_VIEW_RegisterSpriteResources(u8 *p, void *archive);
extern u8 *PMSIV_EDIT_Create(void *,u8 *,void *);
extern void PMSIV_EDIT_Setup(u8 *p, u32 a);
extern u8 *PMSIV_CATEGORY_Create(u32 a, u8 *b, u32 c);
extern void PMSIV_CATEGORY_Setup(u8 *p, u32 data);
extern u8 *PMSIV_WORDWIN_Create(void *,void *,void *);
extern void PMSIV_WORDWIN_Setup(u8 *);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
struct Object;
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern int func_02061CA4(void *,u32,u32,int);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern u32 PMS_INPUT_HasInitialSentence(u8 *);
extern u32 PMS_INPUT_GetInputMode(u8 *);
extern void PMS_INPUT_VIEW_PrintHelpMessage(u8 *,int);
extern void PMS_INPUT_VIEW_LoadBgPalette(u8 *,int);
extern u8 *PMSIV_MENU_Create(u8 *,u8 *,void *);
extern void PMSIV_MENU_ShowEditEntries(struct Object *p);
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern void GX_DispOn(void);
extern void ARC_TOOL_DeleteHandle(void *);
extern void PMS_INPUT_VIEW_EndTask(u8 *);
void PMS_INPUT_VIEW_TaskInit(void *unused,u8 *p) {
    void *h;
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= ~0xe000;
    *(volatile u32 *)0x04001000 &= ~0xe000;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)0x04000000 &= ~0x1f00;
    *(volatile u32 *)0x04001000 &= ~0x1f00;
    h=func_020490F4(43,42);
    PMS_INPUT_VIEW_InitDisplay(p);
    PMS_INPUT_VIEW_RegisterSpriteResources(p,(void *)h);
    *(u8 * *)&((struct Obj22315 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f54=PMSIV_EDIT_Create(*(u8 * *)&((struct Obj00135 *)p)->f0,*(u8 * *)&((struct Obj00135 *)p)->f4,((struct Obj00135 *)p)->f8);
    PMSIV_EDIT_Setup(*(u8 * *)&((struct Obj22316 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f54,(u32)h);
    *(u8 * *)&((struct Obj22317 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f58=PMSIV_CATEGORY_Create((u32)(*(u8 * *)&((struct Obj00135 *)p)->f0),*(u8 * *)&((struct Obj00135 *)p)->f4,(u32)(((struct Obj00135 *)p)->f8));
    PMSIV_CATEGORY_Setup(*(u8 * *)&((struct Obj22318 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f58,(u32)h);
    *(u8 * *)&((struct Obj22319 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f5C=PMSIV_WORDWIN_Create(*(u8 * *)&((struct Obj00135 *)p)->f0,*(u8 * *)&((struct Obj00135 *)p)->f4,((struct Obj00135 *)p)->f8);
    PMSIV_WORDWIN_Setup(*(u8 * *)&((struct Obj22320 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f5C);
    func_020498F4((void *)((u32)h),30,5,0,0,0,42);
    func_02049658((void *)((u32)h),18,5,0,0,0,42);
    func_020498F4((void *)((u32)h),31,6,0,0,0,42);
    func_02049658((void *)((u32)h),18,6,0,0,0,42);
    func_02040588(6,0);
    ARC_UTIL_UploadPaletteFromHandle((void *)((u32)h),4,4,128,160,32,42);
    ((struct Obj22321 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f68=0x294b;
    func_02061CA4((void *)31,188,(u32)(*(u8 * *)&((struct Obj00135 *)p)->f0+0x68),2);
    ((struct Obj22322 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f6A=0x5694;
    func_02061CA4((void *)31,190,(u32)(*(u8 * *)&((struct Obj00135 *)p)->f0+0x6a),2);
    func_02049658((void *)((u32)h),18,7,0,0,0,42);
    func_020498F4((void *)((u32)h),24,7,0,0,0,42);
    func_020413B0(7,0,0,32,32,5);
    ((struct Obj22323 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f6C=BMP_WIN_Create(7,3,5,26,7,5,1);
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)((struct Obj22324 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f6C),7);
    ((struct Obj22325 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f70=0;
    if(PMS_INPUT_HasInitialSentence(*(u8 * *)&((struct Obj00135 *)p)->f4) || PMS_INPUT_GetInputMode(*(u8 * *)&((struct Obj00135 *)p)->f4)!=2) PMS_INPUT_VIEW_PrintHelpMessage(p,1);
    else PMS_INPUT_VIEW_PrintHelpMessage(p,0);
    PMS_INPUT_VIEW_LoadBgPalette(*(u8 * *)&((struct Obj00135 *)p)->f0,0);
    *(u8 * *)&((struct Obj22326 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f64=PMSIV_MENU_Create(*(u8 * *)&((struct Obj00135 *)p)->f0,*(u8 * *)&((struct Obj00135 *)p)->f4,((struct Obj00135 *)p)->f8);
    PMSIV_MENU_ShowEditEntries((struct Object *)(*(u8 * *)&((struct Obj22327 *)(*(u8 * *)&((struct Obj00135 *)p)->f0))->f64));
    func_02040588(0,1);
    BG_SYS_SetMainPlaneVisible(16,1);
    BG_SYS_SetSubPlaneVisible(16,1);
    GX_DispOn();
    func_02049658((void *)((u32)h),16,3,0,0,0,42);
    func_02049658((void *)((u32)h),17,3,96,0,0,42);
    ARC_TOOL_DeleteHandle(h);
    PMS_INPUT_VIEW_EndTask(p);
}

/*
 * function: OEKAKI_LoadSpriteResources
 * address:  0x02184C48
 * packet:   pkt_ov023_02184C48
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020275E4  0x020275E4  thumb
 *   func_020490F4  0x020490F4  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   gClActorInitParam     0x020A1448  data  a4
 *   gOekakiVramBanks     0x02186ACC  data  ov023  a4
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   func_02027618  0x02027618  thumb
 *   func_02027614  0x02027614  thumb
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */
#include "../include/Obj00049.h"

typedef unsigned char u8;
typedef unsigned int  u32;

typedef unsigned short u16;

extern u8 gClActorInitParam[];
extern u8 gOekakiVramBanks[];
extern u32 func_020275E4(void);
extern void *func_020490F4(u32 id, u32 heap);
struct Bank;
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
typedef signed int     s32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void ARC_TOOL_DeleteHandle(void *h);

void OEKAKI_LoadSpriteResources(u8 *p, void *q)
{
    void *h;
    u32 t;

    h = func_020490F4(func_020275E4(), 0x28);
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam, (u32)gOekakiVramBanks, 0x28);
    ((struct Obj00049 *)p)->f38 = (u32)CLACT_CreateUnit(0x35, 1, 0x28);
    ((struct Obj00049 *)p)->f40 = CLACT_RegisterCharacter(q, 3, 0, 0, 0x28);
    ((struct Obj00049 *)p)->f3C = CLACT_RegisterPalette(q, 0, 0, 0, 0x28);
    ((struct Obj00049 *)p)->f44 = CLACT_RegisterCellAnim(q, 5, 8, 0x28);
    ((struct Obj00049 *)p)->f4C = CLACT_RegisterCharacter(h, func_02027618(), 0, 0, 0x28);
    ((struct Obj00049 *)p)->f48 = CLACT_RegisterPaletteEx(h, func_02027614(), 0, 0x160, 0, 3, 0x28);
    t = func_0202761C(0);
    ((struct Obj00049 *)p)->f50 = CLACT_RegisterCellAnim(h, t, func_02027620(0), 0x28);
    ((struct Obj00049 *)p)->f58 = CLACT_RegisterCharacter(q, 3, 0, 1, 0x28);
    ((struct Obj00049 *)p)->f54 = CLACT_RegisterPalette(q, 0, 1, 0, 0x28);
    ((struct Obj00049 *)p)->f5C = CLACT_RegisterCellAnim(q, 5, 8, 0x28);
    ARC_TOOL_DeleteHandle(h);
}

/*
 * function: VS_MULTI_LIST_LoadIconResources
 * address: 0x021F6F88
 * packet: pkt_ov097_021F6F88
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: integer object base; the icon array address comes from a static
 * inline accessor of field fB4 (the inlined parameter and the result share
 * one spill slot: str p; adds #0xb4; str); merged icon is u16.
 * note 2026-10-05: replaced the stand-in `icons = p; icons = p + 0xb4;`
 * with the accessor IconBase(p). EXACT in --lang c99 and --lang c. An
 * accessor returning u32 * with icons[i] stores gives DIFF; one that copies
 * into a local and adds (r = obj; r += 0xb4) gives DIFF.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   POKE_TOOL_GetGraphicIndex 0x0201BA68 thumb
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCEC 0x0201BCEC thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020275E4 0x020275E4 thumb
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   func_0202775C 0x0202775C thumb
 *   func_02027758 0x02027758 thumb
 *   func_02027760 0x02027760 thumb
 *   func_02027764 0x02027764 thumb
 */
#include "../include/Obj00410.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
extern void *POKE_TOOL_GetBoxParam(void *);
extern u32 POKE_TOOL_GetGraphicIndex(void *);
extern u32 POKE_TOOL_CalcGraphicIndex(u32, u32, u32, u32);
extern int CLACT_RegisterCharacter(void *, u32, u32, u32, u16);
extern int func_0201BC3C(void);
extern int CLACT_RegisterPaletteCompressed(void *, u32, u32, u32, u16);
extern int func_0201BC78(void);
extern int func_0201BCEC(void);
extern int CLACT_RegisterCellAnim(void *, u32, u32, u32);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 func_020275E4(void);
extern int CLACT_RegisterPalette(void *, u32, u32, u32, u16);
extern int func_0202775C(int);
extern int func_02027758(void);
extern int func_02027760(int);
extern int func_02027764(int);
static inline u32 IconBase(int obj)
{
    return (u32)&((struct Obj00410 *)obj)->fB4;
}
void VS_MULTI_LIST_LoadIconResources(int p)
{
    u32 a, b;
    void *h;
    void *h2;
    u16 i, icon;
    u32 icons;
    h = func_020490F4(7, 0x8071);
    icons = IconBase(p);
    for (i = 0; i < 6; i++) {
        if (*(void **)(p + i * 4 + 0xf8) != 0)
            icon = POKE_TOOL_GetGraphicIndex(POKE_TOOL_GetBoxParam(*(void **)(p + i * 4 + 0xf8)));
        else
            icon = POKE_TOOL_CalcGraphicIndex(0, 0, 0, 0);
        *(int *)(icons + i * 4) = CLACT_RegisterCharacter(h, icon, 0, 0, 0x71);
    }
    *(int *)&((struct Obj00410 *)p)->fD8 = CLACT_RegisterPaletteCompressed(h, func_0201BC3C(), 0, 0, 0x71);
    a = func_0201BC78();
    b = func_0201BCEC();
    *(int *)&((struct Obj00410 *)p)->fE8 = CLACT_RegisterCellAnim(h, a, b, 0x71);
    ARC_TOOL_DeleteHandle(h);
    h2 = func_020490F4(func_020275E4(), 0x8071);
    ((struct Obj00410 *)p)->fD0 = CLACT_RegisterCharacter(h2, 0xc, 0, 0, 0x71);
    ((struct Obj00410 *)p)->fE0 = CLACT_RegisterPalette(h2, 0xb, 0, 0x60, 0x71);
    ((struct Obj00410 *)p)->fF0 = CLACT_RegisterCellAnim(h2, 0xf, 0x12, 0x71);
    ((struct Obj00410 *)p)->fCC = CLACT_RegisterCharacter(h2, 0x41, 0, 0, 0x71);
    ((struct Obj00410 *)p)->fDC = CLACT_RegisterPalette(h2, 0x42, 0, 0x80, 0x71);
    ((struct Obj00410 *)p)->fEC = CLACT_RegisterCellAnim(h2, 0x45, 0x48, 0x71);
    ((struct Obj00410 *)p)->fD4 = CLACT_RegisterCharacter(h2, func_0202775C(2), 0, 0, 0x71);
    ((struct Obj00410 *)p)->fE4 = CLACT_RegisterPalette(h2, func_02027758(), 0, 0xa0, 0x71);
    a = func_02027760(2);
    b = func_02027764(2);
    ((struct Obj00410 *)p)->fF4 = CLACT_RegisterCellAnim(h2, a, b, 0x71);
    ARC_TOOL_DeleteHandle(h2);
}

/*
 * function: func_021D614C
 * address: 0x021D614C
 * packet: pkt_ov123_021D614C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: 02049990 stack argument 4 is u16 here: the original explicitly
 * truncates it at 021D6184/021D6186 and the three later call sites.
 * interface: 02049F78 forwards its third word unchanged to 02062A98's
 * void **out; original 021D61C2 supplies p+0x18, so the extern names it.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_021D6404 0x021D6404 thumb ov123
 */
#include "../include/Obj00343.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049740(void *,u32,u32,u32,u32,u16);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_021D6404(u8 *);
void func_021D614C(u8 *p)
{
    void *h;
    h=func_020490F4((u32)((void *)143),((struct Obj00343 *)p)->f43C4);
    func_02049B68(h,2,4,0,0,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f0=func_02049740(h,8,4,0,0,((struct Obj00343 *)p)->f43C4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h,21,4,0,(u16)(((struct Obj00343 *)p)->f0),0,0,((struct Obj00343 *)p)->f43C4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h,24,7,0,(u16)(((struct Obj00343 *)p)->f4),0,0,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f1C=ARC_UTIL_LoadPaletteBlockFromHandle(h,2,(u32)((void **)(p+0x18)),((struct Obj00343 *)p)->f43C4);
    func_02049B68(h,2,0,0,0,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f4=func_02049740(h,8,0,0,0,((struct Obj00343 *)p)->f43C4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h,23,0,0,(u16)(((struct Obj00343 *)p)->f4),0,0,((struct Obj00343 *)p)->f43C4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h,24,1,0,(u16)(((struct Obj00343 *)p)->f4),0,0,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f38=(void *)CLACT_RegisterCharacter(h,9,0,2,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f20=(void *)CLACT_RegisterPaletteEx(h,3,2,96,0,4,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f54=(void *)CLACT_RegisterCellAnim(h,12,25,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f3C=(void *)CLACT_RegisterCharacter(h,10,0,2,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f24=(void *)CLACT_RegisterPaletteEx(h,4,2,224,0,0,((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f58=(void *)CLACT_RegisterCellAnim(h,13,26,((struct Obj00343 *)p)->f43C4);
    func_021D6404(p); ARC_TOOL_DeleteHandle(h);
}

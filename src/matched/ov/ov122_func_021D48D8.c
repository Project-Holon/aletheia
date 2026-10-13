/*
 * function: func_021D48D8
 * address: 0x021D48D8
 * packet: pkt_ov122_021D48D8
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: 02049990 argument 5 is u16: original truncates the value at 021D49B4/49D2.
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049740 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02049B40 0x02049B40 arm
 *   func_021D4644 0x021D4644 thumb ov122
 *   func_021D46CC 0x021D46CC thumb ov122
 *   data_021D5870 0x021D5870 data a2
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 */
#include "../include/Obj00073.h"
#include "../include/Obj13963.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct GfFont;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
typedef signed int     s32;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u16 data_021D5870[];
extern void func_021D4644(u16 *, const u16 *, int);
extern u32 func_020307B0(void *p);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(u32);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
extern void func_021D46CC(char *);
void func_021D48D8(char *p)
{
    u32 arc;
    void *resource;
    char *palette;
    ((struct Obj00073 *)p)->f54 = STRBUF_Create(200, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f58 = STRBUF_Create(200, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f50 = STRBUF_Create(200, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f3C = (void *)BMP_WIN_Create(5, 16, 10, 10, 2, 13, 0);
    ((struct Obj00073 *)p)->f4C = GF_FONT_Create(23, 0, 0, 0, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f44 = func_02045B38(0, 2, 23, ((struct Obj00073 *)p)->fC);
    arc = (u32)func_020490F4(29, ((struct Obj00073 *)p)->fC);
    func_02049B68((void *)arc, 0, 0, 0, 0, ((struct Obj00073 *)p)->fC);
    func_02049B68((void *)arc, 1, 4, 0, 0, ((struct Obj00073 *)p)->fC);
    resource = ARC_UTIL_LoadPaletteBlockFromHandle((void *)arc, 1, (u32)&palette, ((struct Obj00073 *)p)->fC);
    MI_CpuCopy8(((struct Obj13963 *)palette)->fC, p + 0x12c, 0xe0);
    MI_CpuCopy8(((struct Obj13963 *)palette)->fC, p + 0x20c, 0xe0);
    func_021D4644((u16 *)(p + 0x20c), data_021D5870, 7);
    func_020307B0(resource);
    ((struct Obj00073 *)p)->f60 = func_02049740((void *)arc, 4, 4, 0, 0, ((struct Obj00073 *)p)->fC);
    ARC_UTIL_UploadBgPaletteAddFromHandle((void *)arc, 9, 4, 0, (u16)(((struct Obj00073 *)p)->f60), 0, 0, ((struct Obj00073 *)p)->fC);
    ARC_UTIL_UploadBgPaletteAddFromHandle((void *)arc, 15, 6, 0, (u16)(((struct Obj00073 *)p)->f60), 0, 0, ((struct Obj00073 *)p)->fC);
    *(int *)&((struct Obj00073 *)p)->f37C = CLACT_RegisterCharacter((void *)arc, 5, 0, 1, ((struct Obj00073 *)p)->fC);
    *(int *)&((struct Obj00073 *)p)->f378 = CLACT_RegisterPaletteEx((void *)arc, 3, 1, 0, 0, 10, ((struct Obj00073 *)p)->fC);
    *(int *)&((struct Obj00073 *)p)->f380 = CLACT_RegisterCellAnim((void *)arc, 7, 16, ((struct Obj00073 *)p)->fC);
    ARC_TOOL_DeleteHandle(arc);
    ((struct Obj00073 *)p)->f5C = func_0201F5DC((void *)5, 11, 0, ((struct Obj00073 *)p)->fC);
    func_02049B40(23, 5, 4, 384, 32, ((struct Obj00073 *)p)->fC);
    func_021D46CC(p);
}

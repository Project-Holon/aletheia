/*
 * function: GSYNC_MENU_LoadResources
 * address: 0x021D4884
 * packet: pkt_ov123_021D4884
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: 02049990 arg5 is u16 at both original call-site truncations; 02049F78 arg3 is an unchanged address payload passed to 02062A98, whose body stores through it.
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   GSYNC_MENU_AddPaletteEntries 0x021D43B8 thumb ov123
 *   func_020307B0 0x020307B0 arm
 *   func_02049740 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   func_02049B40 0x02049B40 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   GSYNC_MENU_CreateActors 0x021D478C thumb ov123
 *   d_021DA9D0 0x021DA9D0 data a4
 */
#include "../include/Obj00471.h"
#include "../include/Obj13968.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021DA9D0[];
struct GfFont;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
typedef signed int     s32;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void MI_CpuCopy8(const void *, void *, u32);
extern void GSYNC_MENU_AddPaletteEntries(u16 *p, const u16 *add, int n);
extern u32 func_020307B0(void *p);
extern u32 func_02049740(void *, u32, u32, u32, u32, u16);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void ARC_TOOL_DeleteHandle(void *);
extern void *BMP_MENUWORK_LoadFrameGfx(void *, u32, u32, u32);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void GSYNC_MENU_CreateActors(char *);
void GSYNC_MENU_LoadResources(char *p)
{
    void *h;
    void *allocated;
    void *record;
    ((struct Obj00471 *)p)->f38 = STRBUF_Create(300, ((struct Obj00471 *)p)->fC);
    ((struct Obj00471 *)p)->f30 = GF_FONT_Create(23, 0, 0, 0, ((struct Obj00471 *)p)->fC);
    ((struct Obj00471 *)p)->f24 = func_02045B38(0, 2, 39, ((struct Obj00471 *)p)->fC);
    ((struct Obj00471 *)p)->f28 = func_02045B38(0, 2, 232, ((struct Obj00471 *)p)->fC);
    h = func_020490F4((u32)((void *)29), ((struct Obj00471 *)p)->fC);
    func_02049B68(h, 1, 4, 0, 0, ((struct Obj00471 *)p)->fC);
    func_02049B68(h, 0, 0, 0, 0, ((struct Obj00471 *)p)->fC);
    allocated = ARC_UTIL_LoadPaletteBlockFromHandle(h, 1, (u32)(&record), ((struct Obj00471 *)p)->fC);
    MI_CpuCopy8(((struct Obj13968 *)record)->fC, p + 0x44, 0xe0);
    MI_CpuCopy8(((struct Obj13968 *)record)->fC, p + 0x124, 0xe0);
    GSYNC_MENU_AddPaletteEntries((u16 *)(p + 0x124), (const u16 *)d_021DA9D0, 7);
    func_020307B0(allocated);
    ((struct Obj00471 *)p)->f40 = func_02049740(h, 4, 4, 0, 0, ((struct Obj00471 *)p)->fC);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 9, 4, 0, (u16)(((struct Obj00471 *)p)->f40), 0, 0, ((struct Obj00471 *)p)->fC);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 14, 6, 0, (u16)(((struct Obj00471 *)p)->f40), 0, 0, ((struct Obj00471 *)p)->fC);
    ARC_TOOL_DeleteHandle(h);
    ((struct Obj00471 *)p)->f3C = BMP_MENUWORK_LoadFrameGfx((void *)5, 12, 0, ((struct Obj00471 *)p)->fC);
    func_02049B40(23, 5, 4, 0x1a0, 32, ((struct Obj00471 *)p)->fC);
    h = func_020490F4((u32)((void *)29), ((struct Obj00471 *)p)->fC);
    ((struct Obj00471 *)p)->f294 = (void *)CLACT_RegisterCharacter(h, 5, 0, 1, ((struct Obj00471 *)p)->fC);
    ((struct Obj00471 *)p)->f290 = (void *)CLACT_RegisterPaletteEx(h, 3, 1, 0, 0, 10, ((struct Obj00471 *)p)->fC);
    ((struct Obj00471 *)p)->f298 = (void *)CLACT_RegisterCellAnim(h, 7, 16, ((struct Obj00471 *)p)->fC);
    ARC_TOOL_DeleteHandle(h);
    GSYNC_MENU_CreateActors(p);
}

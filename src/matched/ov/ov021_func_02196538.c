/*
 * function: IRCBATTLEMENU_LoadMenuGraphics
 * address:  0x02196538
 * packet:   pkt_ov021_02196538
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle  0x02049990  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle  0x02049F78  arm
 *   func_02082D44  0x02082D44  arm
 *   IRCBATTLEMENU_BrightenPalette  0x021964B0  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_0201F5DC  0x0201F5DC  thumb
 *   func_02049B40  0x02049B40  arm
 *   sMenuPlttRowOffsets     0x021DDAD4  data  ov021  a2
 */
#include "../include/Obj00150.h"
#include "../include/Obj12630.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct GfFont;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(void *src, void *dst, u32 n);
extern void IRCBATTLEMENU_BrightenPalette(u16 (*dst)[16], u16 *add, int n);
extern u32 func_020307B0(void *p);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern const u16 sMenuPlttRowOffsets[];

void IRCBATTLEMENU_LoadMenuGraphics(u8 *p)
{
    void *h;
    void *res;
    u8 *pal;

    ((struct Obj00150 *)p)->f2F8 = 0;
    ((struct Obj00150 *)p)->f38 = STRBUF_Create(0x12C, ((struct Obj00150 *)p)->f10);
    ((struct Obj00150 *)p)->f2C = GF_FONT_Create(0x17, 0, 0, 0, ((struct Obj00150 *)p)->f10);
    ((struct Obj00150 *)p)->f28 = func_02045B38(0, 2, 0x2E, ((struct Obj00150 *)p)->f10);

    h = func_020490F4(0x1C, ((struct Obj00150 *)p)->f10);
    func_02049B68(h, 1, 0, 0, 0, ((struct Obj00150 *)p)->f10);
    ((struct Obj00150 *)p)->f44 = func_02049740(h, 6, 0, 0, 0, ((struct Obj00150 *)p)->f10);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 0xD, 0, 0, (u16)((struct Obj00150 *)p)->f44, 0, 0, ((struct Obj00150 *)p)->f10);
    ARC_TOOL_DeleteHandle(h);

    h = func_020490F4(0x1D, ((struct Obj00150 *)p)->f10);
    func_02049B68(h, 2, 4, 0, 0, ((struct Obj00150 *)p)->f10);
    res = ARC_UTIL_LoadPaletteBlockFromHandle(h, 2, (u32)(&pal), ((struct Obj00150 *)p)->f10);
    func_02082D44(((struct Obj12630 *)pal)->fC, p + 0x48, 0x100);
    func_02082D44(((struct Obj12630 *)pal)->fC, p + 0x148, 0x100);
    IRCBATTLEMENU_BrightenPalette((u16 (*)[16])(p + 0x148), (u16 *)sMenuPlttRowOffsets, 8);
    func_020307B0(res);
    func_02049B68(h, 0, 0, 0, 0, ((struct Obj00150 *)p)->f10);
    ((struct Obj00150 *)p)->f40 = func_02049740(h, 4, 4, 0, 0, ((struct Obj00150 *)p)->f10);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 9, 4, 0, (u16)((struct Obj00150 *)p)->f40, 0, 0, ((struct Obj00150 *)p)->f10);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 0xB, 6, 0, (u16)((struct Obj00150 *)p)->f40, 0, 0, ((struct Obj00150 *)p)->f10);
    ARC_TOOL_DeleteHandle(h);

    ((struct Obj00150 *)p)->f3C = func_0201F5DC((void *)5, 0xC, 0, ((struct Obj00150 *)p)->f10);
    func_02049B40(0x17, 5, 4, 0x160, 0x20, ((struct Obj00150 *)p)->f10);
}

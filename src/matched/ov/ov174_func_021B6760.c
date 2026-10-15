/*
 * function: LOCAL_TVT_SYS_CreateTextResources
 * address:  0x021B6760
 * packet:   pkt_021B6760
 * region:   ov174
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 *   BMP_MENUWORK_GetPlttFileId  0x0201F548  thumb
 *   ARC_UTIL_UploadPaletteFromArchive  0x02049B90  arm
 *   func_02049B40  0x02049B40  arm
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb
 *   TCBL_Create  0x0203101C  arm
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   func_02028590  0x02028590  thumb
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 */
#include "../include/Obj00918.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct GfFont;
struct MsgBank;
struct Tcbl;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u8 BMP_MENUWORK_GetPlttFileId(int i);
extern void ARC_UTIL_UploadPaletteFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void GF_FONT_SetDefaultTextColor(void);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 PRINTSYS_QUE_Create(void *p);
extern u32 func_02028590(int a, int b, int c, u32 d);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);

void LOCAL_TVT_SYS_CreateTextResources(u8 *p)
{
    ((struct Obj00918 *)p)->f60 = (u32)GF_FONT_Create(0x17, 0, 0, 0, ((struct Obj00918 *)p)->f0);
    ((struct Obj00918 *)p)->f68 = (u32)func_02045B38(0, 2, 0xc6, ((struct Obj00918 *)p)->f0);
    ((struct Obj00918 *)p)->f6C = (u32)func_02045B38(0, 2, (u16)(*(u16 *)(((struct Obj00918 *)p)->f30) + 0xbf), ((struct Obj00918 *)p)->f0);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 0xd, 0, ((struct Obj00918 *)p)->f0);
    ARC_UTIL_UploadPaletteFromArchive(5, BMP_MENUWORK_GetPlttFileId(0), 0, 0x20, 0x1a0, 0x20, ((struct Obj00918 *)p)->f0);
    func_02049B40(0x17, 7, 0, 0x180, 0x20, ((struct Obj00918 *)p)->f0);
    GF_FONT_SetDefaultTextColor();
    ((struct Obj00918 *)p)->f58 = (u32)TCBL_Create(((struct Obj00918 *)p)->f0, ((struct Obj00918 *)p)->f0, 3, 0x100);
    ((struct Obj00918 *)p)->f64 = 0;
    ((struct Obj00918 *)p)->f5C = 0;
    ((struct Obj00918 *)p)->f70 = 0;
    ((struct Obj00918 *)p)->f74 = 0;
    ((struct Obj00918 *)p)->f78 = PRINTSYS_QUE_Create((void *)(((struct Obj00918 *)p)->f0));
    ((struct Obj00918 *)p)->f7C = func_02028590(0xf, 1, 1, ((struct Obj00918 *)p)->f0);
    GF_FONT_SetTextColor(1, 2, 0xf);
}

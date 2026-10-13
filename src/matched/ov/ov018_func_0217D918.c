/*
 * function: INTRUDE_SUBDISP_ClactResourceLoad
 * address:  0x0217D918
 * packet:   pkt_ov018_0217D918
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   func_020490F4  0x020490F4  arm
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   ARC_UTIL_LoadBgCharDataFromHandle  0x02049DF4  arm
 *   CLACT_GetCharacterVramAddress  0x0204ABBC  arm
 *   func_02030734  0x02030734  arm
 *   func_02082A60  0x02082A60  arm
 *   d_02183B14     0x02183B14  data   a1
 */
#include "../include/Obj02676.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed int     s32;
extern s32 CLACT_RegisterPaletteEx(void *a, unsigned int b, unsigned int c, unsigned int d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, unsigned int b, unsigned int c, unsigned int a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, unsigned int first, unsigned int second, unsigned int mode);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int CLACT_RegisterPaletteCompressed(void *a0, unsigned int a1, unsigned int a2, unsigned int a3, u16 a4);
extern void ARC_TOOL_DeleteHandle(void *);
extern void *ARC_UTIL_LoadBgCharDataFromHandle(void *a0, unsigned int a1, unsigned int a2, unsigned int a3, u16 a4);
extern int CLACT_GetCharacterVramAddress(unsigned int idx, unsigned int flag);
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082A60(const void *, void *, int);
extern const char d_02183B14[];

void INTRUDE_SUBDISP_ClactResourceLoad(u8 *p, void *bg)
{
    void *t;

    ((struct Obj02676 *)p)->f8 = (void *)CLACT_RegisterPaletteEx(bg, 3, 1, 0, 0, 9, 0x15);
    ((struct Obj02676 *)p)->f4 = (void *)CLACT_RegisterCharacter(bg, 0, 1, 1, 0x15);
    ((struct Obj02676 *)p)->f10 = (void *)CLACT_RegisterCellAnim(bg, 1, 2, 0x70);
    t = func_020490F4(0x17, 0x15);
    ((struct Obj02676 *)p)->fC = (void *)CLACT_RegisterPaletteCompressed(t, 5, 1, 0x1a0, 0x15);
    ARC_TOOL_DeleteHandle(t);
    ((struct Obj02676 *)p)->f14 = (void *)CLACT_RegisterCharacter(bg, 10, 1, 1, 0x15);
    ((struct Obj02676 *)p)->f18 = (void *)CLACT_RegisterCellAnim(bg, 12, 13, 0x70);
    ((struct Obj02676 *)p)->fC8 = ARC_UTIL_LoadBgCharDataFromHandle(bg, 10, 1, (unsigned int)(p + 0xcc), 0x70);
    ((struct Obj02676 *)p)->fD4 = (void *)CLACT_GetCharacterVramAddress((unsigned int)(((struct Obj02676 *)p)->f14), 2);
    ((struct Obj02676 *)p)->fD0 = func_02030734(0x70, 0x200, 1, d_02183B14, 0x495);
    func_02082A60((void *)0x050006E2, p + 0x120, 8);
    func_02082A60(p + 0x120, p + 0x130, 8);
    func_02082A60((void *)0x05000702, p + 0x128, 8);
}

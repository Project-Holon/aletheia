/*
 * function: ITEMMENU_LoadPocketGraphics
 * address:  0x021B9EF4
 * packet:   pkt_ov070_021B9EF4
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * lever:    the loop's array slots are spelled `p + i * 4 + 0x614` (index
 *           before offset), which keeps `p + i*4` in one register across both
 *           calls; `p + 0x614 + i * 4` and `((int *)(p + 0x614))[i]` both DIFF.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   BMP_Create  0x02043678  arm
 *   func_02008550  0x02008550  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */
#include "../include/Obj00963.h"

typedef unsigned int u32;
typedef unsigned short u16;

extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
typedef unsigned char  u8;
struct Bmp;
struct Sub0200852CObj;
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void ARC_TOOL_DeleteHandle(void *);

void ITEMMENU_LoadPocketGraphics(char *p)
{
    void *bg;
    int i;

    bg = func_020490F4(0x58, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f574 = CLACT_RegisterPaletteEx(bg, 0x20, 0, 0x1a0, 0, 1, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f578 = CLACT_RegisterCharacter(bg, 0x1f, 0, 0, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f57C = CLACT_RegisterCellAnim(bg, 0x1e, 0x1d, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f554 = CLACT_RegisterPaletteEx(bg, 0x1c, 0, 0x60, 0, 1, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f560 = CLACT_RegisterCharacter(bg, 0x1b, 0, 0, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f568 = CLACT_RegisterCellAnim(bg, 0x1a, 0x19, ((struct Obj00963 *)p)->f544);
    for (i = 0; i < 8; i++) {
        *(int *)(p + i * 4 + 0x614) = (int)BMP_Create(0xc, 2, 0x20, ((struct Obj00963 *)p)->f544);
        *(int *)(p + i * 4 + 0x5F4) =CLACT_RegisterCharacter(bg, 0x14, 0, 0, ((struct Obj00963 *)p)->f544);
    }
    func_02008550((const struct Sub0200852CObj *)(((struct Obj00963 *)p)->f8));
    ((struct Obj00963 *)p)->f588 = CLACT_RegisterPaletteEx(bg, 0x15, 0, 0, 0, 3, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f56C = CLACT_RegisterCellAnim(bg, 0x13, 0x12, ((struct Obj00963 *)p)->f544);
    ARC_TOOL_DeleteHandle(bg);
}

/*
 * function: WORLDTRADE_TITLE_LoadSubBgSwap
 * address:  0x02200B34
 * packet:   pkt_02200B34
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandleExt  0x020499D4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 */
#include "../include/Obj00137.h"

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandleExt(void *h, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void ARC_TOOL_DeleteHandle(void *h);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);

void WORLDTRADE_TITLE_LoadSubBgSwap(u8 *p)
{
    void *h;

    if (((struct Obj00137 *)p)->f12E0 == 1 && ((struct Obj00137 *)p)->f12E4 == 0) {
        h = func_020490F4(0x60, 0x48);
        func_02049B68(h, 5, 4, 0, 0x20, 0x48);
        func_02049658(h, 0xf, 6, 0, 0, 0, 0x48);
        ARC_UTIL_UploadBgPaletteAddFromHandleExt(h, 0x22, 6, 0, 0, 0, 0, 0x48);
        ARC_TOOL_DeleteHandle(h);
    }
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00137 *)p)->fD38, 1);
}

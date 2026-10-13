/*
 * function: SCRCMD_PROC_FLD_UpdateItemIcon
 * address:  0x021B3D60
 * packet:   pkt_ov021_021B3D60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02020E60 0x02020E60 thumb
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   ARC_UTIL_LoadScreenDataFromHandle 0x02049E74 arm
 *   CLACT_TransferPalette 0x0204ADEC arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj03132.h"

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02020E60(u32 a, u32 b);
struct Sub0204A9D0;
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void *ARC_UTIL_LoadScreenDataFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void CLACT_TransferPalette(u32 a, u32 b, u32 c);
extern void CLACT_TransferCharacter(int a, struct Sub0204A9D0 *b);
extern u32 func_020307B0(void *p);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

void SCRCMD_PROC_FLD_UpdateItemIcon(char *w, u32 b)
{
    u32 y;
    u32 x;
    u32 p;
    u32 q;

    if (b <= 0x272) {
        p = (u32)ARC_UTIL_LoadPaletteBlockFromHandle((void *)(((struct Obj03132 *)w)->f1F8), func_02020E60(b, 2), (u32)(&x), ((struct Obj03132 *)w)->f4);
        q = (u32)ARC_UTIL_LoadScreenDataFromHandle((void *)(((struct Obj03132 *)w)->f1F8), func_02020E60(b, 1), 0, (u32)(&y), ((struct Obj03132 *)w)->f4);
        CLACT_TransferPalette(((struct Obj03132 *)w)->f1EC, x, 1);
        CLACT_TransferCharacter(((struct Obj03132 *)w)->f1F0, (struct Sub0204A9D0 *)y);
        func_020307B0((void *)p);
        func_020307B0((void *)q);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj03132 *)w)->f1D0, 1);
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj03132 *)w)->f1D0, 0);
    }
}

/*
 * function: C_GEAR_LoadSkin
 * address:  0x021F1458
 * packet:   pkt_ov029_021F1458
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The 0x230 table must be a struct member (u16 [3][5]); a raw cast keeps
 * p + 0x230 in ip and spills the source pointer instead. `n` is declared
 * before `r` so the counter lands at [sp,#0x20] and the handle at [sp,#0x1c].
 *
 * symbols:
 *   C_GEAR_LoadSkin  0x021F1458  thumb  ov029
 *   ARC_UTIL_LoadPaletteBlockFromHandle  0x02049F78  arm
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   func_0207E468  0x0207E468  arm
 *   func_020307B0  0x020307B0  arm
 *   C_GEAR_LoadTargetPalette  0x021F09B4  thumb  ov029
 *   BG_SYS_CreateRun  0x0203FA08  arm
 *   func_02049658  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle  0x02049990  arm
 *   d_021F31E0     0x021F31E0  data  a4
 *   d_021F31A8     0x021F31A8  data  ov029  a1
 *   d_021F32E0     0x021F32E0  data  a4
 */
#include "../include/Obj04308.h"
#include "../include/Obj05116.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct W {
    u8 pad0[0x230];
    u16 unk_230[3][5];
};

extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void DWCi_ScreenDC_FlushRange(void *a, u32 b);
extern void func_0207E468(void *a, u32 b, u32 c);
extern u32 func_020307B0(void *p);
extern void C_GEAR_LoadTargetPalette(unsigned char *p, unsigned char *q, int n);
extern u32 BG_SYS_CreateRun(u32 a, u32 b, u32 c);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern const int d_021F31E0[];
extern const u8 d_021F31A8[];
extern const int d_021F32E0[][3];

u32 C_GEAR_LoadSkin(u8 *p, int a, int b, int c)
{
    int n;
    int r;
    char *loc;
    u8 *src;
    int m;
    int k;
    u32 size;
    u32 v;

    if (c) {
        r = (int)ARC_UTIL_LoadPaletteBlockFromHandle((void *)(((struct Obj04308 *)p)->f24), d_021F31E0[a], (u32)(&loc), 0x8070);
        DWCi_ScreenDC_FlushRange(((struct Obj05116 *)loc)->fC, ((struct Obj05116 *)loc)->f8);
        func_0207E468(((struct Obj05116 *)loc)->fC, 0, ((struct Obj05116 *)loc)->f8);
        src = *(u8 * *)&((struct Obj05116 *)loc)->fC;
        for (n = 0; n < 5; n++) {
            for (m = 0; m < 3; m++) {
                ((struct W *)p)->unk_230[m][n] = ((u16 *)(src + (n + 1) * 0x20))[d_021F31A8[m]];
            }
        }
        func_020307B0((void *)r);
        r = (int)ARC_UTIL_LoadPaletteBlockFromHandle((void *)(((struct Obj04308 *)p)->f24), 0x17, (u32)(&loc), 0x8070);
        for (k = 0; k < 9; k++) {
            C_GEAR_LoadTargetPalette(p, ((struct Obj05116 *)loc)->fC, k);
        }
        func_020307B0((void *)r);
    }
    size = 0x5000;
    v = BG_SYS_CreateRun(6, size, 0);
    ((struct Obj04308 *)p)->f14 = (u16)v | (size << 16);
    func_02049658((void *)(((struct Obj04308 *)p)->f24), d_021F32E0[b][a], 6, v, 0, 0, 0x70);
    return ARC_UTIL_UploadBgPaletteAddFromHandle((void *)(((struct Obj04308 *)p)->f24), 2, 6, 0, (u16)((struct Obj04308 *)p)->f14, 0, 0, 0x70);
}

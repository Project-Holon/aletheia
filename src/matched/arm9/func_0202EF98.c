/*
 * function: TIME_ICON_Start
 * address:  0x0202EF98
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_0202F099      0x0202F099  data
 *   func_020056EC   0x020056EC  thumb
 *   func_02045730   0x02045730  arm
 *   func_02045758   0x02045758  arm
 *   func_02045738   0x02045738  arm
 *   func_02045760   0x02045760  arm
 *   func_02045740   0x02045740  arm
 *   BMP_WIN_GetPalette   0x02045778  arm
 *   BMP_WIN_Create   0x020450F0  arm
 *   BMP_WIN_MakeScreen   0x02045374  arm
 *   func_02041B6C   0x02041B6C  arm
 *   func_02030DA8   0x02030DA8  arm
 *
 * TIME_ICON_Init's twin with the record unzeroed: the surface is built the
 * same way, then the caller's handle is attached through func_02030DA8.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TIME_ICON_Start.c \
 *       --func TIME_ICON_Start --addr 0x0202EF98 --cc 1.1p1 --thumb
 */
#include "../include/Obj03004.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u8 g_0202F099[];

extern u32 func_020056EC(u32 range);
struct Cfg;
struct Descriptor;
extern u8 func_02045730(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern u8 BMP_WIN_GetPalette(struct Descriptor *p);
extern u32  BMP_WIN_Create(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 a);
extern u32  func_02030DA8(u32 a, u32 b, u32 c, u32 d);

void TIME_ICON_Start(u8 *p, u32 a1, u32 a2, u8 a3, u8 a4)
{
    u32 v0, v3, v2;
    u32 v6, v7;
    u32 v4;

    ((struct Obj03004 *)p)->f13 = 0;
    ((struct Obj03004 *)p)->f12 = a3;
    ((struct Obj03004 *)p)->f14 = a4;
    ((struct Obj03004 *)p)->f15 = func_020056EC(8);

    v0 = func_02045730((struct Descriptor *)a2);
    v6 = func_02045758((struct Descriptor *)a2);
    v7 = func_02045738((struct Descriptor *)a2);
    v3 = func_02045760((struct Descriptor *)a2);
    v2 = func_02045740((struct Descriptor *)a2);
    v4 = BMP_WIN_GetPalette((struct Descriptor *)a2);

    BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj03004 *)p)->f8 = BMP_WIN_Create(v0, (u8)((v6 + v7) - 2),
                                   (u8)((v3 + v2) - 2), 2, 2, v4, 1)));
    func_02041B6C(func_02045730((struct Descriptor *)(((struct Obj03004 *)p)->f8)));

    ((struct Obj03004 *)p)->f4 = 0;
    ((struct Obj03004 *)p)->f0 = func_02030DA8(a1, (u32)g_0202F099, (u32)p, 0);
    ((struct Obj03004 *)p)->f18 = 1;
}

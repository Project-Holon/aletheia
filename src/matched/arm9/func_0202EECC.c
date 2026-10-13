/*
 * function: TIME_ICON_Init
 * address:  0x0202EECC
 * packet:   pkt_0202ECB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056EC   0x020056EC  thumb
 *   func_0204384C   0x0204384C  arm
 *   func_02045730   0x02045730  arm
 *   func_02045758   0x02045758  arm
 *   func_02045738   0x02045738  arm
 *   func_02045760   0x02045760  arm
 *   func_02045740   0x02045740  arm
 *   BMP_WIN_GetPalette   0x02045778  arm
 *   func_020450F0   0x020450F0  arm
 *   func_02045374   0x02045374  arm
 *   func_02041B6C   0x02041B6C  arm
 *
 * Fills in a freshly allocated record: the id, then a surface from the
 * caller's six size queries (width and height are each the sum of two of
 * them minus two, truncated to a byte).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TIME_ICON_Init.c \
 *       --func TIME_ICON_Init --addr 0x0202EECC --cc 1.1p1 --thumb
 */
#include "../include/Obj03003.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
extern u32 func_020056EC(u32 range);
struct Bmp;
struct Cfg;
extern struct Bmp *func_0204384C(u32 arc, u32 member, u32 heap2, u32 heap);
extern u8 func_02045730(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern u8 BMP_WIN_GetPalette(struct Descriptor *p);
extern u32  func_020450F0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 a);

void TIME_ICON_Init(u8 *p, void *a1, u8 a2, u8 a3, u16 a4)
{
    u32 v0, v3, v2;
    u32 v6, v7;
    u32 v4;

    ((struct Obj03003 *)p)->f10 = a4;
    ((struct Obj03003 *)p)->f13 = 0;
    ((struct Obj03003 *)p)->f12 = a2;
    ((struct Obj03003 *)p)->f14 = a3;
    ((struct Obj03003 *)p)->f15 = func_020056EC(8);
    ((struct Obj03003 *)p)->fC = (u32)func_0204384C(0xC6, 0, 1, ((struct Obj03003 *)p)->f10);

    v0 = func_02045730((struct Descriptor *)((u32)a1));
    v6 = func_02045758(a1);
    v7 = func_02045738(a1);
    v3 = func_02045760(a1);
    v2 = func_02045740(a1);
    v4 = BMP_WIN_GetPalette(a1);

    func_02045374((struct Cfg *)(((struct Obj03003 *)p)->f8 = func_020450F0(v0, (u8)((v6 + v7) - 2),
                                   (u8)((v3 + v2) - 2), 2, 2, v4, 1)));
    func_02041B6C(func_02045730((struct Descriptor *)(((struct Obj03003 *)p)->f8)));
}

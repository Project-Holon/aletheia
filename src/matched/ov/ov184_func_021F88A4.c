/*
 * function: func_021F88A4
 * address:  0x021F88A4
 * packet:   pkt_021F88A4
 * region:   ov184
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BR_SIDEBAR_SetVisibleBySpace  0x021FEEC0  thumb  ov186
 *   BR_RES_ApplyBgSet  0x021FBDA4  thumb  ov186
 *   BR_RES_ReleaseUiPalette  0x021FC1F8  thumb  ov186
 *   BR_GRAPHIC_Begin3d  0x021FC610  thumb  ov186
 *   func_021F3AF0  0x021F3AF0  thumb  ov112
 */
#include "../include/Obj06618.h"
#include "../include/Obj08319.h"
typedef unsigned short u16;
typedef unsigned int u32;

extern void BR_SIDEBAR_SetVisibleBySpace(char *p, int mode, u32 value);
extern void BR_RES_ApplyBgSet(int a, unsigned mode);
extern void BR_RES_ReleaseUiPalette(int *p, int i);
extern void BR_GRAPHIC_Begin3d(u32 a, u16 b);
typedef unsigned char  u8;
extern u8 *func_021F3AF0(u8 *src, u16 heap);

void func_021F88A4(char *p, char *q)
{
    if (((struct Obj06618 *)p)->f0 != 0)
        return;
    BR_SIDEBAR_SetVisibleBySpace((char *)(((struct Obj08319 *)q)->f4), 0, 0);
    BR_RES_ApplyBgSet(((struct Obj08319 *)q)->fC, 0);
    BR_RES_ReleaseUiPalette((int *)(((struct Obj08319 *)q)->fC), 0);
    BR_GRAPHIC_Begin3d(((struct Obj08319 *)q)->f8, ((struct Obj06618 *)p)->f24);
    ((struct Obj06618 *)p)->f0 = (unsigned int)func_021F3AF0((u8 *)(((struct Obj06618 *)p)->f28), ((struct Obj06618 *)p)->f24);
}

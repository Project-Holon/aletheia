/*
 * function: func_021F88E0
 * address:  0x021F88E0
 * packet:   pkt_021F88E0
 * region:   ov184
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F3BF0  0x021F3BF0  thumb  ov112
 *   BR_GRAPHIC_End3d  0x021FC640  thumb  ov186
 *   BR_RES_LoadUiPalette  0x021FC148  thumb  ov186
 *   BR_RES_LoadBgGraphics  0x021FB964  thumb  ov186
 *   BR_SIDEBAR_SetVisibleBySpace  0x021FEEC0  thumb  ov186
 */
#include "../include/Obj02233.h"
#include "../include/Obj04581.h"
typedef unsigned short u16;
typedef unsigned int u32;

typedef unsigned char  u8;
extern void func_021F3BF0(u8 *p);
extern void BR_GRAPHIC_End3d(u32 a, u16 b);
extern void BR_RES_LoadUiPalette(char *p, unsigned i, unsigned heap);
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern void BR_SIDEBAR_SetVisibleBySpace(char *p, int mode, u32 value);

void func_021F88E0(char *p, char *q)
{
    if (*(u32 *)&((struct Obj02233 *)p)->f0 == 0)
        return;
    func_021F3BF0(((struct Obj02233 *)p)->f0);
    *(u32 *)&((struct Obj02233 *)p)->f0 = 0;
    BR_GRAPHIC_End3d(((struct Obj04581 *)q)->f8, ((struct Obj02233 *)p)->f24);
    BR_RES_LoadUiPalette((char *)(*(u32 *)&((struct Obj04581 *)q)->fC), 0, ((struct Obj02233 *)p)->f24);
    BR_RES_LoadBgGraphics((void *)(*(u32 *)&((struct Obj04581 *)q)->fC), 0, ((struct Obj02233 *)p)->f24);
    BR_SIDEBAR_SetVisibleBySpace((char *)(((struct Obj04581 *)q)->f4), 0, 1);
}

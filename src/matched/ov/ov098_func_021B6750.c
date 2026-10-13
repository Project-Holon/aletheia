/*
 * function: func_021B6750
 * address:  0x021B6750
 * packet:   pkt_ov098_021B6750
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B6A00  0x021B6A00  thumb  ov098
 *   func_021B6A3C  0x021B6A3C  thumb  ov098
 *   FADE_Start  0x0204E720  arm
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   FADE_IsActive  0x0204E804  arm
 */
#include "../include/Obj03730.h"

typedef unsigned char  u8;
extern void func_021B6A00(u8 *p, u8 *q);
extern int func_021B6A3C(u8 *p);
typedef signed int     s32;
typedef unsigned int   u32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern void GFL_USE_FadeOutBgm(u32 a);
extern int FADE_IsActive(void);

int func_021B6750(char *p)
{
    switch (((struct Obj03730 *)p)->f60) {
    case 0:
        func_021B6A00((u8 *)(((struct Obj03730 *)p)->f14), (u8 *)(((struct Obj03730 *)p)->f0));
        ((struct Obj03730 *)p)->f60 = ((struct Obj03730 *)p)->f60 + 1;
        break;
    case 1:
        if (func_021B6A3C((u8 *)(((struct Obj03730 *)p)->f14)) != 0) {
            FADE_Start(3, 0, 0x10, 2);
            GFL_USE_FadeOutBgm(8);
            ((struct Obj03730 *)p)->f60 = ((struct Obj03730 *)p)->f60 + 1;
        }
        break;
    case 2:
        if (FADE_IsActive() == 0)
            return 2;
        break;
    }
    return 0;
}

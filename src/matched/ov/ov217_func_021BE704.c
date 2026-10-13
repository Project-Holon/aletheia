/*
 * function: func_021BE704
 * address:  0x021BE704
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   func_021BE7D8  0x021BE7D8  thumb  ov217
 *   func_021BE934  0x021BE934  thumb  ov217
 *   func_021BEA3C  0x021BEA3C  thumb  ov217
 *   func_021BEAF8  0x021BEAF8  thumb  ov217
 *   func_021BEF98  0x021BEF98  thumb  ov217
 *   func_021BF08C  0x021BF08C  thumb  ov217
 *   func_021BF11C  0x021BF11C  thumb  ov217
 *   func_021BF13C  0x021BF13C  thumb  ov217
 *   func_021BF264  0x021BF264  thumb  ov217
 *   func_021BF2FC  0x021BF2FC  thumb  ov217
 *   func_021BF38C  0x021BF38C  thumb  ov217
 *   func_021BF47C  0x021BF47C  thumb  ov217
 *   func_021BF704  0x021BF704  thumb  ov217
 *   func_021BF76C  0x021BF76C  thumb  ov217
 *   func_021BF810  0x021BF810  thumb  ov217
 *   func_021BFC60  0x021BFC60  thumb  ov217
 *   func_021C116C  0x021C116C  thumb  ov217
 *
 * Identical frame step to func_021BE678 with the sub-state delta -1.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00021.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern u32 func_021BE7D8(u32 a0);
extern int func_021BE934(char *p);
extern void func_021BEA3C(char *p, int a);
extern void func_021BEAF8(u8 *p);
extern void func_021BEF98(char *p);
extern void func_021BF08C(char *p);
extern void func_021BF11C(char *p);
extern void func_021BF13C(char *p);
extern void func_021BF264(char *p);
extern void func_021BF2FC(char *p);
extern void func_021BF38C(char *p);
extern void func_021BF47C(char *p);
extern void func_021BF704(void *p);
extern u8 *func_021BF76C(void *p);
extern u32 func_021BF810(void *p);
extern void func_021BFC60(char *p);
extern void func_021C116C(u8 *h);

void func_021BE704(char *p)
{
    if (((struct Obj00021 *)p)->f3C8 != 0) {
        if (func_021BF810(p) != 0) {
            func_021C116C(func_021BF76C(p));
        }
    }
    func_021BFC60(p);
    func_021BF704(p);
    func_021BEA3C(p, -1);
    ((struct Obj00021 *)p)->f3C8 = 0;
    func_021BF08C(p);
    func_021BE934(p);
    func_021BF11C(p);
    func_021BF13C(p);
    func_021BE7D8((u32)p);
    func_021BF264(p);
    func_021BF2FC(p);
    func_021BF38C(p);
    func_021BEF98(p);
    func_021BF47C(p);
    func_021BEAF8((u8 *)p);
    GFL_USE_PlaySeDefaultVolume(1352);
}

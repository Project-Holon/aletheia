/*
 * function: func_021BD118
 * address: 0x021BD118
 * packet: pkt_ov210_021BD118
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   func_021BC8B4 0x021BC8B4 thumb ov210
 *   func_021BCA84 0x021BCA84 thumb ov210
 *   func_021BE564 0x021BE564 thumb ov210
 *   func_021BF418 0x021BF418 thumb ov210
 *   func_021BC5B4 0x021BC5B4 thumb ov210
 *   func_021BCD30 0x021BCD30 thumb ov210
 *   func_021BFEAC 0x021BFEAC thumb ov210
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   func_021BCE0C 0x021BCE0C thumb ov210
 *   func_021BC82C 0x021BC82C thumb ov210
 */
#include "../include/Obj01779.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 PALANM_GetFadeRequestBits(const char *);
extern void func_021BC8B4(int);
extern void func_021BCA84(void *a0);
extern void func_021BE564(u8 *);
extern u32 func_021BF418(u8 *);
extern void func_021BC5B4(u32);
extern void func_021BCD30(u8 *);
extern void func_021BFEAC(char *ctx, int index);
typedef unsigned short u16;
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern void func_021BCE0C(char *, int);
extern void func_021BC82C(char *p, u8 b, u8 c);
int func_021BD118(u8 *p)
{
    if (PALANM_GetFadeRequestBits(*(char * *)&((struct Obj01779 *)p)->fC) != 0) return 3;
    func_021BC8B4(1);
    func_021BCA84(p);
    func_021BE564(p);
    func_021BC5B4(func_021BF418(p));
    func_021BCD30(p);
    if (p[0x2b9] == 255) {
        func_021BFEAC((char *)p, 0);
        GXx_SetMasterBrightness_((void *)0x0400006c, 0);
        GXx_SetMasterBrightness_((void *)0x0400106c, 0);
        func_021BCE0C((char *)p, -8);
        func_021BC82C((char *)p, 16, 0);
        return 4;
    } else {
        func_021BFEAC((char *)p, p[0x2b9]);
        return 4;
    }
}

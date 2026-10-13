/*
 * function: func_021B9F34
 * address: 0x021B9F34
 * packet: pkt_ov110_021B9F34
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 */
#include "../include/Obj05286.h"
#include "../include/Obj22328.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern signed int CLACT_RegisterPalette(void *a, unsigned int b, unsigned int c, unsigned int d, u16 g);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
void func_021B9F34(u8 *p, void *archive) {
    u8 *q = *(u8 * *)&((struct Obj22328 *)p)->f0;
    int i;
    for (i=0; i<2; ++i) {
        u8 *r = q+i*12;
        ((struct Obj05286 *)r)->f24 = CLACT_RegisterPalette(archive, 7, i, 0, 42);
        ((struct Obj05286 *)r)->f28 = CLACT_RegisterCharacter((void *)archive, 19, 0, i, 42);
        ((struct Obj05286 *)r)->f2C = CLACT_RegisterCellAnim((void *)archive, 36, 42, 42);
        ((struct Obj05286 *)r)->f3C = CLACT_RegisterPalette(archive, 1, i, 224, 42);
        ((struct Obj05286 *)r)->f40 = CLACT_RegisterCharacter((void *)archive, 46, 0, i, 42);
        ((struct Obj05286 *)r)->f44 = CLACT_RegisterCellAnim((void *)archive, 34, 40, 42);
    }
}

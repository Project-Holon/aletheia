/*
 * file:     wifilogin_disp_p14.c
 * unit:     yes
 * function: func_021D613C, func_021D6150
 * address:  0x021D613C
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D6134 0x021D6134 thumb ov115
 *   func_021D6198 0x021D6198 thumb ov115
 */
#include "../../matched/include/Obj13855.h"
#include "../../matched/include/Obj22605.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021D6134(void *a0, int a1, int a2);
extern void func_021D6198(u8 *p);
int func_021D613C(u8 *p);
void func_021D6150(u8 *p);


int func_021D613C(u8 *p) { void (*cb)(u8 *);cb=*(void (**)(u8 *))(p+12);if(cb){cb(p);return 0;}return 1; }

void func_021D6150(u8 *p) {
    int color;
    if (((struct Obj22605 *)(*(u8 * *)&((struct Obj13855 *)p)->f10))->f10 & 8) color = 0x7fff;
    else color = 0;
    func_0202208C(0, 1, 1, (u16)color, 6, 1, ((struct Obj13855 *)p)->f14);
    func_021D6134(p, (int)((void (*)(void))func_021D6198), 0x15b);
}

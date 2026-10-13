/*
 * function: func_021BA6F0
 * address: 0x021BA6F0
 * packet: pkt_ov181_021BA6F0
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: display register stores 04000050, 04000052, 04001050, 04001052.
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 */
#include "../include/Obj00784.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
extern void func_0207D63C(unsigned, int, int, int, int);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct CharBuf { u8 *pixels; u16 width, height, tileSize; };
extern void BMP_Clear(struct CharBuf *, u8);
int func_021BA6F0(char *p)
{
    int a, b;
    switch (((struct Obj00784 *)p)->f2CE) {
    case 0:
        if (((struct Obj00784 *)p)->f2CF & 1) func_0207D63C(0x04000050, 2, 0x21, 16, 0);
        if (((struct Obj00784 *)p)->f2CF & 2) func_0207D63C(0x04001050, 2, 0x21, 16, 0);
        ++((struct Obj00784 *)p)->f2CE;
    case 1:
        if (((struct Obj00784 *)p)->f2D2 == 1) ((struct Obj00784 *)p)->f2D0 += 16;
        else ((struct Obj00784 *)p)->f2D0 += 4;
        b = ((struct Obj00784 *)p)->f2D0;
        if (b > 16) { a = 0; b = 16; }
        else a = 16 - b;
        if (((struct Obj00784 *)p)->f2CF & 1) *(volatile u16 *)0x04000052 = a | (b << 8);
        if (((struct Obj00784 *)p)->f2CF & 2) *(volatile u16 *)0x04001052 = a | (b << 8);
        if (((struct Obj00784 *)p)->f2D0 >= 16) {
            if (((struct Obj00784 *)p)->f2CF & 1) BMP_Clear(func_02045770(((struct Obj00784 *)p)->f2BC), 0);
            if (((struct Obj00784 *)p)->f2CF & 2) BMP_Clear(func_02045770(((struct Obj00784 *)p)->f2C4), 0);
            ((struct Obj00784 *)p)->f2CC = ((struct Obj00784 *)p)->f2CF;
            *(u8 *)&((struct Obj00784 *)p)->f2D0 = 0;
            ++((struct Obj00784 *)p)->f2CE;
        }
        break;
    case 2:
        if (((struct Obj00784 *)p)->f2CF & 1) *(volatile u16 *)0x04000050 = 0;
        if (((struct Obj00784 *)p)->f2CF & 2) *(volatile u16 *)0x04001050 = 0;
        ((struct Obj00784 *)p)->f2CF = 0;
        ((struct Obj00784 *)p)->f2CE = 0;
        return 0;
    }
    return 1;
}

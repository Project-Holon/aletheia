/*
 * function: STAFF_ROLL_StepFadeIn
 * address: 0x021BA5E8
 * packet: pkt_ov181_021BA5E8
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: display registers 04000052 and 04001052 are hardware.
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 */
#include "../include/Obj01274.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
extern void func_0207D63C(unsigned, int, int, int, int);
int STAFF_ROLL_StepFadeIn(char *p)
{
    int a, b;
    switch (((struct Obj01274 *)p)->f2CE) {
    case 0:
        if (((struct Obj01274 *)p)->f2CF & 1) func_0207D63C(0x04000050, 2, 0x21, 0, 16);
        if (((struct Obj01274 *)p)->f2CF & 2) func_0207D63C(0x04001050, 2, 0x21, 0, 16);
        ((struct Obj01274 *)p)->f2CC = ((struct Obj01274 *)p)->f2CF;
        ++((struct Obj01274 *)p)->f2CE;
        break;
    case 1:
        if (((struct Obj01274 *)p)->f2D2 == 1) ((struct Obj01274 *)p)->f2D0 += 16;
        else ((struct Obj01274 *)p)->f2D0 += 4;
        a = ((struct Obj01274 *)p)->f2D0;
        if (a > 16) { a = 16; b = 0; }
        else b = 16 - a;
        if (((struct Obj01274 *)p)->f2CF & 1) *(volatile u16 *)0x04000052 = a | (b << 8);
        if (((struct Obj01274 *)p)->f2CF & 2) *(volatile u16 *)0x04001052 = a | (b << 8);
        if (((struct Obj01274 *)p)->f2D0 >= 16) {
            if (((struct Obj01274 *)p)->f2CF & 1) *(volatile u16 *)0x04000050 = 0;
            if (((struct Obj01274 *)p)->f2CF & 2) *(volatile u16 *)0x04001050 = 0;
            *(u8 *)&((struct Obj01274 *)p)->f2D0 = 0;
            ((struct Obj01274 *)p)->f2CE = 0;
            return 0;
        }
        break;
    }
    return 1;
}

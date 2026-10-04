/*
 * function: func_021EE038
 * address:  0x021EE038
 * packet:   pkt_ov170_021EE038
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EC000 0x021EC000 thumb
 *   func_021EBFCC 0x021EBFCC thumb
 */
#include "../include/Obj00000.h"

extern void func_021EC000(char *p, int i, int v);
extern void func_021EBFCC(char *p, int i, int v);

void func_021EE038(char *p, int a, int b, int c)
{
    p[0x1F] = a;
    p[0x20] = b;
    p[0x21] = c;
    if (a == 0) {
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 6, 1);
        func_021EBFCC(*(char * *)&((struct Obj00000 *)p)->f2C, 6, 1);
    } else if (a == 1) {
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 6, 0);
    } else {
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 6, 1);
        func_021EBFCC(*(char * *)&((struct Obj00000 *)p)->f2C, 6, 0xF);
    }
    if (b == 0) {
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 7, 1);
        func_021EBFCC(*(char * *)&((struct Obj00000 *)p)->f2C, 7, 0);
    } else if (b == 1) {
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 7, 0);
    } else {
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 7, 1);
        func_021EBFCC(*(char * *)&((struct Obj00000 *)p)->f2C, 7, 0xE);
    }
    if (c == 0) {
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 8, 1);
        func_021EBFCC(*(char * *)&((struct Obj00000 *)p)->f2C, 8, 0);
    } else if (c == 1) {
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 8, 0);
    } else {
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 8, 1);
        func_021EBFCC(*(char * *)&((struct Obj00000 *)p)->f2C, 8, 2);
    }
}

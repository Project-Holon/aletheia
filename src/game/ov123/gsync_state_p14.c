/*
 * file:     gsync_state_p14.c
 * unit:     yes
 * function: func_021D7858, func_021D78C0, func_021D7910, func_021D7960
 * address:  0x021D7858
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_021D7BDC 0x021D7BDC thumb ov123
 *   func_021D5C2C 0x021D5C2C thumb ov123
 *   func_021D5C0C 0x021D5C0C thumb ov123
 *   func_021D5B70 0x021D5B70 thumb ov123
 *   func_021D66D0 0x021D66D0 thumb ov123
 *   func_021D75D0 0x021D75D0 thumb ov123
 *   func_021D76F0 0x021D76F0 thumb ov123
 *   func_021D5D8C 0x021D5D8C thumb ov123
 *   func_021D77C4 0x021D77C4 thumb ov123
 *   func_021D5C9C 0x021D5C9C thumb ov123
 *   func_021D5D24 0x021D5D24 thumb ov123
 */
#include "../../matched/include/Obj03270.h"
#include "../../matched/include/Obj02837.h"
#include "../../matched/include/Obj08112.h"
#include "../../matched/include/Obj13988.h"

typedef unsigned int   u32;

typedef unsigned char  u8;

extern int func_021D5C2C(char *p);
extern int func_021D5C0C(char *p);
extern void func_021D5B70(char *p);
extern void func_021D66D0(unsigned char *,int);
extern void func_021D6FF0(char *p);
extern void func_021D7BDC(char *p);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern int func_021D5D8C(int);
extern void func_021D77C4(int,int);
extern void func_021D75D0(int a);
extern void func_021D76F0(int a);
extern void func_021D5C9C(char *p);
extern int func_021D5D24(char *p);
void func_021D7858(int a);
void func_021D78C0(int a);
void func_021D7910(int a);
void func_021D7960(int a);

void func_021D7858(int a)
{
    if(func_021D5C0C((char *)(((struct Obj03270 *)a)->f8))) {
        if(func_021D5C2C((char *)(((struct Obj03270 *)a)->f8))) {
            ((struct Obj03270 *)a)->f80=0xfff0;
            func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x3b6);
            return;
        }
        func_021D5B70((char *)(((struct Obj03270 *)a)->f8));
        ((struct Obj03270 *)a)->f8=0;
        if(((int *)a)[28]<100) ((int *)a)[28]+=10;
        func_021D66D0(*(unsigned char * *)&((struct Obj03270 *)a)->f14,((struct Obj03270 *)a)->f70);
        func_021D6EE0((u8 *)a,(int)func_021D7BDC,0x3c3);
    }
}

void func_021D78C0(int a)
{
    switch(((struct Obj02837 *)a)->fA7) {
    case 0: func_021D6EE0((u8 *)a,(int)func_021D75D0,0x3cb); break;
    case 1: func_021D77C4(a,func_021D5D8C(((struct Obj02837 *)a)->f8)-2); break;
    case 2: func_021D6EE0((u8 *)a,(int)func_021D76F0,0x3d1); break;
    }
}

void func_021D7910(int a)
{
    if(func_021D5C2C((char *)(((struct Obj08112 *)a)->f8))) {
        ((struct Obj08112 *)a)->f80=0xfff0;
        func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x3dd);
        return;
    }
    if(func_021D5C0C((char *)(((struct Obj08112 *)a)->f8))) {
        func_021D5C9C((char *)(((struct Obj08112 *)a)->f8));
        func_021D6EE0((u8 *)a,(int)func_021D78C0,0x3e8);
    }
}

void func_021D7960(int a)
{
    if (func_021D5D24((char *)(((struct Obj13988 *)a)->f8))) {
        func_021D6EE0((u8 *)a, (int)func_021D7910, 0x3f1);
        return;
    }
    ((struct Obj13988 *)a)->f80 = 0xfff0;
    func_021D6EE0((u8 *)a, (int)func_021D6FF0, 0x3f5);
}

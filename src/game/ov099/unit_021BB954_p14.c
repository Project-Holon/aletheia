/*
 * file:     unit_021BB954_p14.c
 * unit:     yes
 * function: func_021BC7B4, func_021BC850
 * address:  0x021BC7B4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C282C  0x021C282C  thumb  ov099
 *   func_021BC104  0x021BC104  thumb  ov099
 *   func_021BAADC  0x021BAADC  thumb  ov099
 *   func_021C18C8  0x021C18C8  thumb  ov099
 *   func_021C24A4  0x021C24A4  thumb  ov099
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_021BB954  0x021BB954  thumb  ov099
 */
#include "../../matched/include/Obj04414.h"
#include "../../matched/include/Obj18192.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

extern int func_021C282C(u8 *p);
extern void func_021BC104(char *p);
extern void func_021BAADC(char *p, int a, int b);
extern void func_021C18C8(char *p, int a, int b);
extern void func_021C24A4(char *p, int v);
extern void func_021BA8EC(char *p);
extern void func_021BB954(char *p, int flag);
int func_021BC7B4(char *p, int v);
int func_021BC850(char *p, int v);


int func_021BC7B4(char *p, int v)
{
    int r4;
    int sel;

    func_021C282C(*(u8 * *)&((struct Obj04414 *)p)->f8);
    ((struct Obj04414 *)p)->f1351 = 0;
    sel = ((struct Obj04414 *)p)->f132C;
    switch (sel) {
    case 0x4b:
        r4 = 4;
        break;
    case 0x4c:
        r4 = 5;
        break;
    case 0x4d:
        r4 = 6;
        break;
    }
    switch (sel) {
    case 0x4b:
        func_021BC104(p);
        func_021BAADC(p, 0x7b, 0);
        func_021C18C8(p, 4, 4);
        func_021C24A4(p, 0);
        ((struct Obj04414 *)p)->f1355 = 0;
        ((struct Obj04414 *)p)->f1CC = 0x10;
        break;
    case 0x4c:
        func_021BA8EC(p);
        ((struct Obj04414 *)p)->f1D0 = r4;
        v = 2;
        break;
    case 0x4d:
        func_021BC104(p);
        func_021BA8EC(p);
        ((struct Obj04414 *)p)->f1D0 = r4;
        v = 2;
        break;
    }
    func_021C18C8(p, 4, r4);
    return v;
}


/*
 * Runs the setup for selector 0x54 with the true flag and stamps it 0x1CC bytes in.
 */
int func_021BC850(char *p, int v)
{
    func_021BB954(p, 1);
    ((struct Obj18192 *)p)->f1CC = 0x54;
    return v;
}

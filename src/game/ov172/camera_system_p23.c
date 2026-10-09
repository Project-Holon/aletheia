/*
 * file:     camera_system_p23.c
 * unit:     yes
 * function: func_021B688C, func_021B68A0
 * address:  0x021B688C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02085D3C 0x02085D3C arm
 *   func_021B6918 0x021B6918 arm ov172
 *   func_021B6920 0x021B6920 arm ov172
 *   func_021B6928 0x021B6928 arm ov172
 *   func_021B6930 0x021B6930 arm ov172
 *   func_021B697C 0x021B697C thumb ov172
 *   func_021B699C 0x021B699C thumb ov172
 *   func_021B6938 0x021B6938 thumb ov172
 *   func_021B6944 0x021B6944 thumb ov172
 */
#include "../../matched/include/Obj24060.h"
#include "../../matched/include/Obj01264.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern int func_02085D3C(void);
extern int func_021B6918(void);
extern void func_021B6920(int);
extern int func_021B6928(u32, u32);
extern void func_021B6930(int);
extern int func_021B697C(void *);
extern int func_021B699C(void *);
extern u16 func_021B6938(void *);
extern u16 func_021B6944(void *);
int func_021B688C(void *p);
void func_021B68A0(char *p);


int func_021B688C(void *p)
{
    u8 v = ((struct Obj24060 *)p)->f44;
    return v == 6 || v == 0;
}

void func_021B68A0(char *p)
{
    int result;
    u32 width;
    u32 height;
    if (((struct Obj01264 *)p)->f10 != 0) return;
    if ((func_02085D3C() == 1 ? func_021B6918() : 0) != 0) return;
    if (func_02085D3C() == 1) func_021B6920(0);
    result = 0;
    ((struct Obj01264 *)p)->f34 = 0;
    ((struct Obj01264 *)p)->f36 = func_021B697C(p);
    ((struct Obj01264 *)p)->f38 = 0;
    ((struct Obj01264 *)p)->f3A = func_021B699C(p);
    width = func_021B6938(p);
    height = func_021B6944(p);
    if (func_02085D3C() == 1) result = func_021B6928(width, height);
    if (func_02085D3C() == 1) func_021B6930(result);
    ((struct Obj01264 *)p)->f14 = 0;
}

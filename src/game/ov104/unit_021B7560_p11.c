/*
 * file:     unit_021B7560_p11.c
 * unit:     yes
 * function: func_021B8E8C, func_021B8E90, func_021B8EA4, func_021B8EB0, func_021B8F00
 * address:  0x021B8E8C
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021B89DC 0x021B89DC thumb ov104
 */
#include "../../matched/include/Obj22235.h"
#include "../../matched/include/Obj04434.h"
#include "../../matched/include/Obj22236.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32_021B8E8C;

typedef int s32_021B8EA4;

typedef signed int     s32_021B8EB0;

extern void func_02082BCC(void *, int, int);
extern s32_021B8EB0 func_021B89DC(int a, u16 *p, int angle, int bank, u8 index, u16 c1, u16 c2);
u32 func_021B8E8C(u8 *p);
void func_021B8E90(int *p, int a1);
void func_021B8EA4(void *p);
void func_021B8EB0(u8 *p);
void func_021B8F00(void *p);


u32 func_021B8E8C(u8 *p) { return ((struct Obj22235 *)p)->f8; }


void func_021B8E90(int *p, int a1)
{
    func_02082BCC(p, 0, 16);
    p[1] = 1;
}

void func_021B8EA4(void *p) { func_02082BCC(p, 0, 0x10); }

void func_021B8EB0(u8 *p) {
 int a;
 if(((struct Obj04434 *)p)->fC && ((struct Obj04434 *)p)->f4) {
  a=((struct Obj04434 *)p)->f2+0x400;
  if(a>=0x10000) ((struct Obj04434 *)p)->f2=((struct Obj04434 *)p)->f2-0xfc00;
  else ((struct Obj04434 *)p)->f2=a;
  func_021B89DC(15,(u16 *)p,((struct Obj04434 *)p)->f2,5,3,0x6adf,0x55fe);
 }
}


void func_021B8F00(void *p)
{
    ((struct Obj22236 *)p)->fC = 1;
}

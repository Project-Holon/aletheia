/*
 * file:     btl_server_p94.c
 * unit:     yes
 * function: func_021C8408, func_021C8434
 * address:  0x021C8408
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021BB914 0x021BB914 thumb ov093
 *   func_021C845C 0x021C845C thumb ov093
 *   func_021BE52C 0x021BE52C thumb ov093
 */
#include "../../matched/include/Obj09974.h"
#include "../../matched/include/Obj21121.h"

typedef unsigned char u8;

typedef unsigned int   u32;

extern void *func_021B86B8(void ***);
extern u8 func_021B8DDC(u32 x);
extern u8 func_021B8FF4(u8 *);
extern void func_021BB914(int *);
extern int func_021C845C(u8 *, int);
extern void func_021BE52C(u8 *, int, int, int);
void func_021C8408(u8 *p, int a);
void func_021C8434(u8 *p, int a, int b);

void func_021C8408(u8 *p, int a)
{
    unsigned int t = (unsigned int)func_021B86B8(*(void *** *)&((struct Obj09974 *)p)->f4);
    int k = func_021B8DDC(a);
    if (t <= 1 && k == func_021B8FF4(*(u8 * *)&((struct Obj09974 *)p)->f4)) func_021BB914(*(int * *)&((struct Obj09974 *)p)->f0);
}

void func_021C8434(u8 *p, int a, int b)
{
    int c = func_021C845C(p + 0x1ab8, b);
    func_021BE52C(*(u8 * *)&((struct Obj21121 *)p)->f4B0, a, b, c);
}

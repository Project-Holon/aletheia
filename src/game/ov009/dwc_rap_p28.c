/*
 * file:     dwc_rap_p28.c
 * unit:     yes
 * function: func_02156CF4, func_02156D84
 * address:  0x02156CF4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   func_0203D798  0x0203D798  arm
 *   func_0203D650  0x0203D650  arm
 */
#include "../../matched/include/Obj18656.h"
#include "../../matched/include/Obj18657.h"
#include "../../matched/include/Obj18658.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void *func_0203D798(void);
extern u32 func_0203D650(void);
void func_02156CF4(void);
u32 func_02156D5C(void);
void func_02156D70(u32 v);
int func_02156D84(void);
void func_02156DB0(u32 v);
extern u8 *g_021A8264;


void func_02156CF4(void)
{
    volatile int off2 = 0x17c;
    int i;
    i = 0;
    off2 = 0x1fc;
    for (; i < 32; i++) {
        if (*(int *)(g_021A8264 + i * 4 + 0x17c) != -1) {
            u8 *p = func_0203D798();
            if (((struct Obj18656 *)p)->f3C != 0) {
                u8 *q = g_021A8264 + i * 4;
                u32 r = func_0203D650();
                ((void (*)(u32, u32, u32))*(u32 *)(p + 0x3c))(((struct Obj18657 *)q)->f17C, *(u32 *)(q + off2), r);
            }
            *(int *)(g_021A8264 + i * 4 + 0x17c) = -1;
        }
    }
}


u32 func_02156D5C(void)
{
    return *(u32 *)(g_021A8264 + 0x758);
}


void func_02156D70(u32 v)
{
    g_021A8264[0x7a5] = v;
}


/*
 * Two functions: 0x02156D84, 0x02156DB0.
 */
int func_02156D84(void)
{
    u8 *g = g_021A8264;
    if (g == 0) {
        return 1;
    }
    {
        u32 s = ((struct Obj18658 *)g)->f754;
        if (s == 0x13 || s == 0x10 || s == 0x14) {
            return 1;
        }
    }
    return 0;
}


void func_02156DB0(u32 v)
{
    g_021A8264[0x7a3] = v;
}

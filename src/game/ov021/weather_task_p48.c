/*
 * file:     weather_task_p48.c
 * unit:     yes
 * function: func_021A4698, func_021A46F0
 * address:  0x021A4698
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A4598  0x021A4598  thumb  ov021
 *   func_021A4544  0x021A4544  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A4768  0x021A4768  thumb  ov021
 *   func_021A47B4  0x021A47B4  thumb  ov021
 *   func_021A4664  0x021A4664  thumb  ov021
 *   func_021A4698  0x021A4698  thumb  ov021
 *   func_021A482C  0x021A482C  thumb  ov021
 *   func_021A4890  0x021A4890  thumb  ov021
 *   func_021A48A4  0x021A48A4  thumb  ov021
 */
#include "../../matched/include/Obj01657.h"
#include "../../matched/include/Obj12735.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern u16 func_0216D5F8(void *p);
extern void *func_0216D4B4(char *p);
extern int func_0216D3CC(int a0);
extern int func_021A4598(u8 *a, void *b, u8 *c);
extern int func_021A4544(u8 *p, u32 r, u8 *q);
extern void *func_021A3960(unsigned char *p);
extern int func_021A4768(u8 *, void *, u32);
extern int func_021A47B4(u8 *, void *, u32);
extern int func_021A4664(int a, int b, u8 *c);
extern int func_021A4698(u8 *, void *, u32);
extern int func_021A482C(u8 *, void *, u32);
extern int func_021A4890(u8 *a, u32 b, u32 c);
extern int func_021A48A4(u32 a, u32 b, u32 c);
int ov021_func_021A4698(u32 a, u32 b, u8 *c);
int ov021_func_021A46F0(u8 *a, u32 b);


int ov021_func_021A4698(u32 a, u32 b, u8 *c)
{
    u32 r = func_0216D5F8((void *)b);
    if (((struct Obj01657 *)c)->f8 != 9 && ((struct Obj01657 *)c)->f8 != r) {
        func_0216D4B4((char *)b);
        return func_021A4598((u8 *)a, (void *)b, (u8 *)((u32)c));
    }
    if (func_0216D3CC(b) == 0) {
        return 0;
    }
    if (((struct Obj01657 *)c)->f8 == 9) {
        return func_021A4544((u8 *)a, b, (u8 *)((u32)c));
    }
    return func_021A4598((u8 *)a, (void *)b, (u8 *)((u32)c));
}


int ov021_func_021A46F0(u8 *a, u32 b)
{
    void *r = func_021A3960(((struct Obj12735 *)a)->fC);
    int ret = 0;
    switch (((struct Obj12735 *)a)->f0) {
    case 0:
        ret = func_021A4768(a, r, b);
        break;
    case 1:
        ret = func_021A47B4(a, r, b);
        break;
    case 2:
        ret = func_021A4664((int)a, (int)r, (u8 *)b);
        break;
    case 3:
        ret = func_021A4698(a, r, b);
        break;
    case 4:
        ret = func_021A482C(a, r, b);
        break;
    case 5:
    case 6:
        ret = func_021A4890(a, (u32)r, b);
        break;
    case 7:
        ret = func_021A48A4((u32)a, (u32)r, b);
        break;
    }
    return ret;
}

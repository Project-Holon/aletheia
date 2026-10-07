/*
 * file:     weather_task_p51.c
 * unit:     yes
 * function: func_021A48C8, func_021A491C
 * address:  0x021A48C8
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
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A491C  0x021A491C  thumb  ov021
 *   func_021A4994  0x021A4994  thumb  ov021
 *   func_021A4A74  0x021A4A74  thumb  ov021
 *   func_021A4AA8  0x021A4AA8  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 */
#include "../../matched/include/Obj12737.h"
#include "../../matched/include/Obj02084.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void *func_021A3960(unsigned char *p);
extern int func_021A491C(u8 *, void *, u32);
extern int func_021A4994(u8 *a, void *b, u8 *c);
extern int func_021A4A74(int a, int b, u8 *c);
extern int func_021A4AA8(u8 *, void *, u32);
extern u16 func_0216D5F8(void *p);
extern int func_0216D3CC(int a0);
int ov021_func_021A48C8(u8 *a, u32 b);
int ov021_func_021A491C(u32 a, u32 b, u8 *c);


int ov021_func_021A48C8(u8 *a, u32 b)
{
    void *r = func_021A3960(((struct Obj12737 *)a)->fC);
    int ret = 0;
    switch (((struct Obj12737 *)a)->f0) {
    case 0:
        ret = func_021A491C(a, r, b);
        break;
    case 1:
        ret = func_021A4994(a, r, (u8 *)b);
        break;
    case 2:
        ret = func_021A4A74((int)a, (int)r, (u8 *)b);
        break;
    case 3:
        ret = func_021A4AA8(a, r, b);
        break;
    }
    return ret;
}


int ov021_func_021A491C(u32 a, u32 b, u8 *c)
{
    if (func_0216D3CC(b) == 1) {
        if (((struct Obj02084 *)c)->f8 != 9) {
            u32 r = func_0216D5F8((void *)b);
            if (((struct Obj02084 *)c)->f8 != r && ((struct Obj02084 *)c)->f10 == 0) {
                return 3;
            }
            return func_021A4994((u8 *)a, (void *)b, (u8 *)((u32)c));
        }
        return 1;
    }
    return 0;
}

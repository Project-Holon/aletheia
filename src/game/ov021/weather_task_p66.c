/*
 * file:     weather_task_p66.c
 * unit:     yes
 * function: func_021A5928, func_021A5964
 * address:  0x021A5928
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
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216E0AC  0x0216E0AC  thumb  ov010
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_0219E2C0  0x0219E2C0  thumb  ov021
 *   d_021DDEE0     0x021DDEE0  data  a4
 *   d_021DDEE0b    0x021DDEE0  data  a4
 */
#include "../../matched/include/Obj05027.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern u16 func_0216D5A0(void *p);
extern u16 func_0216D598(void *p);
extern void func_0216E0AC(void *a0, void *a1);
extern void *func_0219E348(void *a);
extern void func_0219E2C0(void *a, void *r);
void func_021A5928(u8 *p, int v);
void func_021A5964(u32 *p);
extern u16  d_021DDEE0[2];
extern u16  d_021DDEE0b[2];


/*
 * Addresses are Black-image addresses.
 */
void func_021A5928(u8 *p, int v)
{
    if (func_0216D5A0((void *)(((struct Obj05027 *)p)->f1C)) != 0x45) {
        d_021DDEE0[1] = func_0216D598((void *)(((struct Obj05027 *)p)->f1C));
        func_0216E0AC((void *)(((struct Obj05027 *)p)->f1C), d_021DDEE0b);
    }
    ((struct Obj05027 *)p)->f20 = (int)func_0219E348((void *)(((struct Obj05027 *)p)->f1C));
    func_0219E2C0((void *)(((struct Obj05027 *)p)->f1C), (void *)v);
}


/*
 * Unlabelled leaf: clears the word at +0x20.
 *
 * Addresses are Black-image addresses.
 */
void func_021A5964(u32 *p)
{
    p[8] = 0;
}

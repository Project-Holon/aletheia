/*
 * file:     weather_task_p59.c
 * unit:     yes
 * function: func_021A5408, func_021A5458
 * address:  0x021A5408
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
 *   func_021A572C  0x021A572C  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D7DC  0x0216D7DC  thumb  ov010
 *   func_021A5318  0x021A5318  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB348  0x021AB348  thumb  ov021
 */
#include "../../matched/include/Obj09570.h"
#include "../../matched/include/Obj19803.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void *func_021A572C(u8 *p);
extern u32 func_0216D5F8(void);
extern void *func_0216D4B4(char *p);
extern void func_0216D5E0(int a0, int a1);
extern void func_0216D674(void *p, u16 v);
extern void func_021A3964(u8 *p, u32 v);
void *func_021A3960(unsigned char *p);
u32 func_0216D7DC(void *p);
int func_021A5318(u32 *p, u32 m);
u16 func_021AB0F0(u32 attr);
int func_021AB348(u32 id);
int func_021A5408(u8 *a);
int func_021A5458(u32 *p);


/*
 * Addresses are Black-image addresses.
 */
int func_021A5408(u8 *a)
{
    u32 x;
    u32 y;
    switch (((struct Obj09570 *)a)->f0) {
    case 0:
        break;
    case 1:
        return 0;
    case 2:
    case 3:
        x = (u32)func_021A572C(a);
        y = func_0216D5F8();
        func_0216D4B4((char *)x);
        func_0216D5E0(x, y);
        func_0216D674((void *)x, 0);
        func_021A3964((u8 *)(*(u32 *)&((struct Obj09570 *)a)->fC), 0);
        break;
    }
    return 1;
}


int func_021A5458(u32 *p)
{
    int x = func_0216D7DC(func_021A3960(*(unsigned char * *)&((struct Obj19803 *)p)->fC));

    if (func_021A5318(p, 2) == 0 && func_021AB348(func_021AB0F0(x)) == 1)
        return 1;
    return 0;
}

/*
 * file:     field_wfbc_p10.c
 * unit:     yes
 * function: func_021942C8, func_02194300
 * address:  0x021942C8
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
 *   func_02194418  0x02194418  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021945A0  0x021945A0  thumb  ov021
 *   func_02194434  0x02194434  thumb  ov021
 */
#include "../../matched/include/Obj07446.h"
#include "../../matched/include/Obj09482.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u32 key; u32 x4; u32 x8; } Item;

typedef struct { u16 n; u16 pad; u32 x4; Item *items; } List;

extern int func_02194418(u32 a);
extern u32 func_020307B0(void *p);
extern int func_021945A0(int x);
extern void *func_02194434(unsigned char *a, int x, u16 *q, int d, int e, int f);
void func_021942C8(List *p);
void func_02194300(u16 *a, int b, int c, u16 *d, int e, int f);


/*
 * Addresses are Black-image addresses.
 */
void func_021942C8(List *p)
{
    u16 i;
    Item *it;

    i = 0;
    it = p->items;
    if (i < p->n) {
        for (; i < p->n; i++) {
            if (it->x8 != 0) {
                func_02194418((u32)it);
            }
            it++;
        }
    }
    func_020307B0(p->items);
    func_020307B0(p);
}


void func_02194300(u16 *a, int b, int c, u16 *d, int e, int f)
{
    u16 i;
    unsigned char *q = *(unsigned char * *)&((struct Obj09482 *)a)->f8;

    func_021945A0(*d);
    for (i = 0; i < *a; i++) {
        if (*(int *)&((struct Obj07446 *)q)->f8 == 0) {
            ((struct Obj07446 *)q)->f8 = func_02194434((unsigned char *)a, c, d, e, f, (int)q);
            ((struct Obj07446 *)q)->f0 = b;
            ((struct Obj07446 *)q)->f6 = a[1];
            return;
        }
        q += 0xc;
    }
}

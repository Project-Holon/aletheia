/*
 * file:     field_wfbc_p21.c
 * unit:     yes
 * function: func_02194C60, func_02194CE8
 * address:  0x02194C60
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
 *   func_02195E70  0x02195E70  thumb  ov021
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02194B3C  0x02194B3C  thumb  ov021
 *   func_02194D1C  0x02194D1C  thumb  ov021
 */
#include "../../matched/include/Obj01351.h"
#include "../../matched/include/Obj02377.h"

struct Owner;
struct Sprite;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_02195E70(u8 *p, u8 *e);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern void func_02194B3C(u8 *p, u8 *e);
extern void func_02194D1C(struct Owner *a, struct Sprite *b, int c);
void func_02194C60(u8 *p, u8 *e);
void func_02194CE8(int a, u16 *b);


/*
 * Addresses are Black-image addresses.
 */
void func_02194C60(u8 *p, u8 *e)
{
    u32 t;

    switch (((struct Obj02377 *)e)->f0) {
    case 2:
        ((struct Obj02377 *)e)->f5E = 0;
        ((struct Obj02377 *)e)->f0 = 3;
    case 3:
        ((struct Obj02377 *)e)->f0 = 4;
        t = ((struct Obj02377 *)e)->f60;
        func_02195E70(p, e);
        ((struct Obj02377 *)e)->f8 = func_0201CCE4(((struct Obj02377 *)e)->fC, e[0x5C], e[0x5D], ((struct Obj02377 *)e)->f14,
                                        ((struct Obj01351 *)p)->f8, t, *(u32 *)&((struct Obj01351 *)p)->fC98, 0, ((struct Obj01351 *)p)->f0, 15);
        return;
    case 5:
        ((struct Obj02377 *)e)->f0 = 6;
        return;
    case 6:
        func_02194B3C(p, e);
        return;
    }
}


/*
 * The callee 0x02194D1C is src/matched/ov/ov021_func_02194D1C.c. EXACT* only
 * because that callee is the unlabelled follower.
 */
void func_02194CE8(int a, u16 *b)
{
    switch (*b) {
    case 0:
    case 1:
    case 2:
    case 5:
    case 6:
        break;
    case 3:
        func_02194D1C((struct Owner *)a, (struct Sprite *)b, 0);
        break;
    case 4:
        func_02194D1C((struct Owner *)a, (struct Sprite *)b, 1);
        break;
    }
}

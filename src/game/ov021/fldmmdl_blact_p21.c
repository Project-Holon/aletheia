/*
 * file:     fldmmdl_blact_p21.c
 * unit:     yes
 * function: func_0219EA10, func_0219EA24, func_0219EA40, func_0219EA5C, func_0219EA78, func_0219EA94, func_0219EAB8
 * address:  0x0219EA10
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
 *   func_0219E9F8  0x0219E9F8  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 *   d_021D84E8  0x021D84E8  data
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D530  0x0216D530  thumb
 *   func_021BB394  0x021BB394  thumb  ov021
 *   func_021B7DC0  0x021B7DC0  thumb  ov021
 *   func_0219EAD8  0x0219EAD8  thumb  ov021
 *   func_021BB3A0  0x021BB3A0  thumb  ov021
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0219EAEC  0x0219EAEC  thumb  ov021
 */
#include "../../matched/include/Obj12077.h"
#include "../../matched/include/Obj17976.h"
#include "../../matched/include/Obj07482.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { int key; int val; } Entry;

extern u32 func_020056EC(u32);
extern int func_0219E9F8(u32 *arr, u32 v);
extern u32 func_0216D530(u32);
extern void *func_0216D67C(void *a0);
extern u32 func_021BB394(u32);
extern void func_021B7DC0(void *p, u16 *out);
extern void func_0219EAD8(u32 *p, u16 *src);
extern u32 *func_0216D550(u32 *p, u32 v);
extern void func_021BB3A0(u8 *p, u32 a1);
extern u32 func_0219EAEC(u32, u32);
int func_0219EA10(u32 *a, int b);
u32 func_0219EA24(u32 a, u32 b);
int func_0219EA40(int key);
int func_0219EA5C(void *a, u32 b);
void func_0219EA78(u32 *p, u32 a1);
u32 func_0219EA94(u32 a, u32 *b);
int func_0219EAB8(u32 a, u32 b);
extern Entry d_021D84E8[];



/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219EA10(u32 *a, int b)
{
return *(u32 *)((u8 *)(a) + ((func_020056EC(func_0219E9F8((u32 *)a, b)) << 2)));
}



/*
 * Addresses are Black-image addresses.
 */
u32 func_0219EA24(u32 a, u32 b)
{
    u32 *t = (u32 *)func_0219EA40(a);
    return t[func_020056EC(func_0219E9F8(t, b))];
}



int func_0219EA40(int key)
{
    Entry *e = d_021D84E8;
    int k = 0;
    do {
        if (k == key) {
            return e->val;
        }
        e++;
        k = e->key;
    } while (k != 11);
    return 0;
}



/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D530 (0x0216D530) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219EA5C(void *a, u32 b)
{
((struct Obj12077 *)((u8 *)(a)))->f0 = func_021BB394(func_0216D530((u32)func_0216D67C((void *)b)));
((struct Obj12077 *)((u8 *)(a)))->f6 = 2;
return 2;
}



void func_0219EA78(u32 *p, u32 a1)
{
    u16 buf[4];
    func_021B7DC0((void *)*p, buf);
    func_0219EAD8(p, buf);
}



u32 func_0219EA94(u32 a, u32 *b)
{
func_021BB3A0((u8 *)func_0216D530((u32)func_0216D67C((void *)b)), ((struct Obj17976 *)((u8 *)(a)))->f0);
return (u32)func_0216D550(b, (2 << 12));
}


int func_0219EAB8(u32 a, u32 b)
{
*(u32 *)&((struct Obj07482 *)((u8 *)(a)))->f0 = func_021BB394(func_0216D530((u32)func_0216D67C((void *)b)));
return func_0219EAEC(a, b);
}

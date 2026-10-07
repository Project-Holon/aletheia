/*
 * file:     trial_house_p02.c
 * unit:     yes
 * function: func_021CF0F4, func_021CF110, func_021CF128, func_021CF12C
 * address:  0x021CF0F4
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
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_02008494  0x02008494  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_0203D1C0  0x0203D1C0  arm
 */
#include "../../matched/include/Obj20269.h"

struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16;

typedef signed char    s8;

extern int func_021909BC(void *a);
extern void func_02008494(void *a, void *b);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern u32 func_0203D1C0(u32 index);
void func_021CF0F4(u8 *p);
void func_021CF110(u8 *p, u32 v, void *a);
u32 func_021CF128(void);
int func_021CF12C(int mask);


void func_021CF0F4(u8 *p)
{
    u32 *q = (u32 *)(p + 0x130);

    if (q[0] != 0) {
        func_021909BC((void *)q[0]);
        q[0] = 0;
    }
    ((u8 *)q)[8] = 0;
}


void func_021CF110(u8 *p, u32 v, void *a)
{
    ((struct Obj20269 *)p)->f52C = v;
    func_02008494(a, p + 0x530);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021CF128(void)
{
return 132;
}


int func_021CF12C(int mask)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        if (i != func_0203D1A4((struct Link *)((int)func_020399A8())) && ((1 << i) & mask) && func_0203D1C0(i) == 1) {
            return 1;
        }
    }
    return 0;
}

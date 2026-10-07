/*
 * file:     dwc_rap_p01.c
 * unit:     yes
 * function: func_02155160, func_02155168, func_021551B0
 * address:  0x02155160
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
 *   func_02156DFC  0x02156DFC  thumb  ov009
 *   func_0203D798  0x0203D798  arm
 *   func_02157048  0x02157048  thumb  ov009
 *   func_02030734  0x02030734  arm
 *   d_021A8260     0x021A8260  data  ov009  a4
 *   d_021A1C4C     0x021A1C4C  data  ov009  a1
 *   func_0203D5EC 0x0203D5EC arm
 *   func_0203D610 0x0203D610 arm
 *   func_0215539C 0x0215539C thumb ov009
 *   func_0215592C 0x0215592C thumb ov009
 */
#include "../../matched/include/Obj12254.h"

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_02156DFC(int a);
void *func_0203D798(void);
void func_02157048(u32 a, u32 b);
void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0203D5EC(void);
extern u32 func_0203D610(void);
extern int func_0215539C(int, int);
extern int func_0215592C(int);
void func_02155160(int a);
int func_02155168(int a, int b);
int func_021551B0(void (*cb)(int));
int func_021551D4(int a);
extern int *d_021A8260;
extern char d_021A1C4C[];


void func_02155160(int a)
{
    func_02156DFC(a);
}


int func_02155168(int a, int b)
{
    int p;

    if (d_021A8260 != 0)
        return 0;
    p = (int)func_0203D798();
    func_02157048(((struct Obj12254 *)p)->f58, ((struct Obj12254 *)p)->f48);
    d_021A8260 = func_02030734(a, 8, 1, d_021A1C4C, 0xba);
    *d_021A8260 = b;
    return 1;
}

int func_021551B0(void (*cb)(int))
{
    u32 a;
    int r;
    a = func_0203D5EC();
    r = func_0215539C(a, func_0203D610());
    if (cb) cb(1);
    return r;
}

int func_021551D4(int a)
{
    return func_0215592C(a);
}

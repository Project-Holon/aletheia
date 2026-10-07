/*
 * file:     unit_0219B508_p02.c
 * unit:     yes
 * function: func_0219B968, func_0219B984, func_0219B9B0, func_0219B9D8
 * address:  0x0219B968
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
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216DA50  0x0216DA50  thumb
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 */
#include "../../matched/include/Obj17959.h"
#include "../../matched/include/Obj05008.h"
#include "../../matched/include/Obj05998.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_0216DA50(u32);
extern u32 func_02197EDC(u8 *p);
extern void *func_0216D67C(void *a0);
extern void *func_0216DEE0(void *a0);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
int func_0219B968(u32 a, u32 b, u32 c, u32 d);
int func_0219B984(u32 a, u32 b);
void func_0219B9B0(u32 a, u8 *s);
int func_0219B9D8(u32 a, u8 *s);


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216DA50 (0x0216DA50) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219B968(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC((u8 *)a) == 1) {
    func_0216DA50(a);
    ((struct Obj17959 *)((u8 *)(b)))->f0 = 0;
}
return 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219B984(u32 a, u32 b)
{
if (func_0216DEE0((void *)func_0216D67C((void *)a)) == 0) {
    ((struct Obj05008 *)((u8 *)(b)))->f1 = 0;
    return 0;
}
if (((struct Obj05008 *)((u8 *)(b)))->f1 == 0) {
    func_0219B9B0(a, (u8 *)b);
}
return 1;
}


void func_0219B9B0(u32 a, u8 *s)
{
    u32 o = (u32)func_0216DEE0(func_0216D67C((void *)a));
    s[1] = 1;
    ((struct Obj05008 *)s)->f2 = func_0216D83C((void *)o);
    ((struct Obj05008 *)s)->f4 = func_0216D86C((void *)o);
    ((struct Obj05008 *)s)->f6 = 0xFF;
}


int func_0219B9D8(u32 a, u8 *s)
{
    u32 o = (u32)func_0216DEE0(func_0216D67C((void *)a));
    int x;
    int y;
    if (o != 0) {
        x = func_0216D83C((void *)o);
        y = func_0216D86C((void *)o);
        if (x != *(s16 *)&((struct Obj05998 *)s)->f2 || y != *(s16 *)&((struct Obj05998 *)s)->f4) {
            return 1;
        }
    }
    return 0;
}

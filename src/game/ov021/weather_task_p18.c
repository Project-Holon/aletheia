/*
 * file:     weather_task_p18.c
 * unit:     yes
 * function: func_021A548C, func_021A54A0, func_021A54B4
 * address:  0x021A548C
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
 *   func_021A5458  0x021A5458  thumb  ov021
 *   func_021A53BC  0x021A53BC  thumb  ov021
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_021640B0  0x021640B0  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DCE8  0x0216DCE8  thumb  ov010
 *   func_021A3960  0x021A3960  thumb
 */
#include "../../matched/include/Obj12739.h"

struct Actor;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

typedef struct { s32 x, y, z; } VecFx32;

extern u32 func_021A5458(u32, u32, u32, u32);
extern int func_021A53BC(u32 a);
extern void *func_021A3960(u8 *p);
extern int func_0216DB4C(void *a0, int a1);
extern int func_0216DCE8(void *a0, int a1);
extern void *func_0216D568(void *p, u32 v);
extern int func_02164010(int a);
extern void func_0216D88C(const struct Actor *obj, struct VecFx32 *out);
extern void func_0216D85C(void *p, int v);
extern int func_021640B0(int a);
extern int func_02163F10(int a0);
int func_021A548C(u32 a, u32 b, u32 c, u32 d);
int func_021A54A0(u32 a);
void func_021A54B4(u8 *p);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A548C(u32 a, u32 b, u32 c, u32 d)
{
if (func_021A5458(a, 9, c, d) != 0) {
    return 1;
}
return 0;
}


int func_021A54A0(u32 a)
{
if (func_021A53BC(a) == 1) {
    return 1;
}
return 0;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A54B4(u8 *p)
{
    VecFx32 v;
    void *o = func_021A3960(((struct Obj12739 *)p)->fC);

    func_0216DB4C(o, 0);
    func_0216DCE8(o, 0);
    func_0216D568(o, 0x140);
    func_02164010((int)o);
    func_0216D88C(o, (struct VecFx32 *)&v);
    func_0216D85C(o, (s16)((v.y >> 4) / 4096));
    func_021640B0((int)o);
    func_02163F10((int)o);
}

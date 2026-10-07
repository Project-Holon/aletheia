/*
 * file:     field_palace_sys_p03.c
 * unit:     yes
 * function: func_021D1884, func_021D1894, func_021D18E0
 * address:  0x021D1884
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
 *   func_021BBA1C  0x021BBA1C  thumb  ov021
 *   func_0201147C  0x0201147C  thumb
 *   func_021D1988  0x021D1988  thumb  ov021
 *   func_0216D568  0x0216D568  thumb  ov010
 */
#include "../../matched/include/Obj18374.h"
#include "../../matched/include/Obj04301.h"

struct Vec3;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_021BBA1C(int *p);
extern void *func_0201147C(u32 heap, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern void func_021D1988(u32 a, u32 b, struct Vec3 *c);
extern void *func_0216D568(void *p, u32 v);
void func_021D1884(u8 *p);
void func_021D1894(u8 *p, u32 n);
u32 func_021D18E0(u8 *p, u32 a1, u32 a2, u32 a3);


/*
 * Tail call on the word at +0x188.
 *
 * Addresses are Black-image addresses.
 */
void func_021D1884(u8 *p)
{
    func_021BBA1C((int *)(((struct Obj18374 *)p)->f188));
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D1894(u8 *p, u32 n)
{
    ((struct Obj04301 *)p)->f184 = (u32)func_0201147C(((struct Obj04301 *)p)->f19C, 0xCB, n, 10, (u32)(p + 4), 0x180);
    p[0x19A] = 1;
    p[0x199] = n;
    func_021D1988(((struct Obj04301 *)p)->f184, ((struct Obj04301 *)p)->f0, (struct Vec3 *)(p + 0x18C));
    func_0216D568((void *)(((struct Obj04301 *)p)->f0), 0x8000);
}


u32 func_021D18E0(u8 *p, u32 a1, u32 a2, u32 a3)
{
    if (p[0x19a] == 0) {
        return 1;
    }
    return 0;
}

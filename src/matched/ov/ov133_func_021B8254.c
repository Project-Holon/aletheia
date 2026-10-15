/*
 * function: func_021B8254
 * address: 0x021B8254
 * packet: pkt_ov133_021B8254
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA148 0x021BA148 thumb ov133
 *   func_021BA124 0x021BA124 thumb ov133
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   MUSICAL_MCSS_SetElemRotZ 0x021F4EB4 thumb ov112
 *   MUSICAL_MCSS_SetElemScale 0x021F4EA4 thumb ov112
 *   MUSICAL_MCSS_SetElemPos 0x021F4E8C thumb ov112
 */
#include "../include/Obj00004.h"
typedef unsigned char u8;
typedef struct { int x,y,z; } Vec;
extern unsigned int func_021BA218(u8 *p);
typedef signed short   s16;
typedef unsigned int   u32;
extern void func_021BA148(u8 *p, u8 *q);
extern void func_021BA124(u8 *p, u8 *q);
extern void *func_021BA184(char *p);
extern u32 func_021BA208(u8 *p);
extern void MUSICAL_MCSS_SetElemRotZ(u32 unused, u32 p, s16 a, s16 b);
extern void MUSICAL_MCSS_SetElemScale(u32 unused, u32 p, u32 q);
extern void MUSICAL_MCSS_SetElemPos(int, int, Vec *);
void func_021B8254(u8 *p)
{
    Vec v;
    u8 *e, *s;
    int z = 0xa000;
    s = (u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);
    func_021BA148(((struct Obj00004 *)p)->f1820, *(u8 * *)&((struct Obj00004 *)p)->f38);
    func_021BA124(((struct Obj00004 *)p)->f1820, *(u8 * *)&((struct Obj00004 *)p)->f38);
    MUSICAL_MCSS_SetElemRotZ(*(int *)&((struct Obj00004 *)p)->f1884, (int)s, 4096, 4096);
    e = func_021BA184(((struct Obj00004 *)p)->f1820);
    while (e) {
        s = (u8 *)func_021BA218(e);
        MUSICAL_MCSS_SetElemScale(*(int *)(p + 0x1884), (int)s, (u32)(&v));
        v.z = z;
        MUSICAL_MCSS_SetElemPos(*(int *)(p + 0x1884), (int)s, &v);
        z -= 1024;
        e = (u8 *)func_021BA208(e);
    }
}

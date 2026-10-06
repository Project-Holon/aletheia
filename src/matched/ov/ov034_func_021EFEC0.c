/*
 * function: func_021EFEC0
 * address:  0x021EFEC0
 * packet:   pkt_ov034_021EFEC0
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EFEC0 0x021EFEC0 thumb
 *   func_02030734 0x02030734 arm
 *   d_021F0B20    0x021F0B20 data ov034 a1
 *   func_021F0114 0x021F0114 thumb ov034
 *   func_021F0228 0x021F0228 thumb ov034
 *   func_021F0724 0x021F0724 thumb ov034
 *   func_021F0284 0x021F0284 thumb ov034
 *   func_0203D34C 0x0203D34C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021F09BC 0x021F09BC thumb ov034
 */
#include "../include/Obj00166.h"

typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char d_021F0B20[];
extern void func_021F0114(u32 heapId);
extern void func_021F0228(int);
typedef unsigned char  u8;
extern void func_021F0724(int *p);
extern void func_021F0284(u8 *p);
extern void func_0203D34C(u32 a, u32 b);
extern int func_020056A0(void *, void *, int);
extern void func_021F09BC(void *task, char *p);

void *func_021EFEC0(int a0, int a1)
{
    char *p = (char *)func_02030734(a1, 0x130, 0, d_021F0B20, 0x114);
    *(int *)&((struct Obj00166 *)p)->f0 = a0;
    ((struct Obj00166 *)p)->f12C = a1;
    ((struct Obj00166 *)p)->f110 = 0;
    ((struct Obj00166 *)p)->f128 = 0;
    func_021F0114(((struct Obj00166 *)p)->f12C);
    func_021F0228(((struct Obj00166 *)p)->f12C);
    func_021F0724((int *)p);
    func_021F0284((u8 *)p);
    func_0203D34C(0, a1);
    ((struct Obj00166 *)p)->f10C = func_020056A0(func_021F09BC, p, 0);
    return p;
}

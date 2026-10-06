/*
 * function: func_021E3E80
 * address: 0x021E3E80
 * packet: pkt_ov119_021E3E80
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_021D8AA8(void *);
typedef unsigned int   u32;
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *);
void func_021E3E80(char *p)
{
    void *v;
    int kind;
    int mode;
    v = func_020490F4(0x66, ((struct Obj00001 *)p)->f5F4);
    mode = func_021D8AA8(p);
    kind = 4;
    if (mode == 0)
        kind = 11;
    func_02049B68(v, 9, 0, 0, 0, ((struct Obj00001 *)p)->f5F4);
    if (*(int *)&((struct Obj00001 *)p)->f86C == 0)
        *(int *)&((struct Obj00001 *)p)->f86C = func_02049740(v, 10, 2, 0, 0, ((struct Obj00001 *)p)->f5F4);
    func_02049990(v, kind, (int)2, (int)0, (unsigned short)(((struct Obj00001 *)p)->f86C), (int)0, (int)0, (unsigned int)(((struct Obj00001 *)p)->f5F4));
    func_02049238(v);
}

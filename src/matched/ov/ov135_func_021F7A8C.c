/*
 * function: func_021F7A8C
 * address: 0x021F7A8C
 * packet: pkt_ov135_021F7A8C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F8950 0x021F8950 thumb ov135
 *   func_02202644 0x02202644 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj01552.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021F8950(void *p, u16 *old);
typedef unsigned int   u32;
struct Descriptor;
struct Obj;
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern void func_0201F868(void *p);
extern void func_02202644(u32 a, int kind);
extern void func_0201F7A8(void *p, unsigned kind);
extern void func_020452E8(struct Descriptor *d);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_020061E4(unsigned se);
int func_021F7A8C(u8 *p)
{
    switch ((unsigned)func_021F8950(((struct Obj01552 *)p)->fDF4, (u16 *)(p + 0xBC))) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        func_0202020C(((struct Obj01552 *)p)->fDF4, (u16 *)(*(u8 * *)&((struct Obj01552 *)p)->fE00 + 6), (u16 *)(*(u8 * *)&((struct Obj01552 *)p)->fE00 + 4));
        func_0201F868(((struct Obj01552 *)p)->fDE8);
        ((struct Obj01552 *)p)->f28 = 5;
        func_020061E4(0x54C);
        break;
    case (unsigned)-2:
        func_0202020C(((struct Obj01552 *)p)->fDF4, (u16 *)(*(u8 * *)&((struct Obj01552 *)p)->fE00 + 6), (u16 *)(*(u8 * *)&((struct Obj01552 *)p)->fE00 + 4));
        func_0201F868(((struct Obj01552 *)p)->fDE8);
        func_02202644((u32)(((struct Obj01552 *)p)->fD50), 0);
        func_0201F7A8(((struct Obj01552 *)p)->fD40, 0);
        func_020452E8(((struct Obj01552 *)p)->fD50);
        func_020452E8(((struct Obj01552 *)p)->fD54);
        func_021F4EC0(p, 5, 5);
        ((struct Obj01552 *)p)->f28 = 2;
        func_020061E4(0x54C);
        break;
    case 0:
        break;
    }
    return 2;
}

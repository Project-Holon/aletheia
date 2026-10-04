/*
 * function: func_021B8FB8
 * address:  0x021B8FB8
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tears down both 0x2c/0x7c buffers and the five 0x90 blocks, then clears the
 * display register.
 *
 * symbols:
 *   func_02027858  0x02027858  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020452E8  0x020452E8  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_020414EC  0x020414EC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02505.h"

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Descriptor;
struct Obj;
struct TaskMenu;
extern void func_02027858(struct TaskMenu *m);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_020452E8(struct Descriptor *d);
extern void func_0204B3B4(struct Obj *p);
extern void func_020414EC(u32 i);

void func_021B8FB8(void *a0, char *a1)
{
    void *p;

    if (((struct Obj02505 *)a1)->f80 != 0)
        func_02027858(((struct Obj02505 *)a1)->f80);

    p = ((struct Obj02505 *)a1)->f2C;
    func_020456F8(p);
    func_020409B4(func_02045730(p));

    p = ((struct Obj02505 *)a1)->f7C;
    func_020456F8(p);
    func_020409B4(func_02045730(p));

    func_020452E8(((struct Obj02505 *)a1)->f2C);
    func_020452E8(((struct Obj02505 *)a1)->f7C);
    func_0204B3B4(((struct Obj02505 *)a1)->f98);
    func_0204B3B4(((struct Obj02505 *)a1)->fA0);
    func_0204B3B4(((struct Obj02505 *)a1)->f9C);
    func_0204B3B4(((struct Obj02505 *)a1)->f94);
    func_0204B3B4(((struct Obj02505 *)a1)->f90);
    func_020414EC(6);
    func_020409B4(6);
    *(u16 *)0x04001050 = 0;
}

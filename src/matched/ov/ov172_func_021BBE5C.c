/*
 * function: func_021BBE5C
 * address:  0x021BBE5C
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Frees the 0x1c owner, both stream buffers, the two 0x400/0x404 blocks, the
 * 0xf by 0x1c record ring and the 0xf by 0x24 handle ring.
 *
 * symbols:
 *   func_02028148  0x02028148  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020452E8  0x020452E8  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02041EE4  0x02041EE4  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03316.h"
#include "../include/Obj08261.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Descriptor;
struct Obj;
extern void func_02028148(u8 *p);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_020307B0(void *p);
extern void func_020414EC(u32 i);
extern void func_02041EE4(u32 index, u32 a, u32 b);

void func_021BBE5C(void *a0, char *a1)
{
    u32 p;
    u8 i, j;

    if (((struct Obj03316 *)a1)->f1C != 0) {
        func_02028148((u8 *)(*(u32 *)&((struct Obj03316 *)a1)->f1C));
        *(u32 *)&((struct Obj03316 *)a1)->f1C = 0;
    }

    p = ((struct Obj03316 *)a1)->f2C;
    func_020456F8((struct Descriptor *)p);
    func_020409B4(func_02045730((struct Descriptor *)p));
    func_020452E8((struct Descriptor *)(((struct Obj03316 *)a1)->f2C));

    p = ((struct Obj03316 *)a1)->f30;
    func_020456F8((struct Descriptor *)p);
    func_020409B4(func_02045730((struct Descriptor *)p));
    func_020452E8((struct Descriptor *)(((struct Obj03316 *)a1)->f30));

    func_0204B3B4((struct Obj *)(((struct Obj03316 *)a1)->f404));
    func_0204B3B4((struct Obj *)(((struct Obj03316 *)a1)->f400));

    for (i = 0; i < 0xf; i++) {
        char *q = a1 + i * 0x1c;

        func_020452E8((struct Descriptor *)(((struct Obj08261 *)q)->f54));
        func_0204B3B4((struct Obj *)(((struct Obj08261 *)q)->f50));
        func_0204B3B4((struct Obj *)(((struct Obj08261 *)q)->f4C));
        func_0204B3B4((struct Obj *)(((struct Obj08261 *)q)->f48));
    }

    for (j = 0; j < 0xf; j++)
        func_020307B0((void *)(*(u32 *)(a1 + j * 0x24 + 0x1f8)));

    func_020414EC(6);
    func_020409B4(6);
    func_02041EE4(6, 3, 0);
    func_020414EC(4);
    func_020409B4(4);
    func_02041EE4(4, 3, 0);
}

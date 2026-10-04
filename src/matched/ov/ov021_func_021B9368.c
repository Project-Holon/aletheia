/*
 * function: func_021B9368
 * address:  0x021B9368
 * packet:   pkt_ov021_021B9368
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021B7EE4  0x021B7EE4  thumb  ov021
 *   func_021B80E0  0x021B80E0  thumb  ov021
 *   func_021B810C  0x021B810C  thumb  ov021
 *   func_021B8028  0x021B8028  thumb  ov021
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_021B7DE0  0x021B7DE0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03136.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_021B7EE4(u32 a, u32 b, u32 c, u32 d);
void func_021B80E0(u32 a, u32 b, u32 c);
struct Sub;
void func_021B810C(struct Sub *o);
void func_021B8028(u32 a, u32 b);
typedef signed int     s32;
s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
int func_021B7DE0(u32 a, u32 b);

int func_021B9368(u8 *p, u32 a1, u32 a2, int a3, u32 a5)
{
    int i;

    func_021B7EE4(((struct Obj03136 *)p)->f1C, a1, a2, a3);
    func_021B80E0(((struct Obj03136 *)p)->f1C, 4, a2);
    func_021B810C((struct Sub *)(((struct Obj03136 *)p)->f1C));
    func_021B80E0(((struct Obj03136 *)p)->f1C, 0, a2);
    for (i = 0; i < 16; i++) {
        if (a3 == i)
            func_021B8028(((struct Obj03136 *)p)->f1C, a5);
        func_021B810C((struct Sub *)(((struct Obj03136 *)p)->f1C));
    }
    if (func_0203EFC8((void *)a1, (void *)(((struct Obj03136 *)p)->f1C + 0x5c), 8) == 0)
        return 0;
    return func_021B7DE0(((struct Obj03136 *)p)->f1C, ((struct Obj03136 *)p)->f1C + 0x5c);
}

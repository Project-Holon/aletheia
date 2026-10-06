/*
 * function: func_021F1E98
 * address:  0x021F1E98
 * packet:   pkt_ov029_021F1E98
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021F1DB0  0x021F1DB0  thumb  ov029
 *   func_021F1BBC  0x021F1BBC  thumb  ov029
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0203FB44  0x0203FB44  arm
 */
#include "../include/Obj02111.h"

typedef unsigned int   u32;
extern void func_021F1DB0(char *p);
extern void func_021F1BBC(char *p);
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);

void func_021F1E98(char *p)
{
    int i;
    int *q;
    unsigned int v;

    func_021F1DB0(p);
    func_021F1BBC(p);
    for (i = 0; i < 11; i++) {
        q = (int *)(p + i * 4);
        if (q[0x4b] != 0) {
            func_0204B3B4((struct Obj *)q[0x4b]);
            q[0x4b] = 0;
        }
    }
    for (i = 0; i < 3; i++) {
        q = (int *)(p + i * 4);
        if (q[0x56] != 0) {
            func_0204B3B4((struct Obj *)q[0x56]);
            q[0x56] = 0;
        }
    }
    for (i = 0; i < 20; i++) {
        q = (int *)(p + i * 12);
        if (q[0xf] != 0) {
            func_0204B3B4((struct Obj *)q[0xf]);
            q[0xf] = 0;
        }
    }
    func_0204AFD8(((struct Obj02111 *)p)->f30);
    func_0204A8D4(((struct Obj02111 *)p)->f2C);
    func_0204ADA4(((struct Obj02111 *)p)->f28);
    v = ((struct Obj02111 *)p)->f14;
    func_0203FB44((int)6, (unsigned short)v, (unsigned short)(v >> 16));
}

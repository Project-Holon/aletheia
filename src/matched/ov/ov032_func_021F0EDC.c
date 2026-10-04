/*
 * function: func_021F0EDC
 * address:  0x021F0EDC
 * packet:   pkt_ov032_021F0EDC
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F0EDC  0x021F0EDC  thumb
 *   func_021F0EA4  0x021F0EA4  thumb  ov032
 *   func_021F0ED0  0x021F0ED0  thumb  ov032
 *   func_02043B5C  0x02043B5C  arm
 *   func_020257D0  0x020257D0  thumb
 *   func_0204581C  0x0204581C  arm
 *   func_02031194  0x02031194  arm
 */
#include "../include/Obj00225.h"

typedef unsigned char u8;

extern void func_021F0EA4(char *p, unsigned a);
extern void func_021F0ED0(char *p, int a);
struct CharBuf;
struct Obj;
struct TcblNode;
struct U16Vec;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020257D0(struct Obj *o);
extern void func_0204581C(struct U16Vec *vec);
extern void func_02031194(struct TcblNode *n);

void func_021F0EDC(char *p)
{
    int z = 0;

    func_021F0EA4(p, 0);
    func_021F0ED0(p, 0);
    func_02043B5C((struct CharBuf *)(((struct Obj00225 *)p)->f1C), 0);
    func_020257D0((struct Obj *)(*(int *)&((struct Obj00225 *)p)->f18));
    func_0204581C((struct U16Vec *)(*(int *)&((struct Obj00225 *)p)->f24));
    func_0204581C((struct U16Vec *)(*(int *)&((struct Obj00225 *)p)->f20));
    ((struct Obj00225 *)p)->f1 = 0xff;
    ((struct Obj00225 *)p)->f2 = z;
    ((struct Obj00225 *)p)->f3 = z;
    if (((struct Obj00225 *)p)->f2C != 0) {
        func_02031194((struct TcblNode *)(((struct Obj00225 *)p)->f2C));
        ((struct Obj00225 *)p)->f2C = z;
    }
    if (*(int *)&((struct Obj00225 *)p)->f30 != 0) {
        func_02031194((struct TcblNode *)(*(int *)&((struct Obj00225 *)p)->f30));
        *(int *)&((struct Obj00225 *)p)->f30 = 0;
    }
}

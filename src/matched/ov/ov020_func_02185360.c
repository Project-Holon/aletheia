/*
 * function: func_02185360
 * address:  0x02185360
 * packet:   pkt_ov020_02185360
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012894  0x02012894  thumb
 *   func_02012870  0x02012870  thumb
 *   func_02013E7C  0x02013E7C  thumb
 *   func_020128C0  0x020128C0  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_0201447C  0x0201447C  thumb
 *   func_02162694  0x02162694  thumb  ov010
 *   func_021625E8  0x021625E8  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 *   func_02184388  0x02184388  thumb  ov020
 *   func_02184CEC  0x02184CEC  thumb  ov020
 *   func_02185EB0  0x02185EB0  thumb  ov020
 */
#include "../include/Obj00248.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int f[7]; } S7;

struct BigObj;
struct Ctx;
struct Desc;
struct Obj;
struct Sub02014444Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void *func_020120F4(const struct Ctx *p);
S7 *func_02012894(void *p);
u16 *func_02012870(void *p);
u32 func_02013E7C(u32 id);
void func_020128C0(void *a, void *b);
void *func_02012B38(const struct BigObj *p);
u8 func_0201447C(struct Sub02014444Obj *o, u8 v);
int func_021625E8(int a0);
int func_02162694(int a0, int a1, int a2);
u8 func_021626E8(u8 *p);
int func_02184388(int a, int *state, u8 *p);
void func_02184CEC(void *obj, void *p);
void func_02185EB0(int a, u16 *p);

void *func_02185360(void *p, int u, int a, int b)
{
    char *r4;
    void *r5 = func_020120F4(p);
    void *r0v = func_020122C0(p, 0, func_02184388, 0x9c);
    u16 *r6;

    r4 = func_020124E8(r0v);
    func_02184CEC(r4, p);
    ((struct Obj00248 *)r4)->f40 = 1;
    if (func_021625E8(a) != 0) {
        *(S7 *)(r4 + 0x10) = *func_02012894(r5);
    } else {
        func_02162694(a, (int)(r4 + 0x10), b);
    }
    ((struct Obj00248 *)r4)->f2C = func_021626E8((u8 *)a);
    r6 = func_02012870(r5);
    if (func_02013E7C(r6[2]) == 1 && func_02013E7C(((struct Obj00248 *)r4)->f14) == 0) {
        func_020128C0(r5, r6);
    }
    func_02185EB0((int)r5, (u16 *)(r4 + 0x10));
    func_0201447C(func_02012B38(r5), 2);
    return r0v;
}

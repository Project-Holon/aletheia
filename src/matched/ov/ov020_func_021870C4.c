/*
 * function: func_021870C4
 * address:  0x021870C4
 * packet:   pkt_ov020_021870C4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02158434  0x02158434  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_021871F8  0x021871F8  thumb  ov020
 *   func_020124E8  0x020124E8  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020127D0  0x020127D0  thumb
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC70  0x0218DC70  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_020127F0  0x020127F0  thumb
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_02186090  0x02186090  thumb  ov020
 *   func_0219390C  0x0219390C  thumb  ov021
 */
#include "../include/Obj01343.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

typedef unsigned int   u32;
struct Ctx;
struct Desc;
struct Obj;
u16 func_02188C84(u8 *p);
u32 func_02188C54(u8 *p);
void *func_020120F4(const struct Ctx *p);
unsigned int func_02012138(const struct Ctx *p);
struct MsgBank;
struct U16Vec;
struct WordSet;
int func_02158344(int a0);
void *func_02158434(char *p);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
int func_021871F8(void *a, int *st, char *o);
struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
struct WordSet *func_0201EC64(u32 heap);
u8 *func_020127D0(u8 *o, u32 idx);
u32 func_02188C98(u8 *p);
void *func_0218DC70(u8 *p);
void *func_02188CB4(u8 *p);
void *func_02188C7C(u8 *p);
void func_020127F0(void *a);
int func_021A3460(u32 a, u32 b, u32 c, u32 d);
void *func_0216DDC0(u32 a, u32 b, u32 c, u32 d);
struct Actor;
struct VecFx32;
void func_0216D88C(const struct Actor *a, struct VecFx32 *b);
int func_02186090(void *p);
void *func_0219390C(void *a, unsigned int b);

void *func_021870C4(void *a0, void *a1)
{
    int n;
    int c54;
    void *h;
    void *w;
    void *ret;
    void *b;
    s16 v[3];
    char *o;
    void *a;
    void *c;
    int d;
    int e;
    void *x;

    n = func_02188C84(a1);
    c54 = func_02188C54(a1);
    h = func_020120F4(a0);
    w = (void *)func_02158344((int)((void *)func_02012138(a0)));
    if (w == 0)
        return 0;
    w = func_02158434(w);
    ret = func_020122C0(a0, 0, func_021871F8, 0x58);
    o = func_020124E8(ret);
    ((struct Obj01343 *)o)->f0 = a0;
    ((struct Obj01343 *)o)->f4 = a1;
    ((struct Obj01343 *)o)->f20 = (int)func_020457B0(0x100, n);
    ((struct Obj01343 *)o)->f24 = (int)func_020457B0(0x100, n);
    ((struct Obj01343 *)o)->f18 = (int)func_02045B38(0, 3, 0x142, n);
    ((struct Obj01343 *)o)->f1C = (int)func_0201EC64(n);
    ((struct Obj01343 *)o)->fC = c54;
    ((struct Obj01343 *)o)->f40 = w;
    ((struct Obj01343 *)o)->f56 = 1;
    ((struct Obj01343 *)o)->f8 = (n & 0x7FFF) | 0x8000;
    ((struct Obj01343 *)o)->f44 = (int)func_020127D0(h, 1);
    ((struct Obj01343 *)o)->f48 = (int)func_020127D0(h, 0);
    a = func_0218DC70((u8 *)func_02188C98(a1));
    b = func_02188CB4(a1);
    c = func_02188C7C(a1);
    func_020127F0(func_020120F4(a0));
    func_021A3460((u32)b, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    d = (int)func_0216DDC0((u32)c, v[2], v[0], 0);
    func_0216D88C((const struct Actor *)d, (struct VecFx32 *)(o + 0x34));
    e = func_02186090((void *)d);
    x = func_0219390C(a, e);
    ((struct Obj01343 *)o)->f28 = a;
    ((struct Obj01343 *)o)->f2C = x;
    ((struct Obj01343 *)o)->f30 = d;
    ((struct Obj01343 *)o)->f4C = e;
    return ret;
}

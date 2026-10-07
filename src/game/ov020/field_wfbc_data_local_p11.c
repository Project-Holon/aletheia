/*
 * file:     field_wfbc_data_local_p11.c
 * unit:     yes
 * function: func_02186E94, func_02186EB8, func_02187000, func_02187098, func_021870C4, func_021871F8
 * address:  0x02186E94
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_02158F58 0x02158F58 thumb ov010
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_020127F0 0x020127F0 thumb
 *   func_021869BC 0x021869BC thumb ov020
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_020127C4  0x020127C4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0201AA18  0x0201AA18  thumb
 *   func_021869D0  0x021869D0  thumb  ov020
 *   func_0203F4E4  0x0203F4E4  arm
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC70  0x0218DC70  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_02186090  0x02186090  thumb
 *   func_0219391C  0x0219391C  thumb  ov021
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_0201210C 0x0201210C thumb
 *   func_0215897C 0x0215897C thumb ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02158434  0x02158434  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020127D0  0x020127D0  thumb
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0219390C  0x0219390C  thumb  ov021
 *   func_021620A0  0x021620A0  thumb  ov010
 *   func_02162048  0x02162048  thumb  ov010
 *   func_0216208C  0x0216208C  thumb  ov010
 *   func_0216209C  0x0216209C  thumb  ov010
 *   func_0218741C  0x0218741C  thumb  ov020
 *   func_02186278  0x02186278  thumb  ov020
 *   func_02161E4C  0x02161E4C  thumb  ov010
 *   func_0218748C  0x0218748C  thumb  ov020
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_02012944  0x02012944  thumb
 *   func_02161F90  0x02161F90  thumb  ov010
 *   func_02193B20  0x02193B20  thumb  ov021
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_02187508  0x02187508  thumb  ov020
 *   func_021875B8  0x021875B8  thumb  ov020
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201ED04  0x0201ED04  thumb
 */
#include "../../matched/include/Obj01343.h"

#define P(o)  (*(void **)(o))
#define P18   (*(void **)(o + 0x18))
#define P1C   (*(void **)(o + 0x1c))
#define P20   (*(void **)(o + 0x20))
#define P24   (*(void **)(o + 0x24))
#define P28   (*(void **)(o + 0x28))
#define P30   (*(void **)(o + 0x30))
#define P40   (*(void **)(o + 0x40))
#define P44   (*(void **)(o + 0x44))
#define P48   (*(void **)(o + 0x48))
#define H08   (*(u16 *)(o + 0x08))
#define H4C   (*(u16 *)(o + 0x4c))
#define H4E   (*(u16 *)(o + 0x4e))
#define H50   (*(u16 *)(o + 0x50))
#define B54   (*(u8 *)(o + 0x54))
#define B56   (*(u8 *)(o + 0x56))
struct Ctx;
struct BigObj;
struct RtcDate;
struct Obj00020;
struct Desc;
struct Obj;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Actor;
struct VecFx32;
struct Rec;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char  u8;

typedef short s16;

typedef signed int     s32;

extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern int func_020127F0(int a0);
extern void func_021869BC(u16 *p);
void *func_0215A5E4(void *a);
u8 *func_020127C4(void *p);
void *func_02012934(const struct BigObj *p);
u16 *func_02159AE8(void *a, void *b);
u32 func_0201AA18(void *a);
u16 func_021869D0(char *p);
void func_0203F4E4(struct RtcDate *date);
void *func_0201AB28(void *a, u32 i);
u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02188C98(unsigned char *p);
extern void *func_0218DC70(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_02188C7C(u8 *p);
extern void *func_02158F74(void *);
extern unsigned int func_02159B10(void *a0, void *a1);
extern int func_021A3460(u32 a, u32 b, u32 c, u32 d);
extern void *func_0216DDC0(u32 a, u32 b, u32 c, u32 d);
extern int func_02186090(void *p);
extern unsigned char func_0219391C(unsigned char *);
extern void *func_0215A5DC(void *p);
extern void *func_0201210C(const struct Ctx *p);
extern void func_0215897C(void *vm, void *task);
u16 func_02188C84(u8 *p);
u32 func_02188C54(u8 *p);
unsigned int func_02012138(const struct Ctx *p);
int func_02158344(int a0);
void *func_02158434(char *p);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
struct WordSet *func_0201EC64(u32 heap);
u8 *func_020127D0(u8 *o, u32 idx);
void func_0216D88C(const struct Actor *a, struct VecFx32 *b);
void *func_0219390C(void *a, unsigned int b);
int func_021620A0(int a0);
void func_02162048(u16 *a, int b, int c);
int func_0216208C(char *p, int unused);
u16 func_0216209C(char *p);
void func_0218741C(char *p, int a1, int *out, int a3);
int func_02186278(char *p, int which);
int func_02161E4C(void *a0, int id, unsigned mode);
void func_0218748C(char *p, int a1, int *out, int a3, u16 a4);
void func_0204E720(u32 a, s32 b, s32 c, s32 d);
int func_0204E804(void);
u8 *func_02012944(void *p);
void func_02161F90(int unused, u16 *x, char *y, int z, u16 w, u16 v);
int func_02193B20(u32 a, u32 b);
void func_0216CF2C(void *a);
int func_02187508(char *p);
int func_021875B8(char *p);
void func_02045808(struct U16Vec *vec);
u32 func_02045C04(struct Rec *rec);
u32 func_0201ED04(struct WordSet *p);
int func_02186E94(void *unused, void *p);
int func_02186EB8(void *a0, void *a1);
int func_02187000(int a0, int a1);
int func_02187098(void *unused, void *p);
void *func_021870C4(void *a0, void *a1);
int func_021871F8(void *a, int *st, char *o);

/*
 * extent: two trailing zero alignment bytes.
 * interface: 020127F0's body loads only r0, forwarding r0 through 0200A864/0200A898.
 */
int func_02186E94(void *unused, void *p)
{
    func_021869BC((void *)func_020127F0((int)func_020120F4(func_02188C80(*(void **)(func_02158F58((int)func_0215A5F4(p)) + 4)))));
    return 0;
}


int func_02186EB8(void *a0, void *a1)
{
    void *s;
    void *w;
    void *b;
    u16 *f0;
    u16 *f1;
    u16 *f2;
    u32 n;
    int key;
    int d[4];
    u32 i;
    void *e;
    int v5, v92, v93, v94, v96, v4c, v8f, v90, v91;

    func_0215A5F4(a1);
    s = func_0215A5E4(a1);
    func_020127C4(s);
    w = (void *)func_020127F0((int)s);
    b = func_02012934(s);
    f0 = func_02159AE8(a0, a1);
    f1 = func_02159AE8(a0, a1);
    f2 = func_02159AE8(a0, a1);
    n = func_0201AA18(b);
    key = func_021869D0(w);
    func_0203F4E4((struct RtcDate *)d);
    *f0 = 0;
    *f1 = 0;
    *f2 = 0xFFFF;
    for (i = 0; i < n; i++) {
        e = func_0201AB28(b, i);
        v5 = func_02017E1C(e, 5, 0);
        v92 = func_02017E1C(e, 0x92, 0);
        v93 = func_02017E1C(e, 0x93, 0);
        v94 = func_02017E1C(e, 0x94, 0);
        v96 = func_02017E1C(e, 0x96, 0);
        v4c = func_02017E1C(e, 0x4c, 0);
        v8f = func_02017E1C(e, 0x8f, 0);
        v90 = func_02017E1C(e, 0x90, 0);
        v91 = func_02017E1C(e, 0x91, 0);
        if (v5 == key && v4c == 0 && v96 == 0x33 && v8f + v91 + v90 == 0) {
            *f0 = 1;
            if (*f2 == 0xFFFF)
                *f2 = i;
            if (v92 == d[0] && v93 == d[1] && v94 == d[2]) {
                *f1 = 1;
                *f2 = i;
            }
        }
    }
    return 0;
}


int func_02187000(int a0, int a1)
{
    void *r6;
    int *s;
    void *a;
    void *b;
    void *c;
    u16 *r4;
    int r5;
    int n;
    s16 v[3];

    r6 = func_0215A5F4((void *)a1);
    s = (int *)func_02158F58((int)r6);
    a = func_0218DC70((u8 *)func_02188C98((unsigned char *)s[1]));
    b = func_02188CB4((struct Obj00020 *)s[1]);
    c = func_02188C7C((u8 *)s[1]);
    func_02158F74(r6);
    r4 = func_02159AE8((void *)a0, (void *)a1);
    r5 = func_02159B10((void *)a0, (void *)a1);
    func_021A3460((u32)b, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    n = func_02186090(func_0216DDC0((u32)c, v[2], v[0], 0));
    r5 = (u16)(r5 - 1);
    if (func_0219391C(a) == 0)
        *r4 = r5 + (n * 4 + 1);
    else
        *r4 = r5 + (n * 4 + 9);
    return 0;
}

int func_02187098(void *unused, void *p)
{
    void *vm;
    void *obj;
    vm = func_0215A5F4(p);
    obj = func_0215A5DC(p);
    func_0215897C(vm, func_021870C4(obj, func_0201210C(obj)));
    return 1;
}


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
    func_020127F0((int)func_020120F4(a0));
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


/*
 * The step callback func_021870C4 registers (func_020122C0's third
 * argument) for the 0x58-byte work block it fills.
 */
int func_021871F8(void *a, int *st, char *o)
{
    if (func_02158344((int)((void *)func_02012138(P(o)))) == 0 && B56 != 0)
        *st = 0x11;

    switch (*st) {
    case 0:
        func_021620A0((int)P40);
        func_02162048(P40, H4C, 0);
        *st = 1;
        break;
    case 1:
        if (func_0216208C(P40, H4C) == 0)
            break;
        if (func_0216209C(P40) == 0)
            *st = 3;
        else
            *st = 2;
        break;
    case 2:
        func_0218741C(o, 0, st, 0x11);
        break;
    case 3:
        if (((u16 *)P44)[1] != ((u16 *)P48)[1])
            *st = 5;
        else
            *st = 4;
        break;
    case 4:
        func_0218741C(o, 1, st, 0x11);
        break;
    case 5:
        if ((unsigned int)func_02186278(P44, 0) >= 10) {
            *st = 6;
            break;
        }
        if (func_02161E4C(P44, H4C, 2) != 0)
            *st = 6;
        else
            *st = 7;
        break;
    case 6:
        func_0218741C(o, 2, st, 0x11);
        break;
    case 7:
        func_0218748C(o, 3, st, 9, 8);
        break;
    case 8:
        func_0218741C(o, 4, st, 0x11);
        break;
    case 9:
        func_021620A0((int)P40);
        func_02162048(P40, H4C, 1);
        *st = 10;
        break;
    case 10:
        if (func_0216208C(P40, H4C) == 0)
            break;
        if (func_0216209C(P40) == 2)
            *st = 12;
        else
            *st = 11;
        break;
    case 11:
        B56 = 0;
        func_0218741C(o, 5, st, 0x11);
        break;
    case 12:
        func_0218741C(o, 7, st, 0xd);
        func_021620A0((int)P40);
        func_02162048(P40, H4C, 2);
        B56 = 0;
        break;
    case 13:
        func_0204E720(1, 0, 0x10, 0);
        *st = 14;
        break;
    case 14:
        if (func_0204E804() != 0)
            break;
        func_02161F90((int)P40, P44, P48, (int)func_02012944(func_020120F4(P(o))), H4C, H08);
        func_02193B20((u32)P28, H4C);
        func_0216CF2C(P30);
        func_0204E720(1, 0x10, 0, 0);
        *st = 15;
        break;
    case 15:
        if (func_0204E804() != 0)
            break;
        *st = 0x11;
        break;
    case 16:
        if (func_02187508(o) == 0)
            break;
        if (B54)
            *st = H4E;
        else
            *st = H50;
        break;
    case 17:
        if (func_021875B8(o) == 0)
            break;
        func_02045808(P20);
        func_02045808(P24);
        func_02045C04(P18);
        func_0201ED04(P1C);
        return 1;
    }
    return 0;
}

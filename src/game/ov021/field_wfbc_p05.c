/*
 * file:     field_wfbc_p05.c
 * unit:     yes
 * function: func_02193BE4, func_02193C00, func_02193C04, func_02193C08, func_02193C80, func_02193CBC, func_02193D08, func_02193D30, func_02193E54, func_02193EB4
 * address:  0x02193BE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02193F34  0x02193F34  thumb  ov021
 *   func_02186770  0x02186770  thumb
 *   func_021867C4  0x021867C4  thumb  ov020
 *   func_02030734  0x02030734  arm
 *   func_02193F6C  0x02193F6C  thumb  ov021
 *   func_020490F4  0x020490F4  arm
 *   func_02186830  0x02186830  thumb
 *   d_021DDA60     0x021DDA60  data  a4
 *   func_020307B0  0x020307B0  arm  arm9
 *   func_02049238  0x02049238  arm  arm9
 *   func_02186804  0x02186804  thumb  ov020
 *   func_0218683C  0x0218683C  thumb  ov020
 *   func_02082BCC  0x02082BCC  arm
 *   func_02193FE8  0x02193FE8  thumb  ov021
 *   func_02194078  0x02194078  thumb  ov021
 *   func_0218625C  0x0218625C  thumb  ov020
 *   func_02161ECC  0x02161ECC  thumb  ov010
 *   func_02186818  0x02186818  thumb  ov020
 *   func_02186844  0x02186844  thumb  ov020
 *   func_0218682C  0x0218682C  thumb  ov020
 *   func_02193F80  0x02193F80  thumb  ov021
 *   func_02194084  0x02194084  thumb  ov021
 *   func_02194128  0x02194128  thumb  ov021
 *   func_020493D4  0x020493D4  arm
 *   func_0204932C  0x0204932C  arm
 *   d_021D3F58     0x021D3F58  data  a4
 *   func_0218609C  0x0218609C  thumb  ov020
 *   func_021860B8  0x021860B8  thumb  ov020
 *   func_02193FD4  0x02193FD4  thumb  ov021
 *   func_02193FBC  0x02193FBC  thumb  ov021
 */
#include "../../matched/include/Obj00485.h"
#include "../../matched/include/Obj04214.h"
#include "../../matched/include/Obj19618.h"
#include "../../matched/include/Obj07441.h"
#include "../../matched/include/Obj12617.h"

struct V;
struct E50;
struct ArcFile;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16_02193BE4;

typedef signed char    s8;

typedef short          s16_02193C80;

typedef struct X {
    u32 f00;
    void *f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    void *f14;
    u8  pad18[0x100];
    u32 f118;
} X;

typedef struct { u8 a; u8 b; u8 rest[0x16]; } E18_02193D30;

typedef struct { u16 h0; u16 h1; u32 w4; E18_02193D30 A[10]; E18_02193D30 B[10]; } Src;

typedef short          s16_02193EB4;

typedef struct E50 {
    u16 f00;
    u8  pad02[0x32];
    u8  f34[0x1C];
} E50;

typedef struct E18_02193EB4 {
    u8 b[0x18];
} E18_02193EB4;

typedef struct Tbl {
    u8  hdr[8];
    E18_02193EB4 e[10];
} Tbl;

typedef struct V {
    u8   f00;
    u8   f01;
    u8   pad02[2];
    E50 *f04;
    Tbl *f08;
} V;

extern int func_02186770(u8 *);
extern u8 *func_02193F34(void *, u32);
extern int *func_021867C4(int a, int id);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern void func_02193F6C(struct E50 *e);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_02186830(int, int, int);
extern void func_0218683C(void *p);
extern u32 func_020307B0(void *p);
extern void func_02049238(u32 a);
extern void func_02186804(void **p);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02193FE8(void *p);
extern void func_02194078(u32 a);
extern int func_0218625C(unsigned short *p);
extern int func_02161ECC(E18_02193D30 *p);
extern void func_02186818(u32 *p, u32 member);
extern u8 *func_02186844(u8 *t, int i);
extern char *func_0218682C(char *p);
extern void func_02193F80(struct E50 *e, void *a, u8 *b, void *c);
extern void func_02194084(u8 *p, Src *s, int h);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern void func_02194128(u8 *p, int a, u8 *b);
extern void func_0218609C(char *p);
extern void func_021860B8(char *p);
extern void func_02193FD4(u16 *a, void *b);
extern void func_02193FBC(u16 *a, void *b);
int func_02193BE4(void *a, u32 b);
char *func_02193C00(char *p);
void *func_02193C04(u8 *p);
void func_02193C08(char *p, int heap);
void func_02193C80(X *x);
void func_02193CBC(unsigned char *p);
int func_02193D08(unsigned char *p);
void func_02193D30(u8 *o, Src *s, int which);
void func_02193E54(unsigned char *p, unsigned char *q);
void func_02193EB4(V *v);
extern int d_021DDA60;
extern int d_021D3F58[];


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_02186770 (0x02186770) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02193BE4(void *a, u32 b)
{
func_02193EB4(a);
return func_02186770((func_02193F34(a, b) + 52));
}

char *func_02193C00(char *p)
{
    return p + 4;
}


/*
 * Unlabelled leaf (saves nothing, so disasm.py prints it as .word data);
 * filed as the blocker of func_02186D48 (ov020).
 */
void *func_02193C04(u8 *p)
{
    return p + 0x34;
}


void func_02193C08(char *p, int heap)
{
    int i;

    if (((struct Obj00485 *)p)->fC == 0) {
        i = 0;
        ((struct Obj00485 *)p)->fC = (int)func_021867C4(0, heap);
        ((struct Obj00485 *)p)->f4 = func_02030734(heap, 0x320, 1, (const char *)&d_021DDA60, 0x39e);
        for (i = 0; i < 10; i++) {
            func_02193F6C((struct E50 *)((char *)*(int *)&((struct Obj00485 *)p)->f4 + i * 0x50));
        }
        ((struct Obj00485 *)p)->f10 = func_020490F4(0x9a, heap);
        ((struct Obj00485 *)p)->f14 = func_02030734(heap, 0x600, 1, (const char *)&d_021DDA60, 0x3ab);
        *(int *)&((struct Obj00485 *)p)->f118 = func_02186830(((struct Obj00485 *)p)->fC, ((struct Obj00485 *)p)->f0, heap);
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_02193C80(X *x)
{
    if (x->f0c != 0) {
        func_0218683C((void *)x->f118);
        func_020307B0(x->f14);
        func_02049238(x->f10);
        func_02186804((void **)x->f0c);
        func_020307B0(x->f04);
        x->f0c = 0;
        x->f04 = 0;
        x->f10 = 0;
        x->f14 = 0;
        x->f118 = 0;
    }
}


void func_02193CBC(unsigned char *p)
{
    int i;
    unsigned char *q = *(unsigned char * *)&((struct Obj04214 *)p)->f4;

    p[0] = 0;
    p[1] = 0;
    ((struct Obj04214 *)p)->f8 = 0;
    if (q != 0) {
        for (i = 0; i < 10; i++)
            func_02193F6C((struct E50 *)(*(unsigned char * *)&((struct Obj04214 *)p)->f4 + i * 0x50));
    }
    if (((struct Obj04214 *)p)->f14 != 0)
        func_02082BCC(((struct Obj04214 *)p)->f14, 0, 0x600);
    func_02193FE8(p + 0x18);
    func_02194078((u32)(p + 0x11c));
}


int func_02193D08(unsigned char *p)
{
    int count = 0;
    int i;
    unsigned char *q = *(unsigned char * *)&((struct Obj19618 *)p)->f4;

    if (q != 0) {
        for (i = 0; i < 10; i++) {
            if (*(unsigned short *)(q + i * 0x50) != 0)
                count++;
        }
    }
    return count;
}


void func_02193D30(u8 *o, Src *s, int which)
{
    int i;
    int off;
    u8 *pair;

    func_0218625C((short unsigned int *)s);
    func_02193CBC(o);
    o[0] = s->h1;
    o[1] = which;
    for (i = 0; i < 10; i++) {
        if (which == 0) {
            off = i * 0x18;
            if (func_02161ECC((E18_02193D30 *)((u8 *)s->A + off))) {
                func_02186818((u32 *)(((struct Obj00485 *)o)->fC), s->A[i].b);
                func_02193F80((struct E50 *)(*(u8 * *)&((struct Obj00485 *)o)->f4 + i * 0x50), (E18_02193D30 *)((u8 *)s->A + off),
                              func_02186844(*(u8 * *)&((struct Obj00485 *)o)->f118, i),
                              (u16 *)func_0218682C((char *)(((struct Obj00485 *)o)->fC)));
            }
        } else {
            off = i * 0x18;
            if (func_02161ECC((E18_02193D30 *)((u8 *)s->B + off))) {
                func_02186818((u32 *)(((struct Obj00485 *)o)->fC), s->B[i].b);
                pair = func_02186844(*(u8 * *)&((struct Obj00485 *)o)->f118, i);
                func_0218682C((char *)(((struct Obj00485 *)o)->fC));
                func_02193F80((struct E50 *)(*(u8 * *)&((struct Obj00485 *)o)->f4 + i * 0x50), (E18_02193D30 *)((u8 *)s->B + off),
                              pair, (u16 *)func_0218682C((char *)(((struct Obj00485 *)o)->fC)));
            }
        }
    }
    func_02194084(o + 0x11c, s, ((struct Obj00485 *)o)->fC);
    if (which == 0)
        *(Src * *)&((struct Obj00485 *)o)->f8 = s;
    else
        *(Src * *)&((struct Obj00485 *)o)->f8 = 0;
    func_020493D4((struct ArcFile *)(*(int *)&((struct Obj00485 *)o)->f10), d_021D3F58[o[0]]);
    func_0204932C((struct ArcFile *)(*(int *)&((struct Obj00485 *)o)->f10), d_021D3F58[o[0]], (void *)(*(int *)&((struct Obj00485 *)o)->f14));
    func_02194128(o + 0x11c, *(int *)&((struct Obj00485 *)o)->f14, o + 0x18);
}


void func_02193E54(unsigned char *p, unsigned char *q)
{
    int i;

    ((struct Obj12617 *)q)->f0 = 1;
    ((struct Obj12617 *)q)->f2 = p[0];
    if (p[1] == 0) {
        func_0218609C((char *)q);
        q += 8;
        for (i = 0; i < 10; i++)
            func_02193FD4((u16 *)(*(unsigned char * *)&((struct Obj07441 *)p)->f4 + i * 0x50), q + i * 0x18);
    } else {
        func_021860B8((char *)q);
        q += 0xf8;
        for (i = 0; i < 10; i++)
            func_02193FD4((u16 *)(*(unsigned char * *)&((struct Obj07441 *)p)->f4 + i * 0x50), q + i * 0x18);
    }
}


void func_02193EB4(V *v)
{
    int i;

    if (v->f01 == 0 && v->f08 != 0) {
        for (i = 0; i < 10; i++)
            func_02193FBC((u16 *)(&v->f04[i]), &v->f08->e[i]);
    }
}

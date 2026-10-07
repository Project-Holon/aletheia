/*
 * file:     fieldmap_func_p03.c
 * unit:     yes
 * function: func_021BB778, func_021BB7B4, func_021BB808, func_021BB890, func_021BB90C, func_021BB948, func_021BB954
 * address:  0x021BB778
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
 *   func_020061E4  0x020061E4  thumb
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B0C  0x02048B0C  arm
 *   func_02048B30  0x02048B30  arm
 *   func_0207BCA0  0x0207BCA0  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0207B0A4  0x0207B0A4  arm
 *   func_0207B51C  0x0207B51C  arm
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_02030734  0x02030734  arm
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   d_021DE2F8     0x021DE2F8  data  a4
 *   func_021BBA1C  0x021BBA1C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_02030D28  0x02030D28  arm
 */
#include "../../matched/include/Obj18174.h"
#include "../../matched/include/Obj18175.h"

struct Ctx;
typedef unsigned int   u32;

typedef struct Vec {
    int x;
    int y;
    int z;
} Vec;

typedef unsigned char  u8;

typedef struct {
    char b[0x18];
} E18;

typedef struct {
    int f0;
    int f4;
    int n;
    E18 *arr;
    void *f10;
    void *f14;
} Obj;

typedef unsigned short u16;

void func_020061E4(u32 a);
void func_02048AE8(int a, int *out);
void func_02048B0C(int a, int *out);
void func_02048B30(int a, int *out);
void func_0207BCA0(int *a, int *b, int *c, int *d);
void func_02082B60(int *a, int *b);
void func_0207B0A4(int *a, int *b);
void func_0207B51C(int a, int *b, int c);
void *func_02188C58(void *p);
u32 func_0218EC2C(u8 *p);
void func_0207C9D0(Vec *a, Vec *b, Vec *c);
void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);
u32 func_02030CB0(u32 idx);
struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_021BBA1C(int *p);
extern u32 func_020307B0(void *p);
extern void func_02030D28(struct Ctx *c);
void func_021BB778(int n);
void func_021BB7B4(int a, int b, int c);
void func_021BB808(int *o, Vec *out);
int *func_021BB890(int a, int b, int n);
void func_021BB90C(Obj *p);
void func_021BB948(u8 *p);
void func_021BB954(u8 *p);
extern int d_021DE2F8;


void func_021BB778(int n)
{
    int id = 0;

    switch (n) {
    case 0:
        id = 0x678;
        break;
    case 1:
        id = 0x730;
        break;
    case 2:
        id = 0x731;
        break;
    case 3:
        return;
    }
    func_020061E4(id);
}


void func_021BB7B4(int a, int b, int c)
{
    int v6c[3];
    int v60[3];
    int v54[3];
    int m24[12];
    int m0[9];

    func_02048AE8(a, v6c);
    func_02048B0C(a, v60);
    func_02048B30(a, v54);
    func_0207BCA0(v6c, v60, v54, m24);
    func_02082B60(m24, m0);
    func_0207B0A4(m0, m0);
    func_0207B51C(b, m0, c);
}


void func_021BB808(int *o, Vec *out)
{
    int r3;
    Vec w;

    switch (o[7]) {
    case 0:
        o[10] += o[11];
        if (o[10] != 0) {
            o[11] = o[11] - 0x2000;
        } else {
            o[11] = 0;
            o[7] = o[7] + 1;
        }
        break;
    case 1:
        o[8] = o[8] + 1;
        if (o[8] >= 30) {
            o[7] = o[7] + 1;
            o[9] = 1;
        }
        break;
    }
    r3 = func_0218EC2C(func_02188C58((void *)o[6]));
    {
        Vec v = {0, 0, 0};

        v.y = o[10] + 0x16000;
        w = v;
    }
    func_021BB7B4(r3, (int)(&w), (int)(&w));
    func_0207C9D0(&w, out, out);
}


int *func_021BB890(int a, int b, int n)
{
    int *p = func_02030734(b, 0x18, 1, (const char *)&d_021DE2F8, 0x46);
    int sz;

    p[0] = a;
    p[1] = b;
    p[2] = n;
    p[3] = (int)func_02030734(b, 0x18 * n, 1, (const char *)&d_021DE2F8, 0x4a);
    sz = func_02030CB0(n);
    p[5] = (int)func_02030734(b, sz, 1, (const char *)&d_021DE2F8, 0x56);
    p[5] = (int)func_02030CBC(n, (struct Ctx *)p[5]);
    p[4] = (int)func_02030734(b, sz, 1, (const char *)&d_021DE2F8, 0x59);
    p[4] = (int)func_02030CBC(n, (struct Ctx *)p[4]);
    return p;
}


void func_021BB90C(Obj *p)
{
    int i;

    for (i = 0; i < p->n; i++) {
        func_021BBA1C((int *)(&p->arr[i]));
    }
    func_020307B0(p->arr);
    func_020307B0(p->f10);
    func_020307B0(p->f14);
    func_020307B0(p);
}


void func_021BB948(u8 *p)
{
    func_02030D28((struct Ctx *)(((struct Obj18174 *)p)->f10));
}


void func_021BB954(u8 *p)
{
    func_02030D28((struct Ctx *)(((struct Obj18175 *)p)->f14));
}

/*
 * file:     intrude_subdisp_p17.c
 * unit:     yes
 * function: func_0217FCAC, func_0217FD34
 * address:  0x0217FCAC
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02158344  0x02158344  thumb ov010
 *   func_02167A54  0x02167A54  thumb ov010
 *   func_02188C7C  0x02188C7C  thumb ov021
 *   func_0216D9A0  0x0216D9A0  thumb ov010
 *   func_0216D9E4  0x0216D9E4  thumb ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_0217FDA0  0x0217FDA0  thumb ov018
 *   func_021800A4  0x021800A4  thumb ov018
 */
#include "../../matched/include/Obj04178.h"

struct Ctx;
struct Evt;
struct Obj;
struct Desc;
typedef unsigned short u16;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef struct {
    int w[13];
} S52;

void *func_020124E4(struct Obj *p);
unsigned int func_02012138(const struct Ctx *p);
void func_02012374(struct Evt *evt, struct Evt **out);
int func_02158344(int a0);
int func_02167A54(int *p, int i);
void *func_02188C7C(unsigned char *p);
void func_0216D9A0(void *x);
u32 *func_0216D9E4(void *c);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void func_02082BCC(void *p, int v, int n);
void func_0217FDA0(int a, u8 *b, u8 *c, int d, int e, int f, u16 g);
int func_021800A4(void);
int func_0217FCAC(int x, int *st, int *obj);
void *func_0217FD34(int a, int b, u8 *c, int d, int e, u16 f);


int func_0217FCAC(int x, int *st, int *obj)
{
    int v = (int)func_020124E4((struct Obj *)x);
    int *m;

    m = (int *)func_02158344(func_02012138((const struct Ctx *)v));
    switch (*st) {
    case 0:
        if (m == 0) {
            return 1;
        }
        if (func_02167A54((int *)m[2], obj[2]) == 0) {
            return 1;
        }
        func_0216D9A0(func_02188C7C((unsigned char *)obj[0]));
        func_02012374((struct Evt *)x, func_0217FD34(v, obj[0], (u8 *)m, obj[1], obj[2], ((struct Obj04178 *)obj)->fC));
        *st = *st + 1;
        break;
    case 1:
        func_0216D9E4(func_02188C7C((unsigned char *)obj[0]));
        return 1;
    }
    return 0;
}


void *func_0217FD34(int a, int b, u8 *c, int d, int e, u16 f)
{
    void *r = func_020122C0((void *)a, 0, func_021800A4, 0x9c);
    u8 *q = func_020124E8(r);

    func_02082BCC(q, 0, 0x9c);
    func_0217FDA0(a, (u8 *)((int *)c), q, b, d, e, f);
    q[0x41] = c[0x11c];
    *(S52 *)(q + 0x44) = *(S52 *)(c + 0x120);
    return r;
}

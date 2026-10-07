/*
 * file:     fld3d_ci_p05.c
 * unit:     yes
 * function: func_021C21B4, func_021C223C, func_021C22AC, func_021C2320
 * address:  0x021C21B4
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
 *   func_021C24A8  0x021C24A8  thumb  ov021
 *   func_021C1AB4  0x021C1AB4  thumb  ov021
 *   func_020489F4  0x020489F4  arm
 *   func_02048A18  0x02048A18  arm
 *   func_0204779C  0x0204779C  arm
 *   func_020478B8  0x020478B8  arm
 *   func_021C1A48  0x021C1A48  thumb  ov021
 *   func_021C24F0  0x021C24F0  thumb  ov021
 *   func_021C1C24  0x021C1C24  thumb  ov021
 *   func_021C1A98  0x021C1A98  thumb  ov021
 *   func_021C1AA8  0x021C1AA8  thumb  ov021
 *   func_02048A00  0x02048A00  arm
 *   func_020477A4  0x020477A4  arm
 *   func_02051B04  0x02051B04  arm
 *   func_020124E4  0x020124E4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_02012374  0x02012374  thumb
 */
#include "../../matched/include/Obj01864.h"
#include "../../matched/include/Obj05076.h"
#include "../../matched/include/Obj05077.h"
#include "../../matched/include/Obj00456.h"
#include "../../matched/include/Obj00616.h"

struct Desc;
struct G3dSys;
struct Evt;
struct Obj;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

void func_021C24A8(char *p, int k);
int func_021C1AB4(u32 *p);
unsigned int func_020489F4(u8 *a0, int i);
u32 func_02048A18(u8 *a0, int i);
int func_0204779C(int *p);
int func_020478B8(void *a, int idx, int amount);
int func_021C1A48(int a);
void func_021C24F0(char *q, int d, u16 e);
void func_021C1C24(char *p, char *q);
void *func_021C1A98(u16 *p, int a, int b);
int func_021C1AA8(u32 a, u32 b, u32 c, u32 d);
u32 func_02048A00(u8 *a0, int i);
u32 func_020477A4(struct G3dSys *sys, u32 idx);
u16 func_02051B04(void *res);
void *func_020124E4(struct Obj *p);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void func_02012374(struct Evt *evt, struct Evt **out);
int func_021C21B4(char *p);
int func_021C223C(char *p);
int func_021C22AC(char *p);
void func_021C2320(void *a, char *p, char *q, int d);


int func_021C21B4(char *p)
{
    if (((struct Obj01864 *)p)->f64 == 0) {
        if (((struct Obj01864 *)p)->f78 == 0) {
            if (((struct Obj01864 *)p)->f5C != 0) {
                (((struct Obj01864 *)p)->f5C)--;
            } else {
                func_021C24A8(p, 0);
                ((struct Obj01864 *)p)->f78 = 1;
            }
        }
        if (((struct Obj01864 *)p)->f7C == 0) {
            if (((struct Obj01864 *)p)->f5E != 0) {
                (((struct Obj01864 *)p)->f5E)--;
            } else {
                func_021C24A8(p, 1);
                ((struct Obj01864 *)p)->f7C = 1;
            }
        }
        if (((struct Obj01864 *)p)->f78 != 0 && ((struct Obj01864 *)p)->f7C != 0)
            ((struct Obj01864 *)p)->f64 = 1;
    } else if (func_021C1AB4((u32 *)(((struct Obj01864 *)p)->f0)) != 0) {
        return 1;
    }
    return 0;
}


int func_021C223C(char *p)
{
    int a;
    u8 k;
    int r;
    int n;

    if (((struct Obj05076 *)p)->f80 == 0)
        return 1;
    if (((struct Obj05076 *)p)->f60 != 0) {
        (((struct Obj05076 *)p)->f60)--;
    } else {
        a = func_02048A18((u8 *)(((struct Obj05076 *)p)->f14), (int)func_020489F4((u8 *)(((struct Obj05076 *)p)->f14), (u16)(((struct Obj05076 *)p)->f18)));
        n = func_0204779C((int *)a);
        for (k = 0; k < n; k++)
            r = func_020478B8((void *)a, k, 0x1000);
        if (r == 0)
            return 1;
    }
    return 0;
}


int func_021C22AC(char *p)
{
    int a;
    u8 k;
    int r;
    int n;

    if (((struct Obj05077 *)p)->f84 == 0)
        return 1;
    if (((struct Obj05077 *)p)->f62 != 0) {
        (((struct Obj05077 *)p)->f62)--;
    } else {
        a = (int)func_02048A18((u8 *)(((struct Obj05077 *)p)->f14), (u16)((int)func_020489F4((u8 *)(((struct Obj05077 *)p)->f14), (u16)(((struct Obj05077 *)p)->f18)) + 1));
        n = func_0204779C((int *)a);
        for (k = 0; k < n; k++)
            r = func_020478B8((void *)a, k, 0x1000);
        if (r == 0)
            return 1;
    }
    return 0;
}


void func_021C2320(void *a, char *p, char *q, int d)
{
    int t;
    u8 i;
    int base;
    int cnt;
    u8 k;
    int h;
    int n;
    int r;

    ((struct Obj00616 *)p)->f58 = func_021C1A48(((struct Obj00616 *)p)->f0);
    func_021C24F0(q, d, ((struct Obj00616 *)p)->f10);
    func_021C1C24(p, q + 0x10);
    if (((struct Obj00456 *)q)->f28 != 0xFFFF) {
        t = (int)func_021C1A98((u16 *)(((struct Obj00616 *)p)->f0), 0x73, ((struct Obj00456 *)q)->f28);
        func_021C1AA8(((struct Obj00616 *)p)->f0, t, 1, 0);
    } else {
        t = 0;
    }
    base = (int)func_020489F4((u8 *)(((struct Obj00616 *)p)->f14), (u16)(((struct Obj00616 *)p)->f18));
    cnt = (int)func_02048A00((u8 *)(((struct Obj00616 *)p)->f14), (u16)(((struct Obj00616 *)p)->f18));
    for (i = 0; i < cnt; i++) {
        h = (int)func_02048A18((u8 *)(((struct Obj00616 *)p)->f14), (u16)(base + i));
        n = func_0204779C((int *)h);
        for (k = 0; k < n; k++)
            func_020477A4((struct G3dSys *)h, (u8)k);
    }
    ((struct Obj00616 *)p)->f5C = ((struct Obj00456 *)q)->f20;
    ((struct Obj00616 *)p)->f5E = ((struct Obj00456 *)q)->f22;
    ((struct Obj00616 *)p)->f60 = ((struct Obj00456 *)q)->f24;
    ((struct Obj00616 *)p)->f62 = ((struct Obj00456 *)q)->f26;
    if (t != 0)
        r = func_02051B04((void *)t);
    else
        r = 0;
    if (r == 2) {
        ((struct Obj00616 *)p)->f78 = 0;
        ((struct Obj00616 *)p)->f7C = 0;
    } else if (r == 1) {
        ((struct Obj00616 *)p)->f78 = 0;
        ((struct Obj00616 *)p)->f7C = 1;
    } else {
        ((struct Obj00616 *)p)->f78 = 1;
        ((struct Obj00616 *)p)->f7C = 1;
    }
    ((struct Obj00616 *)p)->f80 = 0;
    ((struct Obj00616 *)p)->f84 = 0;
    if (((struct Obj00456 *)q)->f2E != 0)
        ((struct Obj00616 *)p)->f80 = 1;
    if (((struct Obj00456 *)q)->f2F != 0)
        ((struct Obj00616 *)p)->f84 = 1;
    if (((struct Obj00616 *)p)->f128 != 0) {
        h = (int)func_020124E4((struct Obj *)a);
        func_02012374((struct Evt *)a, (struct Evt **)func_020122C0((void *)h, a, (void *)(((struct Obj00616 *)p)->f128), (int)0));
    }
}

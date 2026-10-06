/*
 * function: func_021C2320
 * address:  0x021C2320
 * packet:   pkt_ov021_021C2320
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021C1A48  0x021C1A48  thumb  ov021
 *   func_021C24F0  0x021C24F0  thumb  ov021
 *   func_021C1C24  0x021C1C24  thumb  ov021
 *   func_021C1A98  0x021C1A98  thumb  ov021
 *   func_021C1AA8  0x021C1AA8  thumb  ov021
 *   func_020489F4  0x020489F4  arm
 *   func_02048A00  0x02048A00  arm
 *   func_02048A18  0x02048A18  arm
 *   func_0204779C  0x0204779C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_02051B04  0x02051B04  arm
 *   func_020124E4  0x020124E4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_02012374  0x02012374  thumb
 */
#include "../include/Obj00456.h"
#include "../include/Obj00616.h"

typedef unsigned char u8;
typedef unsigned short u16;

int func_021C1A48(int a);
void func_021C24F0(char *q, int d, u16 e);
void func_021C1C24(char *p, char *q);
void *func_021C1A98(u16 *p, int a, int b);
typedef unsigned int   u32;
int func_021C1AA8(u32 a, u32 b, u32 c, u32 d);
int func_020489F4(int a, u16 b);
int func_02048A00(int a, u16 b);
int func_02048A18(int a, u16 b);
struct Evt;
struct Obj;
int func_0204779C(int *p);
void func_020477A4(int a, u8 b);
u16 func_02051B04(void *res);
void *func_020124E4(struct Obj *p);
int func_020122C0(int a, int b, int c, int d);
void func_02012374(struct Evt *evt, struct Evt **out);

void func_021C2320(int a, char *p, char *q, int d)
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
    base = func_020489F4(((struct Obj00616 *)p)->f14, ((struct Obj00616 *)p)->f18);
    cnt = func_02048A00(((struct Obj00616 *)p)->f14, ((struct Obj00616 *)p)->f18);
    for (i = 0; i < cnt; i++) {
        h = func_02048A18(((struct Obj00616 *)p)->f14, base + i);
        n = func_0204779C((int *)h);
        for (k = 0; k < n; k++)
            func_020477A4(h, k);
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
        func_02012374((struct Evt *)a, (struct Evt **)func_020122C0(h, a, ((struct Obj00616 *)p)->f128, 0));
    }
}

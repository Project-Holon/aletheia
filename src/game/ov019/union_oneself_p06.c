/*
 * file:     union_oneself_p06.c
 * unit:     yes
 * function: func_0217FAF0, func_0217FB30, func_0217FB70, func_0217FBD0, func_0217FC08, func_0217FC64, func_0217FCA4, func_0217FCC0, func_0217FCC4, func_0217FCE4, func_0217FD04, func_0217FD38, func_0217FD88, func_0217FDC8, func_0217FDF8, func_0217FE24, func_0217FE38, func_0217FE44, func_0217FEB8, func_0217FEF4, func_0217FF14
 * address:  0x0217FAF0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MTX_Identity33_  0x0207ADC4  arm
 *   func_0216DA30    0x0216DA30  thumb  ov010
 *   func_0217FA9C    0x0217FA9C  thumb  ov019
 *   d_0218071C       0x0218071C  data   ov019 a4
 *   func_0217FA54  0x0217FA54  thumb  ov019
 *   sub_020490F4   0x020490F4  arm
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   sub_02034714   0x02034714  arm
 *   func_02049238  0x02049238  arm
 *   d_02180814     0x02180814  data  ov019 a4
 *   func_020470D0 0x020470D0 arm
 *   func_02046EFC 0x02046EFC arm
 *   func_02034714  0x02034714  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02047400  0x02047400  arm
 *   func_0204767C  0x0204767C  arm
 *   func_02047738 0x02047738 arm
 *   func_02047504 0x02047504 arm
 *   func_0216D88C 0x0216D88C thumb ov010
 *   func_02047AC8 0x02047AC8 arm
 *   d_02180758       0x02180758  data   ov019 a4
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   d_02180794     0x02180794  data  ov019  a4
 *   d_0218079C     0x0218079C  data  ov019  a4
 *   func_02080D24 0x02080D24 arm
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   d_021807AC     0x021807AC  data  ov019  a4
 *   d_021807C0     0x021807C0  data  ov019  a4
 */
#include "../../matched/include/Obj07393.h"
#include "../../matched/include/Obj04971.h"
#include "../../matched/include/Obj05959.h"
#include "../../matched/include/Obj04188.h"

struct Tagged;
struct Rec;
struct E;
struct Actor;
struct Arg;
struct VecFx32;
struct Obj00020;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct B60 { u32 w[15]; };

struct E { u32 a, b, c, d; u16 h; };

typedef struct { int x,y,z; } VecFx32;

struct E_0217FCE4 { u32 a,b,c,d; unsigned short h; };

struct E_0217FD04 { u32 a,b,c,d; unsigned short h; };

struct E_0217FD38 { u32 a, b, c, d; u16 h; };

typedef short s16;

extern void MTX_Identity33_(void *m);
extern int func_0216DA30(u32 a);
extern void func_0217FA9C(u32 *p, u32 *b);
extern void func_0217FA54(u32 *p);
extern void *sub_020490F4(u32 id, u32 heap);
extern void *func_02046E24(u32 a0, u32 a1);
extern int func_02046FF8(int *self);
extern void sub_02034714(const char *expr, u32 line, const char *file);
extern void func_02049238(void *h);
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);
extern void func_02034714(const char *a, u32 b, const char *c);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern int func_02047AC8(void *a, struct Arg *b);
extern int func_0203D1B4(void);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern int func_0216D83C(void *);
extern int func_0216D86C(void *);
extern unsigned int func_02080D24(int a);
extern void func_021A3038(unsigned char *p, struct VecFx32 *v);
extern u16 func_02188C9C(u8 *p);
void func_0217FAF0(u32 *p);
struct E *func_0217FB30(struct E *p);
void func_0217FB70(char *p, u32 heap);
void func_0217FBD0(char *p);
void func_0217FC08(char *p, u32 a1, u32 a2);
void func_0217FC64(char *self, u32 *out, u32 a2, u16 a3, int flag);
void func_0217FCA4(u32 *p);
void func_0217FCC0(struct E *e);
void func_0217FCC4(u32 *p, u32 *b);
void func_0217FCE4(struct E_0217FCE4 *p);
void func_0217FD04(struct E_0217FD04 *p);
void func_0217FD38(struct E_0217FD38 *p);
u8 *func_0217FD88(u8 *base);
int func_0217FDC8(u8 *p);
int func_0217FDF8(u8 *p);
int func_0217FE24(u8 *p);
void func_0217FE38(u8 *p);
int func_0217FE44(int a, int mode, unsigned *out);
int func_0217FEB8(u8 *p);
int func_0217FEF4(u8 *p);
int func_0217FF14(void *a);
extern struct B60 d_0218071C;
extern u32 d_02180814[];
extern struct B60 d_02180758;
extern s16 d_02180794[][2];
extern s16 d_0218079C[][2];
extern s16 d_021807AC[][2];
extern s16 d_021807C0[][2];





/*
 * Addresses are Black-image addresses.
 */
void func_0217FAF0(u32 *p)
{
    struct B60 b = d_0218071C;

    MTX_Identity33_(&b.w[6]);
    if (p[3] != 0 && func_0216DA30(p[0]) == 1) {
        func_0217FA9C(p, (u32 *)(&b));
    }
}





struct E *func_0217FB30(struct E *p)
{
    int i, best = 0;

    for (i = 0; i < 1; i++) {
        struct E *e = &p[i];
        if (e->d == 0) {
            return e;
        }
        if (e->h < p[best].h) {
            best = i;
        }
    }
    func_0217FA54((u32 *)(&p[best]));
    return &p[best];
}





/*
 * Sub-object constructor reached from func_0217F8C0 (called at +0x14 with
 * p+0x20).  Grabs a handle from sub_020490F4(0x59) -- the r1 "owner" word is a
 * leftover of the caller, so only r0 is set, the one-argument forwarding shape
 * -- then fills two fields from func_02046E24(h, index) and asserts each with
 * func_02046FF8; a zero result goes to sub_02034714 against d_02180814.
 *
 * Addresses are Black-image addresses.
 */
void func_0217FB70(char *p, u32 heap)
{
    void *h = sub_020490F4((u32)((void *)0x59), heap);

    *(u32 *)&((struct Obj07393 *)p)->fC8 = (u32)func_02046E24((u32)h, 0x16);
    *(u32 *)&((struct Obj07393 *)p)->fCC = (u32)func_02046E24((u32)h, 0x17);
    if (func_02046FF8(*(int * *)&((struct Obj07393 *)p)->fC8) == 0) {
        sub_02034714((const char *)d_02180814, 0, (const char *)d_02180814);
    }
    if (func_02046FF8(*(int * *)&((struct Obj07393 *)p)->fCC) == 0) {
        sub_02034714((const char *)d_02180814, 0, (const char *)d_02180814);
    }
    func_02049238(h);
}




void func_0217FBD0(char *p)
{
    func_020470D0(*(u32 * *)&((struct Obj04971 *)p)->fC8);
    func_020470D0(*(u32 * *)&((struct Obj04971 *)p)->fCC);
    func_02046EFC(*(struct Tagged * *)&((struct Obj04971 *)p)->fC8);
    func_02046EFC(*(struct Tagged * *)&((struct Obj04971 *)p)->fCC);
    *(u32 *)&((struct Obj04971 *)p)->fC8=0;
    *(u32 *)&((struct Obj04971 *)p)->fCC=0;
}





void func_0217FC08(char *p, u32 a1, u32 a2)
{
    if (((struct Obj05959 *)p)->fC8 == 0) {
        func_02034714((const char *)d_02180814, 0, (const char *)d_02180814);
    }
    if (((struct Obj05959 *)p)->fCC == 0) {
        func_02034714((const char *)d_02180814, 0, (const char *)d_02180814);
    }
    func_0217FC64(p, (u32 *)func_0217FD88((u8 *)p), a1, ((struct Obj05959 *)p)->fD0, a2);
    ((struct Obj05959 *)p)->fD0 = ((struct Obj05959 *)p)->fD0 + 1;
}





/*
 * The reload of out[1] before the last call is spelled with a volatile read.
 *
 * Addresses are Black-image addresses.
 */
void func_0217FC64(char *self, u32 *out, u32 a2, u16 a3, int flag)
{
    u32 *q;

    func_02082BCC(out, 0, 0x14);
    out[0] = a2;
    ((struct Obj04188 *)out)->f10 = a3;
    if (flag == 0) {
        q = (u32 *)(self + 0xc8);
    } else {
        q = (u32 *)(self + 0xcc);
    }
    out[1] = (u32)func_02047400((void *)(*q), 0, (void *)(*q));
    out[3] = (u32)func_0204767C(*(volatile u32 *)&out[1], 0, 0);
}




void func_0217FCA4(u32 *p) { func_02047738((struct Rec *)p[3]); func_02047504((struct Rec *)p[1]); func_02082BCC(p,0,0x14); }




void func_0217FCC0(struct E *e)
{
}



void func_0217FCC4(u32 *p, u32 *b) { func_0216D88C((const struct Actor *)p[0], (struct VecFx32 *)b); b[1] -= 0x6800; func_02047AC8((void *)p[3], (struct Arg *)b); }



void func_0217FCE4(struct E_0217FCE4 *p) { int i; for(i=0;i<10;i++) { struct E_0217FCE4 *e=&p[i]; if(e->d != 0) func_0217FCA4((u32 *)e); } }



void func_0217FD04(struct E_0217FD04 *p)
{
    int i;
    for (i=0;i<10;i++) {
        struct E_0217FD04 *e=&p[i];
        if (e->d != 0) {
            if (func_0216DA30(e->a) == 1) func_0217FCC0((struct E *)e);
            else func_0217FCA4((u32 *)e);
        }
    }
}




void func_0217FD38(struct E_0217FD38 *p)
{
    struct B60 b = d_02180758;
    int i;

    MTX_Identity33_(&b.w[6]);
    for (i = 0; i < 10; i++) {
        struct E_0217FD38 *e = &p[i];
        if (e->d != 0 && func_0216DA30(e->a) == 1) {
            func_0217FCC4((u32 *)e, (u32 *)(&b));
        }
    }
}




u8 *func_0217FD88(u8 *base)
{
    int i;
    int best = 0;
    u8 *e;

    for (i = 0; i < 10; i++) {
        e = base + i * 20;
        if (*(int *)&((struct Obj04188 *)e)->fC == 0)
            return e;
        if (((struct Obj04188 *)e)->f10 < *(u16 *)(base + best * 20 + 16))
            best = i;
    }
    e = base + best * 20;
    func_0217FCA4((u32 *)e);
    return e;
}



int func_0217FDC8(u8 *p)
{
    int n=0; int i;
    for (i=0;i<4;i++) { if (p[0x3e + i*0x2c] == 1) n++; }
    if (n >= func_0203D1B4()) return 1;
    return 0;
}




int func_0217FDF8(u8 *p)
{
    int i;
    int n = 0;

    for (i = 0; i < 4; i++) {
        if (p[0x144 + i] == 1)
            n++;
    }
    if (n >= func_0203D1B4())
        return 1;
    return 0;
}




/*
 * note:     unlabelled leaf (prints as .word in ov019.s); called from
 *           func_0217E440.
 */
int func_0217FE24(u8 *p)
{
    if (p[0x160] == 1)
        return 1;
    return 0;
}




void func_0217FE38(u8 *p)
{
    p[0x160] = 0;
}




int func_0217FE44(int a, int mode, unsigned *out)
{
    unsigned i;
    int x;
    void *y;
    int y2;
    void *h;

    h = func_02188CB4((void *)a);
    *out = 0;
    y = func_021A3074((void *)h);
    x = func_0216D83C(y);
    y2 = func_0216D86C(y);
    if (mode == 2) {
        for (i = 0; i < 2; i++) {
            if (d_02180794[i][0] == x && d_02180794[i][1] == y2) {
                *out = i;
                return 1;
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (d_0218079C[i][0] == x && d_0218079C[i][1] == y2) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}



int func_0217FEB8(u8 *p)
{
    int n=0; int i; int value=p[0x16e];
    for (i=0;i<4;i++) { if(p[0x162+i] == 1) n++; }
    if (n >= func_0203D1B4() || n >= (int)func_02080D24(value)) return 1;
    return 0;
}



int func_0217FEF4(u8 *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (p[i + 0x162] == 1) return 1;
    }
    return 0;
}




int func_0217FF14(void *a)
{
    int v[3];
    s16 (*t)[2];
    int i;
    int n;

    func_021A3038(func_02188CB4(a), (struct VecFx32 *)v);
    v[0] >>= 12;
    v[2] >>= 12;
    if (func_02188C9C(a) == 0x96) {
        t = d_021807AC;
        n = 5;
    } else {
        t = d_021807C0;
        n = 5;
    }
    for (i = 0; i < n; i++) {
        if (v[0] == t[i][0] && v[2] == t[i][1])
            return 1;
    }
    return 0;
}

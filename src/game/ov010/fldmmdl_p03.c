/*
 * file:     fldmmdl_p03.c
 * unit:     yes
 * function: func_0216CD50, func_0216CD64, func_0216CD78, func_0216CD88, func_0216CDB8, func_0216CDC4, func_0216CE60, func_0216CE6C, func_0216CEAC
 * address:  0x0216CD50
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02197C4C  0x02197C4C  thumb
 *   func_0216CD30  0x0216CD30  thumb  ov010
 *   func_02030D28  0x02030D28  arm
 *   func_0219C5FC  0x0219C5FC  thumb
 *   func_0219C624  0x0219C624  thumb
 *   func_0219C630  0x0219C630  thumb
 *   func_02087A3C  0x02087A3C  arm
 *   func_0216D95C  0x0216D95C  thumb  ov010
 *   func_0216DEEC  0x0216DEEC  thumb  ov010
 *   func_0216D1C8  0x0216D1C8  thumb  ov010
 *   func_0216D040  0x0216D040  thumb  ov010
 *   func_0216D208  0x0216D208  thumb  ov010
 *   func_0216E51C  0x0216E51C  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_0216D4D4  0x0216D4D4  thumb  ov010
 *   func_0216D244  0x0216D244  thumb  ov010
 *   func_0216D268  0x0216D268  thumb  ov010
 *   func_0216E114  0x0216E114  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D4FC  0x0216D4FC  thumb  ov010
 *   func_0216D0E8  0x0216D0E8  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_0216E418 0x0216E418 thumb ov010
 *   func_0216E42C 0x0216E42C thumb ov010
 */
#include "../../matched/include/Obj17770.h"
#include "../../matched/include/Obj01464.h"
#include "../../matched/include/Obj17771.h"
#include "../../matched/include/Obj19116.h"
#include "../../matched/include/Obj19117.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 w[9];
} Rec;

typedef struct {
    u16 a, p0;
    u16 b, p1;
    u16 c, p2;
} In3;

typedef struct { u16 f, g; } W2;

typedef struct {
    u16 a, b, c;
    u16 pad0[3];
    u16 d;
    u16 pad1[5];
    u32 e;
    W2 w;
    u32 pad2;
} Big;

extern int func_02197C4C();
extern int func_0216CD30();
extern int func_02030D28();
extern int func_0219C5FC();
extern int func_0219C624();
extern int func_0219C630();
extern int func_02087A3C();
extern void func_0216D95C(unsigned int *p, unsigned int v, int a2);
extern int func_0216DEEC(int a0);
extern void func_0216D1C8(u8 *o, u32 a, u32 b);
extern void func_0216D040(u8 *o, u16 *r, u32 b, u32 c);
extern void func_0216D208(void *p);
extern int func_0216E51C(void *a);
extern unsigned int *func_0216D548(unsigned int *, unsigned int);
extern int func_0216D4D4(int a0, int a1);
extern void func_0216D244(u32 a, u8 *o);
extern int func_0216D268(int a0, int a1);
extern int func_0216E114(int a0);
extern void *func_0216D67C(void *a0);
extern int func_0216D4FC(int a0);
extern void func_0216D0E8(u8 *o, Rec *r, u32 z);
extern int func_02082BCC(void *, int, int);
extern int func_0216E418(void *a);
extern unsigned int func_0216E42C(void *bitmap, int id);
int func_0216CD50(int a0);
int func_0216CD64(int a0);
int func_0216CD78(int a0);
int func_0216CD88(int a0);
void func_0216CDB8(u8 *p, u32 v, int a2);
u8 *func_0216CDC4(u32 a, Rec *p, u32 b, u32 c);
void *func_0216CE60(int a, int b, int c);
void *func_0216CE6C(void *o, u32 f, u32 g, u32 d, In3 in, u32 x);
void func_0216CEAC(u32 a,u8 *p,u32 b,u32 n,u32 c);




int func_0216CD50(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_02197C4C(a0);
loc_0216CD58:
a0 = 0;
((struct Obj17770 *)t4)->f40 = a0;
a0 = t4 + 0;
    a0 = func_0216CD30(a0);
loc_0216CD62:
    return a0;}




int func_0216CD64(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj01464 *)t4)->f20;
    a0 = func_02030D28(a0);
loc_0216CD6E:
a0 = t4 + 0;
    a0 = func_0219C5FC(a0);
loc_0216CD74:
    return a0;}




/*
 * blocked:  listing 16 compiled 14
 */
int func_0216CD78(int a0)
{
    int a1;

a1 = ((struct Obj17771 *)a0)->f24;
    if (a1 == 0) goto loc_0216CD84;
loc_0216CD80:
    a0 = func_0219C624(a0);
loc_0216CD84:
    return a0;}




/*
 * blocked:  listing 48 compiled 46
 */
int func_0216CD88(int a0)
{
    int a1;
    int t4;
    int t5;

t5 = a0 + 0;
    a0 = func_0219C630(a0);
loc_0216CD90:
    if (a0 != 1) goto loc_0216CDB4;
loc_0216CD94:
t4 = 1;
loc_0216CD96:
a0 = t5 + 0;
    a0 = func_0216CD64(a0);
loc_0216CD9C:
a0 = t4 + 0;
a1 = t4 + 0;
    a0 = func_02087A3C(a0, a1);
loc_0216CDA4:
a0 = t5 + 0;
    a0 = func_0216CD78(a0);
loc_0216CDAA:
a0 = t5 + 0;
    a0 = func_0219C630(a0);
loc_0216CDB0:
    if (a0 == 1) goto loc_0216CD96;
loc_0216CDB4:
    return a0;}




/*
 * Unlabelled thumb leaf (store, then tail call through a pool word), the
 * sole blocker of ov021 func_02189204 (lane S26).
 * Addresses are Black-image addresses.
 */
void func_0216CDB8(u8 *p, u32 v, int a2)
{
    ((struct Obj19116 *)p)->f40 = v;
    func_0216D95C((unsigned int *)p, 1, a2);
}




u8 *func_0216CDC4(u32 a, Rec *p, u32 b, u32 c)
{
    Rec r = *p;
    u8 *o;

    o = (u8 *)func_0216DEEC(a);
    func_0216D1C8(o, a, b);
    func_0216D040(o, (u16 *)(&r), c, a);
    func_0216D208(o);
    if (func_0216E51C(o) == 1)
        func_0216D548((u32 *)o, 640);
    if (func_0216D4D4(a, 0x10)) {
        func_0216D244(a, o);
        func_0216D268(a, (int)o);
    }
    if (func_0216D4D4(a, 1))
        func_0216E114((int)o);
    func_0216D4FC((int)func_0216D67C(o));
    func_0216D0E8(o, &r, 0);
    return o;
}



void *func_0216CE60(int a, int b, int c){
    func_0216CDC4(a, (Rec *)b, c, 0);
}




void *func_0216CE6C(void *o, u32 f, u32 g, u32 d, In3 in, u32 x)
{
    Big s;
    In3 *ip = &in;
    Big *v = &s;
    W2 *w;

    func_02082BCC(&s, 0, 0x24);
    v->a = ip->a;
    v->b = ip->b;
    v->c = ip->c;
    v->d = d;
    s.e = 0;
    w = &s.w;
    w->f = f;
    w->g = g;
    return func_0216CE60((int)o, (int)(&s), x);
}



/*
 * extent: zero alignment halfword at 0x0216CEE2, then labelled 0x0216CEE4.
 * interface: E42C forwards r0/r1 unchanged; caller reads r0, so extern returns int.
 */
void func_0216CEAC(u32 a,u8 *p,u32 b,u32 n,u32 c) {
    do {
        if(func_0216E418(p)==1 || func_0216E42C((void *)c,((struct Obj19117 *)p)->f8)==0)
            func_0216CDC4((int)a, (Rec *)p, b, c);
        p+=0x24;
    } while(--n);
}

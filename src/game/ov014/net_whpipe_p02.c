/*
 * file:     net_whpipe_p02.c
 * unit:     yes
 * function: func_0217727C, func_02177280, func_02177310, func_0217731C, func_021773E0, func_02177494, func_02177560, func_0217758C, func_021775AC, func_021775BC, func_02177614, func_02177660, func_021776C4, func_02177704, func_0217771C, func_02177744, func_0217778C
 * address:  0x0217727C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021797A4     0x021797A4  data   a4
 *   d_02179780     0x02179780  data   a1
 *   func_02030734  0x02030734  arm
 *   func_0203D798  0x0203D798  arm
 *   func_0208F1B4  0x0208F1B4  arm
 *   func_021790E4  0x021790E4  thumb  ov014
 *   func_02178E1C  0x02178E1C  thumb  ov014
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0217933C  0x0217933C  thumb  ov014
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   func_021785B4  0x021785B4  thumb  ov014
 *   func_02179498  0x02179498  thumb  ov014
 *   func_0217945C  0x0217945C  thumb  ov014
 *   func_020307B0 0x020307B0 arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_02088234  0x02088234  arm
 *   func_02177D58  0x02177D58  thumb  ov014
 */
#include "../../matched/include/Obj05921.h"
#include "../../matched/include/Obj19326.h"
#include "../../matched/include/Obj03087.h"
#include "../../matched/include/Obj05922.h"
#include "../../matched/include/Obj19327.h"
#include "../../matched/include/Obj04174.h"
#include "../../matched/include/Obj07353.h"
#include "../../matched/include/Obj19328.h"
#include "../../matched/include/Obj07354.h"
#include "../../matched/include/Obj09380.h"
#include "../../matched/include/Obj09381.h"

typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Ent {
    u8 b0[4];
    u8 mac[6];
    u8 rest[0xC0 - 10];
} Ent;

typedef struct W {
    u8 pad0[8];
    Ent ent[16];
    u8 pad1[0x38];
    u16 age[16];
    u8 pad2[0xAF - 0x20];
    u8 flag;
} W;

typedef int (*CheckFn)(u8 a, u8 b, u32 c);

typedef void (*NotifyFn)(u32 a, u8 *obj, u32 b, u32 c);

typedef signed int     s32;

typedef int (*SizeFn)(u32 a);

typedef u32 (*DataFn)(u32 a);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_0203D798(void);
extern u16 func_0208F1B4(void);
extern int func_021790E4(u32 heap, int a, int b);
extern void func_02178E1C(u32 v);
u16 func_0203F1FC(const u8 *src, u32 len);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_02082D44(void *src, void *dst, int n);
extern void func_02082BCC(void *, u32, u32);
extern void func_0217933C(void *cb);
extern int func_02178E4C(void);
extern int func_021785B4(u32 a, u16 *b, u32 c);
extern int func_02179498(void);
extern void func_0217945C(void);
extern u32 func_020307B0(void *p);
extern int func_0203CD98(void);
extern void func_02088234(void);
extern void func_02177D58(u8 *buf, u32 len);
void func_0217727C(u32 *p, u32 v);
int func_02177280(int a, int b, u32 c, int d);
void func_02177310(u32 v);
int func_0217731C(u8 *obj);
int func_021773E0(u8 *p);
int func_02177494(u8 *obj, u32 flags);
void func_02177560(void);
void func_0217758C(u8 *p);
int func_021775AC(int a, int b, int c);
int func_021775BC(int arg);
void func_02177614(u8 *p);
void func_02177660(u8 *p);
int func_021776C4(void);
void func_02177704(void);
int func_0217771C(u8 *obj);
void func_02177744(void);
void func_0217778C(void);
extern struct W *g_021797A4;
extern char d_02179780[];





void func_0217727C(u32 *p, u32 v)
{
    *p = v;
}





int func_02177280(int a, int b, u32 c, int d)
{
    u8 *st;
    u8 *w;

    func_0203D798();
    st = func_0203D798();
    if (((u8 *)g_021797A4) != 0)
        return 0;
    w = func_02030734(a, 0xCF8, 1, d_02179780, 0xed);
    g_021797A4 = (struct W *)(w);
    w[0xCE6] = 0xff;
    if (func_021790E4(a, b, d) == 0)
        return 0;
    func_02178E1C(((struct Obj19326 *)st)->f50);
    ((struct Obj05921 *)w)->fC64 = c;
    w[0xCE7] = 0;
    w[0xCE4] = 0;
    ((struct Obj05921 *)w)->fC68 = func_0208F1B4();
    return 1;
}





void func_02177310(u32 v)
{
    *(u32 *)(*(u32 *)0x021797A4 + 4) = v;
}





int func_0217731C(u8 *obj)
{
    u8 *base = ((u8 *)g_021797A4);
    u8 *st = func_0203D798();
    u8 *p;
    int v67;
    u16 v50;
    CheckFn fn;
    NotifyFn nf;

    v67 = st[0x67];
    v50 = ((struct Obj05922 *)st)->f50;
    p = obj + 0x50;
    if (p[7] != 0)
        return 0;
    if (p[5] != 0)
        return 0;
    if (((struct Obj03087 *)p)->f0 != func_0203F1FC(p + 2, 0x6e))
        return 0;
    if (((struct Obj03087 *)p)->f2 != v50)
        return 0;
    nf = *(NotifyFn *)(((u8 *)g_021797A4) + 0xC38);
    if (nf != 0)
        nf(*(u32 *)(((u8 *)g_021797A4) + 0xC3C), obj, p[4], p[6]);
    fn = *(CheckFn *)&((struct Obj05922 *)st)->f20;
    if (fn != 0) {
        if (fn(v67, p[4], ((struct Obj19327 *)base)->fC64) == 0)
            return 0;
    } else if (v67 != p[4]) {
        return 0;
    }
    if (v67 != 0x14 && p[6] >= st[0x60] && st[0x60] > 1)
        return 0;
    return 1;
}



int func_021773E0(u8 *p)
{
    int i;
    W *base = g_021797A4;

    func_0203D798();
    if (func_0217731C(p) == 0)
        return 0;
    for (i = 0; i < 16; i++) {
        if (base->age[i] != 0 && func_0203EFC8(base->ent[i].mac, p + 4, 6) == 0) {
            base->age[i] = 600;
            func_02082D44(p, &base->ent[i], 0xC0);
            return 1;
        }
    }
    for (i = 0; i < 16; i++) {
        if (base->age[i] == 0)
            break;
    }
    if (i >= 16)
        return 0;
    base->age[i] = 600;
    func_02082D44(p, &base->ent[i], 0xC0);
    base->flag = 1;
    return 1;
}








int func_02177494(u8 *obj, u32 flags)
{
    u8 *base = ((u8 *)g_021797A4);
    u8 *st = func_0203D798();
    int v67 = st[0x67];
    u16 v50 = ((struct Obj07353 *)st)->f50;
    u8 *p = obj + 0x50;
    CheckFn fn;

    if ((flags & 1) && p[7] != 0)
        return 0;
    if ((flags & 2) && p[5] != 0)
        return 0;
    if ((flags & 4) && ((struct Obj04174 *)p)->f0 != func_0203F1FC(p + 2, 0x6e))
        return 0;
    if ((flags & 8) && ((struct Obj04174 *)p)->f2 != v50)
        return 0;
    if (flags & 0x10) {
        fn = *(CheckFn *)&((struct Obj07353 *)st)->f20;
        if (fn != 0) {
            if (fn(v67, p[4], ((struct Obj19328 *)base)->fC64) == 0)
                return 0;
        } else if (v67 != p[4]) {
            return 0;
        }
    }
    if ((flags & 0x20) && p[6] >= st[0x60])
        return 0;
    return 1;
}







void func_02177560(void)
{
    u8 *p = ((u8 *)g_021797A4);
    int i;
    for (i = 0; i < 16; i++) *(u16 *)(p + i*2 + 0xC40) = 0;
    func_02082BCC(p + 8, 0, 0xC00);
}







void func_0217758C(u8 *p)
{
    p[0xCEA] = 0;
    p[0xCEF] = 0;
    p[0xCEB] = 0;
    p[0xCEC] = 0;
    p[0xCE9] = 0;
    p[0xCE8] = 0;
}







/*
 * interface: original preserves incoming r0-r2 and spends r3 on the
 * indirect callback target; legacy void(void) callers omit those inputs.
 * void(void) callback spelling changes the target register to r0 (run 2).
 */
int func_021775AC(int a, int b, int c)
{
    return (*(int (**)(int, int, int))(((u8 *)g_021797A4) + 4))(a,b,c);
}








int func_021775BC(int arg)
{
    u8 *w = ((u8 *)g_021797A4);

    if (w == 0)
        return 0;
    func_0217758C(w);
    if (arg != 0)
        func_02177560();
    func_0217933C(func_021775AC);
    w[0xCE8] = 1;
    if (func_02178E4C() == 1 && func_021785B4((u32)func_021773E0, 0, 0) != 0)
        return 1;
    return 0;
}








void func_02177614(u8 *p)
{
    if (func_02178E4C() == 1 && func_02179498() != 0) {
        p[0xCF5] = 0xFF;
        func_0217727C((u32 *)((u8 *)g_021797A4), (u32)func_02177660);
    }
    if (func_02178E4C() == 9) {
        p[0xCF5] = 0xFF;
        func_0217727C((u32 *)((u8 *)g_021797A4), (u32)func_02177660);
    }
}







void func_02177660(u8 *p)
{
    p[0xCF5]--;
    if (func_02178E4C() == 0 || func_02178E4C() == 1) {
        func_0217727C((u32 *)((u8 *)g_021797A4), 0);
        return;
    }
    if (func_02178E4C() == 9) {
        func_0217945C();
        func_0217727C((u32 *)((u8 *)g_021797A4), (u32)func_02177614);
        return;
    }
    if (p[0xCF5] == 0) {
        func_0217945C();
        func_0217727C((u32 *)((u8 *)g_021797A4), (u32)func_02177614);
    }
}







int func_021776C4(void)
{
    u8 *w = ((u8 *)g_021797A4);

    if (w == 0)
        return 1;
    if (w[0xCE7] == 0 && func_02179498() != 0) {
        w[0xCF5] = 0xFF;
        func_0217727C((u32 *)((u8 *)g_021797A4), (u32)func_02177660);
        return 1;
    }
    return 0;
}




void func_02177704(void)
{
    if (g_021797A4 != 0) {
        func_020307B0(g_021797A4);
        g_021797A4 = 0;
    }
}



int func_0217771C(u8 *obj) { u8 *base = (u8 *)g_021797A4; void (*fn)(void); if (func_0217731C(obj) == 0) return 0; fn = *(void (**)(void))(base + 0xC60); if (fn != 0) fn(); return 1; }




void func_02177744(void)
{
    u8 *w = ((u8 *)g_021797A4);
    int i;

    for (i = 0; i < 16; i++) {
        u16 v = *(volatile u16 *)(w + i * 2 + 0xC40);
        if (v != 0 && v != 0) {
            *(volatile u16 *)(w + i * 2 + 0xC40) = *(volatile u16 *)(w + i * 2 + 0xC40) - 1;
            if (*(volatile u16 *)(w + i * 2 + 0xC40) == 0)
                w[0xCEF] = 1;
        }
    }
}




void func_0217778C(void)
{
    u8 *e;
    u8 *st;
    u8 *w;
    SizeFn sfn;
    int n;

    if (func_0203CD98() == 0)
        return;
    w = ((u8 *)g_021797A4);
    st = func_0203D798();
    sfn = *(SizeFn *)&((struct Obj09380 *)st)->f1C;
    if (sfn == 0)
        return;
    n = sfn(((struct Obj09381 *)w)->fC64);
    if (n >= 0x68) {
        func_02088234();
        return;
    }
    e = w + 0xC6E;
    e[4] = st[0x67];
    ((struct Obj07354 *)e)->f2 = ((struct Obj09380 *)st)->f50;
    e[5] = 0;
    e[7] = w[0xCEA];
    func_02082D44((void *)(*(DataFn *)(st + 0x18))(((struct Obj09381 *)w)->fC64), e + 8, n);
    func_02177D58(w + 0xC6E, 0x70);
}

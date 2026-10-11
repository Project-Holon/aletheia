/*
 * file:     net_whpipe.c
 * unit:     yes
 * function: func_0217721C, func_0217723C, func_0217725C, func_02177264, func_0217726C, func_02177274, func_0217727C, func_02177280, func_02177310, func_0217731C, func_021773E0, func_02177494, func_02177560, func_0217758C, func_021775AC, func_021775BC, func_02177614, func_02177660, func_021776C4, func_02177704, func_0217771C, func_02177744, func_0217778C, func_021777FC, func_02177888, func_0217796C, func_021779F4, func_02177A34, func_02177A74, func_02177A94, func_02177AA8, func_02177ACC, func_02177AEC, func_02177B0C, func_02177B2C, func_02177B58, func_02177B80, func_02177BAC, func_02177BCC, func_02177BF4, func_02177BFC
 * address:  0x0217721C
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
 *   func_0203D5D4 0x0203D5D4 arm
 *   func_02010848 0x02010848 thumb
 *   func_0208EE9C 0x0208EE9C arm
 *   func_02178E68  0x02178E68  thumb  ov014
 *   func_02177EDC  0x02177EDC  thumb  ov014
 *   func_02178034  0x02178034  thumb  ov014
 *   func_021780E4  0x021780E4  thumb  ov014
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
 *   d_02179790     0x02179790  data   a4
 *   func_02034714  0x02034714  arm
 *   func_021795A4  0x021795A4  thumb  ov014
 *   func_02179570  0x02179570  thumb  ov014
 *   func_0203D720  0x0203D720  arm
 *   func_0203D754  0x0203D754  arm
 *   func_02177C1C  0x02177C1C  thumb
 *   func_02179664  0x02179664  thumb
 *   func_021793F8  0x021793F8  thumb
 *   func_02178E38  0x02178E38  thumb  ov014
 *   ctrdgi_task_work 0x021797a4 data
 *   d_021797A4  0x021797A4  data  ov014  a4
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
#include "../../matched/include/Obj04955.h"
#include "../../matched/include/Obj19331.h"
#include "../../matched/include/Obj02358.h"

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

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

typedef struct Head Head;

struct Head {
    void (*fn)(Head *);
};

typedef struct {
    u8 pad0[4];
    u8 kind;
    u8 pad5[3];
    u8 rec[4];
} Sub;

typedef struct {
    u8 pad0[0x50];
    Sub sub;
} S;

extern u32 func_0203D5D4(void);
extern u16 func_02010848(void);
extern int func_0208EE9C(void);
int func_02178E68(void);
extern void func_02177EDC(int a);
extern int func_02178034(void);
extern void func_021780E4(int a);
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
extern void func_02034714(const char *expr, u32 line, const char *file);
unsigned short func_021795A4(void);
int func_02179570(void (*cb)(int));
void func_0203D720(u32 a);
void func_0203D754(u32 a);
int func_02177C1C(void);
void func_02179664(unsigned char v);
void func_021793F8(void);
extern u16 func_02178E38(void);
int func_0217721C(void);
int func_0217723C(void);
void func_0217725C(unsigned char v);
void func_02177264(int a);
int func_0217726C(void);
void func_02177274(int a);
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
void func_021777FC(void);
void func_02177888(u32 arg);
void func_0217796C(u32 arg);
int func_021779F4(void);
int func_02177A34(u16 n);
int func_02177A74(void);
int CTRDGi_IsTaskAvailable(void);
int func_02177AA8(void);
unsigned int func_02177ACC(void);
int func_02177AEC(void);
void func_02177B0C(u8 v);
u8 *func_02177B2C(int i);
u8 *func_02177B58(int i);
u8 func_02177B80(int i);
void func_02177BAC(u32 idx);
void func_02177BCC(void);
void func_02177BF4(unsigned int idx);
u8 *func_02177BFC(S *a0, u8 *out);
extern u8 *g_021797A4;
extern char d_02179780[];
extern u8 d_02179790[];
extern void *ctrdgi_task_work;
extern u8 *d_021797A4;


/*
 * extent: two zero alignment bytes at 0217723A; existing code starts 0217723C.
 */
int func_0217721C(void)
{
    if (func_0203D5D4() == 3) return 3 - func_02010848();
    return 3 - func_0208EE9C();
}



/*
 * Normalises a queried mode: 5 maps to 0, and a zero mode with the predicate
 * set maps to 0x14.
 */
int func_0217723C(void)
{
    int r4 = func_02178E68();

    if (r4 == 5)
        r4 = 0;
    if (func_02177AEC() != 0 && r4 == 0)
        r4 = 0x14;
    return r4;
}


void func_0217725C(unsigned char v)
{
    func_02177B0C(v);
}


void func_02177264(int a)
{
    func_02177EDC(a);
}


int func_0217726C(void)
{
    return func_02178034();
}


void func_02177274(int a)
{
    func_021780E4(a);
}








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
    if (g_021797A4 != 0)
        return 0;
    w = func_02030734(a, 0xCF8, 1, d_02179780, 0xed);
    g_021797A4 = w;
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
    u8 *base = g_021797A4;
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
    nf = *(NotifyFn *)(g_021797A4 + 0xC38);
    if (nf != 0)
        nf(*(u32 *)(g_021797A4 + 0xC3C), obj, p[4], p[6]);
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
    W *base = (W *)g_021797A4;

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
    u8 *base = g_021797A4;
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
    u8 *p = g_021797A4;
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
    return (*(int (**)(int, int, int))(g_021797A4 + 4))(a,b,c);
}











int func_021775BC(int arg)
{
    u8 *w = g_021797A4;

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
        func_0217727C((u32 *)g_021797A4, (u32)func_02177660);
    }
    if (func_02178E4C() == 9) {
        p[0xCF5] = 0xFF;
        func_0217727C((u32 *)g_021797A4, (u32)func_02177660);
    }
}










void func_02177660(u8 *p)
{
    p[0xCF5]--;
    if (func_02178E4C() == 0 || func_02178E4C() == 1) {
        func_0217727C((u32 *)g_021797A4, 0);
        return;
    }
    if (func_02178E4C() == 9) {
        func_0217945C();
        func_0217727C((u32 *)g_021797A4, (u32)func_02177614);
        return;
    }
    if (p[0xCF5] == 0) {
        func_0217945C();
        func_0217727C((u32 *)g_021797A4, (u32)func_02177614);
    }
}










int func_021776C4(void)
{
    u8 *w = g_021797A4;

    if (w == 0)
        return 1;
    if (w[0xCE7] == 0 && func_02179498() != 0) {
        w[0xCF5] = 0xFF;
        func_0217727C((u32 *)g_021797A4, (u32)func_02177660);
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
    u8 *w = g_021797A4;
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
    w = g_021797A4;
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




void func_021777FC(void)
{
    u8 *w = g_021797A4;
    u8 *e = w + 0xC6E;
    u8 *st = func_0203D798();
    SizeFn sfn = *(SizeFn *)&((struct Obj19331 *)st)->f1C;
    int n;

    if (sfn != 0) {
        n = sfn(((struct Obj04955 *)w)->fC64);
        if (n > 0x68)
            func_02034714((const char *)d_02179790, 0, (const char *)d_02179790);
        func_02082D44((void *)(*(DataFn *)(st + 0x18))(((struct Obj04955 *)w)->fC64), e + 8, n);
    }
    if (e[6] != func_02177A74()) {
        w[0xCF0] = 0;
        e[6] = func_02177A74();
    }
    if (w[0xCF0] == 0) {
        func_02177D58(w + 0xC6E, 0x70);
        w[0xCF0] = 2;
    }
    w[0xCF0]--;
}








void func_02177888(u32 arg)
{
    int mode = func_02178E4C();
    u8 *base = g_021797A4;

    if (func_02177AEC() == 0)
        func_021777FC();
    if (((struct Obj02358 *)base)->fC6A == 0xFFFF)
        ((struct Obj02358 *)base)->fC6A = arg;
    if (base[0xCEC] != 0) {
        if (func_021795A4() == 0 && func_02177ACC() == 0)
            base[0xCEB] = 1;
        if (((struct Obj02358 *)base)->fC6A > arg)
            base[0xCEB] = 1;
    }
    if (func_02178E68() == 0x19)
        func_0203D720(0);
    switch (mode) {
    case 0:
        if (base[0xCE7] == 1)
            func_02177704();
        break;
    case 1:
        if (base[0xCE7] == 1 && func_02179570(0) != 0)
            return;
        if (base[0xCE7] == 2 && func_02179570(0) != 0)
            return;
        break;
    case 8:
    case 9:
        if (base != 0) {
            if (base[0xCEB] == 0)
                func_0203D754(func_02178E68());
            base[0xCEB] = 1;
        }
        break;
    }
}








void func_0217796C(u32 arg)
{
    Head *p = (Head *)*(u32 *)0x021797A4;
    if (p != 0 && p->fn != 0)
        p->fn(p);
    if (*(u32 *)0x021797A4 != 0)
        func_02177888(arg);
    if (*(u32 *)0x021797A4 != 0) {
        if (func_02177C1C() != 0)
            func_02177744();
    }
    if (*(u32 *)0x021797A4 != 0) {
        if (*(u16 *)((u8 *)*(u32 *)0x021797A4 + 0xC6C) != 0) {
            func_02179664(1);
            ((u8 *)*(u32 *)0x021797A4)[0xCF3] = 1;
            if (((u8 *)*(u32 *)0x021797A4)[0xCF4] == 0)
                *(u16 *)((u8 *)*(u32 *)0x021797A4 + 0xC6C) -= 1;
        } else {
            func_02179664(0);
            ((u8 *)*(u32 *)0x021797A4)[0xCF3] = 0;
        }
    }
    func_021793F8();
}








int func_021779F4(void)
{
    if (g_021797A4 == 0)
        return 0;
    if (func_021795A4() == 0 && func_02177ACC() == 0)
        return 0;
    if (func_02178E4C() == 4 || func_02178E4C() == 5)
        return 1;
    return 0;
}








int func_02177A34(u16 n)
{
    if (g_021797A4 == 0)
        return 0;
    if (func_02178E4C() != 4 && func_02178E4C() != 5)
        return 0;
    if (func_02178E38() & (1 << n))
        return 1;
    return 0;
}







/*
 * evidence: original truncates the index to u16 before calling A34; extern follows caller width.
 * extent: trailing two zero bytes are alignment padding.
 */
int func_02177A74(void) { int count = 0; int i = 0; for (; i < 8; i++) { if (func_02177A34(i) != 0) count++; } return count; }








int CTRDGi_IsTaskAvailable(void)
{
    return ctrdgi_task_work != 0;
}







int func_02177AA8(void) { if (g_021797A4 != 0) { if (func_02178E4C() == 1) return 1; return 0; } return 1; }






unsigned int func_02177ACC(void) { if (g_021797A4 != 0) return func_02178E38() & 0xFFFE; return 0; }







int func_02177AEC(void)
{
    u8 *w = g_021797A4;

    if (w != 0 && w[0xCEB] != 0)
        return 1;
    return 0;
}




void func_02177B0C(u8 v)
{
    u8 *w = g_021797A4;
    if (w != 0) {
        w[0xCEC] = v;
        *(u16 *)(w + 0xC6A) = 0xFFFF;
    }
}





/*
 * lever: integer address sum preserves base+0x58 and the final pointer+8;
 * plain pointer additions fold these into base+0x60 (r1 DIFF, r2 EXACT).
 */
u8 *func_02177B2C(int i) { u8 *base = g_021797A4; if (base != 0 && *(u16 *)(base + 0xC40 + i * 2) != 0) return (u8 *)((unsigned int)(base + 0x58) + i * 0xC0) + 8; return 0; }





u8 *func_02177B58(int i) { u8 *base = g_021797A4; if (base != 0 && *(u16 *)(base + 0xC40 + i * 2) != 0) return base + 0xC + i * 0xC0; return 0; }







/*
 * Recursive MATCH unblocker: the unlabelled ov014 leaf that the arm9
 * wih_dwc.c pollers call (sub_020107FC +001E, func_0201058C +005C).  Reads
 * the per-slot u16 flag array at g_021797A4+0xC40 (stride 2) and returns the
 * slot's u8 state at +0x5C of the 0xC0-byte record, or 0 when the global or
 * the flag is clear.  func_02178098 is byte-identical.
 */
u8 func_02177B80(int i)
{
    u8 *base = g_021797A4;

    if (base != 0 && *(u16 *)(base + 0xC40 + i * 2) != 0)
        return *(u8 *)(base + 0x5C + i * 0xC0);
    return 0;
}






/*
 * Unlabelled leaf: clears halfword idx of the table at +0xC40 of the
 * object pointed to by the global at 0x021797A4. Blocks func_02177BF4.
 *
 * Addresses are Black-image addresses.
 */
void func_02177BAC(u32 idx)
{
    u8 *p = d_021797A4;
    u16 *h;
    if (p != 0) {
        h = (u16 *)(p + 0xc40);
        if (h[idx] != 0) {
            h[idx] = 0;
        }
    }
}





/*
 * Unlabelled overlay leaf blocking ov010 func_02157760.
 */
void func_02177BCC(void)
{
    u8 *p;
    int i;
    p = d_021797A4;
    if (p != 0) {
        for (i = 0; i < 16; i++)
            *(u16 *)(p + 0xC40 + i * 2) = 0;
    }
}






/*
 * Unlabelled tail-call thunk (ldr r3,[pc]; bx r3) to func_02177BAC.
 * Sole blocker of the func_02164E04 / func_02164D6C MATCHes (ov010).
 *
 * Addresses are Black-image addresses.
 */
void func_02177BF4(unsigned int idx)
{
    func_02177BAC(idx);
}






/*
 * Unlabelled Thumb leaf (prints as .word data in ov014.s), the sole blocker
 * of ov011 func_02173368 +004A: writes the byte at +0x54 through its second
 * argument and returns the address of +0x58.
 *
 * Addresses are Black-image addresses.
 */
u8 *func_02177BFC(S *a0, u8 *out)
{
    Sub *s = &a0->sub;

    *out = s->kind;
    return s->rec;
}

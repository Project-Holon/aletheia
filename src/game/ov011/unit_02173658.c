/*
 * file:     unit_02173658.c
 * unit:     yes
 * function: func_02173658, func_021736A4, func_021736B0, func_021736C0, func_021736D0, func_021736D8, func_021736E0, func_021736EC, func_02173728, func_02173758, func_0217379C, func_021737A8, func_021737CC, func_02173828, func_021738BC, func_021738E4, func_0217392C, func_02173984, func_021739C8, func_021739E0, func_02173A04, func_02173A2C, func_02173AB4, func_02173AE0, func_02173B20, func_02173B44, func_02173B8C, func_02173B9C, func_02173BE4, func_02173C04, func_02173C50, func_02173C6C
 * address:  0x02173658
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02175628  0x02175628  thumb
 *   func_02039338 0x02039338 arm
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02026478 0x02026478 thumb
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02012B4C 0x02012B4C thumb
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_02174EAC  0x02174EAC  thumb  ov011
 *   func_02012B58  0x02012B58  thumb
 *   func_0203D378  0x0203D378  arm
 *   func_0203D578  0x0203D578  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02175920  0x02175920  thumb ov011
 *   func_0217592C  0x0217592C  thumb ov011
 *   func_02167658 0x02167658 thumb ov010
 *   func_020264B4  0x020264B4  thumb
 *   func_02174F54  0x02174F54  thumb ov011
 *   func_021753D0 0x021753D0 thumb ov011
 *   func_02082BCC  0x02082BCC  arm
 *   func_021754E8 0x021754E8 thumb ov011
 *   func_02175508  0x02175508  thumb ov011
 */
#include "../../matched/include/Obj12413.h"
#include "../../matched/include/Obj09343.h"
#include "../../matched/include/Obj00269.h"

struct Entry;
struct Link;
struct BigObj;
struct Ent;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef signed int s32;

typedef struct { u8 d[0x34]; } E_021736B0;

typedef struct { u8 d[0x4c]; } E_021736C0;

typedef struct {
    int f0;
    int f4;
    u8 pad08[0x8fa];
    u8 n;
    u8 pad03[0x3c];
    u8 flag : 1;
} D_021737A8;

typedef struct {
    u8 pad[0x4b];
    u8 lo : 6;
    u8 hit : 1;
} C_0;

typedef struct { void *sys; void *obj; } Work;

typedef struct C_0217392C {
    char pad[0x14];
    unsigned short w14;
    unsigned short f : 3;
} C_0217392C;

typedef struct Rec { u32 words[14]; } Rec;

typedef struct T {
    int w[13];
} T;

typedef struct B {
    unsigned char a;
    unsigned char b;
    short pad;
    T t;
} B;

typedef struct { u8 pad[0x15c]; u8 v[4]; } D_02173B9C;

int func_02175628(void);
extern u16 func_02039338(void);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 func_02026478(void *obj);
extern unsigned int func_0203D1A4(struct Link *);
extern void func_02012B4C(struct BigObj *p, u8 v);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void func_02174EAC(u8 *p, int idx, u8 *q);
extern u8 func_02012B58(const struct BigObj *p);
extern u32 func_0203D378(void);
int func_0203D578(int a, int b);
void func_02082D44(void *d, void *s, int n);
void func_02175920(void *p);
void func_0217592C(void *p);
extern void func_02167658(Work *, int);
void func_020264B4(void *p, int idx, u16 val0, u8 val3, u32 val4, int flag);
void func_02174F54(u8 *p, int idx, const struct Ent *src, int arg);
int func_021753D0(u8 *p, int i, u8 v);
void func_02082BCC(void *p, int v, int n);
void func_021754E8(u8 *p, int a, int b, int c);
void func_02175508(int a, int b, int c);
void func_02173658(u8 *o);
u8 *func_021736A4(int a, u8 *p);
E_021736B0 *func_021736B0(int i, u8 *p);
E_021736C0 *func_021736C0(int i, u8 *p);
u8 *func_021736D0(int a, u8 *p);
int func_021736D8(void);
void func_021736E0(int a, int b, int c, char *p, unsigned int d);
int func_021736EC(char *p);
void func_02173728(unsigned int a, int b, u8 *c, u8 *d);
int func_02173758(int a, int b, ...);
void func_0217379C(int a, int b, int c, u8 *p);
int func_021737A8(void);
void func_021737CC(int a, int b, C_0 *c, D_021737A8 *d);
int func_02173828(char *p);
void func_021738BC(int a, int b, int *c, u8 *d, void *e);
int func_021738E4(void *a, int b);
void func_0217392C(int a, int b, const C_0217392C *c, unsigned char *d);
int func_02173984(char *p, int b);
void func_021739C8(int a, int b, int c, u8 *p);
int func_021739E0(void);
void func_02173A04(int a, int b, Rec *c, u8 *d);
int func_02173A2C(unsigned char *p, int b, T *c, int d);
void func_02173AB4(int a, int b, u8 *c, u8 *d);
int func_02173AE0(int a, int b, int c, int d);
void func_02173B20(int a, int b, u8 *c, u8 *d);
int func_02173B44(void *a, int b, int c);
void func_02173B8C(int a, int b, u8 *c, int d);
int func_02173B9C(int a, int b);
void func_02173BE4(int a, int b, const u8 *src, D_02173B9C *dst);
int func_02173C04(int a, int b);
void func_02173C50(int n, int b, int c, u8 *p);
int func_02173C6C(int a, int b);




void func_02173658(u8 *o)
{
    int i;

    if (o[0x925] != 0) {
        o[0x926] = o[0x926] + 1;
        if (o[0x926] > 0x96) {
            for (i = 0; i < o[0x925]; i++)
                *(int *)(o + 0x930 + i * 4) = 0;
            o[0x926] = 0;
            o[0x925] = 0;
        }
    }
}




u8 *func_021736A4(int a, u8 *p) { return p + 0x648; }



E_021736B0 *func_021736B0(int i, u8 *p) { return (E_021736B0 *)(p + 0x754) + i; }



E_021736C0 *func_021736C0(int i, u8 *p) { return (E_021736C0 *)(p + 0x670) + i; }




u8 *func_021736D0(int a, u8 *p) { return p + 0x7f0; }





int func_021736D8(void)
{
    return func_02175628();
}




void func_021736E0(int a, int b, int c, char *p, unsigned int d)
{
    p[0x8fa] = 1;
}




/*
 * The fifth argument to 021736E0 is visibly written to the outgoing stack slot.
 */
int func_021736EC(char *p)
{
    unsigned int n;
    if (func_021736D8() == 0) {
        n = func_02039338();
        func_021736E0(n, 0, 0, p, (unsigned int)func_020399A8());
        return 1;
    }
    return func_0203D3A8((struct Entry *)((unsigned int)func_020399A8()), 0x200, 0, 0);
}




/*
 * The loaded byte stays live as r1 into 02012B4C.
 */
void func_02173728(unsigned int a, int b, u8 *c, u8 *d)
{
    void *h;
    unsigned int n;
    h = (void *)func_02026478(((struct Obj12413 *)d)->f4);
    if (a != func_0203D1A4((struct Link *)func_020399A8())) {
        n = *c;
        d[0x902] = n;
        func_02012B4C(h, n);
    }
}




/*
 * Handed as 0x0217375A; the function starts at the push {r0-r3} at 0x02173758.
 */
int func_02173758(int a, int b, ...)
{
    if (func_021736D8() == 0)
        return 0;
    return func_0203D3F8((int)func_020399A8(), 0xff, 0x201, 1, (u32)(&b), 1, 0, 0);
}


void func_0217379C(int a, int b, int c, u8 *p) { p[0x8fe] = 1; }





/*
 * Return-valued externs reflect r0 consumed after both forwarding calls.
 */
int func_021737A8(void)
{
    if (func_021736D8() == 0)
        return 0;
    return func_0203D3A8((struct Entry *)((unsigned int)func_020399A8()), 0x202, 0, 0);
}






void func_021737CC(int a, int b, C_0 *c, D_021737A8 *d)
{
    int h;

    h = func_02026478((void *)d->f4);
    if (a < d->n) {
        func_02174EAC((u8 *)d, a, (u8 *)c);
        if (a != func_02012B58((const struct BigObj *)h) && func_0203D378() == 0 && a == 0 && c->hit == 1)
            d->flag = 1;
    }
}






int func_02173828(char *p)
{
    int r;

    if (func_021736D8() == 0) {
        return 0;
    }
    if (func_0203D578((int)func_020399A8(), 0x203) == 1) {
        return 0;
    }
    func_02082D44(p + 0x160, p + 0x3A4, 0x4C);
    r = func_0203D3F8((int)func_020399A8(), 0xFF, 0x203, 0x4C, (unsigned int)(p + 0x3A4), 0, 0, 1);
    if (r == 1) {
        p[0x8FE] = 0;
        if (func_0203D378() == 1) {
            p[0x903] = 1;
            func_02175920(p + 0x1AC);
            func_0217592C(p + 0x1AC);
        }
    }
    return r;
}





/*
 * The index loaded from c remains live in r1 into 02167658.
 */
void func_021738BC(int a, int b, int *c, u8 *d, void *e)
{
    int i;
    u32 bit;
    u8 mask;
    i = *c;
    bit = 1u << i;
    mask = d[0x8fb];
    if (mask & bit) {
        d[0x8fb] = mask ^ (u8)bit;
        func_02167658(*(Work * *)&((struct Obj09343 *)d)->f8, i);
    }
}






int func_021738E4(void *a, int b)
{
    int h;

    if (func_021736D8() == 0) {
        h = func_02039338();
        func_021738BC(h, 4, &b, (u8 *)a, func_020399A8());
        return 1;
    }
    return func_0203D3A8(func_020399A8(), 0x204, 4, (u32)(&b));
}




void func_0217392C(int a, int b, const C_0217392C *c, unsigned char *d)
{
    if (a == func_0203D1A4((struct Link *)((int)func_020399A8()))) {
        func_020264B4((void *)(((struct Obj00269 *)d)->f4), a, c->w14, c->f, 0x15, 0);
    } else if ((d[0x8FB] & (1 << a)) != 0) {
        func_02174F54(d, a, (const struct Ent *)c, 0);
    }
}



int func_02173984(char *p, int b)
{
    int r;

    if (func_021736D8() == 0) {
        return 0;
    }
    r = func_0203D3F8((int)func_020399A8(), 0xFF, 0x205, 0x1C, (u32)((void *)b), 0, 1, 0);
    if (r == 1) {
        p[0x900] = 0;
    }
    return r;
}


void func_021739C8(int a, int b, int c, u8 *p)
{
    u32 *w = (u32 *)(p + 0x940);
    *w = (*w & 0x7fffffff) | 0x80000000;
}




int func_021739E0(void)
{
    if (func_021736D8() == 0) return 1;
    return func_0203D3A8((struct Entry *)((int)func_020399A8()), 0x206, 0, 0);
}





void func_02173A04(int a, int b, Rec *c, u8 *d)
{
    if (func_021753D0(d, a, ((u8 *)c)[1]) == 1) *(Rec *)(d + 0x11c) = *c;
}





int func_02173A2C(unsigned char *p, int b, T *c, int d)
{
    B buf;
    int r;

    if (func_021736D8() == 0) {
        return 0;
    }
    if (p[0x944] == 0) {
        p[0x944]++;
    }
    func_02082BCC(&buf, 0, 0x38);
    buf.a = d;
    buf.t = *c;
    buf.b = p[0x944];
    r = func_0203D3F8((int)func_020399A8(), (unsigned char)b, 0x207, 0x38, (u32)(&buf), 0, 0, 0);
    if (r == 1) {
        p[0x158] = p[0x944];
        p[0x159] = p[0x944];
    }
    return r;
}





void func_02173AB4(int a, int b, u8 *c, u8 *d)
{
    u8 v;
    v = c[1];
    if (v == d[0x159]) func_021754E8((u8 *)((int)d), a, c[0], v);
    else (d + a)[0x948] = v;
}




int func_02173AE0(int a, int b, int c, int d)
{
    unsigned char buf[4];

    if (func_021736D8() == 0) {
        return 0;
    }
    buf[0] = c;
    buf[1] = d;
    return func_0203D3F8((int)func_020399A8(), (unsigned char)b, 0x208, 4, (u32)buf, 0, 0, 0);
}




void func_02173B20(int a, int b, u8 *c, u8 *d)
{
    if (d[0x154] == a && d[0x158] == c[0]) func_021754E8((u8 *)((int)d), a, 3, c[0]);
}




int func_02173B44(void *a, int b, int c)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8((int)func_020399A8(), (unsigned char)b, 0x209, 1, (u32)(&c), 0, 0, 0);
}


void func_02173B8C(int a, int b, u8 *c, int d)
{
    func_02175508(d, a, *c);
}



int func_02173B9C(int a, int b)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D3F8((int)func_020399A8(), (unsigned char)a, 0x20A, 1, (u32)(&b), 0, 0, 0);
}


/*
 * sdk:      DWCi_CheckDWCServer (dwc_match.o)
 */
void func_02173BE4(int a, int b, const u8 *src, D_02173B9C *dst)
{
    dst->v[0] = src[0];
    dst->v[1] = src[1];
    dst->v[2] = src[2];
    dst->v[3] = src[3];
}



int func_02173C04(int a, int b)
{
    unsigned char buf[4];

    if (func_021736D8() == 0) {
        return 0;
    }
    func_02082BCC(buf, 0, 4);
    buf[0] = 1;
    buf[1] = b;
    return func_0203D3F8((int)func_020399A8(), (unsigned char)a, 0x20B, 4, (u32)buf, 0, 0, 0);
}


void func_02173C50(int n, int b, int c, u8 *p) { p[0x924] |= (u8)(1 << n); }


int func_02173C6C(int a, int b)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), b, 0x20C, 0, 0, 0, 0, 0);
}

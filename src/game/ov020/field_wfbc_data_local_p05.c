/*
 * file:     field_wfbc_data_local_p05.c
 * unit:     yes
 * function: func_02186520, func_02186538, func_02186670, func_021866F8, func_02186748, func_02186764, func_02186770
 * address:  0x02186520
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02186AC8 0x02186AC8 thumb ov020
 *   func_02186278  0x02186278  thumb  ov020
 *   func_02030734  0x02030734  arm
 *   func_021867C4  0x021867C4  thumb  ov020
 *   func_02186830  0x02186830  thumb  ov020
 *   func_02161ECC  0x02161ECC  thumb  ov010
 *   func_021867B0  0x021867B0  thumb  ov020
 *   func_02186818  0x02186818  thumb  ov020
 *   func_0218682C  0x0218682C  thumb  ov020
 *   func_0216E618  0x0216E618  thumb  ov010
 *   func_0218683C  0x0218683C  thumb  ov020
 *   func_02186804  0x02186804  thumb  ov020
 *   d_02187EB4     0x02187EB4  data  ov020  a1
 *   d_02187DBC     0x02187DBC  data  ov020  a4
 *   func_02045A98  0x02045A98  arm
 *   func_02161E78  0x02161E78  thumb  ov010
 *   func_02186BB8 0x02186BB8 thumb ov020
 */
#include "../../matched/include/Obj19457.h"
#include "../../matched/include/Obj12540.h"
#include "../../matched/include/Obj19460.h"

struct ArcFile;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u16 f8;
    u16 fA;
    int f0C[6];
} Tmpl;

struct S {
    u8 lo : 4;
    u8 hi : 4;
};

struct State { u8 pad[3]; u8 low:2; u8 flag:1; u8 high:5; };

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
u8 a;
u8 b;
u8 c;
u8 flag : 1;
} S;

extern void func_02186AC8(char *, int, char *, int);
extern int func_02186278(char *p, int which);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int *func_021867C4(int a, int id);
extern void *func_02186830(struct ArcFile **p, int b, unsigned int heap);
extern int func_02161ECC(void *p);
extern int func_021867B0(u8 *p);
extern void func_02186818(u32 *p, u32 member);
extern char *func_0218682C(char *p);
extern void func_0216E618(Tmpl *, u16, u16, int);
extern void func_0218683C(void *p);
extern void func_02186804(void **p);
extern u16 func_02045A98(void);
extern void func_02161E78(void *a0);
extern int func_02186BB8(u8 *p, int delta);
void func_02186520(char *p, int b, char *c);
Tmpl *func_02186538(u16 *p, int which, int id);
void func_02186670(char *base, char *out, u16 *cnt, int n, u16 id);
void func_021866F8(char *p);
void func_02186748(struct State *p);
void func_02186764(S *p);
int func_02186770(u8 *p);
extern const char d_02187EB4[];
extern const Tmpl d_02187DBC;

void func_02186520(char *p, int b, char *c) { if (((struct Obj19457 *)p)->f2 == 0) func_02186AC8(p,b,c,1); else func_02186AC8(p,b,c,0); }


Tmpl *func_02186538(u16 *p, int which, int id)
{
    int k;
    Tmpl *buf;
    int h;
    u8 *t;
    int heap;
    int n;
    int i;
    int off;
    char *base;
    u16 *r;
    Tmpl *e;
    Tmpl tmp;

    heap = (u16)((id & 0x7FFF) | 0x8000);
    n = func_02186278((char *)p, which);
    if (n == 0)
        return 0;
    if (which == 0)
        base = (char *)p + 8;
    else
        base = (char *)p + 0xf8;
    buf = func_02030734(heap, n * 0x24, 1, d_02187EB4, 0x2E3);
    k = 0;
    h = (int)func_021867C4(0, heap);
    t = func_02186830((struct ArcFile **)h, p[1], heap);
    i = 0;
    tmp = d_02187DBC;
    for (; i < 10; i++) {
        off = i * 0x18;
        if (func_02161ECC(base + off)) {
            e = &buf[k];
            *e = tmp;
            func_02186818((u32 *)h, func_021867B0((u8 *)(base + off)));
            r = (u16 *)func_0218682C((char *)h);
            e->f0 = func_021867B0((u8 *)(base + off)) + 0x80;
            e->f2 = r[0];
            e->f4 = 3;
            if (which == 0) {
                if (p[1] == 0)
                    e->fA = r[0xf];
                else
                    e->fA = r[0xe];
            } else {
                if (p[1] == 0)
                    e->fA = r[0x11];
                else
                    e->fA = r[0x10];
            }
            func_0216E618(e, t[i * 2], t[i * 2 + 1], 0);
            k++;
        }
    }
    func_0218683C(t);
    func_02186804((void **)h);
    return buf;
}


void func_02186670(char *base, char *out, u16 *cnt, int n, u16 id)
{
    unsigned t;
    unsigned lim;
    int k;
    int num;
    int i;
    int h;
    char *r;
    char *q;

    t = func_02186278(base, 0);
    k = n * 2;
    lim = k + 2;
    if (lim > t)
        lim = t;
    num = lim - k;
    i = 0;
    h = (int)func_021867C4(0, id);
    r = func_0218682C((char *)h);
    *cnt = 0;
    if (num > 0) {
        q = base + k * 0x18;
        do {
            func_02186818((u32 *)h, (u8)q[i * 0x18 + 9]);
            *(u16 *)(out + *cnt * 8) = ((struct Obj12540 *)r)->f28;
            *(int *)(out + *cnt * 8 + 4) = ((struct Obj12540 *)r)->f2A;
            *cnt = *cnt + 1;
            i++;
        } while (i < num);
    }
    func_02186804((void **)h);
}


void func_021866F8(char *p)
{
    int i;
    int found;
    u16 v;

    v = func_02045A98();
    if ((u8)p[1] >= 0x1e)
        func_02161E78(p);
    if ((u8)p[2] > 0x64)
        func_02161E78(p);
    if (((struct S *)p)->hi != 0) {
        found = 0;
        for (i = 0; i < 8; i++) {
            if (v == *(u16 *)(p + 4 + i * 2))
                found = 1;
        }
        if (found == 0)
            func_02161E78(p);
    }
}

/*
 * Lever: raw-byte flag test, then bitfield assignment for the bics clear.
 */
void func_02186748(struct State *p) { if (((u8 *)p)[3] & 4) { func_02186BB8((u8 *)p, 10); p->flag = 0; } }


/*
 * Clear bit 0 of the byte at +3.
 *
 * Addresses are Black-image addresses.
 */
void func_02186764(S *p)
{
p->flag = 0;
}

/*
 * Test: is bit 0 of the byte at +3 set.
 *
 * Addresses are Black-image addresses.
 */
int func_02186770(u8 *p)
{
return (((struct Obj19460 *)p)->f3 & 1) != 0;
}

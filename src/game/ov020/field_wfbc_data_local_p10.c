/*
 * file:     field_wfbc_data_local_p10.c
 * unit:     yes
 * function: func_02186BA8, func_02186BB8, func_02186BE0, func_02186BE4, func_02186C44, func_02186CC4, func_02186D48
 * address:  0x02186BA8
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC70  0x0218DC70  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_02186090  0x02186090  thumb
 *   func_02193B40  0x02193B40  thumb  ov021
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_020127F0  0x020127F0  thumb
 *   func_02193BE4  0x02193BE4  thumb  ov021
 *   func_02193BC4  0x02193BC4  thumb  ov021
 *   func_021869B0  0x021869B0  thumb
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02193B68  0x02193B68  thumb  ov021
 *   func_020127C4  0x020127C4  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02186278  0x02186278  thumb  ov020
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_02193904  0x02193904  thumb  ov021
 *   func_0219390C  0x0219390C  thumb  ov021
 *   func_02193C00  0x02193C00  thumb  ov021
 *   func_02193C04  0x02193C04  thumb  ov021
 *   func_021867B4  0x021867B4  thumb  ov020
 *   func_021867A8  0x021867A8  thumb  ov020
 *   func_021869AC  0x021869AC  thumb  ov020
 *   func_021869B8  0x021869B8  thumb  ov020
 *   func_021938F4  0x021938F4  thumb  ov021
 *   func_021869D8  0x021869D8  thumb  ov020
 *   func_021869D0  0x021869D0  thumb  ov020
 */
#include "../../matched/include/Obj19474.h"

struct Obj00020;
struct V;
typedef unsigned char u8;

typedef short s16;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int f0;
    int f4;
} Ent;

extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern u32 func_02188C98(unsigned char *p);
extern void *func_0218DC70(u8 *p);
extern void *func_0215A5E4(void *a0);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_02188C7C(u8 *p);
extern int func_021A3460(u32 a, u32 b, u32 c, u32 d);
extern void *func_0216DDC0(u32 a, u32 b, u32 c, u32 d);
extern int func_02186090(void *p);
extern void func_02193B40(struct V *v, u32 key);
extern int func_020127F0(int a0);
extern int func_02193BE4(void *, unsigned int);
extern void func_02193BC4(void *, unsigned int);
extern void func_021869B0(u16 *p);
extern void *func_02158F74(void *);
extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 func_0215A5CC(void *a0);
extern void func_02193B68(void *, void *, int, int, int);
extern u8 *func_020127C4(void *p);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_02186278(char *p, int which);
extern u16 func_0216D588(void *p);
extern int func_02193904(void *p);
extern void *func_0219390C(void *a, unsigned int b);
extern char *func_02193C00(char *p);
extern void *func_02193C04(u8 *p);
extern int func_021867B4(u8 *p);
extern int func_021867A8(void *a);
extern u16 func_021869AC(u16 *p);
extern u16 func_021869B8(u16 *p);
extern int func_021938F4(unsigned char *a);
extern u16 func_021869D8(u16 *p);
extern u16 func_021869D0(char *p);
int func_02186BA8(u8 *p);
int func_02186BB8(u8 *p, int delta);
void func_02186BE0(char *p, int v);
int func_02186BE4(int a0, int a1);
int func_02186C44(int a0, int a1);
int func_02186CC4(int a0, int a1);
int func_02186D48(int a0, int a1);

/*
 * extent: two trailing zero alignment bytes.
 */
int func_02186BA8(u8 *p)
{
    if (p[2] == 0) return 1;
    return 0;
}

int func_02186BB8(u8 *p, int delta)
{
    int ret;
    int sum;
    ret = 0;
    sum = p[2] + delta;
    if (sum > 100) p[2] = 100;
    else if (sum < 0) { p[2] = 0; ret = 1; }
    else p[2] += (u8)delta;
    return ret;
}


void func_02186BE0(char *p, int v)
{
    ((struct Obj19474 *)p)->f2 = v;
}


int func_02186BE4(int a0, int a1)
{
    int *s;
    void *a;
    void *c;
    void *d;
    int e;
    s16 v[3];

    s = (int *)func_02158F58((int)func_0215A5F4((void *)a1));
    a = func_0218DC70((u8 *)func_02188C98((unsigned char *)s[1]));
    c = func_02188CB4((struct Obj00020 *)s[1]);
    d = func_02188C7C((u8 *)s[1]);
    func_021A3460((u32)c, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    e = func_02186090(func_0216DDC0((u32)d, v[2], v[0], 0));
    func_02193B40(a, e);
    return 0;
}


int func_02186C44(int a0, int a1)
{
    int *s;
    void *a;
    int b;
    void *c;
    void *d;
    int e;
    s16 v[3];

    s = (int *)func_02158F58((int)func_0215A5F4((void *)a1));
    a = func_0218DC70((u8 *)func_02188C98((unsigned char *)s[1]));
    b = func_020127F0((int)func_0215A5E4((void *)a1));
    c = func_02188CB4((struct Obj00020 *)s[1]);
    d = func_02188C7C((u8 *)s[1]);
    func_021A3460((u32)c, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    e = func_02186090(func_0216DDC0((u32)d, v[2], v[0], 0));
    if (func_02193BE4(a, e) != 0) {
        func_02193BC4(a, e);
        func_021869B0((u16 *)b);
    }
    return 0;
}


int func_02186CC4(int a0, int a1)
{
    void *r6;
    int *s;
    void *a;
    void *b;
    void *c;
    int r5;
    int r4;
    s16 v[3];

    r6 = func_0215A5F4((void *)a1);
    s = (int *)func_02158F58((int)r6);
    a = func_0218DC70((u8 *)func_02188C98((unsigned char *)s[1]));
    b = func_02188CB4((struct Obj00020 *)s[1]);
    c = func_02188C7C((u8 *)s[1]);
    r6 = func_02158F74(r6);
    r5 = func_02159B10((void *)a0, (void *)a1);
    r4 = func_0215A5CC((void *)a1);
    func_021A3460((u32)b, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    func_02193B68(a, r6, func_02186090(func_0216DDC0((u32)c, v[2], v[0], 0)), r5, r4);
    return 0;
}


int func_02186D48(int a0, int a1)
{
    int cur;
    int st;
    void *id;
    int *rec;
    void *sub;
    void *b;
    void *obj;
    int c;
    void *d;
    void *w;
    int kind;
    u16 *out;
    Ent *ent;
    void *m;
    void *s;
    s16 v[3];

    m = func_0215A5F4((void *)a1);
    b = func_0215A5E4((void *)a1);
    c = (int)func_020127C4(b);
    kind = func_02159B10((void *)a0, (void *)a1);
    out = func_02159AE8((void *)a0, (void *)a1);
    if (kind == 3) {
        *out = func_02186278((char *)c, 0);
    } else {
    ent = (Ent *)func_02158F58((int)m);
    m = func_0218DC70((u8 *)func_02188C98((u8 *)ent->f4));
    d = func_02188CB4((struct Obj00020 *)ent->f4);
    w = func_02188C7C((u8 *)ent->f4);
    s = (void *)func_020127F0((int)b);
    func_021A3460((u32)d, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    obj = func_0216DDC0((u32)w, v[2], v[0], 0);
    if (obj != 0) {
        cur = func_02186090(obj);
        st = func_0216D588(obj);
        func_02193904(m);
        sub = func_0219390C(m, cur);
        if (sub != 0) {
            rec = (int *)func_02193C00(sub);
            id = func_02193C04(sub);
        }
    }
    switch (kind) {
    case 0:
        *out = rec[6];
        break;
    case 1:
        *out = func_021867B4(id);
        break;
    case 2:
        *out = func_021867A8(id);
        break;
    case 3:
        break;
    case 4:
        *out = func_021869AC(s);
        break;
    case 5:
        *out = func_021869B8(s);
        break;
    case 6:
        if (func_021938F4(m) == 0)
            *out = 0;
        else
            *out = 1;
        break;
    case 7:
        *out = func_021869D8(s);
        break;
    case 8:
        *out = func_021869D0(s);
        break;
    case 9:
        *out = cur;
        break;
    case 10:
        *out = func_02193BE4(m, cur);
        break;
    case 11:
        *out = st;
        break;
    }
    }
    return 0;
}

/*
 * file:     unit_021743B4_p05.c
 * unit:     yes
 * function: func_02174978, func_02174AE0, func_02174B2C, func_02174B7C, func_02174BC4, func_02174C38, func_02174CCC, func_02174D5C, func_02174DF4, func_02174E14, func_02174E3C
 * address:  0x02174978
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
 *   func_02026478  0x02026478  thumb
 *   func_0203D378  0x0203D378  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02012B4C  0x02012B4C  thumb
 *   func_02173758  0x02173758  thumb  ov011
 *   func_0217546C  0x0217546C  thumb  ov011
 *   func_02173828  0x02173828  thumb  ov011
 *   func_021743B4  0x021743B4  thumb  ov011
 *   func_021757C4  0x021757C4  thumb  ov011
 *   func_02174374  0x02174374  thumb  ov011
 *   func_021752DC  0x021752DC  thumb  ov011
 *   func_02173984  0x02173984  thumb  ov011
 *   func_02012E40  0x02012E40  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_021756D0  0x021756D0  thumb  ov011
 *   func_0200BE84  0x0200BE84  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02014484  0x02014484  thumb
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_021737A8  0x021737A8  thumb ov011
 *   func_021738E4  0x021738E4  thumb ov011
 *   func_02173AE0  0x02173AE0  thumb ov011
 *   func_02173B44  0x02173B44  thumb ov011
 *   func_020127C4 0x020127C4 thumb
 *   func_02174734 0x02174734 thumb ov011
 *   func_02162024 0x02162024 thumb ov010
 *   func_021747A8 0x021747A8 thumb ov011
 *   func_02162038 0x02162038 thumb ov010
 *   func_0216202C 0x0216202C thumb ov010
 *   func_021747F4 0x021747F4 thumb ov011
 *   func_02162040 0x02162040 thumb ov010
 *   func_021748CC  0x021748CC  thumb ov011
 *   func_02174954  0x02174954  thumb ov011
 *   func_0200E0B0  0x0200E0B0  thumb
 *   func_0216749C  0x0216749C  thumb ov010
 *   func_021673C4  0x021673C4  thumb ov010
 *   func_021673A8  0x021673A8  thumb ov010
 *   func_02039338  0x02039338  arm
 *   func_02173CB0 0x02173CB0 thumb ov011
 *   func_02012944  0x02012944  thumb
 *   func_02008468  0x02008468  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_020127B8  0x020127B8  thumb
 *   func_02175710  0x02175710  thumb ov011
 */
#include "../../matched/include/Obj00269.h"
#include "../../matched/include/Obj09347.h"
#include "../../matched/include/Obj07329.h"
#include "../../matched/include/Obj04951.h"
#include "../../matched/include/Obj09349.h"

struct Big;
struct BigObj;
struct Sub02014444Obj;
struct Entry32;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Bits;

typedef struct Blk {
    u8 pad[0x50];
    u32 a : 6;
    u32 b : 4;
    u32 c : 4;
    u32 d : 4;
    u32 e : 6;
} Blk;

typedef struct {
    u16 low : 9;
    u16 state : 6;
    u16 high : 1;
} F86_02174E14;

typedef struct Ent {
    int w[7];
} Ent;

typedef struct F86_02174E3C {
    u16 x : 3;
    u16 rest : 13;
} F86_02174E3C;

extern u32 func_02026478(void *obj);
extern u32 func_0203D378(void);
extern int func_0203D1B4(void);
extern void func_02012B4C(struct BigObj *p, u8 v);
extern int func_02173758(int a, int b, ...);
extern void func_0217546C(u8 *);
extern int func_02173828(char *p);
extern int func_021743B4(char *p);
extern void func_021757C4(u8 *, u8 *);
extern int func_02174374(int *a);
extern int func_021752DC(u8 *);
extern int func_02173984(char *p, int b);
extern u8 func_02012E40(const u8 *o);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern int func_021756D0(u32 x);
extern void func_0200BE84(void *, u8 *);
void *func_02012B38(const struct BigObj *p);
unsigned char func_02014484(struct Sub02014444Obj *o);
u32 func_0203D1C0(u32 index);
int func_021737A8(void);
int func_021738E4(void *a, int b);
int func_02173AE0(int a, int b, int c, int d);
int func_02173B44(void *p, int i, int v);
unsigned char *func_020127C4(void *p);
int func_02174734(char *p, int b, void *c);
int func_02162024(char *p, int index, void *out);
int func_021747A8(void *a, int b);
void func_02162038(char *p, int index);
int func_0216202C(char *p, void *out, u8 *index);
int func_021747F4(int a, int b);
void func_02162040(char *p);
int func_021748CC(char *p, int a);
u32 func_02174954(u32 p);
void *func_0200E0B0(void *p);
unsigned short func_0216749C(struct Entry32 *list, struct Entry32 *out, u32 cap, int page, u8 *n);
u8 func_021673C4(u8 *p);
u8 func_021673A8(u8 *p);
u16 func_02039338(void);
int func_02173CB0(int *a, int b);
u8 *func_02012944(void *p);
int func_02008468(void);
void func_02082D44(int a, u8 *b, int c);
void *func_020127B8(void *p);
void func_02175710(u8 *o, u32 v);
void func_02174978(u8 *s);
void func_02174AE0(unsigned char *p);
void func_02174B2C(unsigned char *p);
void func_02174B7C(unsigned char *p);
void func_02174BC4(unsigned char *p);
void func_02174C38(unsigned char *p);
void func_02174CCC(unsigned char *p);
void func_02174D5C(int *p, const u8 *q);
void func_02174DF4(u8 *p);
void func_02174E14(u8 *p, int a);
void func_02174E3C(u8 *p);


/*
 * Addresses are Black-image addresses.
 */
void func_02174978(u8 *s)
{
    int h;
    int n;
    void *w;

    h = func_02026478((void *)(((struct Obj00269 *)s)->f4));
    if (func_0203D378() == 1) {
        n = func_0203D1B4();
        if (n > s[0x902]) {
            s[0x902] = n;
            s[0x903] = 1;
            func_02012B4C((struct BigObj *)h, s[0x902]);
        }
    }
    if (s[0x903] == 1 && func_02173758((int)s, s[0x902]) == 1) {
        s[0x903] = 0;
    }
    func_02174AE0(s);
    func_0217546C(s);
    if (s[0x8fe] == 1) {
        func_02174E3C(s);
        func_02173828((char *)s);
    }
    func_02174B2C(s);
    func_02174B7C(s);
    func_02174BC4(s);
    if (s[0x93e] == 1 && func_021743B4((char *)s) == 1) {
        s[0x93e] = 0;
    }
    func_021757C4(s, s + 0x1ac);
    if (s[0x907] == 1 && func_02174374((int *)s) == 1) {
        s[0x907] = 0;
    }
    func_02174C38(s);
    func_02174CCC(s);
    func_02174DF4(s);
    if (func_021752DC(s) == 1) {
        s[0x900] = 1;
    }
    if (s[0x900] == 1 && ((Bits *)(s + 0x904))->b1 == 0 && func_02173984((char *)s, (int)(s + 0x70)) == 1) {
        s[0x900] = 0;
    }
    if (func_02012E40((const u8 *)h) == 0 && ((Bits *)(s + 0x8f8))->b0 == 1) {
        w = func_0200BE48(func_02012EBC((struct Big *)h));
        if (func_021756D0(((struct Obj00269 *)s)->f8F4) == 0) {
            ((struct Obj00269 *)s)->f8F4 = 0x11;
        }
        func_0200BE84(w, s + 0x8e4);
        ((Bits *)(s + 0x8f8))->b0 = 0;
    }
}


void func_02174AE0(unsigned char *p)
{
    int r;

    r = func_02014484((struct Sub02014444Obj *)func_02012B38((const struct BigObj *)func_02026478((void *)(((struct Obj09347 *)p)->f4))));
    switch (r) {
    case 0:
        if (((unsigned)(((struct Obj09347 *)p)->f86 << 17) >> 26) == 2) {
            func_02174E14(p, 0);
        }
        break;
    case 1:
        if (((unsigned)(((struct Obj09347 *)p)->f86 << 17) >> 26) == 0) {
            func_02174E14(p, 2);
        }
        break;
    }
}


void func_02174B2C(unsigned char *p)
{
    int i;

    if (p[0x8FF] != 0) {
        p[0x8FF]--;
        return;
    }
    for (i = 0; i < p[0x902]; i++) {
        if ((int)func_0203D1C0((unsigned char)i) == 1 && !(p[0x8FB] & (1 << i))) {
            func_021737A8();
            p[0x8FF] = 30;
            return;
        }
    }
}


void func_02174B7C(unsigned char *p)
{
    int i;

    if (func_0203D378() != 0) {
        for (i = 0; i < p[0x902]; i++) {
            if ((int)func_0203D1C0((unsigned char)i) == 0 && (p[0x8FB] & (1 << i))) {
                func_021738E4(p, i);
            }
        }
    }
}


void func_02174BC4(unsigned char *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (p[i + 0x945] != 0) {
            if ((int)func_0203D1C0((unsigned char)i) == 1) {
                if (func_02173AE0((int)p, i, 2, p[i + 0x945]) == 1) {
                    p[i + 0x945] = 0;
                }
            } else {
                p[i + 0x945] = 0;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        if (p[i + 0x948] != 0) {
            if ((int)func_0203D1C0((unsigned char)i) == 1) {
                if (func_02173B44(p, i, p[i + 0x948]) == 1) {
                    p[i + 0x948] = 0;
                }
            } else {
                p[i + 0x948] = 0;
            }
        }
    }
}

/*
 * func_02026478 returns the argument consumed by func_020127C4.
 */
void func_02174C38(unsigned char *p)
{
    int b1[2];
    int b2[2];
    unsigned char i;
    int h;
    h = func_02026478((void *)(((struct Obj07329 *)p)->f4));
    if (p[0x908] != 0) {
        if (func_02174734((char *)p, p[0x908], (void *)func_020127C4((void *)h)) == 1) {
            p[0x908] = 0;
        }
    }
    for (i = 0; i < 3; i++) {
        if (func_02162024((char *)(p + 0x35C), i, b1) == 1) {
            if (func_021747A8(b1, i) == 1) {
                func_02162038((char *)(p + 0x35C), i);
            }
        }
    }
    if (func_0216202C((char *)(p + 0x35C), b2, &i) == 1) {
        if (func_021747F4((int)b2, i) == 1) {
            func_02162040((char *)(p + 0x35C));
        }
    }
}


/*
 * The guard's ldrb lands in r1 because func_02026478's result is live in r0:
 * it is func_020127C4's argument (the r0 at that call is never re-set).
 */
void func_02174CCC(unsigned char *p)
{
    unsigned char i;
    unsigned char *e;
    unsigned char *q;
    int h;

    h = func_02026478((void *)(((struct Obj04951 *)p)->f4));
    if (p[0x908] != 0) {
        if (func_02174734((char *)p, p[0x908], (void *)func_020127C4((void *)h)) == 1) {
            p[0x908] = 0;
        }
    }
    e = p + 0x8D4;
    for (i = 0; i < 3; i++) {
        q = p + i * 4;
        if (q[0x8D5] == 1) {
            func_02174D5C((int *)p, e + i * 4);
            if (func_021748CC((char *)p, i) == 1) {
                q[0x8D5] = 0;
            }
        }
    }
    if (p[0x8E1] == 1) {
        if (func_02174954((u32)(p + 0x8E0)) == 1) {
            p[0x8E1] = 0;
        }
    }
}


void func_02174D5C(int *p, const u8 *q)
{
    Blk *b;
    void *x;
    int t;
    u8 buf[4];

    b = (Blk *)((u8 *)p + 0x880);
    x = func_0200E0B0(func_02012EBC((struct Big *)func_02026478((void *)p[1])));
    func_0216749C(x, (struct Entry32 *)b, 0x14, q[0], buf);
    b->a = buf[0];
    b->b = func_021673C4(x);
    b->c = func_021673A8(x);
    t = func_02039338();
    b->d = t;
    b->e = q[0];
}

void func_02174DF4(u8 *p)
{
    if (p[0x924] != 0) {
        if (func_02173CB0((int *)p, p[0x924]) == 1) {
            p[0x924] = 0;
        }
    }
}

void func_02174E14(u8 *p, int a)
{
    ((F86_02174E14 *)(p + 0x86))->state = (u16)a;
    p[0x900] = 1;
}


void func_02174E3C(u8 *p)
{
    int v;

    v = func_02026478((void *)(((struct Obj09349 *)p)->f4));
    func_02082D44((int)func_02012944((void *)v), p + 0x160, func_02008468());
    func_02082D44((int)func_020127B8((void *)v), p + 0x180, 0x10);
    func_021752DC(p);
    if (((F86_02174E3C *)(p + 0x86))->x == 0x80) {
        func_02175710(p, func_02039338());
    }
    *(Ent *)(p + 0x190) = *(Ent *)(p + 0x70);
}

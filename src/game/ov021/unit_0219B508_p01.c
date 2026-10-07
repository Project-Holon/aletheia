/*
 * file:     unit_0219B508_p01.c
 * unit:     yes
 * function: func_0219B508, func_0219B520, func_0219B59C, func_0219B6B0, func_0219B6E0, func_0219B75C, func_0219B8A8
 * address:  0x0219B508
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
 *   func_0216D6A0  0x0216D6A0  thumb  ov010
 *   func_0216D63C  0x0216D63C  thumb  ov010
 *   func_0216D6B8  0x0216D6B8  thumb  ov010
 *   func_0219B494  0x0219B494  thumb  ov021
 *   func_0219B4C8  0x0219B4C8  thumb  ov021
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   d_021D5238     0x021D5238  data   ov021  a4
 *   d_021D5248     0x021D5248  data   ov021  a4
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 *   func_02164168  0x02164168  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   d_021D5258     0x021D5258  data   ov021  a4
 *   func_0203630C  0x0203630C  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct St_0219B520 {
    u8 state;
    s8 f1;
    s8 cur;
    s8 max;
} St_0219B520;

typedef struct Tbl4 { u32 w[4]; } Tbl4;

typedef struct Tbl22 { u32 w[2][2]; } Tbl22;

typedef struct St_0219B59C {
    u8 f0;
    u8 state;
    u8 f2;
    u8 f3;
    s8 f4;
    s8 f5;
    s8 f6;
    s8 f7;
    s8 f8;
} St_0219B59C;

typedef struct St_0219B6E0 {
    u8 state;
    s8 f1;
    s8 cur;
    s8 max;
} St_0219B6E0;

typedef struct Tbl24 { u32 w[2][4]; } Tbl24;

typedef struct St_0219B75C {
    u8 f0;
    u8 state;
    u8 f2;
    u8 f3;
    s8 f4;
    s8 f5;
    s8 f6;
    s8 f7;
    s8 f8;
} St_0219B75C;

extern void *func_0216D6A0(int a0, int a1);
extern int func_0216D63C(char *a0, int a1);
extern void *func_0216D6B8(void *p);
extern int func_0219B494(int a);
extern int func_0219B4C8(int a);
extern int func_0216DA5C(void *a0);
extern u16 func_0216D5F8(void *p);
extern int func_02197E7C(int a, int b);
extern void func_0216D438(char *a0, int a1);
extern u32 func_02197EDC(u8 *p);
extern u16 func_0216D5A8(u8 *p);
extern int func_02164168(int a);
extern void func_0216D5E0(int a0, int a1);
extern unsigned int func_0203630C(void);
void func_0219B508(u32 a);
int func_0219B520(int a);
int func_0219B59C(char *a);
void func_0219B6B0(u32 a);
int func_0219B6E0(int a);
int func_0219B75C(char *a);
int func_0219B8A8(void);
extern Tbl4 d_021D5238;
extern Tbl22 d_021D5248;
extern Tbl24 d_021D5258;


void func_0219B508(u32 a)
{
    u8 *p = func_0216D6A0(a, 9);
    p[3] = func_0216D63C((char *)a, 1);
}


int func_0219B520(int a)
{
    St_0219B520 *p;

    p = func_0216D6B8((void *)a);
    switch (p->state) {
    case 0:
        if (func_0219B494(a) == 1) {
            p->state++;
        }
        break;
    case 1:
        if (func_0219B4C8(a) == 0) {
            break;
        }
        p->cur++;
        if (p->cur < p->max) {
            p->state = 0;
            break;
        }
        p->state++;
    case 2:
        if (func_0216DA5C((void *)a) == 1) {
            break;
        }
        p->state++;
        p->cur = 0;
        p->f1 = 0;
    case 3:
        return 1;
    }
    return 0;
}


int func_0219B59C(char *a)
{
    St_0219B59C *p;
    int lim;

    p = func_0216D6B8((void *)a);
    switch (p->state) {
    case 0: {
        Tbl4 t = d_021D5238;
        u16 v = func_0216D5F8((void *)a);
        p->f4 = v;
        p->f5 = t.w[v];
        p->state++;
    }
    case 1: {
        Tbl22 t = d_021D5248;
        func_0216D438(a, (u16)((u32)func_02197E7C((u16)t.w[p->f5][p->f6], (u16)0)));
        p->state++;
    }
    case 2:
        if (func_02197EDC((u8 *)a) == 0) {
            return 1;
        }
        p->state++;
    case 3:
        lim = 8;
        if (func_0216D5A8((u8 *)a) == 14 && func_0219B8A8() == 1 && func_02164168((int)a) == 1) {
            lim = 4;
        }
        if (++p->f8 < lim) {
            return 1;
        }
        p->f8 = 0;
        if (++p->f7 < 4) {
            p->f6 = (p->f6 + 1) & 1;
            p->state = 1;
            return 1;
        }
        func_0216D5E0((int)a, p->f4);
        p->state++;
        p->f7 = 0;
        p->f0 = 0;
    }
    return 0;
}


void func_0219B6B0(u32 a)
{
    u8 *p = func_0216D6A0(a, 9);
    u32 s;
    u8 v = 1;
    p[3] = func_0216D63C((char *)a, 1);
    s = func_0216D5A8((u8 *)a);
    if (s == 5 || s == 20 || s == 15) {
        v = 0;
    }
    p[5] = v;
}


int func_0219B6E0(int a)
{
    St_0219B6E0 *p;

    p = func_0216D6B8((void *)a);
    switch (p->state) {
    case 0:
        if (func_0219B494(a) == 1) {
            p->state++;
        }
        break;
    case 1:
        if (func_0219B4C8(a) == 0) {
            break;
        }
        p->cur++;
        if (p->cur < p->max) {
            p->state = 0;
            break;
        }
        p->state++;
    case 2:
        if (func_0216DA5C((void *)a) == 1) {
            break;
        }
        p->state++;
        p->cur = 0;
        p->f1 = 0;
    case 3:
        return 1;
    }
    return 0;
}


int func_0219B75C(char *a)
{
    Tbl24 t = d_021D5258;
    St_0219B75C *p;
    int lim;
    int i;
    u16 v;
    u16 k;

    p = func_0216D6B8((void *)a);
    switch (p->state) {
    case 0:
        v = func_0216D5F8((void *)a);
        for (i = 0; i < 4 && v != t.w[p->f5][i]; i++) {
        }
        i++;
        p->f4 = v;
        p->f6 = i % 4;
        p->state++;
    case 1:
        func_0216D438(a, (u16)((u32)func_02197E7C((u16)t.w[p->f5][p->f6], (u16)0)));
        p->state++;
    case 2:
        if (func_02197EDC((u8 *)a) == 0) {
            return 1;
        }
        p->state++;
    case 3:
        lim = 8;
        k = func_0216D5A8((u8 *)a);
        if ((k == 15 || k == 16) && func_0219B8A8() == 1 && func_02164168((int)a) == 1) {
            lim = 4;
        }
        if (++p->f8 < lim) {
            return 1;
        }
        p->f8 = 0;
        if (++p->f7 < 4) {
            p->f6 = (p->f6 + 1) % 4;
            p->state = 1;
            return 1;
        }
        func_0216D5E0((int)a, p->f4);
        p->state++;
        p->f7 = 0;
        p->f0 = 0;
    }
    return 0;
}


int func_0219B8A8(void)
{
    if (func_0203630C() & 2) {
        return 1;
    }
    return 0;
}

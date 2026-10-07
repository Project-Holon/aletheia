/*
 * file:     fld_exp_obj_p06.c
 * unit:     yes
 * function: func_021BEBA8, func_021BEBD8, func_021BEC24, func_021BEC54, func_021BEC84, func_021BECB4, func_021BECE4, func_021BED14, func_021BED44, func_021BED74, func_021BEDA4, func_021BEDD4, func_021BEE24
 * address:  0x021BEBA8
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
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BEF8C  0x021BEF8C  thumb  ov021
 *   func_021BEA6C  0x021BEA6C  thumb  ov021
 *   func_021BF0A4  0x021BF0A4  thumb  ov021
 *   func_021BF130  0x021BF130  thumb  ov021
 *   func_021BF19C  0x021BF19C  thumb  ov021
 *   func_021BF348  0x021BF348  thumb  ov021
 *   func_021BF208  0x021BF208  thumb  ov021
 *   func_021BF3BC  0x021BF3BC  thumb  ov021
 *   func_021BF274  0x021BF274  thumb  ov021
 *   func_021BF430  0x021BF430  thumb  ov021
 *   func_021BF2E0  0x021BF2E0  thumb  ov021
 *   func_021BF4A4  0x021BF4A4  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 */
struct Desc;
struct Obj;
struct Obj00020;
typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} Work_021BEBA8;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} Ent;

typedef struct {
    void *x0;
    u32 x4;
    u32 x8;
    u32 xc;
} Work_021BECB4;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} Work_021BECE4;

typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; } X;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} Work_021BED44;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_021BEF8C(u32 p0, int *st, u8 *q);
extern int func_021BEA6C(int a);
int func_021BF0A4(u32 p0, int *st, u8 *q);
int func_021BF130(u32 p0, int *st, u8 *q);
int func_021BF19C(u32 p0, int *st, u8 *q);
extern int func_021BF348(u32 p0, int *st, u8 *q);
int func_021BF208(u32 p0, int *st, u8 *q);
extern int func_021BF3BC(int a, int *s, int *q);
extern int func_021BF274(u32 p0, int *st, u8 *q);
extern int func_021BF430(int a, int *s, int *q);
int func_021BF2E0(u32 p0, int *st, u8 *q);
int func_021BF4A4(int a, int *s, int *q);
extern void *func_02188CB4(struct Obj00020 *p);
extern u16 func_021A3050(u8 *p);
void *func_021BEBA8(int a, int b);
void *func_021BEBD8(void *p, int a1, int a2, int a3);
int func_021BEC24(int a, int b);
int func_021BEC54(int a, int b);
void *func_021BEC84(void *a, u32 b);
void *func_021BECB4(void *p, u32 b);
void *func_021BECE4(int a, int b);
u32 func_021BED14(u32 a, u32 b);
void *func_021BED44(int a, int b);
int func_021BED74(int a, int b);
int func_021BEDA4(int a, int b);
int func_021BEDD4(void *a, int b);
void func_021BEE24(void *a, void *b);


void *func_021BEBA8(int a, int b)
{
    void *t = func_020122C0((void *)a, 0, func_021BEF8C, 0x2c);
    Work_021BEBA8 *w = func_020124E8(t);
    w->f0 = a;
    w->f4 = b;
    w->f8 = 2;
    w->fC = func_021BEA6C(2);
    return t;
}


void *func_021BEBD8(void *p, int a1, int a2, int a3)
{
    void *r0v = func_020122C0(p, 0, func_021BF0A4, 0x2C);
    int *r4 = func_020124E8(r0v);

    r4[0] = (int)p;
    r4[1] = a1;
    r4[2] = 3;
    ((u8 *)r4)[0x20] = a2;
    ((u8 *)r4)[0x21] = a3;
    r4[3] = (int)func_021BEA6C(r4[2]);
    r4[9] = 0;
    r4[10] = 0;
    return r0v;
}


int func_021BEC24(int a, int b)
{
    int h = (int)func_020122C0((void *)a, 0, func_021BF130, 0x2c);
    Ent *e = func_020124E8((struct Obj *)h);
    e->f0 = a;
    e->f4 = b;
    e->f8 = 4;
    e->fC = func_021BEA6C(4);
    return h;
}


int func_021BEC54(int a, int b)
{
    int h = (int)func_020122C0((void *)a, 0, func_021BF19C, 0x2c);
    Ent *e = func_020124E8((struct Obj *)h);
    e->f0 = a;
    e->f4 = b;
    e->f8 = 5;
    e->fC = func_021BEA6C(5);
    return h;
}


void *func_021BEC84(void *a, u32 b)
{
    void *t = func_020122C0(a, 0, func_021BF348, 0x2c);
    u32 *w = func_020124E8(t);

    w[0] = (u32)a;
    w[1] = b;
    w[2] = 5;
    w[3] = (u32)func_021BEA6C(5);
    return t;
}


void *func_021BECB4(void *p, u32 b)
{
    void *task = func_020122C0(p, 0, func_021BF208, 0x2C);
    Work_021BECB4 *w = func_020124E8(task);

    w->x0 = p;
    w->x4 = b;
    w->x8 = 6;
    w->xc = func_021BEA6C(6);
    return task;
}


void *func_021BECE4(int a, int b)
{
    void *t = func_020122C0((void *)a, 0, func_021BF3BC, 0x2c);
    Work_021BECE4 *w = func_020124E8(t);
    w->f0 = a;
    w->f4 = b;
    w->f8 = 6;
    w->fC = func_021BEA6C(6);
    return t;
}

/*
 * Addresses are Black-image addresses.
 */
u32 func_021BED14(u32 a, u32 b)
{
    u32 h = (u32)func_020122C0((void *)a, 0, func_021BF274, 0x2c);
    X *x = func_020124E8((struct Obj *)h);
    x->f0 = a;
    x->f4 = b;
    x->f8 = 7;
    x->fC = func_021BEA6C(7);
    return h;
}


void *func_021BED44(int a, int b)
{
    void *t = func_020122C0((void *)a, 0, func_021BF430, 0x2c);
    Work_021BED44 *w = func_020124E8(t);
    w->f0 = a;
    w->f4 = b;
    w->f8 = 7;
    w->fC = func_021BEA6C(7);
    return t;
}


int func_021BED74(int a, int b)
{
    int h = (int)func_020122C0((void *)a, 0, func_021BF2E0, 0x2c);
    Ent *e = func_020124E8((struct Obj *)h);
    e->f0 = a;
    e->f4 = b;
    e->f8 = 8;
    e->fC = func_021BEA6C(8);
    return h;
}


int func_021BEDA4(int a, int b)
{
    int h = (int)func_020122C0((void *)a, 0, func_021BF4A4, 0x2c);
    Ent *e = func_020124E8((struct Obj *)h);
    e->f0 = a;
    e->f4 = b;
    e->f8 = 8;
    e->fC = func_021BEA6C(8);
    return h;
}


int func_021BEDD4(void *a, int b)
{
    switch (func_021A3050(func_02188CB4((struct Obj00020 *)b))) {
    case 2:
    default:
        return func_021BED14((u32)a, b);
    case 3:
        return func_021BED74((int)a, b);
    case 0:
        return func_021BEC54((int)a, b);
    case 1:
        return (int)func_021BECB4(a, b);
    }
}


void func_021BEE24(void *a, void *b)
{
    switch (func_021A3050(func_02188CB4(b))) {
    case 2:
    default:
        func_021BED44((int)a, (int)b);
        break;
    case 3:
        func_021BEDA4((int)a, (int)b);
        break;
    case 0:
        func_021BEC84(a, (u32)b);
        break;
    case 1:
        func_021BECE4((int)a, (int)b);
        break;
    }
}

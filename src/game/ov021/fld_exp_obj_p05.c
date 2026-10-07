/*
 * file:     fld_exp_obj_p05.c
 * unit:     yes
 * function: func_021BE8B8, func_021BE8D4, func_021BE92C, func_021BE9A0, func_021BE9F0, func_021BEA30, func_021BEA6C, func_021BEA9C, func_021BEACC, func_021BEAFC, func_021BEB38, func_021BEB78
 * address:  0x021BE8B8
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
 *   func_02013FD8  0x02013FD8  thumb
 *   func_021BEC24  0x021BEC24  thumb  ov021
 *   func_021BEC54  0x021BEC54  thumb  ov021
 *   func_021BECB4  0x021BECB4  thumb  ov021
 *   func_021BED14  0x021BED14  thumb  ov021
 *   func_021BED74  0x021BED74  thumb  ov021
 *   func_021BEDD4  0x021BEDD4  thumb  ov021
 *   func_021BEBA8  0x021BEBA8  thumb  ov021
 *   func_021BEBD8  0x021BEBD8  thumb  ov021
 *   func_021BEC84  0x021BEC84  thumb  ov021
 *   func_021BECE4  0x021BECE4  thumb  ov021
 *   func_021BED44  0x021BED44  thumb  ov021
 *   func_021BEDA4  0x021BEDA4  thumb  ov021
 *   func_021BEE24  0x021BEE24  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BF0E4  0x021BF0E4  thumb  ov021
 *   func_021BF518  0x021BF518  thumb  ov021
 *   func_021BEE74  0x021BEE74  thumb  ov021
 *   d_021D9F60  0x021D9F60  data
 *   d_021D9FF0     0x021D9FF0  data
 *   func_021BEEB4  0x021BEEB4  thumb  ov021
 *   func_021BEF08  0x021BEF08  thumb  ov021
 */
struct Desc;
struct Obj;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
} Ent;

typedef struct {
    u32 v[6][6];
} Table;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
} Work;

typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; } X;

extern u8 func_02013FD8(u32 id);
extern int func_021BEC24(int a, int b);
extern int func_021BEC54(int a, int b);
extern void *func_021BECB4(void *p, u32 b);
extern u32 func_021BED14(u32 a, u32 b);
extern int func_021BED74(int a, int b);
extern int func_021BEDD4(void *a, int b);
extern void *func_021BEBA8(int a, int b);
extern void *func_021BEBD8(void *p, int a1, int a2, int a3);
extern void *func_021BEC84(void *a, u32 b);
extern void *func_021BECE4(int a, int b);
extern void *func_021BED44(int a, int b);
extern int func_021BEDA4(int a, int b);
extern int func_021BEE24(void *a, int b);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
int func_021BF0E4(u32 p0, int *st, u8 *q);
int func_021BF518(int a, int *s, int *q);
int func_021BEE74(u32 p0, int *st, u8 *q);
int func_021BEEB4(u32 p0, int *st, u8 *q);
extern int func_021BEF08(u32 p0, int *st, u8 *q);
int func_021BE8B8(int a, int b);
int func_021BE8D4(void *a, int b, int sel, int d);
int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
void *func_021BE9A0(void *p, int a1, int a2, int a3, int a4, int a5);
void *func_021BE9F0(void *p, int a1, int a2, int a3, int a4);
u32 func_021BEA30(u32 a, u32 b, u32 c, u32 d);
int func_021BEA6C(int x);
u32 func_021BEA9C(int row, int col);
u32 func_021BEACC(int a, int b);
void *func_021BEAFC(int a, int b, int c, int d);
void *func_021BEB38(void *p, int a1, int a2, int a3, int a4);
u32 func_021BEB78(u32 a, u32 b);
extern const Table d_021D9F60;
extern const Table d_021D9FF0;


int func_021BE8B8(int a, int b)
{
    int x = func_02013FD8(a);
    return func_021BEACC(x, func_02013FD8(b));
}


int func_021BE8D4(void *a, int b, int sel, int d)
{
    switch (sel) {
    default:
        return func_021BEB78((u32)a, b);
    case 0:
    case 1:
    case 3:
        return (int)func_021BEAFC((int)a, b, sel, d);
    case 4:
        return func_021BEC24((int)a, b);
    case 5:
        return func_021BEC54((int)a, b);
    case 6:
        return (int)func_021BECB4(a, b);
    case 7:
        return func_021BED14((u32)a, b);
    case 8:
        return func_021BED74((int)a, b);
    case 9:
        return func_021BEDD4(a, b);
    }
}


int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g)
{
    switch (sel) {
    default:
        return (int)func_021BEBA8((int)a, b);
    case 0:
    case 1:
        return (int)func_021BEB38(a, b, sel, d, e);
    case 3:
        return (int)func_021BEBD8(a, b, f, g);
    case 5:
        return (int)func_021BEC84(a, b);
    case 6:
        return (int)func_021BECE4((int)a, b);
    case 7:
        return (int)func_021BED44((int)a, b);
    case 8:
        return func_021BEDA4((int)a, b);
    case 9:
        return func_021BEE24(a, b);
    }
}


/*
 * Allocator with callback, then link-node field setup with two byte fields and
 * two trailing stack arguments.
 */
void *func_021BE9A0(void *p, int a1, int a2, int a3, int a4, int a5)
{
    void *r0v = func_020122C0(p, 0, func_021BF0E4, 0x2C);
    int *r4 = func_020124E8(r0v);

    r4[0] = (int)p;
    r4[1] = a1;
    r4[2] = 3;
    ((u8 *)r4)[0x20] = a2;
    ((u8 *)r4)[0x21] = a3;
    r4[3] = (int)func_021BEA6C(r4[2]);
    r4[9] = a4;
    r4[10] = a5;
    return r0v;
}


/*
 * Allocator with callback, then link-node field setup; returns the allocator
 * result.
 */
void *func_021BE9F0(void *p, int a1, int a2, int a3, int a4)
{
    void *r0v = func_020122C0(p, 0, func_021BF518, 0x2C);
    int *r4 = func_020124E8(r0v);

    r4[0] = (int)p;
    r4[1] = a1;
    r4[2] = a2;
    r4[5] = a3;
    r4[3] = (int)func_021BEA6C(a2);
    r4[4] = a4;
    return r0v;
}


u32 func_021BEA30(u32 a, u32 b, u32 c, u32 d)
{
    int h = (int)func_020122C0((void *)a, 0, func_021BEE74, 0x2c);
    Ent *e = func_020124E8((struct Obj *)h);
    e->f0 = a;
    e->f4 = b;
    e->f8 = c;
    e->f14 = d;
    e->fC = func_021BEA6C(c);
    return h;
}

int func_021BEA6C(int x)
{
    switch (x) {
    case 0:
    default:
        return 3;
    case 1:
        return 12;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        return 2;
    }
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_021BEA9C(int row, int col)
{
    Table t = d_021D9F60;

    return t.v[row][col];
}


u32 func_021BEACC(int a, int b)
{
    Table t = d_021D9FF0;

    return t.v[a][b];
}


void *func_021BEAFC(int a, int b, int c, int d)
{
    void *t = func_020122C0((void *)a, 0, func_021BEE74, 0x2c);
    Work *w = func_020124E8(t);
    w->f0 = a;
    w->f4 = b;
    w->f8 = c;
    w->f14 = d;
    w->fC = func_021BEA6C(c);
    return t;
}


void *func_021BEB38(void *p, int a1, int a2, int a3, int a4)
{
    void *r0v = func_020122C0(p, 0, func_021BEEB4, 0x2C);
    int *r4 = func_020124E8(r0v);

    r4[0] = (int)p;
    r4[1] = a1;
    r4[2] = a2;
    r4[5] = a3;
    r4[3] = (int)func_021BEA6C(a2);
    r4[6] = a4;
    return r0v;
}

u32 func_021BEB78(u32 a, u32 b)
{
    u32 h = (u32)func_020122C0((void *)a, 0, func_021BEF08, 0x2c);
    X *x = func_020124E8((struct Obj *)h);
    x->f0 = a;
    x->f4 = b;
    x->f8 = 2;
    x->fC = func_021BEA6C(2);
    return h;
}

/*
 * file:     field_effect_p09.c
 * unit:     yes
 * function: func_021AACD4, func_021AAE34
 * address:  0x021AACD4
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
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_0218D168  0x0218D168  thumb  ov021
 *   func_0218DBD4  0x0218DBD4  thumb  ov021
 *   func_021AABF4  0x021AABF4  thumb  ov021
 *   func_0209BDBC  0x0209BDBC  arm
 *   func_0209C95C  0x0209C95C  arm
 *   func_0209CB8C  0x0209CB8C  arm
 *   func_0209C494  0x0209C494  arm
 *   func_0218DBAC  0x0218DBAC  thumb  ov021
 *   func_021AB504  0x021AB504  thumb  ov021
 *   func_02005728  0x02005728  thumb
 *   func_02012A38  0x02012A38  thumb
 *   func_021AAEC0  0x021AAEC0  thumb
 *   func_02188C9C  0x02188C9C  thumb
 *   func_021AABEC  0x021AABEC  thumb
 *   func_021AAFC0  0x021AAFC0  thumb
 */
struct Ctx;
struct BigObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16_021AACD4;

typedef signed int     s32;

typedef struct Vec { int x, y, z; } Vec;

struct Area {
    s16_021AACD4 x;
    s16_021AACD4 y;
    s16_021AACD4 mx;
    s16_021AACD4 my;
    s16_021AACD4 bx;
    s16_021AACD4 by;
    u16 ox;
    u16 oy;
    s16_021AACD4 x0;
    s16_021AACD4 y0;
    s16_021AACD4 x1;
    s16_021AACD4 y1;
};

struct Cell {
    u8 pad00[8];
    u32 f08;
    u32 f0C;
};

struct Spot {
    u8 kind;
    u8 pad01;
    s16_021AACD4 x;
    u8 pad04[2];
    u16 y;
    u32 f08;
};

struct Enc {
    u8 pad00[4];
    u16 count;
    u8 pad06[2];
    struct Spot spots[121];
};

typedef short s16_021AAE34;

typedef struct {
    u8 b0;
    u8 pad1;
    u16 h2;
    u16 h4;
    u16 h6;
    int f8;
} E;

typedef struct {
    int f0;
    u16 h4;
    u16 pad6;
    E e[1];
} R;

typedef struct {
    u16 h0;
    u16 h2;
    u16 h4;
    u16 h6;
    int f8;
    u8 bc;
    u8 lo : 4;
    u8 mid : 2;
    u8 hi : 2;
    u8 pad[2];
} Sub;

typedef struct {
    u8 pad[0x10];
    Sub sub;
} T;

typedef struct {
    int f0;
    int f4;
    int f8;
} S;

extern u32 func_02188C98(u8 *p);
extern void func_02082BCC(void *p, int v, int n);
extern int func_0218D168(char *p);
extern int func_0218DBD4(char *p, int i);
extern void func_021AABF4(struct Ctx *ctx, void *unused, struct Area *a);
extern int func_0209BDBC(int a);
extern int func_0209C95C(int a, int b);
extern int func_0209CB8C(int a, int b);
extern int func_0209C494(int a);
extern int func_0218DBAC(u8 *a, int idx, u32 c, u8 *d);
extern int func_021AB504(u32 attr);
extern u32 func_02005728(u32 n);
extern u32 func_02012A38(const struct BigObj *p);
extern int func_021AAEC0(S *s, s16_021AAE34 x, s16_021AAE34 y, s16_021AAE34 z, int w);
extern u16 func_02188C9C(u8 *p);
extern void func_021AABEC(u8 *p);
extern void func_021AAFC0(S *s, R *r, Sub *b);
void func_021AACD4(void **ctx, struct Enc *e);
void func_021AAE34(S *s, R *r);


/*
 * Addresses are Black-image addresses.
 */
void func_021AACD4(void **ctx, struct Enc *e)
{
    Vec v;
    struct Area a;
    struct Cell c;
    int idx;
    int xs;
    s16_021AACD4 y;
    s16_021AACD4 x;
    u32 m;
    int r;
    int k;

    m = func_02188C98(ctx[0]);
    func_02082BCC(&e->count, 0, 0x5B0);
    v.y = 0;
    idx = func_0218D168((char *)m);
    if (func_0218DBD4((char *)m, idx) == 0)
        return;
    func_021AABF4((struct Ctx *)ctx, e, &a);
    y = a.y0;
    if ((y << 4) > 0)
        r = func_0209C95C(0x3f000000, func_0209BDBC(y << 16));
    else
        r = func_0209CB8C(func_0209BDBC(y << 16), 0x3f000000);
    v.z = func_0209C494(r) + 0x8000;
    if ((a.x0 << 4) > 0)
        r = func_0209C95C(0x3f000000, func_0209BDBC(a.x0 << 16));
    else
        r = func_0209CB8C(func_0209BDBC(a.x0 << 16), 0x3f000000);
    xs = func_0209C494(r) + 0x8000;
    for (; y <= a.y1; y++) {
        v.x = xs;
        for (x = a.x0; x <= a.x1; x++) {
            func_0218DBAC((u8 *)m, idx, (u32)(&v), (u8 *)(&c));
            k = func_021AB504(c.f08);
            if (k != 8) {
                e->spots[e->count].kind = k;
                e->spots[e->count].x = x;
                e->spots[e->count].y = y;
                e->spots[e->count++].f08 = c.f0C;
            }
            v.x += 0x10000;
        }
        v.z += 0x10000;
    }
}


void func_021AAE34(S *s, R *r)
{
    u16 k = func_02005728(r->h4);
    E *e = &r->e[k];
    T *t = (T *)func_02012A38((const struct BigObj *)s->f8);
    Sub *b = &t->sub;
    e->h4 = (e->f8 >> 4) / 0x1000;
    if (func_021AAEC0(s, e->h2, e->h4, e->h6, 0) == 0) {
        b->h2 = e->h2;
        b->h4 = e->h4;
        b->h6 = e->h6;
        b->f8 = e->f8;
        b->bc = e->b0;
        b->h0 = func_02188C9C((u8 *)s->f0);
        b->lo = 1;
        func_021AABEC((u8 *)t);
        func_021AAFC0(s, r, b);
    }
}

/*
 * function: func_021AACD4
 * address:  0x021AACD4
 * packet:   pkt_ov021_021AACD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct Vec { int x, y, z; } Vec;

struct Area {
    s16 x;
    s16 y;
    s16 mx;
    s16 my;
    s16 bx;
    s16 by;
    u16 ox;
    u16 oy;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
};

struct Cell {
    u8 pad00[8];
    u32 f08;
    u32 f0C;
};

struct Spot {
    u8 kind;
    u8 pad01;
    s16 x;
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

extern u32 func_02188C98(void *p);
extern void func_02082BCC(void *p, int v, int n);
extern int func_0218D168(u32 m);
extern int func_0218DBD4(u32 m, int i);
extern void func_021AABF4(void *ctx, struct Enc *e, struct Area *a);
extern int func_0209BDBC(int a);
extern int func_0209C95C(int a, int b);
extern int func_0209CB8C(int a, int b);
extern int func_0209C494(int a);
extern int func_0218DBAC(u32 m, int i, Vec *v, struct Cell *c);
extern int func_021AB504(u32 attr);

void func_021AACD4(void **ctx, struct Enc *e)
{
    Vec v;
    struct Area a;
    struct Cell c;
    int idx;
    int xs;
    s16 y;
    s16 x;
    u32 m;
    int r;
    int k;

    m = func_02188C98(ctx[0]);
    func_02082BCC(&e->count, 0, 0x5B0);
    v.y = 0;
    idx = func_0218D168(m);
    if (func_0218DBD4(m, idx) == 0)
        return;
    func_021AABF4(ctx, e, &a);
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
            func_0218DBAC(m, idx, &v, &c);
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

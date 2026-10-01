/*
 * function: func_021AAE34
 * address:  0x021AAE34
 * packet:   pkt_ov021_021AAE34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005728  0x02005728  thumb
 *   func_02012A38  0x02012A38  thumb
 *   func_021AAEC0  0x021AAEC0  thumb
 *   func_02188C9C  0x02188C9C  thumb
 *   func_021AABEC  0x021AABEC  thumb
 *   func_021AAFC0  0x021AAFC0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

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

extern u32 func_02005728(u32 n);
extern T *func_02012A38(int a);
extern int func_021AAEC0(S *s, s16 x, s16 y, s16 z, int w);
extern u16 func_02188C9C(int a);
extern void func_021AABEC(T *t);
extern void func_021AAFC0(S *s, R *r, Sub *b);

void func_021AAE34(S *s, R *r)
{
    u16 k = func_02005728(r->h4);
    E *e = &r->e[k];
    T *t = func_02012A38(s->f8);
    Sub *b = &t->sub;
    e->h4 = (e->f8 >> 4) / 0x1000;
    if (func_021AAEC0(s, e->h2, e->h4, e->h6, 0) == 0) {
        b->h2 = e->h2;
        b->h4 = e->h4;
        b->h6 = e->h6;
        b->f8 = e->f8;
        b->bc = e->b0;
        b->h0 = func_02188C9C(s->f0);
        b->lo = 1;
        func_021AABEC(t);
        func_021AAFC0(s, r, b);
    }
}

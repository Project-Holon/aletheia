/*
 * file:     unit_021D7E44.c
 * unit:     yes
 * function: func_021D7E44, func_021D7E90, func_021D7EB4, func_021D7EF0, func_021D7F00, func_021D7F2C, func_021D7F38, func_021D7F4C, func_021D7F60, func_021D7F88, func_021D7FBC, func_021D7FF8, func_021D804C, func_021D8058, func_021D805C, func_021D806C, func_021D8090, func_021D80A8, func_021D80BC
 * address:  0x021D7E44
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   data_021F6360  0x021F6360  data  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_02019C90  0x02019C90  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0202A3FC 0x0202A3FC thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_0202A230 0x0202A230 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   d_021F042D     0x021F042D  data  ov093  a1
 *   func_02020FE4 0x02020FE4 thumb
 *   func_021D5814  0x021D5814  thumb  ov093
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   sub_0201BD28   0x0201BD28  thumb
 *   sub_0201BEB8   0x0201BEB8  thumb
 *   func_021B8C50  0x021B8C50  thumb  ov093
 *   func_021B8D38  0x021B8D38  thumb  ov093
 *   func_021B8778  0x021B8778  thumb  ov093
 */
#include "../../matched/include/G_Unk021F6360.h"
#include "../../matched/include/Obj03204.h"

struct QF;
struct Q1;
struct S2;
struct Unk021B8CB0;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

u32 func_021D78AC(u32 range);
u16 func_021D5444(struct QF *p);
extern int func_021D59B4(u8 *p, int k);
u32 func_02019C90(u16 a, u16 b, u32 k);
extern u8 func_0202A3FC(u32);
extern u32 func_0201AA18(void *);
extern void *func_0201AB28(void *,u32);
extern u32 func_0202A230(void *,u32);
extern u32 func_02017E1C(void *,u32,u32);
u8 func_021B9B94(struct Q1 *p);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern u32 func_02020FE4(void *,u32,u32);
extern int func_021D5814(void *p, int k);
extern u32 func_021B8588(void **p);
extern u8 func_021D5440(u8 *p);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern u32 sub_0201BD28(u16 id, u32 field);
extern u32 sub_0201BEB8(u16 id, u32 bit);
extern u8 func_021B8C50(char **p, u32 v, int k);
extern u8 func_021B8D38(void *p, int a, int k, u8 *out);
extern u8 func_021B8778(struct Unk021B8CB0 **p, int k, u8 *out);
u16 func_021D7E44(int a, int b);
int func_021D7E90(const u16 *p,u32 n,u32 v);
u32 func_021D7EB4(void *a);
u32 func_021D7EF0(u32 mode);
u32 func_021D7F00(u32 n);
u8 func_021D7F2C(u32 a, u8 b);
int func_021D7F38(u32 n);
int func_021D7F4C(u32 n);
int func_021D7F60(u32 n);
u32 func_021D7F88(u8 *p);
u32 func_021D7FBC(void **p,void *q);
u32 func_021D7FF8(u32 a, void *b);
void func_021D804C(u32 n);
void func_021D8058(void);
u32 func_021D805C(void *p,u32 n);
u32 func_021D806C(const u8 *p);
void func_021D8090(u32 v,u8 *p);
int func_021D80A8(void *p);
int func_021D80BC(void *p, int a, int m, u16 move);
extern struct Unk021F6360 data_021F6360;
extern u8 d_021F042D[];


u16 func_021D7E44(int a, int b)
{
    u16 i;
    u16 n = 0;

    for (i = 1; i < 0x230; i++) {
        if (func_021D7E90((const u16 *)a, b, i) == 0)
            ((u16 *)data_021F6360.tbl)[n++] = i;
    }
    return ((u16 *)data_021F6360.tbl)[(u16)func_021D78AC(n)];
}

int func_021D7E90(const u16 *p,u32 n,u32 v) { u32 i; for(i=0;i<n;i++) { if(v==p[i]) return 1; } return 0; }


u32 func_021D7EB4(void *a)
{
    int s = func_021D5444(a);
    u16 x = func_021D59B4(a, 0x13);
    u16 y = func_021D59B4(a, 0xf);
    u32 v = func_02019C90(s, x, 9);
    return (v * y) / 5;
}

/*
 * lever: nonzero/non-3 conjunction puts return 1 before the return 0 arm.
 * leaf: only-blocker of ov093 021CEA94; parent expanded scope.
 * semantics: original compares full-word r0 with 0 and 3; no arithmetic,
 * domain bounds, narrowed input, uninitialized values or side effects.
 */
u32 func_021D7EF0(u32 mode)
{
    if (mode != 0 && mode != 3) return 1;
    return 0;
}

u32 func_021D7F00(u32 n) { switch(n) { case 0:return 1; case 1:return 2; case 2:return 3; case 3:return 1; default:return 1; } }


u8 func_021D7F2C(u32 a, u8 b)
{
    if (a == 3)
        b = 3;
    return b;
}

int func_021D7F38(u32 n) { if(func_0202A3FC(n)==2) return 1; return 0; }

int func_021D7F4C(u32 n) { if(func_0202A3FC(n)==3) return 1; return 0; }

int func_021D7F60(u32 n) { if(func_021D7F38(n)) return 1; if(func_021D7F4C(n)) return 1; return n==89; }

u32 func_021D7F88(u8 *p) { u32 n=0; if(((struct Obj03204 *)p)->f0==1) { if(((struct Obj03204 *)p)->f4C && ((struct Obj03204 *)p)->f28) n+=func_021D7FBC(((struct Obj03204 *)p)->f4C,((struct Obj03204 *)p)->f28); if(((struct Obj03204 *)p)->f54 && ((struct Obj03204 *)p)->f30) n+=func_021D7FBC(((struct Obj03204 *)p)->f54,((struct Obj03204 *)p)->f30); } return n; }

u32 func_021D7FBC(void **p,void *q) { u8 n; void *e; u32 v; if(q) { n=(u8)func_0201AA18(q); if(n) { e=func_0201AB28(q,n-1); v=func_0202A230(*p,10); return v*func_02017E1C(e,158,0)*4; } } return 0; }


u32 func_021D7FF8(u32 a, void *b)
{
    u32 n = func_021B9B94(b);
    u32 m = 1;
    u32 i;
    u32 v;

    for (i = 0; i < n; i++) {
        v = func_021D59B4(func_021B9C00(b, (u8)i), 0xf);
        if (v > m)
            m = v;
    }
    if (a >= 9)
        a = 8;
    return d_021F042D[a] * (m << 2);
}

void func_021D804C(u32 n) { (*(u16 *)&data_021F6360)=n; }

void func_021D8058(void) { }

u32 func_021D805C(void *p,u32 n) { return func_02020FE4(p,n,(*(u16 *)&data_021F6360)); }

u32 func_021D806C(const u8 *p) { u32 v=0; u32 i; for(i=0;i<6;i++) v|=(p[i]&31)<<(i*5); return v; }

void func_021D8090(u32 v,u8 *p) { u32 i; for(i=0;i<6;i++) { p[i]=v&31; v>>=5; } }


int func_021D80A8(void *p)
{
    int r = 7;
    if (func_021D5814(p, 7)) r = 0;
    return r;
}


int func_021D80BC(void *p, int a, int m, u16 move)
{
    u32 mode;
    int t;
    u32 kind;
    u8 b;
    u8 buf[8];
    u8 n;

    mode = func_021B8588(p);
    t = func_021B8D8C(p, (void *)a, func_021D5440((u8 *)m));
    kind = sub_0201BD28(move, 0x1B);
    if (move == 0xAE) kind = func_021D80A8((void *)m);

    if (mode == 0) {
        switch (kind) {
        case 0:
        case 3:
        case 4:
        case 5:
        case 9:
            return func_021B8C50(p, t, 0);
        case 1:
        case 7:
            return t;
        case 13:
        default:
            return 6;
        }
    }

    b = 0;
    if (mode == 2) b = sub_0201BEB8(move, 0xB);

    switch (kind) {
    case 0:
    case 3:
    case 9:
        if (b) t = (u16)(t | (6 << 8));
        else t = (u16)(t | (1 << 8));
        break;
    case 1:
        t = (u16)(t | (3 << 8));
        break;
    case 2:
        if (b) t = (u16)(t | (7 << 8));
        else t = (u16)(t | (4 << 8));
        break;
    case 7:
        return t;
    default:
        return 6;
    }

    n = func_021B8D38(p, a, t, buf);
    if (n) {
        n = func_021D78AC(n);
        return func_021B8D8C(p, (void *)a, buf[n]);
    }
    n = func_021B8778(p, t, buf);
    if (n) return buf[(u8)func_021D78AC(n)];
    return 6;
}

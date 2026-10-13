/*
 * file:     unit_0689D1FC.c
 * unit:     yes
 * function: func_0689D1FC, func_0689D258
 * address:  0x0689D1FC
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B8640  0x021B8640  thumb
 *   func_021B8E28  0x021B8E28  thumb
 *   func_021B9920  0x021B9920  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
} Rec;

typedef struct {
    Rec r[6];
    u8 idx[6];
} T;

extern u32 func_021B8640(int);
extern void func_021B8E28(int, int, u8 *, u8 *);
extern int func_021B9920(int, int, int);
extern int BTL_POKEPARAM_IsFainted(int);
extern int BTL_POKEPARAM_GetPokeId(int);
void func_0689D1FC(T *a, int b, int c);
void func_0689D258(T *a, int b, int c, u8 d);


void func_0689D1FC(T *a, int b, int c)
{
    u32 i;
    u32 n;

    for (i = 0; i < 6; i++) {
        a->r[i].a = 0;
        a->r[i].c = 0x1f;
    }
    for (i = 0; i < 6; i++)
        a->idx[i] = 6;
    n = func_021B8640(b);
    for (i = 0; i <= n; i++)
        func_0689D258(a, b, c, i);
}


void func_0689D258(T *a, int b, int c, u8 d)
{
    u8 o1;
    u8 o0;
    int x;
    int y;

    func_021B8E28(b, d, &o1, &o0);
    x = func_021B9920(c, o1, o0);
    if (x != 0 && BTL_POKEPARAM_IsFainted(x) == 0) {
        y = BTL_POKEPARAM_GetPokeId(x);
        a->r[d].c = y;
        a->idx[y] = d;
    } else {
        a->r[d].c = 0x1f;
    }
    a->r[d].b = o1;
    a->r[d].a = 1;
}

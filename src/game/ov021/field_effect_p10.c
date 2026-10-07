/*
 * file:     field_effect_p10.c
 * unit:     yes
 * function: func_021A9828, func_021A996C
 * address:  0x021A9828
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
 *   func_021A9DC8  0x021A9DC8  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Sel {
    void *f00;
    void *f04;
    int f08;
    int f0C;
    u8 pad10[5];
    u8 f15;
    u16 f16;
    u16 f18;
    u8 f1A;
    u8 f1B;
    u8 f1C;
    u8 f1D;
    u8 f1E;
    u8 pad1F;
    u32 f20;
    void *f24;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
    u32 b9 : 1;
    u32 b10 : 1;
    u32 b11 : 1;
    u32 b12 : 1;
    u32 b13 : 1;
    u32 b14 : 1;
    u32 b15 : 1;
};

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct Unit {
    u8 pad00[0x18];
    u16 f18;
    u8 pad1A[4];
    u8 f1E;
    u8 pad1F[9];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 2;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
    u32 b9 : 6;
    u32 b15 : 1;
};

extern u32 func_021A9DC8(void);
void func_021A9828(struct Sel *s, u16 d);
int func_021A996C(struct Unit *u, u8 n);


/*
 * Addresses are Black-image addresses.
 */
void func_021A9828(struct Sel *s, u16 d)
{
    switch (s->f1B) {
    case 0x23:
    case 0x47:
    case 0x63:
        s->b6 = 1;
        return;
    case 0x01:
    case 0x49:
    case 0x5F:
        s->b7 = 1;
        return;
    case 0x08:
        if (d == 3 || d == 12)
            s->b7 = 1;
        return;
    case 0x51:
        if (d == 1 || d == 4 || d == 5)
            s->b7 = 1;
        return;
    case 0x15:
    case 0x3C:
        if (s->b1)
            s->b8 = 1;
        return;
    case 0x0E:
        s->b9 = 1;
        return;
    }
    if (s->f1B == 0x38 && func_021A9DC8() < 0x43) {
        s->b11 = 1;
        return;
    }
    if (func_021A9DC8() < 0x32)
        return;
    switch (s->f1B) {
    case 0x2A:
        s->b12 = 1;
        return;
    case 0x09:
        s->b13 = 1;
        return;
    case 0x2E:
    case 0x37:
    case 0x48:
        s->b14 = 1;
        return;
    case 0x16:
    case 0x33:
        s->b15 = 1;
        return;
    case 0x1C:
        s->b10 = 1;
        return;
    }
}


int func_021A996C(struct Unit *u, u8 n)
{
    if (u->b3)
        return 0;
    if (u->b15 && u->f1E >= n + 5)
        return 1;
    if (!u->b1 && u->b2 && n < u->f1E)
        return 1;
    return 0;
}

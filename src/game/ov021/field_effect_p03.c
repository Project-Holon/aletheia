/*
 * file:     field_effect_p03.c
 * unit:     yes
 * function: func_021A8D40, func_021A8DD8, func_021A8E10, func_021A8E20
 * address:  0x021A8D40
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
 *   func_0203F684  0x0203F684  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_02040618  0x02040618  arm
 *   func_0204B09C  0x0204B09C  arm
 *   func_021A9080  0x021A9080  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

struct W_021A8D40 {
    u8 pad00[0x134];
    u32 f134;
};

typedef short s16;

typedef struct {
    s16 x;
    s16 y;
} P;

typedef struct {
    char pad0[0xfc];
    s16 hfc;
    char pad2[0x120 - 0xfe];
    int f120;
} S_021A8DD8;

typedef struct {
    int pad[2];
    int f8;
} T;

typedef struct {
    char pad[0xf8];
    T *pf8;
} S_021A8E10;

struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 pad0C[8];
    u8 f14;
    u8 f15;
    u8 pad16[2];
    void *f18;
};

struct W_021A8E20 {
    u8 pad00[0x1E];
    u8 f1E;
    u8 f1F;
    u8 pad20[4];
    u32 f24;
    u8 pad28[0xC];
    struct Slot slots[7];
};

extern short func_0203F684(unsigned short x);
extern void func_0207E5D0(void *src, u32 off, u32 n);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0204B09C(int a, int b, P *c);
extern void func_021A9080(struct W_021A8E20 *w, u32 a, u32 b);
void func_021A8D40(void *unused, struct W_021A8D40 *w);
void func_021A8DD8(S_021A8DD8 *s);
int func_021A8E10(S_021A8E10 *s);
void func_021A8E20(struct W_021A8E20 *w, u32 v);


/*
 * Addresses are Black-image addresses.
 */
void func_021A8D40(void *unused, struct W_021A8D40 *w)
{
    s32 t = func_0203F684((u16)w->f134) + 0x1000;
    u16 c[2];

    c[1] = (t * 8 / 0x2000 + 9) | ((0x1F << 10) | ((t * 5 / 0x2000 + 0x12) << 5));
    func_0207E5D0(&c[1], 0x142, 2);
    c[0] = (t * 0x1F / 0x2000) |
           (((t * 6 / 0x2000 + 0x19) << 10) | ((t * 13 / 0x2000 + 0x12) << 5));
    func_0207E5D0(&c[0], 0x15E, 2);
    w->f134 += 6;
}


void func_021A8DD8(S_021A8DD8 *s)
{
    P v;
    s->hfc = 0xc0;
    func_02040618(5, 3, -0xc0);
    func_02040618(6, 3, -0xc5);
    v.x = 0;
    v.y = 0xc0;
    func_0204B09C(s->f120, 0, &v);
}


int func_021A8E10(S_021A8E10 *s)
{
    T *p = s->pf8;
    if (p == 0) {
        return 0;
    }
    return p->f8;
}


void func_021A8E20(struct W_021A8E20 *w, u32 v)
{
    u8 i;
    struct Slot *s;

    for (i = 0, s = w->slots; i < 7; i++) {
        if (w->slots[i].f00 == 1 && v == w->slots[i].f08) {
            w->f1E = i % 2;
            w->f1F = i / 2;
            w->f24 = 1;
            func_021A9080(w, s[w->f1E + w->f1F * 2].f14,
                          s[w->f1E + w->f1F * 2].f15);
        }
    }
}

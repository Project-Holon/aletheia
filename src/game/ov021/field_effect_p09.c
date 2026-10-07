/*
 * file:     field_effect_p09.c
 * unit:     yes
 * function: func_021A9604, func_021A96B8, func_021A9780, func_021A9810
 * address:  0x021A9604
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
 *   func_0219390C  0x0219390C  thumb  ov021
 *   func_02193C00  0x02193C00  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_021A9CAC  0x021A9CAC  thumb
 *   func_021A9D30  0x021A9D30  thumb
 *   func_0200D4B8  0x0200D4B8  thumb
 *   func_021A99A8  0x021A99A8  thumb
 */
struct Mon;
struct Sub0200852CObj;
struct GdsEnt;
struct Entry8;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Sel {
    u8 pad00[8];
    int f08;
};

struct Out {
    u16 f00;
    u16 f02;
    u8 f04;
    u8 f05;
    u8 f06;
    u8 f07;
};

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef unsigned long long u64;

struct Unit_021A96B8 {
    u8 pad00[8];
    int f08;
    u8 pad0C[0x11];
    u8 f1D;
    u8 pad1E[2];
    u32 f20;
    void *f24;
    u32 b0 : 9;
    u32 b9 : 1;
    u32 b10 : 1;
};

struct Slot14 { u16 f00; u16 f02; u8 f04; u8 f05; u8 f06; u8 f07; };

struct Unit_021A9780 {
    u8 pad00[0x20];
    u32 f20;
};

extern void *func_0219390C(void *a, u32 b);
extern u8 *func_02193C00(int a);
extern u32 func_020056EC(u32 v);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_0201ADE4(unsigned int a, int b, unsigned int c);
extern u32 func_021A9D30(struct Unit_021A96B8 *u, void *src, struct Slot14 *s);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void func_02018A00(void *p, u32 a, u32 b);
extern void func_021A9CAC(void *mon, void *src, int a, int b);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern const void *func_020084F4(const void *p);
extern void func_020185C4(void *p);
extern void func_0201AE14(void *p);
extern u32 func_0200D4B8(const struct GdsEnt *e, u32 i);
extern const struct Entry8 *func_021A99A8(void *p);
u32 func_021A9604(int obj, struct Sel *sel, struct Out *out);
void func_021A96B8(void *mon, const struct Unit_021A96B8 *u, struct Slot14 *s);
void func_021A9780(void *mon, const struct Unit_021A9780 *u, void *src);
u16 func_021A9810(int a);


/*
 * Addresses are Black-image addresses.
 */
u32 func_021A9604(int obj, struct Sel *sel, struct Out *out)
{
    u32 k;
    u32 sum;
    u32 r;
    int i;
    u8 *q;
    int p;

    switch (sel->f08) {
    case 0:
        k = 0;
        break;
    case 1:
        k = 1;
        break;
    case 3:
        k = 2;
        break;
    case 0xFF:
        return 0;
    }
    sum = 0;
    for (i = 0; i < 30; i++) {
        p = (int)func_0219390C((void *)obj, i);
        if (p) {
            sum += func_02193C00(p)[k + 0x14];
        }
    }
    r = func_020056EC(sum);
    sum = 0;
    for (i = 0; i < 30; i++) {
        p = (int)func_0219390C((void *)obj, i);
        if (p) {
            q = func_02193C00(p);
            sum += q[k + 0x14];
            if (r < sum) {
                func_02082BCC(out, 0, 0x14);
                out->f00 = ((u16 *)(q + 8))[k];
                out->f04 = (q + k)[0x10];
                return 1;
            }
        }
    }
    return 0;
}


void func_021A96B8(void *mon, const struct Unit_021A96B8 *u, struct Slot14 *s)
{
    void *pd = func_0201ADE4(s->f00, s->f05, 4);
    u32 pid = func_021A9D30((struct Unit_021A96B8 *)u, pd, s);

    func_02017588(mon, s->f00, s->f04, u->f20, 0xFFFFFFFF, pid);
    func_02017E40(mon, 0x6F, s->f05);
    if (s->f07)
        func_02018A00(mon, s->f00, s->f05);
    if (s->f02 <= 0x272) {
        if (s->f02 != 0)
            func_02017E40(mon, 6, s->f02);
        else
            func_021A9CAC(mon, pd, u->b9, u->f08 == 1);
    }
    func_02017E40(mon, 0x9A, func_02008550(u->f24));
    func_02017E40(mon, 0x8E, (u32)func_020084F4(u->f24));
    if (u->b10)
        func_02017E40(mon, 0x70, u->f1D);
    func_020185C4(mon);
    func_0201AE14(pd);
}


/*
 * Addresses are Black-image addresses.
 *
 * Lever: `const struct Unit *u` settles the argument scheduling before the
 * func_02017588 call (as in ov021_func_021A96B8.c).
 */
void func_021A9780(void *mon, const struct Unit_021A9780 *u, void *src)
{
    u16 species = func_0200D4B8(src, 4);
    u8 level = func_0200D4B8(src, 6);
    u32 pow = func_0200D4B8(src, 2);

    func_02017588(mon, species, level, u->f20, pow, func_0200D4B8(src, 3));
    func_02017E40(mon, 0x70, func_0200D4B8(src, 10));
    func_02017E40(mon, 0x9D, func_0200D4B8(src, 7));
    func_02017E40(mon, 0xA0, func_0200D4B8(src, 5));
    func_020185C4(mon);
}


u16 func_021A9810(int a)
{
    u16 *p = (u16 *)func_021A99A8((void *)a);
    if (p == 0) {
        return 0xffff;
    }
    return *p;
}

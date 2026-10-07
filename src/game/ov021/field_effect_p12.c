/*
 * file:     field_effect_p12.c
 * unit:     yes
 * function: func_021A9C58, func_021A9CAC, func_021A9D30, func_021A9DC8, func_021A9DE0, func_021A9E64, func_021A9E98, func_021A9EC4
 * address:  0x021A9C58
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
 *   data_021D8DD8  0x021D8DD8  data
 *   func_021A9B00  0x021A9B00  thumb
 *   func_021A9B68  0x021A9B68  thumb
 *   func_021A9BE8  0x021A9BE8  thumb
 *   data_021D8DCC  0x021D8DCC  data
 *   func_02017E40  0x02017E40  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_020186C8  0x020186C8  thumb
 *   func_0201AF6C  0x0201AF6C  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_0209C2B0  0x0209C2B0  arm
 *   _u32_div_f  0x0209C2B0  arm
 */
struct Slot14;
struct Personal;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct Spec { u16 id : 11; u16 lvl : 5; u8 lo; u8 hi; };

struct Unit_021A9C58 {
    u8 pad00[0x10];
    u32 f10;
    u8 f14;
    u8 pad15[0x13];
    u32 b0 : 12;
    u32 b12 : 1;
    u32 b13 : 1;
};

struct Unit_021A9D30 {
    u8 pad00[0x1C];
    u8 f1C;
    u8 pad1D[3];
    u32 f20;
    u8 pad24[4];
    u32 b0 : 11;
    u32 b11 : 1;
};

struct Slot14 { u16 f00; u8 pad02[3]; u8 f05; u8 f06; u8 pad07[9]; u8 f10; };

extern u8 func_021A9B68(u8 *u, struct Spec *specs, u32 type);
extern void func_021A9B00(struct Spec *spec, struct Slot14 *s);
extern void func_021A9BE8(const struct Unit_021A9C58 *u, const struct Spec *specs, struct Slot14 *s);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_0201AF6C(u32 v);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern u32 func_020056EC(u32 v);
extern u32 func_0209C2B0(u32 a, u32 b);
void func_021A9C58(struct Unit_021A9C58 *u, struct Spec *specs, struct Slot14 *s);
void func_021A9CAC(void *mon, void *src, int a, int b);
u32 func_021A9D30(struct Unit_021A9D30 *u, void *src, struct Slot14 *s);
u32 func_021A9DC8(void);
u32 func_021A9DE0(void);
int func_021A9E64(int a);
int func_021A9E98(int a);
u32 func_021A9EC4(u32 a);
extern const u8 data_021D8DCC[];

extern u32 (*const data_021D8DD8[])(u8 n);


/*
 * Addresses are Black-image addresses.
 */
void func_021A9C58(struct Unit_021A9C58 *u, struct Spec *specs, struct Slot14 *s)
{
    u8 idx = 0xFF;

    if (u->b12)
        idx = func_021A9B68((u8 *)u, specs, 8);
    else if (u->b13)
        idx = func_021A9B68((u8 *)u, specs, 12);
    if (idx == 0xFF)
        idx = data_021D8DD8[u->f10](u->f14);
    func_021A9B00(&specs[idx], s);
    func_021A9BE8(u, specs, s);
}


void func_021A9CAC(void *mon, void *src, int a, int b)
{
    u16 vals[3];
    int i;
    const u8 *w;
    u8 r;
    u8 acc;

    for (i = 0; i < 3; i++)
        vals[i] = func_0201AE1C(src, 0x11 + i);
    if (vals[0] == vals[1]) {
        func_02017E40(mon, 6, vals[0]);
        return;
    }
    w = &data_021D8DCC[(a + b * 2) * 3];
    r = func_021A9DC8();
    acc = 0;
    for (i = 0; i < 3; i++) {
        acc += w[i];
        if (r < acc) {
            func_02017E40(mon, 6, vals[i]);
            return;
        }
    }
}


u32 func_021A9D30(struct Unit_021A9D30 *u, void *src, struct Slot14 *s)
{
    u32 gender = 2;
    u32 r;
    u32 x;

    if (func_0201AF6C((u8)func_0201AE1C(src, 0x14)) != 1) {
        if (u->b11) {
            if (u->f1C == 0)
                gender = 1;
            else if (u->f1C == 1)
                gender = 0;
        }
        if (s->f10 == 1)
            gender = 0;
        else if (s->f10 == 2)
            gender = 1;
    }
    r = func_020186C8(u->f20, s->f00, s->f05, gender, 2, s->f06 == 2 ? 0 : 2);
    if (s->f06 != 2) {
        x = (u16)r ^ ((u->f20 >> 16) ^ (u16)u->f20);
        if (x & 1)
            r |= 0x80000000;
        else
            r &= 0x7FFFFFFF;
    }
    return r;
}


u32 func_021A9DC8(void)
{
    return func_0209C2B0(func_020056EC(0xFFFF), 0x290);
}


u32 func_021A9DE0(void)
{
    u32 v = func_021A9DC8();

    if (v < 0x14) return 0;
    if (v >= 0x14 && v < 0x28) return 1;
    if (v >= 0x28 && v < 0x32) return 2;
    if (v >= 0x32 && v < 0x3C) return 3;
    if (v >= 0x3C && v < 0x46) return 4;
    if (v >= 0x46 && v < 0x50) return 5;
    if (v >= 0x50 && v < 0x55) return 6;
    if (v >= 0x55 && v < 0x5A) return 7;
    if (v >= 0x5A && v < 0x5E) return 8;
    if (v >= 0x5E && v < 0x62) return 9;
    if (v == 0x62) return 10;
    return 11;
}


int func_021A9E64(int a)
{
    u32 v = func_021A9DC8();
    if (v < 60) {
        return 0;
    }
    if (v >= 60 && v < 90) {
        return 1;
    }
    if (v >= 90 && v < 95) {
        return 2;
    }
    if (v >= 95 && v < 99) {
        return 3;
    }
    return 4;
}


int func_021A9E98(int a)
{
    u32 v = func_021A9DC8();
    if (v < 40) {
        return 0;
    }
    if (v < 80) {
        return 1;
    }
    if (v < 95) {
        return 2;
    }
    if (v < 99) {
        return 3;
    }
    return 4;
}


u32 func_021A9EC4(u32 a)
{
    return func_021A9DC8() % a;
}

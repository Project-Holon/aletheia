/*
 * file:     field_effect_p11.c
 * unit:     yes
 * function: func_021A9A5C, func_021A9B00, func_021A9B68, func_021A9BE8
 * address:  0x021A9A5C
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
 *   func_021A99E4  0x021A99E4  thumb
 *   func_02005728  0x02005728  thumb
 *   func_02019C90  0x02019C90  thumb
 *   func_021A9DC8  0x021A9DC8  thumb
 *   _u32_div_f  0x0209C2B0  arm
 */
struct Spec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct Unit_021A9A5C {
    void *f00;
    u8 pad04[4];
    int f08;
    u8 pad0C[4];
    u32 f10;
    u8 f14;
};

struct Slot14 { u16 f00; u8 pad02[2]; u8 f04; u8 f05; u8 pad06[0xE]; };

struct Spec { u16 id : 11; u16 lvl : 5; u8 lo; u8 hi; };

struct Unit_021A9BE8 {
    u8 pad00[0x14];
    u8 f14;
    u8 pad15[0x13];
    u32 b0 : 14;
    u32 b14 : 1;
};

extern int func_021A99E4(void *a0, struct Unit_021A9A5C *u, u16 id, struct Spec *spec);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern u32 func_021A9DC8(void);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern u32 func_02005728(u32 range);
u8 func_021A9A5C(u8 *a0, struct Unit_021A9A5C *u, u16 id, struct Spec *spec);
void func_021A9B00(struct Spec *spec, struct Slot14 *s);
u8 func_021A9B68(u8 *u, struct Spec *specs, u32 type);
void func_021A9BE8(const struct Unit_021A9BE8 *u, const struct Spec *specs, struct Slot14 *s);


/*
 * Addresses are Black-image addresses.
 *
 * Shape: n is a u8 (the return needs no truncation) and each case assigns
 * mode, then n, then src; that order keeps every case its own block with a
 * branch to the join and gives n r6, src r4.
 */
u8 func_021A9A5C(u8 *a0, struct Unit_021A9A5C *u, u16 id, struct Spec *spec)
{
    u8 n = 0;
    u32 mode = 0;
    u8 *src;

    if (func_021A99E4(a0, u, id, spec) != 0)
        return u->f14;
    if (u->f08 >= 7)
        u->f08 = 0;
    switch (u->f08) {
    case 0:
        n = 12;
        src = a0 + 0x08;
        break;
    case 1:
        n = 12;
        src = a0 + 0x38;
        break;
    case 2:
        n = 12;
        src = a0 + 0x68;
        break;
    case 3:
        mode = 1;
        n = 5;
        src = a0 + 0x98;
        break;
    case 4:
        mode = 1;
        n = 5;
        src = a0 + 0xAC;
        break;
    case 5:
        mode = 2;
        n = 5;
        src = a0 + 0xC0;
        break;
    case 6:
        mode = 2;
        n = 5;
        src = a0 + 0xD4;
        break;
    }
    u->f10 = mode;
    u->f14 = n;
    MI_CpuCopy8(src, spec, n * 4);
    return n;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A9B00(struct Spec *spec, struct Slot14 *s)
{
    s16 range = spec->hi - spec->lo;
    u8 cap;
    int lvl;
    u16 id;

    MI_CpuFill8(s, 0, 0x14);
    if (range < 0)
        range = 0;
    s->f04 = spec->lo + func_021A9DC8() % (u32)(range + 1);
    id = spec->id;
    s->f00 = id;
    cap = func_02019C90(id, 0, 0x20);
    lvl = spec->lvl;
    if (lvl == 0x1F)
        s->f05 = func_02005728(cap);
    else if (lvl >= cap)
        s->f05 = 0;
    else
        s->f05 = lvl;
}


u8 func_021A9B68(u8 *u, struct Spec *specs, u32 type)
{
    u8 buf[12];
    int i;
    int n;
    u8 t1, t2;

    n = 0;
    for (i = 0; i < u[0x14]; i++) {
        if (specs[i].lvl != 0x1F) {
            t1 = func_02019C90(specs[i].id, specs[i].lvl, 6);
            t2 = func_02019C90(specs[i].id, specs[i].lvl, 7);
            if (t1 == type || t2 == type) {
                buf[n] = i;
                n++;
            }
        }
    }
    if (n == 0)
        return 0xFF;
    return buf[func_021A9DC8() % n];
}


/*
 * Lever: `const` on both the unit and the spec-table pointers keeps the
 * per-iteration reload of u->f14 and the image colouring; declaration order
 * i, max, base, varied.
 */
void func_021A9BE8(const struct Unit_021A9BE8 *u, const struct Spec *specs, struct Slot14 *s)
{
    int i;
    u8 max;
    u8 base;
    int varied;

    max = s->f04;
    base = max;
    varied = 0;
    if (u->b14 == 0)
        return;
    for (i = 0; i < u->f14; i++) {
        if (varied == 0 && specs[i].lo != specs[i].hi)
            varied = 1;
        if (s->f00 == specs[i].id && max < specs[i].hi)
            max = specs[i].hi;
    }
    if (base + 5 <= max && varied == 1)
        s->f04 += 5;
    else
        s->f04 = max;
}

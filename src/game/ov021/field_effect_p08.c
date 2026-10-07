/*
 * file:     field_effect_p08.c
 * unit:     yes
 * function: func_021A94B0, func_021A9508, func_021A954C, func_021A957C
 * address:  0x021A94B0
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
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_02010FB0  0x02010FB0  thumb
 *   func_021A996C  0x021A996C  thumb
 *   func_021A9C58  0x021A9C58  thumb
 *   func_021A9A5C  0x021A9A5C  thumb
 *   MIi_CpuClear32  0x02082A7C  arm
 *   func_02005728  0x02005728  thumb
 *   func_0200D488  0x0200D488  thumb
 *   func_0200D4AC  0x0200D4AC  thumb
 *   func_0200D4B8  0x0200D4B8  thumb
 */
struct Spec;
struct Unit;
struct Slot14;
struct Blk38;
struct GdsEnt;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Obj {
    u8 pad00[0x18];
    u16 f18;
    u8 pad1A[0xE];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 4;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
};

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct Slot14 { u8 pad00[4]; u8 f04; u8 pad05[0xF]; };

struct Spec { u16 id : 11; u16 lvl : 5; u8 lo; u8 hi; };

struct Unit {
    void *f00;
    void *f04;
};

extern u32 func_0209C2B0(u32 a, u32 b);
extern u32 func_02010FB0(u32 v);
extern void func_021A9C58(struct Unit *u, struct Spec *specs, struct Slot14 *s);
extern int func_021A996C(struct Unit *u, u8 n);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern u8 func_021A9A5C(u8 *a0, struct Unit *u, u16 id, struct Spec *spec);
extern u8 func_0200D488(struct Blk38 *p, u32 i);
extern struct GdsEnt *func_0200D4AC(struct Blk38 *p, u32 i);
extern u32 func_0200D4B8(const struct GdsEnt *e, u32 i);
extern u32 func_02005728(u32 v);
u32 func_021A94B0(struct Obj *o, u32 unused, u32 n);
int func_021A9508(u8 *u, void *arg, struct Slot14 *slots);
int func_021A954C(void *a0, void *u, u16 id, void *slots);
void *func_021A957C(void *a0, struct Unit *u, u32 want);


/*
 * Addresses are Black-image addresses.
 */
u32 func_021A94B0(struct Obj *o, u32 unused, u32 n)
{
    u32 v = n;

    if (o->b1) {
        if (o->b8) {
            v = v * 2;
        }
        if (v > 100) {
            v = 100;
        }
        return v;
    }
    if (o->b6) {
        v = v * 2;
    } else if (o->b7) {
        v = v >> 1;
    }
    if (o->f18 == 0xE0 || o->f18 == 0x140) {
        v = func_0209C2B0(n * 2, 3);
    }
    if (v > 100) {
        v = 100;
    }
    return func_02010FB0(v);
}


int func_021A9508(u8 *u, void *arg, struct Slot14 *slots)
{
    int n = 0;
    int i;

    for (i = 0; i < u[0x15]; i++) {
        struct Slot14 *s = &slots[n];
        func_021A9C58((struct Unit *)u, arg, s);
        if (func_021A996C((struct Unit *)u, s->f04) == 0)
            n++;
    }
    return n;
}


int func_021A954C(void *a0, void *u, u16 id, void *slots)
{
    struct Spec specs[12];

    MIi_CpuClear32(0, specs, sizeof(specs));
    func_021A9A5C(a0, u, id, specs);
    return func_021A9508(u, specs, slots);
}


void *func_021A957C(void *a0, struct Unit *u, u32 want)
{
    void *buf[2];
    u8 n = 0;
    u8 i;
    void *m;

    for (i = 0; i < 2; i++) {
        if (func_0200D488(u->f04, i) == 0)
            continue;
        m = func_0200D4AC(u->f04, i);
        if (func_0200D4B8(m, 1) != want)
            continue;
        if (func_021A996C(u, func_0200D4B8(m, 6)) != 0)
            continue;
        buf[n++] = m;
    }
    if (n == 0 || func_02005728(1000) < 500)
        return 0;
    return buf[func_02005728(n)];
}

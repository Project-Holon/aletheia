/*
 * file:     ui_scene_p11.c
 * unit:     yes
 * function: func_021B7AB0, func_021B7B7C, func_021B7BE0
 * address:  0x021B7AB0
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02035CB8  0x02035CB8  arm
 *   func_021B806C  0x021B806C  thumb  ov067
 *   func_021B8460  0x021B8460  thumb  ov067
 *   func_021B8B74  0x021B8B74  thumb  ov067
 *   func_021B8C4C  0x021B8C4C  thumb  ov067
 *   func_020355C4  0x020355C4  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0202EA40  0x0202EA40  thumb
 *   func_021B9344  0x021B9344  thumb  ov067
 *   func_02041EE4  0x02041EE4  arm
 *   func_021B91D0  0x021B91D0  thumb  ov067
 *   func_021B9228  0x021B9228  thumb  ov067
 *   func_021B92F0  0x021B92F0  thumb  ov067
 */
struct Row;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct S_021B7AB0 {
    u8 pad00[0x30];
    void *f30;
    u8 pad34[0x4e - 0x34];
    u16 f4e;
    u8 pad50[0x54 - 0x50];
    int f54;
    int f58;
    s16 f5c;
    u8 pad5e[0x86 - 0x5e];
    u8 f86_lo : 5;
    u8 f86_b5 : 1;
    u8 f86_hi : 2;
    u8 pad87[0x96 - 0x87];
    u8 f96;
} S_021B7AB0;

typedef signed int     s32;

typedef struct S_021B7B7C {
    u8 pad00[0x18];
    u8 f18;
    u8 f19;
    u16 f1a;
    u8 pad1c[0x4c - 0x1c];
    u16 f4c;
    u8 pad4e[0x5c - 0x4e];
    u16 f5c;
    u16 f5e;
    u16 f60;
    u16 f62;
    u16 f64;
} S_021B7B7C;

typedef signed char s8;

struct Ops {
    void (*fn0)(void);
    void (*fn4)(void *a, int b, int c);
};

typedef struct S_021B7BE0 {
    u8 f0;
    u8 f1;
    u8 f2;
    s8 f3;
    u8 f4;
    u8 f5;
    u8 pad06[0x20 - 0x06];
    struct Ops *f20;
    void *f24;
    u8 pad28[0x46 - 0x28];
    s8 f46;
    s8 f47;
    s8 f48;
    s8 f49;
    u8 pad4a[0x5c - 0x4a];
    s16 f5c;
    u8 pad5e[0x62 - 0x5e];
    s16 f62;
    u8 pad64[0x66 - 0x64];
    s8 f66;
} S_021B7BE0;

extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern int func_021B806C(S_021B7AB0 *p);
extern int func_021B8460(S_021B7AB0 *p);
extern int func_021B8B74(S_021B7AB0 *p);
extern int func_021B8C4C(S_021B7AB0 *p);
extern u8 func_020355C4(void);
extern u32 func_020362DC(void);
extern s32 func_0202EA40(struct Row *p);
extern void func_021B9344(S_021B7AB0 *p);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_021B91D0(S_021B7BE0 *p, int i, int a2);
extern void func_021B9228(S_021B7BE0 *p, int i, int a2);
extern void func_021B92F0(struct S_021B7BE0 *p, u32 a1, u32 a2);
int func_021B7AB0(S_021B7AB0 *p);
void func_021B7B7C(S_021B7B7C *p);
void func_021B7BE0(S_021B7BE0 *p, int a1);


int func_021B7AB0(S_021B7AB0 *p)
{
    int buf;
    int ret = -1;

    if (func_02035CB8((u32 *)(&buf), (u32 *)(&p->f54)) == 0) {
        p->f54 = -1;
        p->f86_b5 = 0;
    }
    switch (p->f4e) {
    case 0:
        ret = func_021B806C(p);
        break;
    case 1:
        if (func_021B8460(p) == 1)
            ret = -10;
        break;
    case 2:
        if (func_021B8B74(p) == 1)
            ret = -9;
        break;
    case 3:
        if (func_021B8C4C(p) == 1)
            ret = -8;
        break;
    case 4:
        if (func_020355C4() == 0 && (func_020362DC() & 1))
            ret = p->f5c;
        if (p->f96 == 0)
            p->f4e = 0;
        else
            p->f96--;
        break;
    }
    p->f58 = p->f54;
    func_0202EA40(p->f30);
    func_021B9344(p);
    return ret;
}


void func_021B7B7C(S_021B7B7C *p)
{
    if (p->f19 > p->f4c) {
        p->f5e = p->f4c;
    } else {
        p->f5e = p->f19;
    }
    if (p->f4c < p->f19) {
        p->f64 = 0;
    } else {
        p->f64 = p->f4c - p->f19;
    }
    if (p->f18 > p->f5e || p->f1a > p->f64) {
        p->f5c = 0;
        p->f62 = 0;
    } else {
        p->f5c = p->f18;
        p->f62 = p->f1a;
    }
}


/*
 * f5 is a u8 read as (s8) in every loop step; the one uncast read in the
 * second window's start (`f3 + 0x18 - f5`) is what makes the original load
 * it with ldrb and sign-extend the CSE'd copy for the loop.  All four loops
 * are `for (;;) { if (!cond) break; ... }` (top test, unconditional b back).
 */
void func_021B7BE0(S_021B7BE0 *p, int a1)
{
    s16 i;
    s8 j;

    func_02041EE4(p->f0, 3, 0);
    p->f66 = 0;
    i = p->f62;
    j = p->f3;
    for (;;) {
        if (i == 0 || j <= 0)
            break;
        i = i - 1;
        j = j - (s8)p->f5;
    }
    p->f46 = 0;
    for (;;) {
        if (j >= 0x18)
            break;
        func_021B91D0(p, i, j);
        p->f46++;
        i = i + 1;
        j = j + (s8)p->f5;
    }
    p->f48 = p->f46;
    if (p->f1 == 0xff)
        return;
    func_02041EE4(p->f1, 3, 0);
    j = p->f3 + 0x18 - p->f5;
    i = p->f62 - 1;
    for (;;) {
        if (j <= 0)
            break;
        i = i - 1;
        j = j - (s8)p->f5;
    }
    p->f47 = 0;
    for (;;) {
        if (j >= 0x18)
            break;
        func_021B9228(p, i, j);
        p->f47++;
        i = i + 1;
        j = j + (s8)p->f5;
    }
    p->f49 = p->f47;
    func_021B92F0(p, (u16)p->f5c, 0xff);
    p->f20->fn4(p->f24, p->f5c + p->f62, a1);
}

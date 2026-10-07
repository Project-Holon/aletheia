/*
 * file:     btl_net_p19.c
 * unit:     yes
 * function: func_021D53C8, func_021D53DC, func_021D5440, func_021D5444, func_021D5448, func_021D5450, func_021D5478, func_021D54B4, func_021D54C0, func_021D54D0, func_021D54E0, func_021D54F4, func_021D5528
 * address:  0x021D53C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj18407.h"
#include "../../matched/include/Obj10048.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021D5444  ldrh r0,[r0,#0xc] */
struct QF { u8 pad[0xc]; u16 v; };

/* 021D5448  movs r1,#5; lsls r1,#6; ldrb r0,[r0,r1] */
struct QG { u8 pad[0x140]; u8 v; };

struct Ent_021D5450 {
    u16 h0;
    u8 pad2[9];
    u8 lo11:4;
    u8 hi11:4;
    u8 fC;
    u8 fD;
};

struct Work {
    u8 pad0[0x104];
    struct Ent_021D5450 e[4];
    u8 pad13C[4];
    u8 n140;
};

typedef struct { u16 a; u8 b; u8 c; u8 pad[10]; } Ent_021D54C0;

struct NB { u8 lo : 4; u8 hi : 4; };

struct Ent_021D54F4 {
    u16 h0;
    u16 h1;
    u16 h2;
    u16 h3;
    u8 b8;
    u8 b9;
    u16 hA;
    u8 fC;
    u8 fD;
};

void func_021D53C8(unsigned char *p);
int func_021D53DC(signed char *p);
/* 021D5440 ldrb r0,[r0,#0x19] */ u8 func_021D5440(u8 *p);
u16 func_021D5444(struct QF *p);
u8 func_021D5448(struct QG *p);
u8 func_021D5450(struct Work *p);
u8 func_021D5478(struct Work *p);
u8 func_021D54B4(u8 *p);
u16 func_021D54C0(u8 *p, int i);
u32 func_021D54D0(u8 *p, u8 i);
/* 021D54E0 the image extracts with lsls #0x1c / lsrs #0x1c, which is a 4-bit * unsigned bitfield read -- neither `& 0xf` nor the shift pair written out in * C reproduces it (both narrow to a mask). */ u32 func_021D54E0(u8 *p, u32 i);
void func_021D54F4(struct Work *src, struct Work *dst);
u16 func_021D5528(u8 *p, u8 i, u8 *a, u8 *b);

/*
 * Unlabelled ov093 leaf: writes 6 into the first seven bytes of its argument.
 * Matched to provide the `matched` witness for the two pending files that call
 * it (func_021D53C0, func_021D5F08).
 */
void func_021D53C8(unsigned char *p)
{
    p[0] = 6;
    p[1] = 6;
    p[2] = 6;
    p[3] = 6;
    p[4] = 6;
    p[5] = 6;
    p[6] = 6;
}

int func_021D53DC(signed char *p)
{
    int changed = 0;
    int i = 0;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    i = 1;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    i = 2;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    i = 3;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    i = 4;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    i = 5;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    i = 6;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    return changed;
}


/* 021D5440  ldrb r0,[r0,#0x19] */
/*
 * Reads the u8 field at #0x19 of the argument and returns it.
 */
u8 func_021D5440(u8 *p) { return p[0x19]; }

/*
 * Reads the u16 field at #0xc of the argument and returns it.
 */
u16 func_021D5444(struct QF *p) { return p->v; }

/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #5; lsls r1, r1, #6; ldrb r0, [r0, r1]; bx lr.
 */
u8 func_021D5448(struct QG *p) { return p->v; }


/*
 * volatile: 0x021D54A6 (n140 re-read as the loop bound of func_021D5478)
 */
u8 func_021D5450(struct Work *p)
{
    u32 n;
    u32 i;
    i = 0;
    n = 0;
    for (; i < 4; i++) {
        if (p->e[i].h0 == 0) break;
        n++;
    }
    return n;
}


u8 func_021D5478(struct Work *p)
{
    u8 n;
    u8 i;
    i = 0;
    n = 0;
    for (; i < *(volatile u8 *)&p->n140; i++) {
        if (p->e[i].lo11 != 0) n++;
    }
    return n;
}


/*
 * ldrb at #0x143 (pool constant)
 */
u8 func_021D54B4(u8 *p)
{
    return ((struct Obj18407 *)p)->f143;
}


/*
 * lever: the halfword is the first member of a 14-byte record in the array
 * at +0x10a; the image's `adds r2,#0xfc` is the constant 0x10a folded with
 * the stride, not a +0xa field.
 */
u16 func_021D54C0(u8 *p, int i)
{
    return ((Ent_021D54C0 *)(p + 0x10a))[i].a;
}

u32 func_021D54D0(u8 *p, u8 i) { return *(u16 *)((u32)p + i * 14 + 0x104); }

/* 021D54E0  the image extracts with lsls #0x1c / lsrs #0x1c, which is a 4-bit
 * unsigned bitfield read -- neither `& 0xf` nor the shift pair written out in
 * C reproduces it (both narrow to a mask). */
u32 func_021D54E0(u8 *p, u32 i)
{
    return ((struct NB *)(p + i * 0xe + 0x10f))->lo;
}


void func_021D54F4(struct Work *src, struct Work *dst)
{
    u32 i;
    for (i = 0; i < 4; i++) dst->e[i] = src->e[i];
    dst->n140 = src->n140;
}


u16 func_021D5528(u8 *p, u8 i, u8 *a, u8 *b)
{
    u8 *q = p + i * 14;
    *a = q[0x10c];
    *b = q[0x10d];
    return ((struct Obj10048 *)q)->f10A;
}

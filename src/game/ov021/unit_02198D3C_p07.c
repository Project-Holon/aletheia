/*
 * file:     unit_02198D3C_p07.c
 * unit:     yes
 * function: func_02199234, func_02199268, func_02199298, func_021992CC, func_021992FC, func_0219932C, func_02199360, func_02199394, func_021993C8, func_021993FC, func_02199430, func_02199460
 * address:  0x02199234
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
 *   func_0219912C  0x0219912C  thumb  ov021
 *   d_021D4B44     0x021D4B44  data  ov021  a4
 *   d_021D4204     0x021D4204  data  ov021  a4
 *   d_021D4C04     0x021D4C04  data  a4
 *   d_021D41E0     0x021D41E0  data  ov021  a4
 *   d_021D4210     0x021D4210  data  a4
 *   d_021D4C10     0x021D4C10  data  a4
 *   d_021D4648     0x021D4648  data  a4
 *   d_021D4BF8     0x021D4BF8  data  a4
 *   d_021D4BEC     0x021D4BEC  data  a4
 *   d_021D4BE0     0x021D4BE0  data  a4
 *   d_021D4BD4     0x021D4BD4  data  a4
 *   d_021D4BC8     0x021D4BC8  data  a4
 */
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec;

extern void func_0219912C(u32 a, Vec *b, u32 c, u32 d, u32 e, u8 f);
int func_02199234(u32 a);
int func_02199268(u32 a);
int func_02199298(u32 a);
int func_021992CC(u32 a);
int func_021992FC(u32 a);
int func_0219932C(u32 a);
int func_02199360(u32 a);
int func_02199394(u32 a);
int func_021993C8(u32 a);
int func_021993FC(u32 a);
int func_02199430(u32 a);
int func_02199460(u32 a);
extern const Vec d_021D4B44;
extern const Vec d_021D4204;
extern const Vec d_021D4C04;
extern const Vec d_021D41E0;
extern const Vec d_021D4210;
extern const Vec d_021D4C10;
extern const Vec d_021D4648;
extern const Vec d_021D4BF8;
extern const Vec d_021D4BEC;
extern const Vec d_021D4BE0;
extern const Vec d_021D4BD4;
extern const Vec d_021D4BC8;


/*
 * Addresses are Black-image addresses.
 */
int func_02199234(u32 a)
{
    Vec t = d_021D4B44;
    func_0219912C(a, &t, 2, 0, 8, 3);
    return 1;
}


int func_02199268(u32 a)
{
    Vec t = d_021D4204;
    func_0219912C(a, &t, 3, 1, 8, 3);
    return 1;
}


/*
 * Byte-correct (2026-10-01).  Sole blocker: the ABS32 pool word for the const
 * Vec initialiser is an ov021 data start that another overlay mapped over the
 * same window also starts an object at, so the symbols hint is contested and
 * no single-reference witness exists.  No C change needed to promote.
 *
 * 2026-10-01: the own-overlay data hint is dropped from symbols: so the
 *   own-window rule (code running in ov021 can only see ov021's bytes in its
 *   window) fixes the overlay; with the hint the tool refused it as contested.
 *
 * Addresses are Black-image addresses.
 */
int func_02199298(u32 a)
{
    Vec t = d_021D4C04;
    func_0219912C(a, &t, 1, 2, 8, 3);
    return 1;
}


int func_021992CC(u32 a)
{
    Vec t = d_021D41E0;
    func_0219912C(a, &t, 0, 3, 8, 3);
    return 1;
}


int func_021992FC(u32 a)
{
    Vec t = d_021D4210;
    func_0219912C(a, &t, 3, 0, 8, 3);
    return 1;
}


int func_0219932C(u32 a)
{
    Vec t = d_021D4C10;
    func_0219912C(a, &t, 2, 1, 8, 3);
    return 1;
}


int func_02199360(u32 a)
{
    Vec t = d_021D4648;
    func_0219912C(a, &t, 0, 2, 8, 3);
    return 1;
}


int func_02199394(u32 a)
{
    Vec t = d_021D4BF8;
    func_0219912C(a, &t, 1, 2, 8, 3);
    return 1;
}


int func_021993C8(u32 a)
{
    Vec t = d_021D4BEC;
    func_0219912C(a, &t, 1, 0, 8, 3);
    return 1;
}


int func_021993FC(u32 a)
{
    Vec t = d_021D4BE0;
    func_0219912C(a, &t, 0, 1, 8, 3);
    return 1;
}


int func_02199430(u32 a)
{
    Vec t = d_021D4BD4;
    func_0219912C(a, &t, 3, 2, 8, 3);
    return 1;
}


int func_02199460(u32 a)
{
    Vec t = d_021D4BC8;
    func_0219912C(a, &t, 2, 3, 8, 3);
    return 1;
}

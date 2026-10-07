/*
 * file:     zonedata_p07.c
 * unit:     yes
 * function: func_020140B4, func_020140BC, func_020140C0, func_020140CC, func_020140D8, func_020140DC, func_020140E0, func_020140E4, func_020140E8, func_020140F8, func_02014110
 * address:  0x020140B4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj00193.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Sub020140BCObj {
    u16 f00;
    u16 f02;
    u8  f04;
    u8  f05;
    u8  f06;
    u8  f07;
    u8  f08;
    u8  f09;
};

typedef struct {
    u32 x00;
    u16 x04, x06, x08, x0A;
    u32 x0C, x10, x14, x18;
} Rect14110;

extern u32 sub_020307B0(void *p);
u32 sub_020140B4(void *a);
u32 sub_020140E8(u32 x);
void func_020140F8(int p0);
void func_02014110(Rect14110 *p, u16 a, u16 b, u16 c, u16 d, u32 e, u32 f, u32 g);


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_020140D8, sub_020140DC, sub_020140E0, sub_020140E4
 *
 * alias: sub_020140B4 is a bare tail call to the ARM function
 * sub_020307B0: the compiler cannot tell caller and callee interwork, so
 * it always spends a pool word and `bx` rather than ever emitting a direct
 * branch (docs/idioms/tail-call-is-a-pool-word-and-bx.md), even though the
 * wrapper's own body is otherwise empty.
 *
 * sub_020140BC through sub_020140E4 are seven more leaf accessors on a
 * small object passed in directly (not through sub_02013AD0()), hiding in
 * the same way: none of the seven save `lr`, so disasm.py's prologue sweep
 * never labels them and they print as a run of `.word`s between two
 * literal pools (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * Two of them (offsets 0x04 and 0x05) return the sentinel 0xFFFFFFFF in
 * place of a stored byte value of 0xFF, rather than the plain
 * zero-extended byte every other accessor here returns.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020140B4.c \
 *       --addr 0x020140B4 --thumb
 */
u32 sub_020140B4(void *a)
{
    return sub_020307B0(a);
}


u16 sub_020140BC(struct Sub020140BCObj *p)
{
    return p->f02;
}

u32 sub_020140C0(struct Sub020140BCObj *p)
{
    if (p->f04 == 0xFF)
        return (u32)-1;
    return p->f04;
}

u32 sub_020140CC(struct Sub020140BCObj *p)
{
    if (p->f05 == 0xFF)
        return (u32)-1;
    return p->f05;
}

u8 sub_020140D8(struct Sub020140BCObj *p)
{
    return p->f06;
}

u8 sub_020140DC(struct Sub020140BCObj *p)
{
    return p->f07;
}

u8 sub_020140E0(struct Sub020140BCObj *p)
{
    return p->f08;
}

u8 sub_020140E4(struct Sub020140BCObj *p)
{
    return p->f09;
}


/*
 * A plain range test on the raw id, called by sub_0201407C
 * (unit_02013ED8.c is a sibling file, not this one; the call there is
 * attested by this function's own definition living outside its range).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020140E8.c \
 *       --func sub_020140E8 --addr 0x020140E8 --cc 1.1p1 --thumb
 */
u32 sub_020140E8(u32 x)
{
    return x >= 2 && x < 0xD2;
}


void func_020140F8(int p0){ *(int *)&((struct Obj00193 *)p0)->f0 = (int)0; ((struct Obj00193 *)p0)->f4 = (unsigned short)0; ((struct Obj00193 *)p0)->f6 = (unsigned short)0; ((struct Obj00193 *)p0)->f8 = (unsigned short)0; ((struct Obj00193 *)p0)->fA = (unsigned short)0; *(int *)&((struct Obj00193 *)p0)->fC = (int)0; *(int *)&((struct Obj00193 *)p0)->f10 = (int)0; *(int *)&((struct Obj00193 *)p0)->f14 = (int)0; *(int *)&((struct Obj00193 *)p0)->f18 = (int)0; }


/*
 * Initialiser: clears +0x00 and +0x0C, stores four halfwords at +0x04..+0x0A
 * and three words at +0x10..+0x18.
 *
 * Addresses are Black-image addresses.
 */
void func_02014110(Rect14110 *p, u16 a, u16 b, u16 c, u16 d, u32 e, u32 f, u32 g)
{
    p->x00 = 0;
    p->x04 = a;
    p->x06 = b;
    p->x08 = c;
    p->x0A = d;
    p->x0C = 0;
    p->x10 = e;
    p->x14 = f;
    p->x18 = g;
}

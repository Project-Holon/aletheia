/*
 * file:     bmp_oam_p02.c
 * unit:     yes
 * function: func_020258E8, func_0202590C, func_0202597C, func_020259C4, func_02025A0C, func_02025A54, func_02025A9C, func_02025B18, func_02025B38, func_02025B3C, func_02025B64, func_02025B94, func_02025BA0, func_02025BB8, func_02025BD0, func_02025BE8, func_02025BEC, func_02025C1C, func_02025C30, func_02025C44
 * address:  0x020258E8
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
 *   sub_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B688  0x0204B688  arm
 *   func_0204B800  0x0204B800  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   gModeTable     0x0209F87C  data
 *   func_0204AF28  0x0204AF28  arm
 *   sub_0204AFD8  0x0204AFD8  arm
 *   sub_02025B3C_Table  0x0209FA34  data
 *   g_0209FA34  0x0209FA34  data
 *   g_0209FA3D  0x0209FA3D  data
 *   sub_02025BA0_Table  0x0209FA36  data
 *   d_0209FA34 0x0209FA34 data
 *   d_0209FA35 0x0209FA35 data
 *   g_0209FA38  0x0209FA38  data
 *   g_0209FA3C  0x0209FA3C  data
 */
#include "../../matched/include/Obj08787.h"
#include "../../matched/include/Obj08788.h"
#include "../../matched/include/Obj08789.h"
#include "../../matched/include/Obj08790.h"

struct Actor;
struct Obj;
struct Vec2;
struct Node;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

struct PtS {
    s16 x;
    s16 y;
};

struct Obj02025774_020258E8 {
    u8            pad00[4];
    struct Actor *actor;
    u8            pad08[0xc0];
    u16           space;
};

struct Point {
    s16 x;
    s16 y;
};

struct Grid {
    u32   pad_0;
    void *a[25];
    void *b[24];
    u16   flags;
    u8    cols;
    u8    rows;
};

typedef signed char    s8;

struct Obj {
    u32 field_0;
    u16 field_4;
    u16 field_6;
    u32 field_8;
    u32 slot[3];
};

struct ModeEntry {
    u32 size;
    u32 a;
    u32 b;
};

typedef signed int     s32;

struct Obj02025774_02025B18 {
    u8  pad[0xc];
    s32 slots[3];
};

extern void sub_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B84C(void *p, u32 a);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void sub_0204AFD8(u32 slot);
extern u8 sub_02025B64(u32 v);
void func_0202597C(u8 *g, u32 a);
void func_020259C4(u8 *g, u32 a);
void func_02025A0C(u8 *g, u32 a);
void func_02025A54(u8 *g, u32 a);
int func_02025B38(void);
u32 func_02025B3C(u32 key);
u8 func_02025B64(u32 v);
u32 func_02025B94(u32 a);
u32 func_02025BA0(u32 idx);
u32 func_02025BB8(u32 i);
u32 func_02025BD0(u32 i);
int func_02025BE8(void);
u32 func_02025BEC(u32 a, u32 b, u32 c);
u32 sub_02025C1C(u32 a, u32 b, u32 c);
u32 sub_02025C30(u32 a, u32 b, u32 c);
int func_02025C44(u32 a0, u32 *a1, u32 *a2);
extern const struct ModeEntry gModeTable[];
extern const u8 sub_02025B3C_Table[];
extern u8 g_0209FA34[];
extern u8 g_0209FA3D[];
extern const u8 sub_02025BA0_Table[];
extern const unsigned char d_0209FA34[];
extern const unsigned char d_0209FA35[];
extern u8  g_0209FA38[];
extern u8  g_0209FA3C[];


void func_020258E8(struct Obj02025774_020258E8 *p, s16 *out_x, s16 *out_y)
{
    struct PtS pt;

    sub_0204B454(p->actor, &pt, p->space);
    *out_x = pt.x;
    *out_y = pt.y;
}


/*
 * bmp_oam.c.  The x/y parameters are s16, not int: only the narrow
 * parameter type puts the two spills ahead of the object copy in the
 * prologue.
 * Repositions every cell of the rows x cols grid: each cell
 * gets the base position offset by its column (x, step 32) and its row
 * (y, step 16), passed as a packed s16 pair.
 */
void func_0202590C(struct Grid *g, s16 x, s16 y)
{
    struct Point pt;
    int i, j;

    for (i = 0; i < g->rows; i++) {
        for (j = 0; j < g->cols; j++) {
            pt.x = (s16)(x + (j << 5));
            pt.y = (s16)(y + (i << 4));
            func_0204B404(g->a[j + i * g->cols], (const struct Vec2 *)(&pt), g->flags);
        }
    }
}


void func_0202597C(u8 *g, u32 a)
{
    int i;
    int j;

    for (i = 0; i < ((struct Obj08787 *)g)->fCB; i++) {
        for (j = 0; j < ((struct Obj08787 *)g)->fCA; j++) {
            func_0204B688(*(void **)(g + 4 + (i * ((struct Obj08787 *)g)->fCA + j) * 4), a);
        }
    }
}


void func_020259C4(u8 *g, u32 a)
{
    int i;
    int j;

    for (i = 0; i < ((struct Obj08788 *)g)->fCB; i++) {
        for (j = 0; j < ((struct Obj08788 *)g)->fCA; j++) {
            func_0204B800(*(void **)(g + 4 + (i * ((struct Obj08788 *)g)->fCA + j) * 4), a);
        }
    }
}


void func_02025A0C(u8 *g, u32 a)
{
    int i;
    int j;

    for (i = 0; i < ((struct Obj08789 *)g)->fCB; i++) {
        for (j = 0; j < ((struct Obj08789 *)g)->fCA; j++) {
            func_0204B84C(*(void **)(g + 4 + (i * ((struct Obj08789 *)g)->fCA + j) * 4), a);
        }
    }
}


void func_02025A54(u8 *g, u32 a)
{
    int i;
    int j;

    for (i = 0; i < ((struct Obj08790 *)g)->fCB; i++) {
        for (j = 0; j < ((struct Obj08790 *)g)->fCA; j++) {
            func_0204B6F4(*(void **)(g + 4 + (i * ((struct Obj08790 *)g)->fCA + j) * 4), a, 0);
        }
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02025A9C.c \
 *       --func func_02025A9C --addr 0x02025A9C --thumb
 *
 * Map the engine's DISPCNT OBJ-mapping bits (mask 0x00300010) to a slot
 * index 0/1/2 and lazily fill that slot through func_0204AF28 with the
 * gModeTable record's two ids (docs/families/bmp_oam.h, section 5).
 *
 * Closed in wave 13.  The two bytes the 2026-09-21 note could not move
 * (`bne default` against `beq merge` at +0x24) are the 0x00200010 arm: it
 * is NOT empty, it sets mode = 0 itself, and it is written FIRST of the
 * four arms.  The body is then cross-jumped onto default's identical
 * `mode = 0`, which is why the image branches to the same address on both
 * sides of the last compare.  With the arm empty the compiler jumps past
 * the zeroing; with `mode = 0` in any other position it lays the arm out
 * separately (55 bytes out).
 */
u32 func_02025A9C(struct Obj *obj, u32 engine, u32 arg)
{
    volatile u32 *reg;
    u32 mode;

    if (engine == 0) {
        reg = (volatile u32 *)0x04000000;
    } else {
        reg = (volatile u32 *)0x04001000;
    }

    switch (*reg & 0x00300010) {
    case 0x00200010:
        mode = 0;
        break;
    case 0x00100010:
        mode = 1;
        break;
    case 0x00000010:
        mode = 2;
        break;
    default:
        mode = 0;
        break;
    }

    if (obj->slot[mode] != (u32)-1) {
        return mode;
    }

    obj->slot[mode] = (u32)func_0204AF28((void *)arg, gModeTable[mode].a,
                                         gModeTable[mode].b, obj->field_4);
    return mode;
}


void func_02025B18(struct Obj02025774_02025B18 *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (p->slots[i] != -1) {
            sub_0204AFD8(p->slots[i]);
            p->slots[i] = -1;
        }
    }
}

int func_02025B38(void)
{
    return 19;
}


/*
 * A linear search over a fixed 19-entry, 12-byte-stride table, matching
 * on the first byte of each record; returns the matching index, or 0
 * (not -1) when nothing matches, which is why the caller cannot
 * distinguish "matched slot 0" from "no match".
 *
 * The table pointer is a plain pool word to private data outside this
 * range; left as an untyped byte-stride index rather than a struct
 * pointer since nothing else in this file constrains its layout.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02025B3C.c \
 *       --func func_02025B3C --addr 0x02025B3C --cc 1.1p1 --thumb
 */
u32 func_02025B3C(u32 key)
{
    u32 i;

    for (i = 0; i < 0x13; i++) {
        if (key == sub_02025B3C_Table[i * 0xc]) {
            return i;
        }
    }
    return 0;
}


u8 func_02025B64(u32 v)
{
    u32 i;

    for (i = 0; i < 0x13; i++) {
        if (v == g_0209FA34[i * 0xc]) {
            return g_0209FA3D[i * 0xc];
        }
    }
    return 0;
}


/*
 * A two-stage lookup: map a caller value to a record index with
 * func_02025B3C (src/matched/sub_02025B3C.c), then map that index to a
 * message/asset id with func_02025BA0 (src/matched/sub_02025BA0.c). The
 * first call's result is left in its return register and flows straight
 * into the second call's argument.
 *
 * This is the blocker for src/pending/sub_0201F094.c's wordset.c setter,
 * which is promoted alongside this file.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02025B94.c \
 *       --func func_02025B94 --addr 0x02025B94 --cc 1.1p1 --thumb
 */
u32 func_02025B94(u32 a)
{
    return func_02025BA0(func_02025B3C(a));
}


/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by
 * the C.
 *
 * Parked at MATCH by the evidence rather than by the C: every concrete
 * byte is reproduced (confirmed against the exact shape below), but the
 * one relocation, the table pointer, has no witness outside this
 * function's own range. The only other occurrence of the word
 * 0x0209FA36 in the image is at 0x02025BB4, inside the unlabelled filler
 * that immediately follows this function and that this compile's own
 * trailing bytes overlap, so the honesty rule discards it. The table is
 * two bytes into the same record array func_02025B3C searches
 * (src/matched/sub_02025B3C.c, whose own table symbol at 0x0209FA34 does
 * have outside witnesses), but declaring this address as an offset off
 * that symbol changes the code shape mwccarm emits for the pointer
 * arithmetic and no longer reproduces the bytes, so the two are kept as
 * separate declarations. func_02025B94 (src/matched/sub_02025B94.c)
 * calls this function and reaches EXACT anyway, because the `label`
 * class attests the call itself from a second caller in ov186 at
 * 0x02185CC6, independently of this file's own status.
 *
 * Bounds-checked lookup into a 19-entry (0x13) table of u16, 12-byte
 * stride, at offset +2 into the record func_02025B3C indexes. Out of
 * range returns the sentinel 0xE7.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02025BA0.c \
 *       --func func_02025BA0 --addr 0x02025BA0 --cc 1.1p1 --thumb
 */
u32 func_02025BA0(u32 idx)
{
    if (idx < 0x13) {
        return *(const u16 *)(sub_02025BA0_Table + idx * 0xc);
    }
    return 0xE7;
}

u32 func_02025BB8(u32 i)
{
    if (i < 19)
        return d_0209FA34[i * 12];
    return 0;
}

u32 func_02025BD0(u32 i)
{
    if (i < 19)
        return d_0209FA35[i * 12];
    return 18;
}

/*
 * 4 bytes. Returns the constant 0x69. Filed in wave D6 as the unlabelled leaf
 * that ov219 func_02183D14 calls.
 */
int func_02025BE8(void)
{
    return 0x69;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * func_02025BEC is a three-argument predicate: out of range (`a >= 0xE9`)
 * fails immediately; otherwise it looks `a` up through sub_02025B64
 * (src/pending/sub_02025B64.c, parked at MATCH) and fails if the result
 * is below `b`; otherwise, when `c == 1`, it fails unless `a` is one of
 * two special-cased values (0x69 or 0). Every early exit is a direct
 * `return`, not a shared tail, because each guard sits right after the
 * comparison that produces it with nothing in between
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-
 * conjunction.md does not apply here: the guards are not adjacent, they
 * are separated by the calls and comparisons that feed the next one).
 *
 * sub_02025C1C and sub_02025C30 both wrap the predicate with the same
 * shape, "return the value on success, 0 on failure", differing only in
 * which argument is guarded: the first, or the second. Both forward all
 * three arguments to func_02025BEC unchanged; the wrapped argument is
 * kept in its own register (r4) only for the return, which is why the
 * call still carries the original registers.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02025BEC.c \
 *       --addr 0x02025BEC --thumb
 */
u32 func_02025BEC(u32 a, u32 b, u32 c)
{
    if (a >= 0xE9) {
        return 0;
    }
    if (sub_02025B64(a) < b) {
        return 0;
    }
    if (c == 1) {
        if (a != 0x69 && a != 0) {
            return 0;
        }
    }
    return 1;
}


u32 sub_02025C1C(u32 a, u32 b, u32 c)
{
    u32 r = a;

    if (!func_02025BEC(a, b, c)) {
        r = 0;
    }
    return r;
}


u32 sub_02025C30(u32 a, u32 b, u32 c)
{
    u32 r = b;

    if (!func_02025BEC(a, b, c)) {
        r = 0;
    }
    return r;
}


int func_02025C44(u32 a0, u32 *a1, u32 *a2)
{
    u32 i = func_02025B3C(a0);
    u32 off;

    if (i == 0) {
        return 0;
    }
    off = i * 12;
    *a1 = *(u32 *)(g_0209FA38 + off);
    *a2 = g_0209FA3C[off];
    return 1;
}

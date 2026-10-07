/*
 * file:     field_ground_anime_p06.c
 * unit:     yes
 * function: func_021A7A40, func_021A7A88, func_021A7A8C, func_021A7A90
 * address:  0x021A7A40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj18066.h"
#include "../../matched/include/Obj18067.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Pair { u8 lo; u8 hi; } Pair;

typedef struct Tbl {
    u16 *keys;
    u8 *lo;
    u8 *hi;
    u8 *group;
    u32 limit;
    u32 count;
} Tbl;

typedef struct {
    u16 *f0;
    u32 f4;
    u32 f8;
    u8 *fc;
    u32 f10;
    u32 f14;
} S;

Pair func_021A7A40(const Tbl *t, u32 idx, u32 key);
u32 func_021A7A88(u8 *p);
u32 func_021A7A8C(u8 *p);
u16 func_021A7A90(S *s, int i);


/*
 * Levers: the 2-byte struct returned by value (stack stores, reload of byte 0),
 * `*(g + idx + 1)` for the (g+idx)[1] address, and `const Tbl *` so the
 * t->hi load schedules above the first store.
 */
Pair func_021A7A40(const Tbl *t, u32 idx, u32 key)
{
    Pair r;
    u8 *g;
    u32 n;
    u32 i;
    u32 end;

    g = t->group;
    n = t->count;
    i = g[idx];
    if (idx + 1 < n)
        end = *(g + idx + 1);
    else
        end = t->limit;
    end = end - 1;
    for (; i < end; i++) {
        if (t->keys[i + 1] > key)
            break;
    }
    r.lo = t->lo[i];
    r.hi = t->hi[i];
    return r;
}


/*
 * Loads the 32-bit word at byte +0x14 of the object.
 */
u32 func_021A7A88(u8 *p)
{
    return ((struct Obj18066 *)p)->f14;
}


/*
 * Loads the 32-bit word at byte +0x18 of the object.
 */
u32 func_021A7A8C(u8 *p)
{
    return ((struct Obj18067 *)p)->f18;
}


u16 func_021A7A90(S *s, int i)
{
    int k;
    if (i + 1 < s->f14) {
        k = *(s->fc + i + 1);
    } else {
        k = s->f10;
    }
    return *(s->f0 + k - 1);
}

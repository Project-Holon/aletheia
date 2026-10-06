/*
 * file:     unit_0206EA58.c
 * unit:     yes
 * function: func_0206EA58, func_0206EACC
 * address:  0x0206EA58
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj08931.h"
#include "../../matched/include/Obj11641.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

u16 *func_0206EA58(u16 *p, u32 arg, u32 v);
unsigned char *func_0206EACC(void *p, u32 idx);


/*
 * Bucket search in a BTX0-style table: the signed halfword at +4 of the block
 * func_0206EACC returns scales the key, the result is a fixed-point index, and
 * the two walks that follow step it down over entries >= v and then up over
 * entries <= v, returning the entry address.
 *
 * The entry stride is four *bytes* and is spelled through a byte pointer, and
 * the two walks are one `while` each: the emitted shape is the rotated form
 * the compiler produces for a conjunction whose second term loads.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206EA58.c \
 *       --func func_0206EA58 --addr 0x0206EA58 --cc 1.1p1 --arm
 */
u16 *func_0206EA58(u16 *p, u32 arg, u32 v)
{
    u8 *h = func_0206EACC(p, arg);
    s16 n = ((struct Obj08931 *)h)->f4;
    u8 *t = (u8 *)p + ((struct Obj08931 *)h)->f6;
    u32 i = (u32)(n * v) >> 12;

    while (i != 0 && *(u16 *)(t + i * 4) >= v)
        i--;
    while (i + 1 < ((struct Obj08931 *)h)->f0 && *(u16 *)(t + 4 + i * 4) <= v)
        i++;
    return (u16 *)(t + i * 4);
}


/*
 * The null test is on the *computed* pointer, not on `p`: the original opens
 * with `adds r3, r0, #12` and branches on its zero flag.  The field reads for
 * the bound and the offset stay p-relative (+13, +18) while the indexed
 * halfword goes through the computed base - that mix of spellings is what
 * reproduces the register use, not a local `q` for all three.
 *
 * The two guards must be `goto`s, not `return 0`s: as returns, mwccarm
 * predicates the body (see docs/idioms/a-factored-tail-lets-the-compiler-predicate-the-arms.md);
 * as gotos the original's `beq`/`bcs` branches survive.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206EACC.c \
 *       --func func_0206EACC --addr 0x0206EACC --cc 1.1p1 --arm
 */
unsigned char *func_0206EACC(void *p, u32 idx)
{
    unsigned char *q = (unsigned char *)p + 12;
    u16 off;
    u16 n;

    if (q == 0)
        goto fail;
    if (idx >= *((unsigned char *)p + 13))
        goto fail;
    off = ((struct Obj11641 *)p)->f12;
    n = *(u16 *)(q + off);
    return q + off + 4 + n * idx;
fail:
    return 0;
}

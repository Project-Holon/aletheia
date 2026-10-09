/*
 * file:     unit_0206A67C.c
 * function: func_0206A67C
 * address:  0x0206A67C
 * packet:   pkt_0206A67C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The unlabelled follower of src/matched/func_0206A5B4.c, and the bulk form
 * of that function's per-entry work: resolve the same cell table out of the
 * header chain and walk every entry, clearing the done bit (flags bit 0 at
 * +3) on each.  It shares 0x0206A5B4's Ent layout and its
 * base/entry resolution exactly.
 *
 * NOT pinned, despite the parent carrying ../2.0/sp2.  One probe under
 * `--cc ../2.0/sp2` was run and measured 128 bytes / 63 concrete out, the
 * same shortfall as 1.1p1's 128 / 64: the front end is not the difference
 * here and the whole 4-byte gap is in the C.  Three levers close it, all
 * under the default 1.1p1:
 *
 *   1. The entry test is written against the counter (`e1->count <= i`,
 *      both unsigned), not against zero.  `count == 0` and `count <= 0`
 *      both give `bxeq lr`; only the comparison with the unsigned counter
 *      gives the image's `bxls lr` at +0028.
 *   2. The in-loop bound must be re-read.  Written plainly, the compiler
 *      forwards the r0 it already loaded for the entry test and drops the
 *      `ldrb r0, [r3, #1]` at +0038, which is the whole 4-byte shortfall;
 *      reading it through `volatile` restores the fresh load.
 *   3. The clear is masked at full width: `(u8)(flags & ~1u)` gives the
 *      image's `bicne r0, r0, #1` at +006C, where the narrow `flags &= ~1`
 *      folds to `andne r0, r0, #0xfe`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206A67C.c \
 *       --func func_0206A67C --addr 0x0206A67C --cc 1.1p1 --arm
 */
#include "../../matched/include/Obj07044.h"
#include "../../matched/include/Obj16557.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  f0;
    u8  count;
    u8  f2;
    u8  flags;
    u16 f4;
    u16 tbl;
} Ent;

void func_0206A67C(char *h)
{
    char *base;
    Ent  *e1;
    u32   i;

    base = (h != 0 && ((struct Obj07044 *)h)->f8 != 0) ? h + ((struct Obj07044 *)h)->f8 : 0;
    e1 = (Ent *)(base + ((struct Obj16557 *)base)->f2);

    i = 0;
    if (e1->count <= i)
        return;

    do {
        Ent *t;
        if (e1 != 0 && i < *(volatile u8 *)&e1->count) {
            u16 t2 = e1->tbl;
            u16 st = *(u16 *)((char *)e1 + t2);
            t = (Ent *)((char *)e1 + t2 + 4 + st * i);
        } else {
            t = 0;
        }
        i++;
        if (t->flags & 1) {
            t->flags = (u8)(t->flags & ~1u);
        }
    } while (i < e1->count);
}

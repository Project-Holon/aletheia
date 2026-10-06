/*
 * unit:     no
 * function: func_02064D70
 * address:  0x02064D70
 * packet:   pkt_02064B68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Name-record walker, the 0x5c / 0x28 stride pair of the cluster_02064B68
 * bank family.  A table with a u16 count at +0x00 and an 8-byte-record array
 * at +0x04: mode 1 hands the callback a pointer into the 0x5c-record array
 * indexed by the record's HIGH BYTE, every other mode the first word of the
 * 0x28-record array.  The callback gets (ctx, record, value, index) and a
 * zero return stops the walk.  This is a `void` function whose early exit is
 * a bare `return;`: an `int` return materialises a value and changes both
 * epilogues.
 *
 * Two levers closed the 4-byte residue docs/notes/func_02064D70.c.txt
 * records, and both are worth keeping:
 *
 *   The high-byte extract.  The image is three instructions,
 *   `and r2, r2, #0xff00` / `lsl r2, r2, #8` / `lsr ip, r2, #0x10`, and the
 *   note measured five spellings (`f >> 8`, `(u8)(f >> 8)`,
 *   `((f >> 8) & 0xff)`, `(f & 0xff00) >> 8`, f as u16 and as u32) that all
 *   fold to the single shift, which is the four bytes it was short.  The
 *   spelling that keeps all three is the mask assigned into a u16 and then
 *   shifted through u32: `(u32)((x & 0xff00) << 8) >> 16`.  The mask must be
 *   NARROWED to u16 before the pair, which is what makes the `lsl #8` survive
 *   instead of folding with the `lsr`.
 *
 *   Declaration order.  `i` must be declared FIRST, before `tab` and `n`;
 *   the note's register rotation (tab -> r8, count -> sb, i -> r7 in the
 *   image against r7/r8/sb in the compile) is entirely that, per
 *   docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 *   The permuter named both levers: decl-order(i<->n), decl-order(i<->tab)
 *   and expand(f), 18 concrete bytes out -> 0.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02064D70.c \
 *       --func func_02064D70 --addr 0x02064D70 --arm --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16  count;
    u8   pad_02[2];
    u8  *entries;      /* +0x04 */
} Tab;

typedef struct {
    Tab  *f00;
    u8    pad_04[4];
    u32   f08;
    u8   *f0c;
} S;

void func_02064D70(S *p, int (*fn)(void *, void *, void *, int), void *ctx)
{
    u16  i;
    Tab *tab = p->f00;
    u16  n   = tab->count;

    if (p->f08 == 1) {
        u8 *base = p->f0c;

        for (i = 0; i < n; i++) {
            if (fn(ctx, tab->entries + i * 8,
                   base + ((u32)((*(u16 *)(tab->entries + i * 8 + 6) & 0xff00) << 8) >> 16) * 0x5c,
                   i) == 0)
                return;
        }
    } else {
        u8 *base = p->f0c;

        for (i = 0; i < n; i++) {
            if (fn(ctx, tab->entries + i * 8,
                   *(void **)(base + i * 0x28), i) == 0)
                return;
        }
    }
}

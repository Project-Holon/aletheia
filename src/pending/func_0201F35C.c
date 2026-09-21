/*
 * function: func_0201F35C
 * address:  0x0201F35C
 * packet:   pkt_0201F35C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  literal. Every concrete byte is identical (0 concrete diffs, 192/192).
 *           The three data pool words -- g_0209E784, g_0209E758, g_0209E838 -- have no
 *           witness outside 0201F35C..0201F41C: each address appears in exactly one
 *           literal pool image-wide, this function's own, so the 'literal' class has
 *           nothing to offer and no other matched entry names them. A second reader of
 *           any of the three tables would release this file to EXACT.
 *
 * symbols:
 *   func_0204581C  0x0204581C  arm
 *   func_02045AFC  0x02045AFC  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   g_0209E784     0x0209E784  data
 *   g_0209E758     0x0209E758  data
 *   g_0209E838     0x0209E838  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

extern void func_0204581C(void *ctx);
extern void func_02045AFC(void *ctx, u16 ch);
extern u32  _u32_div_f(u32 a, u32 b);
extern u16  g_0209E784[];
extern u16  g_0209E758[];
extern u32  g_0209E838[];

void func_0201F35C(void *ctx, s32 n, u32 kind, u32 mode, u32 flag)
{
    u16 *tbl;
    u32 d;
    u32 q;

    if (flag == 0) {
        tbl = g_0209E784;
    } else {
        tbl = g_0209E758;
    }
    func_0204581C(ctx);

    if ((u16)(n < 0) != 0) {
        u32 ch;
        s32 neg = ~0;
        n = neg * n;
        if (flag == 0) {
            ch = 0x30FC;
        } else {
            ch = 0x2D;
        }
        func_02045AFC(ctx, (u16)ch);
    }

    d = g_0209E838[kind];
    while (d != 0) {
        q = _u32_div_f((u32)n, d);
        q = (u16)q;
        n = n - d * q;
        if (q >= 10) {
            q = 10;
        }
        if (mode == 2) {
            func_02045AFC(ctx, tbl[q]);
        } else if (q != 0 || d == 1) {
            mode = 2;
            func_02045AFC(ctx, tbl[q]);
        } else if (mode == 1) {
            u32 ch;
            if (flag == 0) {
                ch = 0x3000;
            } else {
                ch = 0x20;
            }
            func_02045AFC(ctx, (u16)ch);
        }
        d = _u32_div_f(d, 10);
    }
}

/*
 * Decimal number printer.  func_0204581C(ctx) resets the glyph writer;
 * func_02045AFC(ctx, u16) emits one glyph; _u32_div_f is the mwccarm
 * integer-division helper (docs/idioms/runtime-helper-reloc.md).
 *
 * `flag` selects one of two glyph tables (0x0209E784 full-width,
 * 0x0209E758 half-width) and the matching minus / space glyphs
 * (0x30FC vs 0x2D, 0x3000 vs 0x20): this is the full-width/half-width
 * font pair, not a version-specific table.
 *
 * Two idioms carried the last four bytes: the negation is `~0 * n`, not
 * `-n` (which compiles to `rsbs`), and the remainder is `n - d * q`, not
 * `n - q * d` (docs/idioms/commutative-operand-order-names-the-temporary.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201F35C.c \
 *       --func func_0201F35C --addr 0x0201F35C --cc 1.1p1 --thumb
 */

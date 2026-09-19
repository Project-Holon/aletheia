/*
 * function: func_0209128C
 * address:  0x0209128C
 * packet:   pkt_020911D8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   g_02153B88      0x02153B88  data
 *
 * blocker:  own-pool.  +0018 ABS32 g_02153B88
 *           -> unresolved: 02153B88 (data, from symbol name) has no witness
 *              outside 0209128C..020912A8
 *           Raw word scan: 0x02153B88 occurs exactly once in the arm9 region,
 *           at 0x020912A4, this function's own pool word - inside the compared
 *           range, so the `literal` class has nothing to cite.  The park at
 *           src/pending/func_020912A8.c lists the same address as
 *           `g_02153B88 [literal x15]`: that witness exists only for ranges
 *           that do not contain 0x020912A4, which is why the site resolves
 *           there and cannot resolve here.
 *
 * THE `../2.0/sp2` PIN: the 1/0 select.
 *   The image materialises the stored byte with BOTH arms predicated:
 *
 *     image      0209128C  cmp r0, #0
 *                02091290  movne r1, #1
 *                02091294  ldr r0, [pc, #8]
 *                02091298  moveq r1, #0
 *                0209129C  strb r1, [r0]
 *                020912A0  bx lr
 *     dsi/1.1p1  02091290  mov r1, #1        <- 1 concrete byte, no predicate
 *                02091298  moveq r1, #0
 *
 *   Nineteen 1.1p1 spellings of the same assignment all leave the first move
 *   unpredicated (`g = x != 0;`, `g = !!x;`, `g = !(x == 0);`,
 *   `g = x ? 1 : 0;`, `g = (x != 0) ? 1 : 0;`, `g = (x == 0) ? 0 : 1;`,
 *   `g = (unsigned char)(x != 0);`, `g = (x != 0) & 1;`, `int b = 0; if (x)
 *   b = 1; g = b;`, `int b = 1; if (!x) b = 0; g = b;`, `int b; if (x) b = 1;
 *   else b = 0; g = b;`, `int b; if (x == 0) b = 0; else b = 1; g = b;`,
 *   `u8 b = x != 0; g = b;`, `if (x) g = 1; else g = 0;`, `g = x ? 1U : 0U;`,
 *   and the `(int)`/`(unsigned char)`/`_Bool` casts) - probes run 2026-09-19.
 *   Under `../2.0/sp2` the file is byte-correct with zero concrete
 *   differences, so the pin is taken on this row, one decision, confirmed by
 *   compile.  Same "kept constants" family as src/matched/func_02074A6C.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0209128C.c \
 *       --func func_0209128C --addr 0x0209128C --arm --cc ../2.0/sp2
 *   -> MATCH, compiled 28 = original 28, 0 concrete differences, 1 wildcard
 */

extern unsigned char g_02153B88;

void func_0209128C(int x)
{
    g_02153B88 = x != 0;
}

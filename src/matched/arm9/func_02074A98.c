/*
 * function: func_02074A98
 * address:  0x02074A98
 * packet:   pkt_02074A6C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02074E10  0x02074E10  arm
 *
 * Sibling of func_02074A6C: the identical wrapper over the other byte-stream
 * reader in the same unit.
 *
 * PER-FILE PIN (../2.0/sp2), same byte evidence and same tell as
 * func_02074A6C (docs/FRONTEND-PINS.md, "kept constants"): the image
 * materialises 0xff / 1 / 0 at the call and the boolean from immediates
 * (44 bytes), `dsi/1.1p1` keeps 1 and 0 live in callee-saved r4/r5 and needs
 * 48 bytes (35 differing), `../2.0/sp2` reproduces the image exactly.
 * Needs a row in docs/FRONTEND-PINS.md; that file is outside this lane's
 * write set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02074A98.c \
 *       --func func_02074A98 --addr 0x02074A98 --arm --cc ../2.0/sp2
 */

typedef unsigned int u32;

extern u32 func_02074E10(u32 a, u32 b, u32 c, u32 d, u32 *out);

u32 func_02074A98(u32 a, u32 b)
{
    return func_02074E10(a, 0xff, b, 1, 0) == 0;
}

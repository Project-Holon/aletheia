/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202DE9C
 * packet:   pkt_0202DBC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0202DE9C, sub_0202DEE0, sub_0202DF24
 *
 * Three copies of one function that differ only in the four constants
 * they answer with. Each reads the display control register of engine A
 * (0x04000000) or engine B (0x04001000), masks it to the two bits that
 * say which BG mode the engine is in, and maps the three interesting
 * values to a resource id.
 *
 * Two details pin the source. The engine A address arrives as
 * `movs r0, #1` / `lsls r0, #0x1A` and the engine B address from a
 * literal pool, which is this compiler materialising 0x04000000 as a
 * shifted small constant and giving up on 0x04001000; both are cast
 * integer constants in the source rather than relocated externs
 * (docs/idioms/volatile-reread-needs-two-locals.md records the same
 * shape). And the mapping is a `switch`, not a chain of `if`s: a switch
 * over sparse values compiles to the `cmp`/`beq` chain the original has,
 * with every arm's body written out after the chain, whereas the chain of
 * `if`s puts each `return` immediately after its own test and is thirty
 * concrete bytes different
 * (docs/idioms/switch-arms-tail-merge.md for the neighbouring case).
 *
 * The third function's `default` answers 0x26, which is the *second*
 * function's family rather than its own, so the three were copied and
 * edited rather than generated.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202DE9C.c  *       --addr 0x0202DE9C --thumb
 */

typedef unsigned int u32;
typedef volatile unsigned int vu32;

u32 sub_0202DE9C(u32 engine)
{
    vu32 *reg;

    if (engine == 0) {
        reg = (vu32 *)0x04000000;
    } else {
        reg = (vu32 *)0x04001000;
    }
    switch (*reg & 0x00300010) {
    case 0x00000010:
        return 0x21;
    case 0x00100010:
        return 0x22;
    case 0x00200010:
        return 0x20;
    }
    return 0x20;
}

u32 sub_0202DEE0(u32 engine)
{
    vu32 *reg;

    if (engine == 0) {
        reg = (vu32 *)0x04000000;
    } else {
        reg = (vu32 *)0x04001000;
    }
    switch (*reg & 0x00300010) {
    case 0x00000010:
        return 0x27;
    case 0x00100010:
        return 0x28;
    case 0x00200010:
        return 0x26;
    }
    return 0x26;
}

u32 sub_0202DF24(u32 engine)
{
    vu32 *reg;

    if (engine == 0) {
        reg = (vu32 *)0x04000000;
    } else {
        reg = (vu32 *)0x04001000;
    }
    switch (*reg & 0x00300010) {
    case 0x00000010:
        return 0x2D;
    case 0x00100010:
        return 0x2E;
    case 0x00200010:
        return 0x2C;
    }
    return 0x26;
}

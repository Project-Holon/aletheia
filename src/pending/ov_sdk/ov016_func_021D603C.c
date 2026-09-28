/*
 * function: DWCi_GXlVisible
 * address:  0x021D603C
 * packet:   pkt_ov016_021D603C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      DWCi_GXlVisible (graphics.o), TwlDWC libdwcutil.TWL.HYB.a
 *
 * blocker:  codegen only, no evidence issue. The body is byte-identical in
 *           size (84) and semantics; every instruction matches except the two
 *           volatile read targets, which are swapped r0<->r2. The original
 *           loads the first read into r2 (then `and ip, r2, #0x1f00`) and the
 *           second into r0 (`bic r2, r0, #0x1f00`); this draft (and every
 *           spelling tried: two named locals, expression in either operand
 *           order, address as cast constant vs pointer local) makes the
 *           compiler load the first read into r0. Pure register allocation,
 *           not a source-shape difference that could be found by bytes.
 *
 * symbols:
 *   (none)
 */
void DWCi_GXlVisible(int lcd, int plane)
{
    if (lcd == 1) {
        volatile unsigned long *reg = (volatile unsigned long *)0x04001000;
        unsigned long a = *reg;
        unsigned long b = *reg;

        *reg = (b & ~0x1f00) | ((plane | ((a & 0x1f00) >> 8)) << 8);
        return;
    }
    {
        volatile unsigned long *reg = (volatile unsigned long *)0x04000000;
        unsigned long a = *reg;
        unsigned long b = *reg;

        *reg = (b & ~0x1f00) | ((plane | ((a & 0x1f00) >> 8)) << 8);
    }
}

/*
 * function: func_02012F50
 * address:  0x02012F50
 * packet:   pkt_02012F50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor: base + 0x6A4.  No register-saving prologue, so
 * disasm.py never traced a func_ label here; matching it gives the overlay
 * call sites a `matched` witness.
 *
 * symbols:
 *   func_02012F50  0x02012F50  thumb
 */

int func_02012F50(int base)
{
    return base + 0x6A4;
}

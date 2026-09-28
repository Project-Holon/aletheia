/*
 * function: func_021D53DC
 * address:  0x021D53DC
 * packet:   pkt_021D53DC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D53DC   0x021D53DC  thumb ov093
 *
 * note: the parked DIFF read this as a 60-byte clamp; the traced extent is the
 * full 100 bytes (0x021D53DC..0x021D5440), returning the "changed" flag.  The
 * image's register-indexed unroll (`movs r2,#i; ldrsb r2,[r0,r2]`) is what
 * mwcc -O4,p emits for seven spelled-out `if` arms whose index is a variable
 * re-assigned before each arm, not for a plain loop (which stays rolled) nor
 * for literal indices (which use immediate offsets).  All 100 bytes reproduce.
 */

int func_021D53DC(signed char *p)
{
    int changed = 0;
    int i = 0;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    i = 1;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    i = 2;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    i = 3;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    i = 4;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    i = 5;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    i = 6;
    if (p[i] < 6) { p[i] = 6; changed = 1; }
    return changed;
}

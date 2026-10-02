/*
 * function: func_021576C4
 * address:  0x021576C4
 * packet:   pkt_021576C4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021576B8  0x021576B8  thumb  ov010
 *
 * Unblocked by matching func_021576B8 (ov010, EXACT). The ABS32 site +0004 now
 * attests as `matched`.
 * The listing extent is now 8 bytes, so the verdict is plain EXACT.
 *
 * `line`: every caller loads r2 with a constant, but the callee never
 * reads it, so the thunk takes it and drops it.
 */

void func_021576B8(char *p, int v);

void func_021576C4(char *p, int v, int line)
{
    func_021576B8(p, v);
}

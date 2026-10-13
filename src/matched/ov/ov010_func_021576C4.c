/*
 * function: DELIVERY_BEACON_SetStepAtLine
 * address:  0x021576C4
 * packet:   pkt_021576C4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   DELIVERY_BEACON_SetStep  0x021576B8  thumb  ov010
 *
 * Unblocked by matching DELIVERY_BEACON_SetStep (ov010, EXACT). The ABS32 site +0004 now
 * attests as `matched`.
 * The listing extent is now 8 bytes, so the verdict is plain EXACT.
 *
 * `line`: every caller loads r2 with a constant, but the callee never
 * reads it, so the thunk takes it and drops it.
 */

void DELIVERY_BEACON_SetStep(char *p, int v);

void DELIVERY_BEACON_SetStepAtLine(char *p, int v, int line)
{
    DELIVERY_BEACON_SetStep(p, v);
}

/*
 * function: func_021EF8B8
 * address:  0x021EF8B8
 * packet:   pkt_ov093_021EF8B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT
 *
 * Tail call into the countdown leaf func_021EF9D0 with the static record.
 *
 * 2026-10-03: byte-correct, MATCH only because 0x021EF9D0 has no label yet.
 * Its witness is filed EXACT as src/matched/ov/ov093_func_021EF9D0.c; once
 * the integrator seeds that start this verifies EXACT.
 *
 * symbols:
 *   func_021EF9D0  0x021EF9D0  thumb  ov093
 *   d_021F63F4  0x021F63F4  data  a4
 */

typedef unsigned int u32;

typedef struct {
    u32 value;
    u32 count;
} Countdown;

extern Countdown d_021F63F4;
extern u32 func_021EF9D0(Countdown *p);

u32 func_021EF8B8(void)
{
    return func_021EF9D0(&d_021F63F4);
}

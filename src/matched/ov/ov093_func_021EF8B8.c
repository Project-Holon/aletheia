/*
 * function: BTL_FIELD_TickCountdown
 * address:  0x021EF8B8
 * packet:   pkt_ov093_021EF8B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT
 *
 * Tail call into the countdown leaf BTL_FIELD_StepCountdown with the static record.
 *
 * 2026-10-03: byte-correct, MATCH only because 0x021EF9D0 has no label yet.
 * Its witness is filed EXACT as src/matched/ov/ov093_func_021EF9D0.c; once
 * the integrator seeds that start this verifies EXACT.
 *
 * symbols:
 *   BTL_FIELD_StepCountdown  0x021EF9D0  thumb  ov093
 *   gBtlFieldCountdown  0x021F63F4  data  a4
 */

#include "../include/G_Countdown.h"

typedef unsigned int u32;

typedef struct {
    u32 value;
    u32 count;
} Countdown;

extern struct Countdown gBtlFieldCountdown;
extern u32 BTL_FIELD_StepCountdown(Countdown *p);

u32 BTL_FIELD_TickCountdown(void)
{
    return BTL_FIELD_StepCountdown(((Countdown *)&gBtlFieldCountdown));
}

/*
 * function: BTL_FIELD_StepCountdown
 * address:  0x021EF9D0
 * packet:   pkt_ov093_021EF9D0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (witness for BTL_FIELD_TickCountdown). Countdown timer: when the
 * value is set and the counter is not 0xff, decrement the counter; when it
 * reaches zero, clear the value and return its low byte.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 value;
    u32 count;
} Countdown;

u32 BTL_FIELD_StepCountdown(Countdown *p)
{
    u32 v = p->value;
    if (v != 0 && p->count != 0xff && --p->count == 0) {
        v = (u8)v;
        p->value = 0;
        return v;
    }
    return 0;
}

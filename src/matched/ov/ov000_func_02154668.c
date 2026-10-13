/*
 * function: EVENT_GSYNC_Entry
 * address:  0x02154668
 * packet:   pkt_ov000_02154668
 * region:   ov000
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Thumb tail call through r3 (ldr r3, =target; bx r3). Labelled in wave D8.
 *
 * symbols:
 *   EVENT_GSYNC_Create  0x02154670  thumb ov000
 */

extern void *EVENT_GSYNC_Create(void *p);

void *EVENT_GSYNC_Entry(void *p)
{
    return EVENT_GSYNC_Create(p);
}

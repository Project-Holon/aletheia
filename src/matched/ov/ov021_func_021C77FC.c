/*
 * function: FIELD_TASK_UpdateWait
 * address:  0x021C77FC
 * packet:   pkt_021C77FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Increments the counter at +0 and returns 1 when it has reached the limit at +2.
 *
 * symbols:
 *   (none)
 */

typedef unsigned short u16;
typedef struct { u16 f0; u16 f2; } X_021C77D8;

int FIELD_TASK_UpdateWait(X_021C77D8 *x)
{
    x->f0++;
    if (x->f2 <= x->f0)
        return 1;
    return 0;
}

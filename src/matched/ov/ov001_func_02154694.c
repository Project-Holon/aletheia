/*
 * function: EVENT_GTSNEGO_Entry
 * address:  0x02154694
 * packet:   pkt_ov001_02154694
 * region:   ov001
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk to EVENT_GTSNEGO_Create, stored as a callback by ov021
 * SCRCMD_PROC_FLD_CallOv001Event (pool word 0x02154695).
 *
 * symbols:
 *   EVENT_GTSNEGO_Create  0x0215466C  thumb  ov001
 */

extern void *EVENT_GTSNEGO_Create(void *p, int a);

void *EVENT_GTSNEGO_Entry(void *p, int a)
{
    return EVENT_GTSNEGO_Create(p, a);
}

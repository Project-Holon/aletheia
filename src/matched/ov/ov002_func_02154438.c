/*
 * function: EVENT_WIFIBATTLEMATCH_Entry
 * address:  0x02154438
 * packet:   pkt_ov002_02154438
 * region:   ov002
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_WIFIBATTLEMATCH_Create  0x021543E8  thumb  ov002
 */

typedef int s32;

extern void *EVENT_WIFIBATTLEMATCH_Create(void *p, int a1, int a2, int a3, int a4);

void EVENT_WIFIBATTLEMATCH_Entry(s32 a, s32 *b)
{
    EVENT_WIFIBATTLEMATCH_Create((void *)a, b[0], b[1], b[2], b[3]);
}

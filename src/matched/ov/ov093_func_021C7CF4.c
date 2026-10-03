/*
 * function: func_021C7CF4
 * address:  0x021C7CF4
 * packet:   pkt_021C7CF4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *
 * Forwarding tail call: p[2] and the caller's i go to func_021B9934, whose
 * listing reads both (lsls r1, r1, #2), and its result is returned.
 */

typedef unsigned char u8;

u8 *func_021B9934(char *p, int i);

void *func_021C7CF4(int *p, int i)
{
    return func_021B9934((char *)p[2], i);
}

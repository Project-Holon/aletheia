/*
 * function: BTL_EVENT_DispatchEventToType
 * address:  0x021D70FC
 * packet:   pkt_021D70FC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_DispatchEventNested  0x021D7108  thumb  ov093
 */

void BTL_EVENT_DispatchEventNested(void *a, int id, int kind, int check);

void BTL_EVENT_DispatchEventToType(int a, int b, int c)
{
    BTL_EVENT_DispatchEventNested((void *)a, b, c, 1);
}

/*
 * unit:     yes
 * function: BTL_EVENT_DispatchEvent, BTL_EVENT_DispatchEventChecked
 * address:  0x021D70E4
 * packet:   pkt_021D70E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two wrappers fixing the third argument to 7.
 *
 * symbols:
 *   BTL_EVENT_DispatchEventNested  0x021D7108  thumb  ov093
 */

extern void BTL_EVENT_DispatchEventNested(void *, int, int, int);

void BTL_EVENT_DispatchEvent(void *a, int id)
{
    BTL_EVENT_DispatchEventNested(a, id, 7, 0);
}

void BTL_EVENT_DispatchEventChecked(void *a, int id)
{
    BTL_EVENT_DispatchEventNested(a, id, 7, 1);
}

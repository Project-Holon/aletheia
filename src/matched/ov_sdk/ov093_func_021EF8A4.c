/*
 * function: BTL_FIELD_SetCountdown
 * address:  0x021EF8A4
 * packet:   pkt_ov093_021EF8A4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * BTL_FIELD_SetCountdown (libdwcutil/main.o): two-argument wrapper that forwards
 * the persistent heap block together with both parameters to the overlay's
 * local DWC_StartUtility copy (BTL_FIELD_StoreCountdown); tail call, so the return type
 * does not affect codegen.
 *
 * symbols:
 *   BTL_FIELD_StoreCountdown  0x021EF9C0  thumb  ov093
 *   HeapMem        0x021F63F4  data   ov093  a4
 */

extern char HeapMem;
extern int *BTL_FIELD_StoreCountdown(int *p, int a, int b);

int BTL_FIELD_SetCountdown(int a, int b)
{
    return (int)BTL_FIELD_StoreCountdown((int *)(&HeapMem), a, b);
}

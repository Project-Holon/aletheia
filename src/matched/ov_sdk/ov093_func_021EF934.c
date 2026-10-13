/*
 * function: DWC_StartUtilityEx
 * address:  0x021EF934
 * packet:   pkt_ov093_021EF934
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * DWC_StartUtilityEx (libdwcutil/main.o): third copy in ov093, a two-argument
 * wrapper forwarding the persistent heap block and both parameters to its own
 * local entry point (BTL_FIELD_TickSlots); tail call.
 *
 * symbols:
 *   BTL_FIELD_TickSlots  0x021EFC78  thumb  ov093
 *   HeapMem        0x021F63F4  data   ov093  a4
 */

extern char HeapMem;
extern int BTL_FIELD_TickSlots(void *mem, int a, int b);

int DWC_StartUtilityEx(int a, int b)
{
    return BTL_FIELD_TickSlots(&HeapMem, a, b);
}

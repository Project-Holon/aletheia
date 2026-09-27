/*
 * function: DWC_StartUtilityEx
 * address:  0x021EF8A4
 * packet:   pkt_ov093_021EF8A4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * DWC_StartUtilityEx (libdwcutil/main.o): two-argument wrapper that forwards
 * the persistent heap block together with both parameters to the overlay's
 * local DWC_StartUtility copy (func_021EF9C0); tail call, so the return type
 * does not affect codegen.
 *
 * symbols:
 *   func_021EF9C0  0x021EF9C0  thumb  ov093
 *   HeapMem        0x021F63F4  data   ov093  a4
 */

extern char HeapMem;
extern int func_021EF9C0(void *mem, int a, int b);

int DWC_StartUtilityEx(int a, int b)
{
    return func_021EF9C0(&HeapMem, a, b);
}

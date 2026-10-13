/*
 * function: DWC_StartUtilityEx
 * address:  0x021EF8F8
 * packet:   pkt_ov093_021EF8F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * DWC_StartUtilityEx (libdwcutil/main.o): second copy in ov093, a two-argument
 * wrapper forwarding the persistent heap block and both parameters to its own
 * local entry point (BTL_FIELD_AddSlotHolder); tail call.
 *
 * symbols:
 *   BTL_FIELD_AddSlotHolder  0x021EFAD8  thumb  ov093
 *   HeapMem        0x021F63F4  data   ov093  a4
 */

extern char HeapMem;
typedef unsigned int   u32;
extern int BTL_FIELD_AddSlotHolder(char *a, u32 b, u32 c);

int DWC_StartUtilityEx(int a, int b)
{
    return BTL_FIELD_AddSlotHolder(&HeapMem, a, b);
}

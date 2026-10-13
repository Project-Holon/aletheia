/*
 * function: EVENT_FIELDMAP_CONTROL_GetExitEffect
 * address:  0x021BE89C
 * packet:   pkt_ov021_021BE89C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02013FD8  0x02013FD8  thumb
 *   EVENT_FIELDMAP_CONTROL_LookupExitEffect  0x021BEA9C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char  u8;
extern u8 func_02013FD8(u32 id);
extern u32 EVENT_FIELDMAP_CONTROL_LookupExitEffect(int row, int col);
int EVENT_FIELDMAP_CONTROL_GetExitEffect(int a, u32 b)
{
    return EVENT_FIELDMAP_CONTROL_LookupExitEffect(func_02013FD8(a), func_02013FD8(b));
}

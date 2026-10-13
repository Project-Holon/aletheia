/*
 * function: EVENT_FIELDMAP_CONTROL_GetEntranceEffect
 * address:  0x021BE8B8
 * packet:   pkt_ov021_021BE8B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02013FD8  0x02013FD8  thumb
 *   EVENT_FIELDMAP_CONTROL_LookupEntranceEffect  0x021BEACC  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 func_02013FD8(u32 id);
extern u32 EVENT_FIELDMAP_CONTROL_LookupEntranceEffect(int a, int b);

int EVENT_FIELDMAP_CONTROL_GetEntranceEffect(int a, int b)
{
    int x = func_02013FD8(a);
    return EVENT_FIELDMAP_CONTROL_LookupEntranceEffect(x, func_02013FD8(b));
}

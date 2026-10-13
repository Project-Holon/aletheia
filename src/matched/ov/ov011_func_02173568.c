/*
 * function: INTRUDE_COMM_OnSessionStarted
 * address:  0x02173568
 * packet:   pkt_ov011_02173568
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIH_SetBeaconFoundCallback  0x0217963C  thumb  ov014
 *   INTRUDE_COMM_ScanCallback  0x02173368  thumb  ov011
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void WIH_SetBeaconFoundCallback(u32 v);
struct Obj;
extern void INTRUDE_COMM_ScanCallback(void *a0, struct Obj *s);

void INTRUDE_COMM_OnSessionStarted(u8 *w)
{
    w[0x8fd] = 2;
    WIH_SetBeaconFoundCallback((u32)INTRUDE_COMM_ScanCallback);
}

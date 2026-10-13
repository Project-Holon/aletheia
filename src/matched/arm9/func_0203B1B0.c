/*
 * function: GFL_NET_STATE_BeaconScan
 * address:  0x0203B1B0
 * packet:   pkt_0203DC70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail-call wrapper over GFL_NET_STATE_ChangeStateDebug (the object at 0x021469DC, the
 * callback GFL_NET_STATE_StartBeaconScan, 0, 0x1BC).  An unlabelled ARM leaf, filed as the
 * witness chain for func_0203D010 (state 10 of GFL_NET_IRC_WIRELESS_Main).
 *
 * symbols:
 *   _pNetState     0x021469DC  data
 *   GFL_NET_STATE_StartBeaconScan  0x0203B170  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 */

extern void *_pNetState;
extern void GFL_NET_STATE_StartBeaconScan(void);
typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);

void GFL_NET_STATE_BeaconScan(void)
{
    GFL_NET_STATE_ChangeStateDebug(_pNetState, GFL_NET_STATE_StartBeaconScan, 0, 0x1BC);
}

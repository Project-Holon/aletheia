/*
 * function: BTL_SERVER_FLOW_OnFieldEffectExpired
 * address:  0x021C4C40
 * packet:   pkt_ov093_021C4C40
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * BTL_SERVER_FLOW_OnFieldEffectExpired (libaes/aes_util.o): tail-call thunk into the overlay's
 * local copy of the event signaller.  The source object relocates the pool
 * word against OS_SignalEvent, but the overlay linked its own function at
 * 0x021C4C50, so the extern is named by that overlay label.  The explicit
 * symbols: entry is required because the address-name convention infers the
 * ISA from the ARM9 listing only and would clear the Thumb bit.
 *
 * symbols:
 *   BTL_SERVER_FLOW_PushFieldEffectExpireMessage  0x021C4C50  thumb  ov093
 */

typedef unsigned char  u8;
extern void BTL_SERVER_FLOW_PushFieldEffectExpireMessage(u8 *p, int k);

void BTL_SERVER_FLOW_OnFieldEffectExpired(int result, void *arg)
{
    BTL_SERVER_FLOW_PushFieldEffectExpireMessage(arg, result);
}

/*
 * function: CallbackForJpeg
 * address:  0x021C4C40
 * packet:   pkt_ov093_021C4C40
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * CallbackForJpeg (libaes/aes_util.o): tail-call thunk into the overlay's
 * local copy of the event signaller.  The source object relocates the pool
 * word against OS_SignalEvent, but the overlay linked its own function at
 * 0x021C4C50, so the extern is named by that overlay label.  The explicit
 * symbols: entry is required because the address-name convention infers the
 * ISA from the ARM9 listing only and would clear the Thumb bit.
 *
 * symbols:
 *   func_021C4C50  0x021C4C50  thumb  ov093
 */

typedef unsigned char  u8;
extern void func_021C4C50(u8 *p, int k);

void CallbackForJpeg(int result, void *arg)
{
    func_021C4C50(arg, result);
}

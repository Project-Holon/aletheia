/*
 * function: func_021F3708
 * address:  0x021F3708
 * packet:   pkt_ov050_021F3708
 * region:   ov050
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two-call wrapper.  Blocker: both callees are unlabelled leaves at
 * 0x02188D2C / 0x021BE580, so no label/sole-ref witness exists.  Address is
 * also resident in ov049; region-qualified packet id.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 
 *
 * UNBLOCKED: func_02188D2C is now an EXACT entry at 0x02188D2C in
 * layout/matched/ov021, and func_021BE580 resolves with the ov021
 * region hint; both call sites fine, verdict promoted to EXACT.
*/

void func_021F3708(void *p)
{
    void *func_02188D2C(void *p);
    void func_021BE580(void *p);
    func_021BE580(func_02188D2C(p));
}

/*
 * function: ov050_func_021F3708
 * address:  0x021F3708
 * packet:   pkt_ov050_021F3708
 * region:   ov050
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Two-call wrapper.  Blocker: both callees are unlabelled leaves at
 * 0x02188D2C / 0x021BE580, so no label/sole-ref witness exists.  Address is
 * also resident in ov049; region-qualified packet id.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb
 *   func_021BE580  0x021BE580  thumb
 */

void func_021F3708(void)
{
    void func_02188D2C(void);
    void func_021BE580(void);
    func_02188D2C();
    func_021BE580();
}

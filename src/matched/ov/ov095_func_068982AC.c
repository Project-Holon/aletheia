/*
 * function: BTL_EVENT_IsFactorKeyRegistered
 * address:  0x068982AC
 * packet:   pkt_ov095_068982AC
 * region:   ov095
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * sdk:      BTL_EVENT_IsFactorKeyRegistered (libdwcmatch.TWL.HYB.thumb.a(dwc_match.o))
 *
 * symbols:
 *   func_068982C0  0x068982C0  thumb  ov095
 */

extern void *func_068982C0(void);

int BTL_EVENT_IsFactorKeyRegistered(void)
{
    if (func_068982C0() == 0)
        return 1;
    return 0;
}

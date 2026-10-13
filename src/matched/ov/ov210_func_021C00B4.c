/*
 * function: func_021C00B4
 * address:  0x021C00B4
 * packet:   pkt_ov210_021C00B4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BFF30 0x021BFF30 thumb ov210
 *   BLINK_PALANM_ResetPhase 0x0202EB04 thumb
 * Addresses are Black-image addresses.
 */

extern void func_021BFF30(int p, unsigned a, unsigned b);
struct CodeIn;
extern void BLINK_PALANM_ResetPhase(struct CodeIn *p);

void func_021C00B4(int p, unsigned a, unsigned b)
{
    func_021BFF30(p, b, 1);
    func_021BFF30(p, a, 3);
    BLINK_PALANM_ResetPhase((struct CodeIn *)(((int *)p)[0xad]));
}

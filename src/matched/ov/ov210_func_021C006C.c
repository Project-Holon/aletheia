/*
 * function: func_021C006C
 * address:  0x021C006C
 * packet:   pkt_ov210_021C006C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   func_021BFF30 0x021BFF30 thumb ov210
 *   BLINK_PALANM_ResetPhase 0x0202EB04 thumb
 * Addresses are Black-image addresses.
 */

extern unsigned KEY_GetTrg(void);
extern void func_021BFF30(int p, unsigned a, unsigned b);
struct CodeIn;
extern void BLINK_PALANM_ResetPhase(struct CodeIn *p);

void func_021C006C(int p, unsigned b)
{
    unsigned r = KEY_GetTrg();

    if ((r & 2) && !(r & 0xf1))
        return;
    func_021BFF30(p, b, 3);
    BLINK_PALANM_ResetPhase((struct CodeIn *)(((int *)p)[0xad]));
}

/*
 * function: func_021DEFC4
 * address:  0x021DEFC4
 * packet:   pkt_021DEFC4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021E22E4  0x021E22E4  arm  ov175
 *   func_021DFE20  0x021DFE20  arm  ov175
 *   func_021BF540  0x021BF540  arm  ov114
 *
 * Build/teardown pair: func_021E22E4 (ov175) and func_021DFE20, each
 *  *  separated by a 0x021BF540 (ov114) step -- the overlay re-arms its state
 *  *  between the two halves.
 */

typedef signed int     s32;
extern s32 func_021E22E4(void);
extern int func_021BF540(void);
extern void func_021DFE20(void);

void func_021DEFC4(void)
{
    func_021E22E4();
    func_021BF540();
    func_021DFE20();
    func_021BF540();
}


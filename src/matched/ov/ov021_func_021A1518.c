/*
 * function: func_021A1518
 * address:  0x021A1518
 * packet:   pkt_ov021_021A1518
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-01: byte-correct; tail-call target is an unlabelled ov034 Thumb function (listing reads it as ARM), no witness.
 *
 * symbols:
 *   func_021F0044  0x021F0044  thumb  ov034
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void func_021F0044(u32);

void func_021A1518(u32 *p)
{
    func_021F0044(p[8]);
}

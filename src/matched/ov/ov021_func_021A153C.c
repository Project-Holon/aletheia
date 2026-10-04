/*
 * function: func_021A153C
 * address:  0x021A153C
 * packet:   pkt_ov021_021A153C
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
 *   func_021F00F0  0x021F00F0  thumb  ov034
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern int func_021F00F0(char *p);

void func_021A153C(u32 *p)
{
    func_021F00F0((char *)p[8]);
}

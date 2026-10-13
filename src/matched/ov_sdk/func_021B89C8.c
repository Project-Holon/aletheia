/*
 * function: AOSSi_Status
 * address:  0x021B89C8
 * packet:   pkt_021C1CF8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DCE20   0x021DCE20  data
 *
 * Dispatch the caller argument through slot 1 of the 0x021DCE20 handler table when set; always return 0.
 * Addresses are Black-image addresses.
 *
 * The data symbol carries NO region token on purpose: 0x021DCE20 is a bss
 * address nine overlays share and another one starts an object at, so an
 * `ov016` hint is contested and refused (see scratch/ov_ov016/o27/report.md).
 * Without the token _overlay_pool() fixes the overlay from the region this
 * function is compiled in, and the site attests sole-ref/self.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/AOSSi_Status.c \
 *       --func AOSSi_Status --addr 0x021B89C8 --region ov016 --cc dsi/1.1p1 --thumb
 */

extern void (*func_021DCE20[])(int);

int AOSSi_Status(int a)
{
    if (func_021DCE20[1])
        func_021DCE20[1](a);
    return 0;
}


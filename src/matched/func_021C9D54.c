/*
 * function: func_021C9D54
 * address:  0x021C9D54
 * packet:   pkt_021C9D54
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C9D54   0x021C9D54  arm
 *   func_0207C958   0x0207C958  arm
 *
 * Scale the shared halfword counter by 1/0x1d and bias by the argument.
 * Every concrete byte matches the image (36 bytes, no register or constant
 * residue).
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x0207C958 is the ARM
 * SDK symbol FX_DivS32 (also an EXACT sdk_calibration entry).  Declaring it
 * `arm` (the image's ISA) lets the `sdk`/`matched` class attest the +0x14
 * call.  The old `thumb` declaration fought the image's ISA and suppressed it.
 *
 * The bias `+ a` must be written with the call result on the left of a local
 * (`v + a`), not `func(...) + a`: the latter emits `add r0, r4, r0` instead of
 * the image's `add r0, r0, r4`.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C9D54.c \
 *       --func func_021C9D54 --addr 0x021C9D54 --region ov016 --cc dsi/1.1p1 --arm
 */

extern int func_0207C958(int, int);

int func_021C9D54(int a)
{
    unsigned char *g = (unsigned char *)0x021DE5EC;
    int v = func_0207C958(*(unsigned short *)(g + 4), 0x1d);

    return v + a;
}

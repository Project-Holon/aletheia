/*
 * function: func_021C9D54
 * address:  0x021C9D54
 * packet:   pkt_021C9D54
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_021C9D54   0x021C9D54  arm
 *   func_0207C958   0x0207C958  thumb
 *
 * Scale the shared halfword counter by 1/0x1d and bias by the argument.
 * Every concrete byte matches the image (36 bytes, no register or constant
 * residue); the only open item is the call at +0x14.
 *
 * BLOCKING SITE: the callee at 0x0207C958 is declared `thumb` because
 * match.py's ISA check refuses `arm` there, and with `thumb` the site reports
 *   +0014 PC24 func_0207C958 -> unresolved: 0207C958 (thumb, from header)
 *   has no witness outside 021C9D54..021C9D78
 * i.e. no pool word elsewhere attests the odd (Thumb) address 0x0207C959 --
 * the encoding at the call site is a plain ARM BL (0xEBFACAFA), which is what
 * the compiler emits for the declared target and what the image holds.  Same
 * tool-side ISA/witness disagreement Lane O39 parked func_021C9D10 for.
 *
 * The bias `+ a` must be written with the call result on the left of a local
 * (`v + a`), not `func(...) + a`: the latter emits `add r0, r4, r0` instead of
 * the image's `add r0, r0, r4`.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_021C9D54.c \
 *       --func func_021C9D54 --addr 0x021C9D54 --region ov016 --cc dsi/1.1p1 --arm
 */

extern int func_0207C958(int, int);

int func_021C9D54(int a)
{
    unsigned char *g = (unsigned char *)0x021DE5EC;
    int v = func_0207C958(*(unsigned short *)(g + 4), 0x1d);

    return v + a;
}

/*
 * function: GF_STANDARD_CalcAngle
 * address:  0x0203F768
 * packet:   pkt_0203F768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Blocked at MATCH on the `label`/`matched` classes: every concrete byte of
 * the body reproduces, but the PC24 at +0x18 to GF_STANDARD_SetupCalc_F7C4 has one
 * branch reference image-wide, this call, so the site has no witness outside
 * 0203F768..0203F7C4.  Filing 0x0203F7C4 as an EXACT manifest entry promotes
 * this file with no change to the C.
 *
 * The six-argument forwarder: the two stacked arguments are copied down into
 * the outgoing frame and the seventh is the divisor, a 20.12 fixed-point
 * product of itself with 0x323d rounded up by 0x800 and shifted down twice.
 *
 * symbols:
 *   GF_STANDARD_SetupCalc_F7C4  0x0203F7C4  arm
 *   _s32_div_f     0x0209C0A4  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GF_STANDARD_CalcAngle.c \
 *       --func GF_STANDARD_CalcAngle --addr 0x0203F768 --cc 1.1p1 --arm
 */

typedef long long s64;

extern int GF_STANDARD_SetupCalc_F7C4(int a0, int a1, int a2, int a3, int a4, int a5);
extern int _s32_div_f(int n, int d);

int GF_STANDARD_CalcAngle(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    int v = GF_STANDARD_SetupCalc_F7C4(a0, a1, a2, a3, a4, a5);
    int d = (int)(((s64)(a6 << 13) * 0x323d + 0x800) >> 12);

    return (v << 16) / (d >> 12);
}

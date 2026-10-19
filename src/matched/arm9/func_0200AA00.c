/*
 * function: IRC_RANKING_GetDateScore
 * address:  0x0200AA00
 * packet:   pkt_0200AA00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FX_SinCosTable_   0x020A1B38  data
 *   _u32_div_f     0x0209C2B0  arm
 *   GF_STANDARD_GetDayOfYear  0x0203F540  arm
 *
 * A date interpolation: copy the caller's 16-byte date record onto the
 * stack (the `ldm/stm` pair of docs/idioms/aggregate-assignment-is-ldm-stm.md),
 * take its day number with GF_STANDARD_GetDayOfYear, overwrite the two fields at +4 and
 * +8 with the two scalar arguments, take the day number again, and wrap the
 * difference into a year.  The tail is the fixed-point sine lookup
 * src/matched/GF_STANDARD_Get_F684.c already evidences -- the same 4096-entry signed
 * halfword table at 0x020A1B38 indexed at `2 * i`, with 30 in place of 360 --
 * scaled to a percentage: `(sin + 0x1000) * 50 >> 12`, truncated to u8.
 *
 * Two things were load-bearing and cost the run:
 *
 *  - `asrs r0, r0, #4` after the second (UNSIGNED) divide.  The division is
 *    _u32_div_f at both sites, so the expression is unsigned, but the shift
 *    is arithmetic: the quotient has to be bound to an `s32` local first.
 *    Writing the whole chain inline gives `lsrs`; making the division itself
 *    signed swaps the helper to _s32_div_f and loses the call.
 *  - `cmp r4, r0` and not `cmp r0, r4`: the guard is written `if (a >= b)`,
 *    naming the FIRST day number first.  The equivalent `if (b <= a)` is two
 *    bytes wrong (cmp operands swapped and blo becomes bhi).  This is
 *    docs/idioms/cmp-operand-order-names-the-temporary.md, and it is the same
 *    lever src/matched/IRC_RANKING_HasEntryByTrainerId.c in this family already records.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/IRC_RANKING_GetDateScore.c \
 *       --func IRC_RANKING_GetDateScore --addr 0x0200AA00 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct Date {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
};

extern s16  FX_SinCosTable_[];
struct RtcDate;
extern s32  GF_STANDARD_GetDayOfYear(struct RtcDate *d);

u8 IRC_RANKING_GetDateScore(u32 a0, u32 a1, struct Date *src)
{
    struct Date d = *src;
    u32 a, b;

    a = GF_STANDARD_GetDayOfYear((struct RtcDate *)&d);
    d.f04 = a0;
    d.f08 = a1;
    b = GF_STANDARD_GetDayOfYear((struct RtcDate *)&d);
    if (a >= b) {
        b += 365;
    }
    {
        s32 i = (s32)((((b - a) % 30) * 0xFFFF) / 30);
        return (u8)((FX_SinCosTable_[2 * (i >> 4)] + 0x1000) * 50 >> 12);
    }
}

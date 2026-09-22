/*
 * function: func_020966B0
 * address:  0x020966B0
 * packet:   pkt_020949F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * MSL __ull2dec: unsigned long long -> decimal record (struct Bcd / DB in the
 * cluster headers, MSL's `decimal`).  Four lanes and ~2800 permuter compiles
 * left this at 192/196 bytes with the callee-saved set rotated by one and
 * one "declined live-range split" (`mov r4, r1`).  That split is the MSL
 * spelling itself: the digit is stored with
 *
 *     result->sig.text[result->sig.length++] = val % 10;
 *
 * i.e. the post-increment of the length FIELD in the subscript, which keeps
 * the old length live across the _ull_mod call as its own value.  With that
 * one line the whole divmod loop is byte-exact.  The remaining residue (the
 * in-place reversal) closed on two points: `end` derived from `start`
 * (`start + length - 1`, not `text + length - 1`), and the swap written as
 * four separate statements with the pointer steps last
 * (`temp = *start; *start = *end; *end = temp; start++; end--;`) -- the
 * post-increment forms put start/end in each other's registers.  No zero
 * special case: a zero value leaves length 0 and exponent -1, as the image
 * does.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020966B0.c \
 *       --func func_020966B0 --addr 0x020966B0 --cc 1.1p1 --arm
 *   EXACT, 196 bytes, 2 relocation sites, all resolved.
 *
 * symbols:
 *   _ll_udiv       0x0209C00C  arm
 *   _ull_mod       0x0209C018  arm
 */

typedef unsigned char u8;
typedef signed short s16;
typedef unsigned long long u64;

typedef struct decimal {
    char sign;
    char unused;
    s16 exp;
    struct {
        u8 length;
        u8 text[32];
        u8 unused;
    } sig;
} decimal;

void func_020966B0(decimal *result, u64 val)
{
    result->sign = 0;
    result->sig.length = 0;

    for (; val != 0; val /= 10)
        result->sig.text[result->sig.length++] = val % 10;

    {
        u8 *start = result->sig.text;
        u8 *end = start + result->sig.length - 1;

        while (start < end) {
            u8 temp = *start;
            *start = *end;
            *end = temp;
            start++;
            end--;
        }
    }

    result->exp = result->sig.length - 1;
}

/*
 * function: __equals_dec
 * address:  0x02096D10
 * packet:   pkt_02096990
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:  none -- the function has no relocation at all
 *
 * String comparison over the length-prefixed string object used by the
 * 0x02096D10 family: byte +5 is a terminator flag, +2 is an s16 key, +4 is
 * the byte length and +5.. is the payload.  Two flag/length guards, a key
 * comparison, then a byte compare over the shorter of the two payloads; when
 * the compared prefix is exactly a's payload the tail of b is checked for a
 * terminator instead, and vice versa.  Returns 1 when the two are equivalent.
 *
 * Three measured levers (all needed, each costs a whole-function diff):
 *   - `volatile u8 f04`.  The second loop re-reads the length out of the
 *     object on every iteration (`ldrb r1, [r0, #4]` after the payload test)
 *     instead of hoisting it; a plain field lets mwcc hoist it and the loop
 *     comes out one instruction short.
 *   - the bound is an `int` copy: `la`/`lb` are locals, so `if (la > lb)`
 *     compares two sign-unknown ints and mwcc emits `movgt`.  Comparing the
 *     u8 fields directly tells mwcc both are 0..255 and it uses `movhi`
 *     instead, which is four bytes that differ.
 *   - `p = a; if (n == la) p = b;`.  As a ternary mwcc keeps the result in
 *     b's register (r1); the two-statement form lets it coalesce p with `a`
 *     and the whole tail allocates as the original does.
 */

typedef unsigned char u8;
typedef signed short  s16;

typedef struct {
    u8  pad00[2];
    s16 f02;
    volatile u8 f04;
    u8  f05[];
} Str;

int __equals_dec(Str *a, Str *b)
{
    Str *p;
    int i, n;
    int la, lb;

    if (a->f05[0] == 0)
        return b->f05[0] == 0;
    if (b->f05[0] == 0)
        return a->f05[0] == 0;
    if (a->f02 != b->f02)
        goto fail;
    i = 0;
    la = a->f04;
    lb = b->f04;
    n = la;
    if (la > lb)
        n = lb;
    for (; i < n; i++) {
        if (a->f05[i] != b->f05[i])
            return 0;
    }
    p = a;
    if (n == la)
        p = b;
    for (; i < p->f04; i++) {
        if (p->f05[i] != 0)
            return 0;
    }
    return 1;
fail:
    return 0;
}

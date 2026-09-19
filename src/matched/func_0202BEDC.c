/*
 * function: func_0202BEDC
 * address:  0x0202BEDC
 * packet:   pkt_0202BEDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A four-byte tail-call thunk to func_0202BF54: one PROGBITS section per
 * function means this compiler cannot encode a displacement to another
 * function, so the target's address materialises through a literal pool word
 * and a `bx` (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The pool
 * word's low bit carries the Thumb bit, so the extern is declared Thumb.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BEDC.c \
 *       --func func_0202BEDC --addr 0x0202BEDC --thumb --cc 1.1p1
 */

extern void func_0202BF54(void);

void func_0202BEDC(void)
{
    func_0202BF54();
}

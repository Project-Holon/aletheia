/*
 * function: ISS_ZONE_SYS_Start
 * address:  0x0202BEDC
 * packet:   pkt_0202BEDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * A four-byte tail-call thunk to ISS_ZONE_SYS_SelectRecord: one PROGBITS section per
 * function means this compiler cannot encode a displacement to another
 * function, so the target's address materialises through a literal pool word
 * and a `bx` (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The pool
 * word's low bit carries the Thumb bit, so the extern is declared Thumb.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ZONE_SYS_Start.c \
 *       --func ISS_ZONE_SYS_Start --addr 0x0202BEDC --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_ZONE_SYS_SelectRecord  0x0202BF54  thumb
 */

extern void ISS_ZONE_SYS_SelectRecord(void);

void ISS_ZONE_SYS_Start(int a, int b)
{
    ISS_ZONE_SYS_SelectRecord();
}

/*
 * function: StringHash
 * address:  0x0219E848
 * packet:   pkt_ov009_0219E848
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      StringHash (sb_server.o)
 *
 * This is a static function, so `match.py one` leaves its two relocation
 * fields wildcarded (a static has no exported symbol to witness them) and caps
 * it at MATCH.  `match.py tu` resolves both: _u32_div_f as label and
 * __lower_mapC as literal, and the TU verdict is EXACT.  The sibling copy at
 * 0x0219FB64 is the same 84-byte body and is filed pending (packet
 * pkt_ov009_0219FB64) for want of a shard witness at that address.
 *
 * The character is walked through a named pointer (`char *p = s; ... p++`)
 * rather than the post-increment subscript form; only that spelling puts the
 * character in lr and the hash accumulator in r12, matching the original.
 *
 * symbols:
 *   _u32_div_f     0x0209C2B0  arm
 *   __lower_mapC   0x020A60DC  data
 */

extern unsigned int _u32_div_f(unsigned int a, unsigned int b);
extern unsigned char __lower_mapC[];

static int StringHash(char *s, int numbuckets)
{
    unsigned int hashcode = 0;
    char *p = s;
    int c;

    while ((c = *p) != 0)
    {
        if (c >= 0 && c < 0x80)
            c = __lower_mapC[c];
        hashcode = hashcode * 0x9CCF9319 + c;
        p++;
    }
    return hashcode % numbuckets;
}

/*
 * function: StringHash
 * address:  0x0219FB64
 * packet:   pkt_ov009_0219FB64
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      StringHash (sb_server.o)
 *
 * Byte-identical to the StringHash entry at 0x0219E848 (same object); identical
 * source.  Parked MATCH: the two relocation sites carry no external witness.
 *
 * symbols:
 *   _u32_div_f     0x0209C2B0  arm
 *   __lower_mapC   0x020A60DC  data
 */

extern unsigned int _u32_div_f(unsigned int a, unsigned int b);
extern unsigned char __lower_mapC[];

static int StringHash(char *s, int numbuckets)
{
    int c = *s;
    unsigned int hashcode = 0;

    while (c != 0)
    {
        if (c >= 0 && c < 0x80)
            c = __lower_mapC[c];
        hashcode = hashcode * 0x9CCF9319 + c;
        c = *++s;
    }
    return hashcode % numbuckets;
}

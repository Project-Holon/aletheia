/*
 * function: update_crc
 * address:  0x021B7FF8
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   make_crc_table  0x021B8030  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol update_crc (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B7FF8.c \
 *       --func update_crc --addr 0x021B7FF8 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

extern void make_crc_table(int crc_table_computed, unsigned long *crc_table);

unsigned long update_crc(unsigned long crc, unsigned char *buf, int len,
                         int crc_table_computed, unsigned long *crc_table)
{
    unsigned long c = crc;
    int n;

    if (!crc_table_computed)
        make_crc_table(crc_table_computed, crc_table);
    for (n = 0; n < len; n++) {
        c = crc_table[(c ^ buf[n]) & 0xff] ^ (c >> 8);
    }
    return c;
}

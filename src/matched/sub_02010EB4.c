/*
 * function: sub_02010EB4
 * address:  0x02010EB4
 * packet:   pkt_02010DB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_0214621C  0x0214621C  data
 *
 * One of the two leaf accessors that follow sub_02010E14 and carry no label
 * because they save no lr (docs/idioms/unlabelled-leaf-functions-hide-in-
 * word-runs.md).  It reads the state byte of one slot straight out of the
 * thirteen-entry byte table; see docs/families/net_save.h section 4.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02010EB4.c \
 *       --func sub_02010EB4 --addr 0x02010EB4 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;

extern u8 g_0214621C[];

u8 sub_02010EB4(int k)
{
    return g_0214621C[k];
}

/*
 * function: aeskw_xor64
 * address:  0x021BAF90
 * packet:   pkt_ov016_021BADD8
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   aeskw_xor64          0x021BAF90  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), static aeskw_xor64 (prototype
 * from the vendor object DWARF): dst = srcA ^ srcB over eight bytes, written out.
 * EXACT* only for the two bytes of alignment padding.
 * atermset.o's .comment stamp is "Metrowerks C/C++ for ARM 3.0.0.126", the
 * ../2.0/sp1p2 front end (see ov016_func_021BBC8C_md5.c for the dsi/1.1p1 contrast).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BAF90.c \
 *       --func aeskw_xor64 --addr 0x021BAF90 --region ov016 --cc dsi/../2.0/sp1p2 --thumb
 */
void aeskw_xor64(unsigned char *srcA, unsigned char *srcB, unsigned char *dst)
{
    dst[0] = srcA[0] ^ srcB[0];
    dst[1] = srcA[1] ^ srcB[1];
    dst[2] = srcA[2] ^ srcB[2];
    dst[3] = srcA[3] ^ srcB[3];
    dst[4] = srcA[4] ^ srcB[4];
    dst[5] = srcA[5] ^ srcB[5];
    dst[6] = srcA[6] ^ srcB[6];
    dst[7] = srcA[7] ^ srcB[7];
}

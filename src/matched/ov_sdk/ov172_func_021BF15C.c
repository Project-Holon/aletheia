/*
 * function: decode_block
 * address:  0x021BF15C
 * packet:   pkt_ov172_021BF15C
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      decode_block (jpegdec.o)
 *
 * symbols:
 *   decode_block_sub  0x021BF1E0  arm  ov172
 *   gJpegDecodeDcTable     0x021C8B1C  data
 *   g_021C726C     0x021C726C  data
 *   gJpegIdctBlock     0x021C8B9C  data
 */

extern short gJpegDecodeDcTable[5][64];
extern unsigned char g_021C726C[64];
extern short gJpegIdctBlock[64];
extern void decode_block_sub(short *s, short *d, int n);

void decode_block(short *d, short n)
{
    int i;
    int p;
    int q;

    for (q = 0, p = 0, i = 0; i < 64; i++, p++, q++) {
        gJpegDecodeDcTable[1][g_021C726C[q]] = gJpegDecodeDcTable[n][p];
    }
    if (n == 0) {
        decode_block_sub(gJpegIdctBlock, d, 0);
    } else {
        decode_block_sub(gJpegIdctBlock, d, 64);
    }
}

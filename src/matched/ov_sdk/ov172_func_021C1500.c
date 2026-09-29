/*
 * function: Yos_JpegEncodeSample2to2Component
 * address:  0x021C1500
 * packet:   pkt_ov172_021C1500
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      Yos_JpegEncodeSample2to2Component (libssp.TWL.HYB.a jpegenc.o)
 *
 * symbols:
 *   Yos_JpegEncoderForwardDct       0x021C0D04  arm  ov172
 */

typedef struct component_structure {
    short *mCofficients;
    unsigned long mCols;
    unsigned long mRows;
    long mLastDcValue;
} component_structure;

extern void Yos_JpegEncoderForwardDct(unsigned char *data, long *qtable, short *output);

void Yos_JpegEncodeSample2to2Component(unsigned char *buffer, long *qTable,
                                       component_structure *component, unsigned long dx)
{
    unsigned char data[64];
    unsigned long v;
    unsigned long x;
    unsigned long y;
    unsigned long u;
    unsigned long z;
    short *dct_coff;
    unsigned long cx;
    unsigned long cy;

    cy = component->mRows;
    dct_coff = component->mCofficients;
    cx = component->mCols;
    for (y = 0, v = 0; y < cy; y++) {
        for (x = 0; x < cx; x++) {
            u = ((y << 4) * dx) + (x << 4);
            for (z = 0; z < 64; z += 8) {
                data[z + 0] = (buffer[u + 0] + buffer[u + 1] + buffer[u + dx + 0] + buffer[u + dx + 1]) >> 2;
                data[z + 1] = (buffer[u + 2] + buffer[u + 3] + buffer[u + dx + 2] + buffer[u + dx + 3]) >> 2;
                data[z + 2] = (buffer[u + 4] + buffer[u + 5] + buffer[u + dx + 4] + buffer[u + dx + 5]) >> 2;
                data[z + 3] = (buffer[u + 6] + buffer[u + 7] + buffer[u + dx + 6] + buffer[u + dx + 7]) >> 2;
                data[z + 4] = (buffer[u + 8] + buffer[u + 9] + buffer[u + dx + 8] + buffer[u + dx + 9]) >> 2;
                data[z + 5] = (buffer[u + 10] + buffer[u + 11] + buffer[u + dx + 10] + buffer[u + dx + 11]) >> 2;
                data[z + 6] = (buffer[u + 12] + buffer[u + 13] + buffer[u + dx + 12] + buffer[u + dx + 13]) >> 2;
                data[z + 7] = (buffer[u + 14] + buffer[u + 15] + buffer[u + dx + 14] + buffer[u + dx + 15]) >> 2;
                u += dx * 2;
            }
            Yos_JpegEncoderForwardDct(data, qTable, dct_coff + v * 64);
            v++;
        }
    }
}

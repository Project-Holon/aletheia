/*
 * function: Yos_JpegEncodeSample1to1Component
 * address:  0x021C1868
 * packet:   pkt_ov172_021C1868
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      Yos_JpegEncodeSample1to1Component (libssp.TWL.HYB.a jpegenc.o)
 *
 * symbols:
 *   Yos_JpegEncoderForwardDct  0x021C0D04  arm  ov172
 *
 * Static: copies an unsubsampled component plane into 8x8 blocks through eight row pointers, each block handed to the forward DCT.
 */

typedef struct component_structure {
    short *mCofficients;
    unsigned long mCols;
    unsigned long mRows;
    long mLastDcValue;
} component_structure;

extern void Yos_JpegEncoderForwardDct(unsigned char *data, long *qtable, short *output);

void Yos_JpegEncodeSample1to1Component(unsigned char *buffer, long *qTable, component_structure *component, unsigned long dx)
{
    unsigned char data[64];
    unsigned long v;
    unsigned long x;
    unsigned long y;
    unsigned long z;
    short *dct_coff;
    unsigned long cx;
    unsigned long cy;
    unsigned char *row0;
    unsigned char *row1;
    unsigned char *row2;
    unsigned char *row3;
    unsigned char *row4;
    unsigned char *row5;
    unsigned char *row6;
    unsigned char *row7;

    cy = component->mRows;
    row0 = buffer;
    row1 = buffer + dx;
    row2 = buffer + dx * 2;
    row3 = buffer + dx * 3;
    row4 = buffer + dx * 4;
    row5 = buffer + dx * 5;
    row6 = buffer + dx * 6;
    row7 = buffer + dx * 7;
    dct_coff = component->mCofficients;
    cx = component->mCols;
    for (y = 0, v = 0; y < cy; y++) {
        for (x = 0; x < cx; x++) {
            for (z = 0; z < 8; z++) {
                data[z + 0] = *row0++;
                data[z + 8] = *row1++;
                data[z + 16] = *row2++;
                data[z + 24] = *row3++;
                data[z + 32] = *row4++;
                data[z + 40] = *row5++;
                data[z + 48] = *row6++;
                data[z + 56] = *row7++;
            }
            Yos_JpegEncoderForwardDct(data, qTable, dct_coff + v * 64);
            v++;
        }
        row0 = row7;
        row1 = row0 + dx;
        row2 = row1 + dx;
        row3 = row2 + dx;
        row4 = row3 + dx;
        row5 = row4 + dx;
        row6 = row5 + dx;
        row7 = row6 + dx;
    }
}

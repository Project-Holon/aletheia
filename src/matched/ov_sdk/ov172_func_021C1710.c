/*
 * function: func_021C1710
 * address:  0x021C1710
 * packet:   pkt_ov172_021C1710
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      Yos_JpegEncodeSample2to1Component (libssp.TWL.HYB.a jpegenc.o)
 *
 * symbols:
 *   func_021C0D04  0x021C0D04  arm  ov172
 *
 * Static: horizontal 2:1 chroma subsampling of a component plane into 8x8 blocks, each handed to the forward DCT.
 */

typedef struct component_structure {
    short *mCofficients;
    unsigned long mCols;
    unsigned long mRows;
    long mLastDcValue;
} component_structure;

extern void func_021C0D04(unsigned char *data, long *qtable, short *output);

void func_021C1710(unsigned char *buffer, long *qTable, component_structure *component, unsigned long dx)
{
    unsigned char data[64];
    unsigned long v;
    unsigned long u;
    unsigned long x;
    unsigned long y;
    unsigned long z;
    short *dct_coff;
    unsigned long cx;
    unsigned long cy;

    cy = component->mRows;
    dct_coff = component->mCofficients;
    cx = component->mCols;
    for (y = 0, v = 0; y < cy; y++) {
        for (x = 0; x < cx; x++) {
            u = ((y << 3) * dx) + (x << 4);
            for (z = 0; z < 64; z += 8) {
            data[z + 0] = (buffer[u + 0] + buffer[u + 1]) >> 1;
            data[z + 1] = (buffer[u + 2] + buffer[u + 3]) >> 1;
            data[z + 2] = (buffer[u + 4] + buffer[u + 5]) >> 1;
            data[z + 3] = (buffer[u + 6] + buffer[u + 7]) >> 1;
            data[z + 4] = (buffer[u + 8] + buffer[u + 9]) >> 1;
            data[z + 5] = (buffer[u + 10] + buffer[u + 11]) >> 1;
            data[z + 6] = (buffer[u + 12] + buffer[u + 13]) >> 1;
            data[z + 7] = (buffer[u + 14] + buffer[u + 15]) >> 1;
                u += dx;
            }
            func_021C0D04(data, qTable, dct_coff + v * 64);
            v++;
        }
    }
}

/*
 * file:     unit_021C0C20_p02.c
 * unit:     yes
 * function: func_021C1248, func_021C12F4, func_021C131C, func_021C1500, func_021C1710
 * address:  0x021C1248
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021CADE4  0x021CADE4  data  ov172
 *   Yos_BitWrite                    0x021C0C3C  arm  ov172
 *   JpegZigZagInputOrderCodes       0x021C85BC  data
 *   Yos_JpegEncoderForwardDct       0x021C0D04  arm  ov172
 *   func_021C0D04  0x021C0D04  arm  ov172
 */
typedef unsigned char u8;

typedef unsigned int u32_021C1248;

typedef unsigned short u16;

typedef unsigned long u32_021C131C;

typedef struct huffman_structure {
    u32_021C131C mFrequencies[257];
    u8  mHuffBits[32];
    u8  mHuffValues[256];
    u16 mEhufco[258];
    u8  mEhufsi[260];
} huffman_structure;

typedef struct component_structure_021C131C {
    short *mCofficients;
    u32_021C131C mCols;
    u32_021C131C mRows;
    long mLastDcValue;
} component_structure_021C131C;

typedef struct component_structure_021C1500 {
    short *mCofficients;
    unsigned long mCols;
    unsigned long mRows;
    long mLastDcValue;
} component_structure_021C1500;

typedef struct component_structure_021C1710 {
    short *mCofficients;
    unsigned long mCols;
    unsigned long mRows;
    long mLastDcValue;
} component_structure_021C1710;

extern int Yos_BitWrite(u8 *dst, u32_021C131C *ptr, u32_021C131C num, u32_021C131C size);
extern void Yos_JpegEncoderForwardDct(unsigned char *data, long *qtable, short *output);
extern void func_021C0D04(unsigned char *data, long *qtable, short *output);
int func_021C1248(u8 *a0, u8 *a1, u32_021C1248 *a2);
int func_021C12F4(unsigned char *p);
void Yos_JpegEncodeSample2to2Component(unsigned char *buffer, long *qTable, component_structure_021C1500 *component, unsigned long dx);
void func_021C1710(unsigned char *buffer, long *qTable, component_structure_021C1710 *component, unsigned long dx);
extern volatile u32_021C1248 g_021CADE4[];
extern u8 JpegZigZagInputOrderCodes[64];


/*
 * Block copier with a running sum: appends the 16 bytes at a0+0x404 to the
 * output buffer a1 (advancing the cursor *a2), accumulates their sum, then
 * appends `sum` more bytes from a0+0x424.  Both the pre-check and the post-check
 * compare the cursor (plus 0x10, then plus sum) against the limit at +8 of
 * g_021CADE4 and return 0 when the buffer would overrun; returns 1 otherwise.
 * The limit is re-read from the global at each of the two sites (the global is
 * volatile in the original), which is what makes the pool word load twice.
 *
 * Addresses are Black-image addresses.
 */
int func_021C1248(u8 *a0, u8 *a1, u32_021C1248 *a2)
{
    u32_021C1248 v;
    u32_021C1248 i;
    u32_021C1248 sum = 0;

    if (*a2 + 0x10 >= g_021CADE4[2])
        return 0;

    for (i = 0; i < 0x10; i++) {
        v = a0[i + 0x404];
        a1[*a2] = v;
        (*a2)++;
        sum += v;
    }

    if (*a2 + sum >= g_021CADE4[2])
        return 0;

    for (i = 0; i < sum; i++) {
        a1[*a2] = a0[i + 0x424];
        (*a2)++;
    }
    return 1;
}

/*
 * Symbols:
 *   (none)
 *
 * Sums 16 bytes at +0x404 and returns the total plus 0x11.
 *
 * Addresses are Black-image addresses.
 */
int func_021C12F4(unsigned char *p)
{
    unsigned int i;
    int sum = 0;

    for (i = 0; i < 0x10; i++)
        sum += p[i + 0x404];

    return sum + 0x11;
}


static int Yos_JpegEncoderComponentSequential(huffman_structure *dc, huffman_structure *ac,
                                              component_structure_021C131C *component, u8 *dst,
                                              u32_021C131C *ptr, u32_021C131C col, u32_021C131C row)
{
    unsigned long index;
    unsigned long ssss;
    unsigned long zerorun;
    long bits;
    short *du;
    long diff;
    int value;
    unsigned long rrrrssss;
    unsigned long inner_tmp;

    du = component->mCofficients + (row * component->mCols + col) * 64;
    value = du[0];
    diff = value - component->mLastDcValue;
    component->mLastDcValue = value;

    if (diff >= 0) {
        value = diff;
    } else {
        diff = -diff;
        value = ~diff;
    }
    index = 0;
    while (diff != 0) {
        index++;
        diff >>= 1;
    }

    if (!Yos_BitWrite(dst, ptr, dc->mEhufco[index], dc->mEhufsi[index]))
        return 0;
    if (index != 0) {
        if (!Yos_BitWrite(dst, ptr, value, index))
            return 0;
    }

    zerorun = 0;
    for (ssss = 1; ssss < 64; ssss++) {
        if (du[JpegZigZagInputOrderCodes[ssss]] != 0) {
            while (zerorun >= 16) {
                if (!Yos_BitWrite(dst, ptr, ac->mEhufco[0xF0], ac->mEhufsi[0xF0]))
                    return 0;
                zerorun -= 16;
            }
            value = du[JpegZigZagInputOrderCodes[ssss]];
            if (value >= 0) {
                bits = value;
            } else {
                value = -value;
                bits = ~value;
            }
            for (inner_tmp = 0; value != 0; inner_tmp++)
                value >>= 1;
            rrrrssss = inner_tmp | (zerorun << 4);
            if (!Yos_BitWrite(dst, ptr, ac->mEhufco[rrrrssss], ac->mEhufsi[rrrrssss]))
                return 0;
            if (inner_tmp != 0) {
                if (!Yos_BitWrite(dst, ptr, bits, inner_tmp))
                    return 0;
            }
            zerorun = 0;
        } else {
            zerorun++;
        }
    }
    if (zerorun != 0) {
        if (!Yos_BitWrite(dst, ptr, ac->mEhufco[0], ac->mEhufsi[0]))
            return 0;
    }
    return 1;
}


void Yos_JpegEncodeSample2to2Component(unsigned char *buffer, long *qTable,
                                       component_structure_021C1500 *component, unsigned long dx)
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


/*
 * sdk:      Yos_JpegEncodeSample2to1Component (libssp.TWL.HYB.a jpegenc.o)
 *
 * Static: horizontal 2:1 chroma subsampling of a component plane into 8x8 blocks, each handed to the forward DCT.
 */
void func_021C1710(unsigned char *buffer, long *qTable, component_structure_021C1710 *component, unsigned long dx)
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

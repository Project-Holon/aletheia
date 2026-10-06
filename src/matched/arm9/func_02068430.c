/*
 * function: func_02068430
 * address:  0x02068430
 * packet:   pkt_020682DC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02069BA0  0x02069BA0  arm
 *
 * NitroSystem g2d_CharCanvas.c LetterChar(LC_INFO *): blit one glyph's
 * bit-packed pixels into one 8x8 character, clipped to the character, at 4
 * or 8 bits per destination pixel, adding the colour base cl to every
 * non-zero source value.  Each row opens an NNSiG2dBitReader at
 * src + offset / 8 and discards offset % 8 bits first
 * (NNSi_G2dBitReaderRead = func_02069BA0).  The LC_INFO block is the
 * ten-word "Blit" struct of docs/families/cluster_020682DC.h.
 *
 * Closed in wave 13 on the first compile of the library body with the
 * TwlSDK MATH_IMax / MATH_IMin inlines and NNSi_G2dBitReaderInit; the
 * wave-11 transcription sat at 119 out.  ../2.0/sp2 and sp2p2 identical;
 * 1.1p1 is 564 bytes.
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct LC_INFO {
    const u8 *dst;
    const u8 *src;
    int ofs_x;
    int ofs_y;
    int width;
    int height;
    int dsrc;
    int srcBpp;
    int dstBpp;
    u32 cl;
} LC_INFO;

typedef struct NNSiG2dBitReader {
    const u8 *src;
    s8 availableBits;
    u8 bits;
    u8 padding_[2];
} NNSiG2dBitReader;

struct BitReader;
extern u32 func_02069BA0(struct BitReader *reader, int nBits);   /* NNSi_G2dBitReaderRead */

static inline int MATH_IMax(int a, int b)
{
    return (a >= b) ? a : b;
}
static inline int MATH_IMin(int a, int b)
{
    return (a <= b) ? a : b;
}

static inline void NNSi_G2dBitReaderInit(NNSiG2dBitReader *reader, const void *src)
{
    reader->availableBits = 0;
    reader->src = (const u8 *)src;
    reader->bits = 0;
}

void func_02068430(LC_INFO *i)
{
    const u8 *pSrc;
    u32 x_st;
    u32 x_ed;
    u32 y_st;
    u32 y_ed;
    u32 offset;

    {
        u32 bit_y_begin;

        x_st = (unsigned int)MATH_IMax(i->ofs_x, 0);
        y_st = (unsigned int)MATH_IMax(i->ofs_y, 0);
        x_ed = (unsigned int)MATH_IMin(8, i->ofs_x + i->width);
        y_ed = (unsigned int)MATH_IMin(8, i->ofs_y + i->height);

        bit_y_begin = (unsigned int)-MATH_IMin(i->ofs_y, 0);
        offset = -MATH_IMin(i->ofs_x, 0) * i->srcBpp + bit_y_begin * i->dsrc;

        pSrc = i->src;
    }

    {
        u32 x;
        const int dsrc = i->dsrc;
        const int srcBpp = i->srcBpp;
        const int dstBpp = i->dstBpp;

        x_st *= dstBpp;
        x_ed *= dstBpp;

        if ( dstBpp == 4 ) {
            u32 *pDst = (u32 *)i->dst + y_st;
            u32 *pDstEnd = (u32 *)i->dst + y_ed;
            u32 cl = i->cl;

            for ( ; pDst < pDstEnd; pDst++) {
                NNSiG2dBitReader reader;
                u32 out_line = *pDst;

                NNSi_G2dBitReaderInit(&reader, pSrc + offset / 8);
                (void)func_02069BA0((struct BitReader *)(&reader), (int)offset % 8);

                for (x = x_st; x < x_ed; x += 4) {
                    u32 bits = func_02069BA0((struct BitReader *)(&reader), srcBpp);

                    if ( bits != 0 ) {
                        out_line = (out_line & ~(0xF << x)) | ((cl + bits) << x);
                    }
                }

                *pDst = out_line;

                offset += dsrc;
            }
        } else {
            u32 *pDst = (u32 *)((u64 *)i->dst + y_st);
            u32 * const pDstEnd = (u32 *)((u64 *)i->dst + y_ed);
            u32 cl = i->cl;

            for ( ; pDst < pDstEnd; pDst += 2) {
                NNSiG2dBitReader reader;
                u32 out_line_0 = *pDst;
                u32 out_line_1 = *(pDst + 1);

                NNSi_G2dBitReaderInit(&reader, pSrc + offset / 8);
                (void)func_02069BA0((struct BitReader *)(&reader), (int)offset % 8);

                for (x = x_st; x < x_ed; x += 8) {
                    u32 bits = func_02069BA0((struct BitReader *)(&reader), srcBpp);

                    if ( bits != 0 ) {
                        if ( x < 32 ) {
                            out_line_0 = (out_line_0 & ~((u32)0xFF << x)) | ((u32)(cl + bits) << x);
                        } else {
                            const u32 x_32 = x - 32;
                            out_line_1 = (out_line_1 & ~((u32)0xFF << x_32)) | ((u32)(cl + bits) << x_32);
                        }
                    }
                }

                *pDst = out_line_0;
                *(pDst + 1) = out_line_1;

                offset += dsrc;
            }
        }
    }
}

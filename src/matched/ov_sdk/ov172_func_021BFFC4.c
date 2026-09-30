/*
 * function: func_021BFFC4
 * address:  0x021BFFC4
 * packet:   pkt_ov172_021BFFC4
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    all 940 bytes reproduced (905 concrete + the 35 bytes of the 11
 *           relocation fields) and all 11 sites resolve, so EXACT.
 *
 *           Witnesses for the two data words: both bcode2 (0x021C88F0) and
 *           SSPiDecodeSignCheckMode (0x021CADA4) live in ov172's own bss
 *           (0x021C88E0..0x021CC540), so the site's own window already fixes
 *           which overlay they are and the original image's pool words at
 *           +0x03A8 / +0x039C already hold those addresses (sole-ref/self).
 *           bcode2's `symbols:` line deliberately carries NO overlay hint:
 *           ov114 starts an object at 0x021C88F0 too, so an ov172 hint there is
 *           contested (audit finding 6) and only the site window may choose.
 *
 *           Recovered forms: the option-to-DSP mask is a parenthesised OR of
 *           three `(opt & m) ? m : 0` terms in the order 1, 4, 0x10; the tag
 *           loops use an unsigned counter; the second entry-count check adds 2
 *           to offset before the multiply test; the tail is one `if (both
 *           halves) { ... return 1;} return 0;`; locals declared offset,
 *           registrationNumber, moff, i, tag.  bcode2 is reached only through
 *           its +0x1c int, so the struct is spelled to put err at +0x1c.
 *
 * sdk:      SSP_StartJpegDecoder (libssp.TWL.HYB.a jpegdec.o)
 *
 * symbols:
 *   OS_IsRunOnTwl           0x02085D3C  arm
 *   MI_CpuCopy8             0x02082D44  arm
 *   MI_CpuFill8             0x02082BCC  arm
 *   AESi_Init               0x027073AC  arm
 *   AESi_VerifySignForJpeg  0x0270788C  arm
 *   Mel_JPEGDecodeExif      0x021BE468  arm  ov172
 *   Mel_JPEGDecode          0x021BE5C4  arm  ov172
 *   SSPiDecodeSignCheckMode 0x021CADA4  data ov172
 *   bcode2                  0x021C88F0  data
 */

typedef struct {
    unsigned int f00;
    unsigned int f04;
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    int err;      /* +0x1c */
} BCode2;

extern int OS_IsRunOnTwl(void);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void AESi_Init(void);
extern int AESi_VerifySignForJpeg(void *sign, void *data, unsigned long size);
extern int Mel_JPEGDecodeExif(unsigned char *a, unsigned long length, int option);
extern int Mel_JPEGDecode(unsigned char *d, unsigned char *a, unsigned long length,
                          long maxWidth, long maxHeight, int option);
extern int SSPiDecodeSignCheckMode;
extern BCode2 bcode2;

int func_021BFFC4(unsigned char *data, unsigned long size, void *dst,
                  short *width, short *height, unsigned long option)
{
    unsigned long offset;
    unsigned long registrationNumber;
    unsigned long moff;
    unsigned long i;
    unsigned short tag;
    int aesResult;
    int ret;
    int optionForDsp;
    unsigned char sign[28];

    if (SSPiDecodeSignCheckMode == 1) {
        if (OS_IsRunOnTwl() == 1) {
            if (size < 0x17)
                return 0;
            offset = data[0x13] + 0xc;
            if (offset + 2 > size)
                return 0;
            registrationNumber =
                (unsigned short)(data[offset + 1] + (data[offset] << 8));
            if (registrationNumber * 12 + (offset + 2) > size)
                return 0;
            tag = 0;
            offset += 2;
            for (i = 0; i < registrationNumber; offset += 0xc, i++) {
                tag = (unsigned short)(data[offset + 1] + (data[offset] << 8));
                if (tag == 0x8769) {
                    offset = (data[offset + 8] << 24) + (data[offset + 9] << 16)
                           + (data[offset + 10] << 8) + data[offset + 11] + 0xc;
                    break;
                }
            }
            if (tag != 0x8769)
                return 0;

            if (offset + 2 > size)
                return 0;
            registrationNumber =
                (unsigned short)(data[offset + 1] + (data[offset] << 8));
            offset += 2;
            if (registrationNumber * 12 + offset > size)
                return 0;
            tag = 0;
            for (i = 0; i < registrationNumber; offset += 0xc, i++) {
                tag = (unsigned short)(data[offset + 1] + (data[offset] << 8));
                if (tag == 0x927c) {
                    offset = (data[offset + 8] << 24) + (data[offset + 9] << 16)
                           + (data[offset + 10] << 8) + data[offset + 11] + 0xc;
                    break;
                }
            }
            if (tag != 0x927c)
                return 0;

            moff = offset;
            if (moff + 4 > size)
                return 0;
            if (data[moff + 2] != 0x10 || data[moff + 3] != 0)
                return 0;
            if (moff + 0xe > size)
                return 0;
            offset = (data[moff + 0xa] << 24) + (data[moff + 0xb] << 16)
                   + (data[moff + 0xc] << 8) + data[moff + 0xd] + 0xc;
            if (offset + 0x1c > size)
                return 0;

            MI_CpuCopy8(data + offset, sign, 0x1c);
            MI_CpuFill8(data + offset, 0, 0x1c);
            if (OS_IsRunOnTwl())
                AESi_Init();
            aesResult = AESi_VerifySignForJpeg(sign, data, size);
            MI_CpuCopy8(sign, data + offset, 0x1c);
            if (aesResult != 1)
                return 0;
        }
    }

    bcode2.err = 0;
    optionForDsp = (((option & 1) ? 1 : 0) | ((option & 4) ? 4 : 0)) | ((option & 0x10) ? 0x10 : 0);

    if (option & 0x10) {
        ret = Mel_JPEGDecodeExif(data, size, optionForDsp);
    } else {
        ret = Mel_JPEGDecode(dst, data, size, *width, *height, optionForDsp);
    }

    if (bcode2.err != 0)
        return 0;
    if ((ret & 0xffff0000) != 0 && (unsigned short)ret != 0) {
        if ((option & 0x10) == 0) {
            *width = ret;
            *height = ret >> 16;
        }
        return 1;
    }
    return 0;
}

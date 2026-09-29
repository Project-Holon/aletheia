/*
 * function: func_021BFFC4
 * address:  0x021BFFC4
 * packet:   pkt_ov172_021BFFC4
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  full reconstruction, compiled 928 of 940 bytes, all 11 relocs
 *           resolve.  Two residual codegen gaps: (a) the option-to-DSP mask
 *           is `(option & 4) | (option & 1) | (option & 0x10)` and the
 *           original builds it with three conditional moves then two `orr`
 *           (r2=(opt&4)?4:0, r1=(opt&1)?1:0, r3=(opt&0x10)?0x10:0, then
 *           r1|r2 and r3|that) while this C emits `orrne` chains (12 bytes
 *           shorter); the ternary spelling is the likely source.  (b) the
 *           scratch split in the two tag-search loops differs (original
 *           keeps the running entry offset in r1 and the +2 base in r2;
 *           this C swaps them), which is a pure allocation difference that
 *           requires pinning the locals.
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
 *   bcode2                  0x021C88F0  data ov172
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
    unsigned short tag;
    unsigned long registrationNumber;
    unsigned long offset;
    unsigned long moff;
    int i;
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
            for (i = 0; i < (int)registrationNumber; offset += 0xc, i++) {
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
            if (registrationNumber * 12 + (offset + 2) > size)
                return 0;
            tag = 0;
            offset += 2;
            for (i = 0; i < (int)registrationNumber; offset += 0xc, i++) {
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
    optionForDsp = 0;
    if (option & 4)
        optionForDsp |= 4;
    if (option & 1)
        optionForDsp |= 1;
    if (option & 0x10)
        optionForDsp |= 0x10;

    if (option & 0x10) {
        ret = Mel_JPEGDecodeExif(data, size, optionForDsp);
    } else {
        ret = Mel_JPEGDecode(dst, data, size, *width, *height, optionForDsp);
    }

    if (bcode2.err != 0)
        return 0;
    if ((ret & 0xffff0000) == 0)
        return 0;
    if ((unsigned short)ret == 0)
        return 0;
    if ((option & 0x10) == 0) {
        *width = ret;
        *height = ret >> 16;
    }
    return 1;
}

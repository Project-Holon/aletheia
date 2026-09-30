/*
 * function: SSPi_JpegEncoderDoSign
 * address:  0x021C1AE4
 * packet:   pkt_021C1AE4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SSPi_JpegEncoderDoSign (libssp.TWL.HYB.a jpegenc.o)
 *
 * Walks the APP1 Exif IFD entries: finds the Exif sub-IFD (0x8769), then the
 * maker note (0x927c), then signs 0x1c bytes at the maker-note payload with the
 * AES unit (or a fill when the AES path is unavailable).
 *
 * Lane U57 (2026-09-30): the vendor object's DWARF fixed this row.  Its six
 * locals are exactly tag(r3), i(r7), registrationNumber(r2), sign[fb], p(r0),
 * offset(r1), and DWARF lists them in reverse source order - so the source
 * declares offset, p, sign, registrationNumber, i, tag.  There is no local for
 * the gBitLen[8] bound: the vendor spells it inline at all eight guards, which
 * is what keeps it in ip and leaves r2 free for registrationNumber (a `limit`
 * local lands in r2 and rotates the whole body, 90 concrete bytes).  There is
 * no `base` local either: offset itself holds the IFD start, the `offset + 2`
 * guard temporary is reused by the following `offset += 2`, and `p = dst +
 * offset` plus a bare `dst[offset]` are what put the p[1] / base+index load
 * pair in the image's order.  Was 103 (size already exact), now EXACT.
 *
 * symbols:
 *   MI_CpuFill8                     0x02082BCC  arm
 *   OS_IsRunOnTwl                   0x02085D3C  arm
 *   AESi_Init                       0x027073AC  arm
 *   AESi_SignForJpeg                0x02707774  arm
 *   MI_CpuCopy8                     0x02082D44  arm
 *   gBitLen                         0x021CADE4  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov172_func_021C1AE4.c \
 *       --func SSPi_JpegEncoderDoSign --addr 0x021C1AE4 --region ov172 \
 *       --arm --cc 1.1p1 --lang c99
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 gBitLen[];
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern int OS_IsRunOnTwl(void);
extern void AESi_Init(void);
extern int AESi_SignForJpeg(u8 *sign, u8 *dst, u32 ptr);
extern void MI_CpuCopy8(void *srcp, void *dstp, u32 size);

static int SSPi_JpegEncoderDoSign(u8 *dst, unsigned long ptr)
{
    unsigned long offset;
    unsigned char *p;
    unsigned char sign[28];
    unsigned long registrationNumber;
    int i;
    u16 tag;

    if (*(u32 *)(gBitLen + 8) < 0x17)
        return 0;

    offset = dst[0x13] + 0xc;
    if (offset + 2 > *(u32 *)(gBitLen + 8))
        return 0;
    p = dst + offset;
    registrationNumber = (u16)((p[1] + (dst[offset] << 8)));
    offset += 2;
    if (registrationNumber * 0xc + offset > *(u32 *)(gBitLen + 8))
        return 0;

    tag = 0;
    for (i = 0; i < registrationNumber; i++) {
        p = dst + offset;
        tag = (u16)((p[1] + (dst[offset] << 8)));
        if (tag == 0x8769) {
            offset = (((u32)p[8] << 24) + ((u32)p[9] << 16) +
                      ((u32)p[10] << 8) + p[11]) + 0xc;
            break;
        }
        offset += 0xc;
    }
    if (tag != 0x8769)
        return 0;

    if (offset + 2 > *(u32 *)(gBitLen + 8))
        return 0;
    p = dst + offset;
    registrationNumber = (u16)((p[1] + (dst[offset] << 8)));
    offset += 2;
    if (registrationNumber * 0xc + offset > *(u32 *)(gBitLen + 8))
        return 0;

    tag = 0;
    for (i = 0; i < registrationNumber; i++) {
        p = dst + offset;
        tag = (u16)((p[1] + (dst[offset] << 8)));
        if (tag == 0x927c) {
            offset = (((u32)p[8] << 24) + ((u32)p[9] << 16) +
                      ((u32)p[10] << 8) + p[11]) + 0xc;
            break;
        }
        offset += 0xc;
    }
    if (tag != 0x927c)
        return 0;

    if (offset + 4 > *(u32 *)(gBitLen + 8))
        return 0;
    p = dst + offset;
    if (p[2] != 0x10 || p[3] != 0)
        return 0;
    if (offset + 0xe > *(u32 *)(gBitLen + 8))
        return 0;

    offset = (((u32)p[0xa] << 24) + ((u32)p[0xb] << 16) +
              ((u32)p[0xc] << 8) + p[0xd]) + 0xc;
    if (offset + 0x1c > *(u32 *)(gBitLen + 8))
        return 0;

    MI_CpuFill8(dst + offset, 0, 0x1c);
    if (OS_IsRunOnTwl())
        AESi_Init();
    if (AESi_SignForJpeg(sign, dst, ptr) != 1)
        return 0;
    MI_CpuCopy8(sign, dst + offset, 0x1c);
    return 1;
}

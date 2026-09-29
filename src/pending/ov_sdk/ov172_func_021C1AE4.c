/*
 * function: SSPi_JpegEncoderDoSign
 * address:  0x021C1AE4
 * packet:   pkt_ov172_021C1AE4
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker: codegen/register allocation.  Segment walk reconstructed in full
 *   (IFD tag 0x8769 -> EXIF sub-IFD tag 0x927c -> sign block) and all six
 *   relocations resolve, but mwcc -O4,p picks different registers than the
 *   original throughout: original keeps `limit` in ip (r12) and stores the
 *   u16 count/tag in r2, mine keeps it in r0/r2 and quantises into r3.
 *   Tried u32 vs u16 count/tag, `|` vs `+` for the big-endian reads, and an
 *   explicit base+2 cursor local; the allocation (not the logic) is what
 *   differs.  Closest 708 of 680 bytes.
 *
 * sdk:      SSPi_JpegEncoderDoSign (libssp.TWL.HYB.a jpegenc.o)
 *
 * symbols:
 *   MI_CpuFill8                     0x02082BCC  arm
 *   OS_IsRunOnTwl                   0x02085D3C  arm
 *   AESi_Init                       0x027073AC  arm
 *   AESi_SignForJpeg                0x02707774  arm
 *   MI_CpuCopy8                     0x02082D44  arm
 *   gBitLen                         0x021CADE4  data  ov172
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

static int SSPi_JpegEncoderDoSign(u8 *dst, u32 ptr)
{
    unsigned char sign[28];
    u32 limit;
    u32 base;
    u32 offset;
    u16 n;
    int tag;
    int i;

    limit = *(u32 *)(gBitLen + 8);
    if (limit < 0x17)
        return 0;

    base = dst[0x13] + 0xc;
    if (base + 2 > limit)
        return 0;
    offset = base + 2;
    n = (u16)((dst[base] << 8) + dst[base + 1]);
    if (n * 0xc + offset > limit)
        return 0;

    tag = 0;
    for (i = 0; i < n; i++) {
        tag = (u16)((dst[offset] << 8) + dst[offset + 1]);
        if (tag == 0x8769) {
            offset = (((u32)dst[offset + 8] << 24) + ((u32)dst[offset + 9] << 16) +
                      ((u32)dst[offset + 10] << 8) + dst[offset + 11]) + 0xc;
            break;
        }
        offset += 0xc;
    }
    if (tag != 0x8769)
        return 0;

    base = offset;
    if (base + 2 > limit)
        return 0;
    offset = base + 2;
    n = (u16)((dst[base] << 8) + dst[base + 1]);
    if (n * 0xc + offset > limit)
        return 0;

    tag = 0;
    for (i = 0; i < n; i++) {
        tag = (u16)((dst[offset] << 8) + dst[offset + 1]);
        if (tag == 0x927c) {
            offset = (((u32)dst[offset + 8] << 24) + ((u32)dst[offset + 9] << 16) +
                      ((u32)dst[offset + 10] << 8) + dst[offset + 11]) + 0xc;
            break;
        }
        offset += 0xc;
    }
    if (tag != 0x927c)
        return 0;

    if (offset + 4 > limit)
        return 0;
    if (dst[offset + 2] != 0x10 || dst[offset + 3] != 0)
        return 0;
    if (offset + 0xe > limit)
        return 0;

    offset = (((u32)dst[offset + 0xa] << 24) + ((u32)dst[offset + 0xb] << 16) +
              ((u32)dst[offset + 0xc] << 8) + dst[offset + 0xd]) + 0xc;
    if (offset + 0x1c > limit)
        return 0;

    MI_CpuFill8(dst + offset, 0, 0x1c);
    if (OS_IsRunOnTwl())
        AESi_Init();
    if (AESi_SignForJpeg(sign, dst, ptr) != 1)
        return 0;
    MI_CpuCopy8(sign, dst + offset, 0x1c);
    return 1;
}

/*
 * function: SSPi_JpegEncoderDoSign
 * address:  0x021C1AE4
 * packet:   pkt_ov172_021C1AE4
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (size-exact, allocator only)
 *
 * blocker: register allocation only, SIZE-EXACT.  Lane T30 fixed the size
 *   (732 -> 680 B): every 4-byte big-endian read addresses `dst[offset + 8]`
 *   ... `dst[offset + 0xb]` inline, so mwcc spent four `add rN, r1, #k` per
 *   read; with a `const unsigned char *p = dst + offset;` local and `p[8]`
 *   ... `p[11]` the image's `add r0, r5, r1` + `[r0,#8..#0xb]` form appears
 *   (same for the `[2]`/`[3]` and `[0xa..#0xd]` checks).  `unsigned int i`
 *   turns the loop guards into the image's `bls`/`blo`, and spelling the
 *   big-endian read `(dst[offset] << 8) + dst[offset+1]` -- i.e. dst[offset]
 *   loaded first -- matches the image's load pair; assigning `offset = base+2`
 *   AFTER the count read in the second block stops the `mov rN, r1` copy.
 *   Left: 680/680 but 103 concrete bytes, all one register rotation from
 *   +0x10 -- the image puts the gBitLen load in ip (`ldr ip,[r2,#8]`) and keeps
 *   `n` in r2, ours reuses r2 for the load and puts `n` in ip; that extra live
 *   value pushes `i` of the second loop into r8 and costs a `push {..., r8}`
 *   the image does not have.  First differing instruction:
 *     +0010 image `ldr ip, [r2, #8]` | ours `ldr r2, [r2, #8]`.
 *   Tried and rejected (all 103-137): `((u32 *)gBitLen)[2]`, a named `u32 *lp`
 *   block, a function-scope `p`, declaring n/tag/p/i in every order, `for`
 *   block-scoped `p` vs assigned.  Pin/flag shut (see lane T19).
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
    const unsigned char *p;
    int tag;
    unsigned int i;

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
        const unsigned char *p = dst + offset;
        tag = (u16)((dst[offset + 1] + (dst[offset] << 8)));
        if (tag == 0x8769) {
            offset = (((u32)p[8] << 24) + ((u32)p[9] << 16) +
                      ((u32)p[10] << 8) + p[11]) + 0xc;
            break;
        }
        offset += 0xc;
    }
    if (tag != 0x8769)
        return 0;

    base = offset;
    if (base + 2 > limit)
        return 0;
    n = (u16)((dst[base] << 8) + dst[base + 1]);
    offset = base + 2;
    if (n * 0xc + offset > limit)
        return 0;

    tag = 0;
    for (i = 0; i < n; i++) {
        const unsigned char *p = dst + offset;
        tag = (u16)((dst[offset + 1] + (dst[offset] << 8)));
        if (tag == 0x927c) {
            offset = (((u32)p[8] << 24) + ((u32)p[9] << 16) +
                      ((u32)p[10] << 8) + p[11]) + 0xc;
            break;
        }
        offset += 0xc;
    }
    if (tag != 0x927c)
        return 0;

    if (offset + 4 > limit)
        return 0;
    p = dst + offset;
    if (p[2] != 0x10 || p[3] != 0)
        return 0;
    if (offset + 0xe > limit)
        return 0;

    offset = (((u32)p[0xa] << 24) + ((u32)p[0xb] << 16) +
              ((u32)p[0xc] << 8) + p[0xd]) + 0xc;
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

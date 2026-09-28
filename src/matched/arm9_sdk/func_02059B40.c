/*
 * function: func_02059B40
 * address:  0x02059B40
 * packet:   pkt_02059B40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Base64Encode (libdwccommon.TWL.HYB.a dwc_base64.o)
 *
 * symbols:
 *   MI_CpuFill8       0x02082BCC arm
 *   MI_CpuCopy8       0x02082D44 arm
 *   DWCi_base64_table 0x020A8028 data a4
 */

typedef unsigned char u8;
typedef unsigned long u32;

#define MATH_MIN(a, b) (((a) < (b)) ? (a) : (b))

extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern char *DWCi_base64_table;

int func_02059B40(const char *src, u32 srclen, char *dst, u32 dstlen)
{
    u32 required_dstsize;
    u32 num_dstout;
    const char *srcread_index;
    const char *tail_src;
    char *dstwrite_index;
    u8 read_buffer[3];

    required_dstsize = (srclen / 3) * 4 + ((srclen % 3) ? 4 : 0);
    if (dst == 0)
        return (int)required_dstsize;
    if (dstlen < required_dstsize)
        return -1;

    tail_src = src + srclen;
    dstwrite_index = dst;
    for (srcread_index = src; srcread_index != tail_src;) {
        int rest = tail_src - srcread_index;
        int len;

        num_dstout = ((u32)rest * 8) / 6 + ((((u32)rest * 8) % 6) ? 1 : 0);
        len = MATH_MIN(rest, 3);
        MI_CpuFill8(read_buffer, 0, sizeof(read_buffer));
        MI_CpuCopy8(srcread_index, read_buffer, len);
        dstwrite_index[0] = DWCi_base64_table[read_buffer[0] >> 2];
        dstwrite_index[1] = (num_dstout >= 2) ? DWCi_base64_table[((read_buffer[0] << 4) & 0x3F) | (read_buffer[1] >> 4)] : '*';
        dstwrite_index[2] = (num_dstout >= 3) ? DWCi_base64_table[((read_buffer[1] << 2) & 0x3F) | (read_buffer[2] >> 6)] : '*';
        dstwrite_index[3] = (num_dstout >= 4) ? DWCi_base64_table[read_buffer[2] & 0x3F] : '*';
        srcread_index += len;
        dstwrite_index += 4;
    }
    return dstwrite_index - dst;
}

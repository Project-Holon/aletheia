/*
 * function: func_02059CBC
 * address:  0x02059CBC
 * packet:   pkt_02059CBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * notes:    13 bytes: the '*'-count lives in ip and i in r5 where the object has count r5, i r6 and the /8 result in ip; rest exact
 *
 * sdk:      DWC_Base64Decode (libdwccommon.TWL.HYB.a dwc_base64.o)
 *
 */

typedef unsigned long u32;

int func_02059CBC(const char *src, u32 srclen, char *dst, u32 dstlen)
{
    const char *srcread_index;
    char *dstwrite_index;
    char read_buffer[4];
    int required_dstsize;
    int i;

    if (srclen % 4)
        return -1;

    required_dstsize = 0;
    for (i = 0; i < (int)srclen; i++) {
        if (src[i] != '*')
            required_dstsize += 6;
    }

    required_dstsize /= 8;

    if (dst == 0)
        return required_dstsize;
    if (dstlen < required_dstsize)
        return -1;
    if (srclen == 0)
        return 0;

    srcread_index = src;
    dstwrite_index = dst;
    do {
        for (i = 0; i < 4; i++) {
            char c = srcread_index[i];

            if (c >= 'A' && c <= 'Z')
                read_buffer[i] = c - 'A';
            else if (c >= 'a' && c <= 'z')
                read_buffer[i] = c - 'a' + 26;
            else if (c >= '0' && c <= '9')
                read_buffer[i] = c - '0' + 52;
            else if (c == '.')
                read_buffer[i] = 62;
            else if (c == '-')
                read_buffer[i] = 63;
            else
                read_buffer[i] = 0;
        }
        dstwrite_index[0] = (char)((read_buffer[0] << 2) | (read_buffer[1] >> 4));
        srcread_index += 4;
        i = dstwrite_index + 1 - dst;
        if (i >= required_dstsize)
            break;
        dstwrite_index[1] = (char)((read_buffer[1] << 4) | (read_buffer[2] >> 2));
        i = dstwrite_index + 2 - dst;
        if (i >= required_dstsize)
            break;
        dstwrite_index[2] = (char)((read_buffer[2] << 6) | read_buffer[3]);
        dstwrite_index += 3;
        i = dstwrite_index - dst;
    } while (i < required_dstsize);

    return i;
}

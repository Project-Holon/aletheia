/*
 * function: func_0217F824
 * address:  0x0217F824
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Pack up to three input bytes into four 6-bit values (the base64 index
 * order).  The source bytes go through a local three-byte buffer, padded
 * with zeros before the shift network runs.
 */

typedef unsigned char u8;

void func_0217F824(const char *src, u8 *dst, int n)
{
    unsigned char buf[4];
    int i;

    for (i = 0; i < n; i++)
        buf[i] = src[i];
    for (; i < 3; i++)
        buf[i] = 0;
    dst[0] = buf[0] >> 2;
    dst[1] = ((buf[0] & 3) << 4) | (buf[1] >> 4);
    dst[2] = ((buf[1] & 0xf) << 2) | (buf[2] >> 6);
    dst[3] = buf[2] & 0x3f;
}

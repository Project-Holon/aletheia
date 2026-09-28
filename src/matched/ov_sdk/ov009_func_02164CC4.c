/*
 * function: CPSi_big_from_char
 * address:  0x02164CC4
 * packet:   pkt_ov009_02164CC4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_big_from_char (biginteger.o)
 *
 * symbols:
 *   MI_CpuFill8                      0x02082bcc arm
 */

void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);

void CPSi_big_from_char(unsigned short *d, unsigned char *s, int numbytes, int digits)
{
    MI_CpuFill8(d, 0, digits * 2);
    s += numbytes - 1;
    while (numbytes > 1) {
        *d++ = (unsigned short)(s[0] + (s[-1] << 8));
        s -= 2;
        numbytes -= 2;
    }
    if (numbytes > 0)
        *d = *s;
}

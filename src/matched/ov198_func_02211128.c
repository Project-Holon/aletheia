/*
 * function: func_02211128
 * address:  0x02211128
 * packet:   pkt_02211128
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */

int func_02211128(unsigned char *p, unsigned char *a, unsigned char *b, int clear)
{
    int i;

    for (i = 1; i >= 0; i--) {
        if (*(unsigned short *)(p + 0x249c + i * 4) == 0xff) {
            continue;
        }
        *a = (unsigned char)*(unsigned short *)(p + 0x249c + i * 4);
        *b = (unsigned char)*(unsigned short *)(p + 0x249c + 2 + i * 4);
        if (clear == 1) {
            *(unsigned short *)(p + 0x249c + i * 4) = 0xff;
            *(unsigned short *)(p + 0x249c + 2 + i * 4) = 0xff;
        }
        return 1;
    }
    return 0;
}

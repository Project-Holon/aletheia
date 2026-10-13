/*
 * function: gs_encode
 * address:  0x0219B858
 * packet:   pkt_ov009_0219B858
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gs_encode (qr2.o)
 *
 * symbols:
 *   encode_ct  0x0219B810  arm  ov009
 */

extern unsigned char encode_ct(unsigned char c);

void gs_encode(unsigned char *ins, int size, unsigned char *result)
{
    int i;
    int pos;
    unsigned char trip[3];
    unsigned char kwart[4];

    i = 0;
    while (i < size) {
        for (pos = 0; pos <= 2; pos++, i++) {
            if (i < size)
                trip[pos] = *ins++;
            else
                trip[pos] = 0;
        }
        kwart[0] = trip[0] >> 2;
        kwart[1] = ((trip[0] & 3) << 4) + (trip[1] >> 4);
        kwart[2] = ((trip[1] & 15) << 2) + (trip[2] >> 6);
        kwart[3] = trip[2] & 63;
        for (pos = 0; pos <= 3; pos++)
            *result++ = encode_ct(kwart[pos]);
    }
    *result = 0;
}

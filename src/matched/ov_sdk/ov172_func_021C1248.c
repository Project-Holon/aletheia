/*
 * function: Yos_JpegEncoderHuffmanEncoderPrintTable
 * address:  0x021C1248
 * packet:   pkt_021C2AD0
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Block copier with a running sum: appends the 16 bytes at a0+0x404 to the
 * output buffer a1 (advancing the cursor *a2), accumulates their sum, then
 * appends `sum` more bytes from a0+0x424.  Both the pre-check and the post-check
 * compare the cursor (plus 0x10, then plus sum) against the limit at +8 of
 * gJpegBitWriterState and return 0 when the buffer would overrun; returns 1 otherwise.
 * The limit is re-read from the global at each of the two sites (the global is
 * volatile in the original), which is what makes the pool word load twice.
 *
 * symbols:
 *   gJpegBitWriterState  0x021CADE4  data  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern volatile u32 gJpegBitWriterState[];

int Yos_JpegEncoderHuffmanEncoderPrintTable(u8 *a0, u8 *a1, u32 *a2)
{
    u32 v;
    u32 i;
    u32 sum = 0;

    if (*a2 + 0x10 >= gJpegBitWriterState[2])
        return 0;

    for (i = 0; i < 0x10; i++) {
        v = a0[i + 0x404];
        a1[*a2] = v;
        (*a2)++;
        sum += v;
    }

    if (*a2 + sum >= gJpegBitWriterState[2])
        return 0;

    for (i = 0; i < sum; i++) {
        a1[*a2] = a0[i + 0x424];
        (*a2)++;
    }
    return 1;
}

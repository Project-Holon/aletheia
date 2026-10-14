/*
 * function: SSP_GetJpegEncoderBufferSize
 * address:  0x021C1A80
 * packet:   pkt_ov172_021C1A80
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SSP_GetJpegEncoderBufferSize (jpegenc.o)
 *
 * symbols:
 *   Yos_JPEGGetMemorySize  0x021C19E4  arm  ov172
 */

extern unsigned long Yos_JPEGGetMemorySize(unsigned long width, unsigned long height, unsigned long sampling);

unsigned long SSP_GetJpegEncoderBufferSize(unsigned long width, unsigned long height, unsigned long sampling, unsigned long option)
{
    unsigned long thumb;
    unsigned long mainSize;
    unsigned long thumbSize;

    thumb = option & 1;
    if (thumb) {
        if (width < 160)
            width = 160;
        if (height < 120)
            height = 120;
    }
    mainSize = Yos_JPEGGetMemorySize(width, height, sampling);
    thumbSize = Yos_JPEGGetMemorySize(160, 120, 1);
    if (mainSize > thumbSize)
        return mainSize + (thumb ? 0x12c00 : 0);
    return thumbSize + (thumb ? 0x12c00 : 0);
}

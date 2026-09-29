/*
 * function: func_021C1A80
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
 *   func_021C19E4  0x021C19E4  arm  ov172
 */

extern unsigned long func_021C19E4(unsigned long width, unsigned long height, unsigned long sampling);

unsigned long func_021C1A80(unsigned long width, unsigned long height, unsigned long sampling, unsigned long option)
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
    mainSize = func_021C19E4(width, height, sampling);
    thumbSize = func_021C19E4(160, 120, 1);
    if (mainSize > thumbSize)
        return mainSize + (thumb ? 0x12c00 : 0);
    return thumbSize + (thumb ? 0x12c00 : 0);
}

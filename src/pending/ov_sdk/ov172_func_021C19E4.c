/*
 * function: func_021C19E4
 * address:  0x021C19E4
 * packet:   pkt_ov172_021C19E4
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      Yos_JPEGGetMemorySize (jpegenc.o)
 *
 * symbols:
 *   _u32_div_f  0x0209C2B0  arm
 */

unsigned long func_021C19E4(unsigned long width, unsigned long height, unsigned long sampling)
{
    unsigned long i;
    unsigned long cx;
    unsigned long cy;
    unsigned long dx;
    unsigned long dy;
    unsigned long samplingx;
    unsigned long samplingy;

    samplingy = samplingx = 1;
    switch (sampling) {
    case 1:
        break;
    case 2:
        samplingy = 2;
        samplingx = samplingy;
        break;
    case 3:
        samplingx = 2;
        break;
    }
    dx = (width + (samplingx * 8 - 1)) & ~(samplingx * 8 - 1);
    dy = (height + (samplingy * 8 - 1)) & ~(samplingy * 8 - 1);
    cx = dx >> 3;
    cy = dy >> 3;
    return dx * dy * 3 + ((cx * cy + ((cx / samplingx) * (cy / samplingy)) * 2) << 7) + 0x2b40;
}

/*
 * function: Yos_JPEGGetMemorySize
 * address:  0x021C19E4
 * packet:   pkt_ov172_021C19E4
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    w9_nm2: both mask locals (mx, my) in place of the inline samplingN * 8 - 1 expressions close it; the object holds the masks in r4 and a short-lived r2.
 *
 * sdk:      Yos_JPEGGetMemorySize (jpegenc.o)
 *
 * symbols:
 *   _u32_div_f  0x0209C2B0  arm
 */

unsigned long Yos_JPEGGetMemorySize(unsigned long width, unsigned long height, unsigned long sampling)
{
    unsigned long i;
    unsigned long mx;
    unsigned long my;
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
    mx = samplingx * 8 - 1;
    dx = (width + mx) & ~mx;
    my = samplingy * 8 - 1;
    dy = (height + my) & ~my;
    cx = dx >> 3;
    cy = dy >> 3;
    return dx * dy * 3 + ((cx * cy + ((cx / samplingx) * (cy / samplingy)) * 2) << 7) + 0x2b40;
}

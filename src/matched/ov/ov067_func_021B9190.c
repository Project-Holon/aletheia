/*
 * function: func_021B9190
 * address: 0x021B9190
 * packet: pkt_ov067_021B9190
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
signed char func_021B9190(const signed char *p, int step)
{
    signed char value, delta;
    value = p[3];
    delta = (unsigned int)(unsigned char)p[5] * (unsigned int)step;
    do { value += delta; } while (value >= 0 && value < 24);
    return value + p[0x66] / 8;
}

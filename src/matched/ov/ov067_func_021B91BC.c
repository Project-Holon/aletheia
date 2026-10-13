/*
 * function: FRAME_LIST_WrapIndex
 * address: 0x021B91BC
 * packet: pkt_ov067_021B91BC
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
signed char FRAME_LIST_WrapIndex(signed char a, signed char limit, int step)
{
    a = (signed char)((unsigned int)a + (unsigned int)step);
    if (a < 0) return limit;
    if (a > limit) return 0;
    return a;
}

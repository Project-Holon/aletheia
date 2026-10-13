/*
 * function: FRAME_LIST_GetStepFrames
 * address: 0x021B8404
 * packet: pkt_ov067_021B8404
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding at 0x021B841A.
 * symbols:
 *   _s32_div_f 0x0209C0A4 arm
 * Zero divisors remain admitted; call the ROM runtime helper directly.
 */
typedef unsigned char u8;
extern int _s32_div_f(int a, int b);
u8 FRAME_LIST_GetStepFrames(u8 *p, int n)
{
    if (n < 0) n = (int)(0u - (unsigned int)n);
    return _s32_div_f(p[5] << 3, n);
}
